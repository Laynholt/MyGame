#include "LibFunVar.h"

void screamer(wchar_t* console)
{
	int16_t rand_flag = rand() % 10;

	for (int16_t x = 0; x < iConsoleWidth; x++)
	{
		for (int16_t y = 0; y < iConsoleHeight; y++)
		{
			if ((x >= iConsoleWidth / 5) && (x <= (iConsoleWidth - iConsoleWidth / 5)) &&
				(y >= iConsoleHeight / 6) && (y <= (iConsoleHeight - iConsoleHeight / 6)))
			{
				console[y * iConsoleWidth + x] = 0x2261;
			}
		}
	}
}

void game_over(wchar_t* console, wchar_t a)
{
	int16_t rand_flag = rand() % 10;

	for (int16_t x = 0; x < iConsoleWidth; x++)
	{
		for (int16_t y = 0; y < iConsoleHeight; y++)
		{
			if (rand_flag != 0)
			{
				console[y * iConsoleWidth + x] = a;
			}

			else
			{
				console[y * iConsoleWidth + x] = 'G';
				console[y * iConsoleWidth + x + 1] = 'A';
				console[y * iConsoleWidth + x + 2] = 'M';
				console[y * iConsoleWidth + x + 3] = 'E';
				console[y * iConsoleWidth + x + 4] = ' ';
				console[y * iConsoleWidth + x + 5] = 'O';
				console[y * iConsoleWidth + x + 6] = 'V';
				console[y * iConsoleWidth + x + 7] = 'E';
				console[y * iConsoleWidth + x + 8] = 'R';
				y += 8;
			}

			rand_flag = rand() % 3;
		}
	}
}

void map_pulling(wstring& map)
{
	map += L"##################################################";
	map += L"#..%.............................#...............#";
	map += L"#.#########......................#...#####.......#";
	map += L"#................###############.#...............#";
	map += L"#!...............................................#";
	map += L"#................................................#";
	map += L"#......###############...........................#";
	map += L"#.................................################";
	map += L"#.........................##......#..............#";
	map += L"#.........................##......#.############.#";
	map += L"#.........................##......#.#..........#.#";
	map += L"#.........................##......#.#..####....#.#";
	map += L"#.........................##......#.#.##########.#";
	map += L"#.........................##......#.#............#";
	map += L"#.........................##......#.##############";
	map += L"#.........................##.....................#";
	map += L"#...............############.....................#";
	map += L"#................................................#";
	map += L"#..........................#.################....#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#................................#...............#";
	map += L"#.#########......................#...#####.......#";
	map += L"#................###############.#...............#";
	map += L"#................................................#";
	map += L"#................................................#";
	map += L"#......###############...........................#";
	map += L"#.................................################";
	map += L"#.........................##......#..............#";
	map += L"#.........................##......#.############.#";
	map += L"#.........................##......#.#..........#.#";
	map += L"#.........................##......#.#..####....#.#";
	map += L"#.........................##......#.#.##########.#";
	map += L"#.........................##......#.#............#";
	map += L"#.........................##......#.##############";
	map += L"#.........................##.....................#";
	map += L"#...............############.....................#";
	map += L"#................................................#";
	map += L"#..........................#.################....#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#................................#...............#";
	map += L"#.#########......................#...#####.......#";
	map += L"#................###############.#...............#";
	map += L"#................................................#";
	map += L"#................................................#";
	map += L"#......###############...........................#";
	map += L"#.................................################";
	map += L"#.........................##......#..............#";
	map += L"#.........................##......#.############.#";
	map += L"#.........................##......#.#..........#.#";
	map += L"#.........................##......#.#..####....#.#";
	map += L"#.........................##......#.#.##########.#";
	map += L"#.........................##......#.#............#";
	map += L"#.........................##......#.##############";
	map += L"#.........................##.....................#";
	map += L"#...............############.....................#";
	map += L"#................................................#";
	map += L"#..........................#.################....#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#................................#...............#";
	map += L"#.#########......................#...#####.......#";
	map += L"#................###############.#...............#";
	map += L"#................................................#";
	map += L"#................................................#";
	map += L"#......###############...........................#";
	map += L"#.................................################";
	map += L"#.........................##......#..............#";
	map += L"#.........................##......#.############.#";
	map += L"#.........................##......#.#..........#.#";
	map += L"#.........................##......#.#..####....#.#";
	map += L"#.........................##......#.#.##########.#";
	map += L"#.........................##......#.#............#";
	map += L"#.........................##......#.##############";
	map += L"#.........................##.....................#";
	map += L"#...............############.....................#";
	map += L"#................................................#";
	map += L"#..........................#.################....#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#..........................#.....................#";
	map += L"#................................#...............#";
	map += L"#.#########......................#...#####.......#";
	map += L"#................###############.#...............#";
	map += L"#................................................#";
	map += L"#................................................#";
	map += L"#......###############...........................#";
	map += L"##################################################";
}

int main()
{
	srand(time(NULL));
	system("mode con cols=150 lines=40");					// Фиксируем размер окна на 150 на 40

	// Создаём буфер экрана
	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;
	float iStopwatch = 0;
	int16_t iScreanDelay = 0;

	map_pulling(map);

	// Воспроизводим музыку
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// Для начала нужно открыть AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "Apocryphos, Kammarheit, Atrium Carceri - Cavern of Igneous Flame.mp3", true); // Создаем поток для нашего звука
	sound->play();															// Проигрываем наш звук
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	// Открываем файл со звуком шагов
	audiere::AudioDevicePtr d1 = audiere::OpenDevice();
	audiere::OutputStreamPtr s1 = OpenSound(d1, "stone_walk3.ogg", false);		// Создаем поток для нашего звука
	int16_t iWalkDelay = 0;

	// Открываем файл с шепотом
	audiere::AudioDevicePtr d2 = audiere::OpenDevice();
	audiere::OutputStreamPtr s2 = OpenSound(d2, "whisper.ogg", false);			// Создаем поток для нашего звука

	// Открываем файл с зловещими звуками :D
	audiere::AudioDevicePtr d3 = audiere::OpenDevice();
	audiere::OutputStreamPtr s3 = OpenSound(d3, "ominous-sounds.ogg", false);	// Создаем поток для нашего звука

	// Открываем файл с голосом
	audiere::AudioDevicePtr d4 = audiere::OpenDevice();
	audiere::OutputStreamPtr s4 = OpenSound(d4, "voice.ogg", false);			// Создаем поток для нашего звука

	// Открываем файл со смехом
	audiere::AudioDevicePtr d5 = audiere::OpenDevice();
	audiere::OutputStreamPtr s5 = OpenSound(d5, "strashnye-zvuki-dyavolskiy-smeh.ogg", false);			// Создаем поток для нашего звука

	int32_t iSoundEffectDelay = 100;

	auto aTimePoint1 = chrono::system_clock::now();
	auto aTimePoint2 = chrono::system_clock::now();

	// Игровой цикл
	while (true)
	{
		if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '%')    // Символ конца игры
		{
			game_over(console, 0x256C);
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '!' && iScreanDelay <= 25)    // Символ скримера
		{
			if (iScreanDelay == 0)
			{
				screamer(console);
				s5->play();
				s5->setVolume(0.6f);
			}

			iScreanDelay++;
		}

		else
		{
			iStopwatch = clock() / 1000.0f;
			iScreanDelay = 0;

			aTimePoint2 = chrono::system_clock::now();
			chrono::duration<float> elapsedTime = aTimePoint2 - aTimePoint1;
			aTimePoint1 = aTimePoint2;
			float fElapsedTime = elapsedTime.count();

			if (GetAsyncKeyState((unsigned short)'A') & 0x8000)		// Клавишей "A" поворачиваем по часовой стрелке
				fPlayerA -= (fSpeed * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// Клавишей "D" поворачиваем против часовой стрелки
				fPlayerA += (fSpeed * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'W') & 0x8000)		// Клавишей "W" идём вперёд
			{
				fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;

				if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '#')  // Если столкнулись со стеной, то откатываем шаг
				{
					fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
					fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
				}
			}

			if (GetAsyncKeyState((unsigned short)'S') & 0x8000)		// Клавишей "S" идём назад
			{
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
				if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '#')  // Если столкнулись со стеной, но откатываем шаг
				{
					fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
					fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
				}
			}

			for (int16_t x = 0; x < iConsoleWidth; x++)
			{
				// Находим расстояние до стенки в направлении fRayAngle 
				float fRayAngle = (fPlayerA - fFoV / 2.0f) + ((float)x / (float)iConsoleWidth) * fFoV;	// Направление луча
				float fDistanceToWall = 0.0f;															// Дистанция до стены
				bool bHitWall = false;																	// Достигнул ли луч стенку
				bool bBoundary = false;																	// Достигнул ли луч границу между стенами

				float fEyeX = sinf(fRayAngle);													// Координаты единичного вектора
				float fEyeY = cosf(fRayAngle);

				while (!bHitWall && fDistanceToWall < fDepth)		// Пока мы не столкнулись со стеной и дистанция до стены меньше максимальная дистанция обзора
				{
					fDistanceToWall += 0.1f;

					int16_t nTestX = (int16_t)(fPlayerX + fEyeX * fDistanceToWall);								// Точка на игровом поле
					int16_t nTestY = (int16_t)(fPlayerY + fEyeY * fDistanceToWall);								// в которую попал луч

					if (nTestX < 0 || nTestX >= iMapWidth || nTestY < 0 || nTestY >= iMapHeight)
					{																					// Если мы вышли за зону
						bHitWall = true;
						fDistanceToWall = fDepth;
					}

					else if (map[nTestY * iMapWidth + nTestX] == '#')	// Проверяем, не является ли ячейка луча стеной
					{
						bHitWall = true;
						//--
						vector <pair <float, float>> p;

						for (int tx = 0; tx < 2; tx++)
							for (int ty = 0; ty < 2; ty++)						// Проходим по всем 4м рёбрам
							{
								float vx = (float)nTestX + tx - fPlayerX;			// Координаты вектора,
								float vy = (float)nTestY + ty - fPlayerY;			// ведущего из наблюдателя в ребро
								float d = sqrt(vx * vx + vy * vy);					// Модуль этого вектора
								float dot = (fEyeX * vx / d) + (fEyeY * vy / d);	// Скалярное произведение (единичных векторов)
								p.push_back(make_pair(d, dot));						// Сохраняем результат в массив
							}
						// Мы будем выводить два ближайших ребра, поэтому сортируем их по модулю вектора ребра
						sort(p.begin(), p.end(), [](const pair <float, float>& left, const pair <float, float>& right) {return left.first < right.first; });

						float fBound = 0.005;							// Угол, при котором начинаем различать ребро.
						if (acos(p.at(0).second) < fBound) bBoundary = true;
						if (acos(p.at(1).second) < fBound) bBoundary = true;
						//--
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

					if (bBoundary)		siShade = 0x2551; // 2502

					for (int16_t y = 0; y < iConsoleHeight; y++)
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

			// Звук шагов с небольшой задержкой
			if ((fPlayerXBuf != fPlayerX || fPlayerYBuf != fPlayerY) && iWalkDelay == 0)
			{
				fPlayerXBuf = fPlayerX;
				fPlayerYBuf = fPlayerY;
				s1->play();														// Проигрываем звук шагов
				s1->setVolume(0.5f);
			}

			else if (fPlayerXBuf == fPlayerX && fPlayerYBuf == fPlayerY)
			{
				s1->stop();
				iWalkDelay = 0;
			}

			else if (iWalkDelay == 30)
			{
				iWalkDelay = -1;
			}

			iWalkDelay++;

			if (iSoundEffectDelay == 0)
			{
				int16_t q = rand() % 3;

				if (q == 0)
				{
					s2->play();														// Проигрываем шепот
					s2->setVolume(0.4f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}

				else if (q == 1)
				{
					s3->play();														// Проигрываем зловещие звуки
					s3->setVolume(0.6f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}

				else if (q == 2)
				{
					s4->play();														// Проигрываем голос
					s4->setVolume(0.6f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}
			}

			iSoundEffectDelay--;

			// Вывод координат и таймера
			swprintf_s(console, 50, L"X=%3.2f, Y=%3.2f, A=%3.2f, Time: %3.3f", fPlayerX, fPlayerY, fPlayerA, iStopwatch);
		}

		// Вывод на экран
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
	
	return 0;
}