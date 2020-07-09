#include <iostream>
#include <chrono>
#include <Windows.h>
#include <cstdint>

using namespace std;

int16_t iConsoleWidth = 120;								// Ширина консоли
int16_t iConsoleHeight = 30;								// Высота консоли
int16_t iMapWidth = 20;										// Ширина карты
int16_t iMapHeight = 16;										// Высота карты

float fPlayerX = 5.0f;
float fPlayerY = 4.0f;
float fPlayerA = 0.0f;										// Направление игрока
float fSpeed = 5.0f;										// Скорость передвижения

float fFoV = 3.14159f / 3.0f;								// Угол обзора
float fDepth = 20.0f;										// Максимальная дистанция обзора

int main()
{
	// Создаём буфер экрана
	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;

	
	//map += L"################";
	map += L"####################";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"####################";
	map += L"################";

	auto aTimePoint1 = chrono::system_clock::now();
	auto aTimePoint2 = chrono::system_clock::now();

	// Игровой цикл
	while (true)
	{
		aTimePoint2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = aTimePoint2 - aTimePoint1;
		aTimePoint1 = aTimePoint2;
		float fElapsedTime = elapsedTime.count();

		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)		// Клавишей "A" поворачиваем по часовой стрелке
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// Клавишей "D" поворачиваем против часовой стрелки
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;

		if (GetAsyncKeyState((unsigned short)'W') & 0x8000)		// Клавишей "W" идём вперёд
		{
			fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;

			if (map[(int)fPlayerY * iMapWidth + (int)fPlayerX] == '#') { // Если столкнулись со стеной, то откатываем шаг
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		if (GetAsyncKeyState((unsigned short)'S') & 0x8000)		// Клавишей "S" идём назад
		{
			fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
			if (map[(int)fPlayerY * iMapWidth + (int)fPlayerX] == '#') { // Если столкнулись со стеной, но откатываем шаг
				fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

		for (int16_t x = 0; x < iConsoleWidth; x++)
		{
			// Находим расстояние до стенки в направлении fRayAngle 
			float fRayAngle = (fPlayerA - fFoV / 2.0f) + ((float)x / (float)iConsoleWidth) * fFoV;	// Направление луча
			float fDistanceToWall = 0.0f;															// Дистанция до стены
			bool bHitWall = false;																	// Достигнул ли луч стенку

			float fEyeX = sinf(fRayAngle);													// Координаты единичного вектора
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth)		// Пока мы не столкнулись со стеной и дистанция до стены меньше максимальная дистанция обзора
			{
				fDistanceToWall += 0.1f;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);								// Точка на игровом поле
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);								// в которую попал луч

				if (nTestX < 0 || nTestX >= iMapWidth || nTestY < 0 || nTestY >= iMapHeight)
				{																					// Если мы вышли за зону
					bHitWall = true;
					fDistanceToWall = fDepth;
				}

				else if (map[nTestY * iMapWidth + nTestX] == '#')	// Проверяем, не является ли ячейка луча стеной
				{
					bHitWall = true;
				}

				//Вычисляем дистанцию потолка и пола
				int16_t iCeiling = (float)(iConsoleHeight / 2.0) - iConsoleWidth / ((float)fDistanceToWall);
				int16_t iFloor = iConsoleHeight - iCeiling;

				short siShade;

				if (fDistanceToWall <= fDepth / 4.0f)        siShade = 0x2588; // Если стенка близко, то рисуем 
				else if (fDistanceToWall < fDepth / 3.0f)    siShade = 0x2593; // светлую полоску
				else if (fDistanceToWall < fDepth / 2.0f)    siShade = 0x2592; // Для отдалённых участков 
				else if (fDistanceToWall < fDepth)           siShade = 0x2591; // рисуем более темную
				else                                         siShade = ' ';

				for (int y = 0; y < iConsoleHeight; y++)
				{
					if (y <= iCeiling)
						console[y * iConsoleWidth + x] = ' ';
					else if (y > iCeiling && y <= iFloor)
						console[y * iConsoleWidth + x] = siShade;
					else
					{
						// То же самое с полом - более близкие части рисуем более заметными символами
						float b = 1.0f - ((float)y - iConsoleHeight / 2.0) / ((float)iConsoleHeight / 2.0);
						if (b < 0.25)        siShade = '#';
						else if (b < 0.5)    siShade = 'x';
						else if (b < 0.75)   siShade = '.';
						else if (b < 0.9)    siShade = '-';
						else                 siShade = ' ';

						console[y * iConsoleWidth + x] = siShade;
					}
				}
			}
		}

		// Вывод на экран
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
	
	return 0;
}