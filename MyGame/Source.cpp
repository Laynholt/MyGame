#include <iostream>
#include <chrono>
#include <Windows.h>
#include <cstdint>

using namespace std;

int16_t iConsoleWidth = 120;								// ������ �������
int16_t iConsoleHeight = 30;								// ������ �������
int16_t iMapWidth = 20;										// ������ �����
int16_t iMapHeight = 16;										// ������ �����

float fPlayerX = 5.0f;
float fPlayerY = 4.0f;
float fPlayerA = 0.0f;										// ����������� ������
float fSpeed = 5.0f;										// �������� ������������

float fFoV = 3.14159f / 3.0f;								// ���� ������
float fDepth = 20.0f;										// ������������ ��������� ������

int main()
{
	// ������ ����� ������
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

	// ������� ����
	while (true)
	{
		aTimePoint2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = aTimePoint2 - aTimePoint1;
		aTimePoint1 = aTimePoint2;
		float fElapsedTime = elapsedTime.count();

		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)		// �������� "A" ������������ �� ������� �������
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// �������� "D" ������������ ������ ������� �������
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;

		if (GetAsyncKeyState((unsigned short)'W') & 0x8000)		// �������� "W" ��� �����
		{
			fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;

			if (map[(int)fPlayerY * iMapWidth + (int)fPlayerX] == '#') { // ���� ����������� �� ������, �� ���������� ���
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		if (GetAsyncKeyState((unsigned short)'S') & 0x8000)		// �������� "S" ��� �����
		{
			fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
			if (map[(int)fPlayerY * iMapWidth + (int)fPlayerX] == '#') { // ���� ����������� �� ������, �� ���������� ���
				fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

		for (int16_t x = 0; x < iConsoleWidth; x++)
		{
			// ������� ���������� �� ������ � ����������� fRayAngle 
			float fRayAngle = (fPlayerA - fFoV / 2.0f) + ((float)x / (float)iConsoleWidth) * fFoV;	// ����������� ����
			float fDistanceToWall = 0.0f;															// ��������� �� �����
			bool bHitWall = false;																	// ��������� �� ��� ������

			float fEyeX = sinf(fRayAngle);													// ���������� ���������� �������
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth)		// ���� �� �� ����������� �� ������ � ��������� �� ����� ������ ������������ ��������� ������
			{
				fDistanceToWall += 0.1f;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);								// ����� �� ������� ����
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);								// � ������� ����� ���

				if (nTestX < 0 || nTestX >= iMapWidth || nTestY < 0 || nTestY >= iMapHeight)
				{																					// ���� �� ����� �� ����
					bHitWall = true;
					fDistanceToWall = fDepth;
				}

				else if (map[nTestY * iMapWidth + nTestX] == '#')	// ���������, �� �������� �� ������ ���� ������
				{
					bHitWall = true;
				}

				//��������� ��������� ������� � ����
				int16_t iCeiling = (float)(iConsoleHeight / 2.0) - iConsoleWidth / ((float)fDistanceToWall);
				int16_t iFloor = iConsoleHeight - iCeiling;

				short siShade;

				if (fDistanceToWall <= fDepth / 4.0f)        siShade = 0x2588; // ���� ������ ������, �� ������ 
				else if (fDistanceToWall < fDepth / 3.0f)    siShade = 0x2593; // ������� �������
				else if (fDistanceToWall < fDepth / 2.0f)    siShade = 0x2592; // ��� ��������� �������� 
				else if (fDistanceToWall < fDepth)           siShade = 0x2591; // ������ ����� ������
				else                                         siShade = ' ';

				for (int y = 0; y < iConsoleHeight; y++)
				{
					if (y <= iCeiling)
						console[y * iConsoleWidth + x] = ' ';
					else if (y > iCeiling && y <= iFloor)
						console[y * iConsoleWidth + x] = siShade;
					else
					{
						// �� �� ����� � ����� - ����� ������� ����� ������ ����� ��������� ���������
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

		// ����� �� �����
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
	
	return 0;
}