#include "LibFunVar.h"

void letter(wchar_t* console, wchar_t* message, int32_t size_message)
{
	int32_t i = 0;
	int16_t A, B, C, D;

	A = iConsoleWidth / 5;
	B = iConsoleWidth - iConsoleWidth / 5;
	C = iConsoleHeight / 6;
	D = iConsoleHeight - iConsoleHeight / 6;

	for (int16_t x = 0; x < iConsoleWidth; x++)
	{
		for (int16_t y = 0; y < iConsoleHeight; y++)
		{
			if ((x >= A) && (x <= B) && (y >= C) && (y <= D))
			{
				if (((x >= A) && (x <= B) && (y == C)) || ((x >= A) && (x <= B) && (y == D)) ||
					((y >= C) && (y <= D) && (x == A)) || ((y >= C) && (y <= D) && (x == B)))
				{
					console[y * iConsoleWidth + x] = 0x00F7;
				}

				else if ((x >= A + 5) && (x <= B - 5) && (y >= C + 2) && (y <= D - 2) && i < size_message)
				{
					console[y * iConsoleWidth + x] = message[i++];
				}

				else
				{
					console[y * iConsoleWidth + x] = 0x2593;
					i = 0;
				}
			}
		}
	}
}

void screamer(wchar_t* console)
{
	int16_t rand_flag = rand() % 17;
	int16_t x1A, y1A, x1B, y1C;
	int16_t x2A, y2A, x2B, y2C;
	int16_t bufx = 0;

	//Цвета
	int16_t White = 0x2588;
	int16_t Grey = 0x2591;
	int16_t Dark_Grey = 0x2592;
	int16_t Question = 0x00BF;
	int16_t Face = 0x2261;

	int16_t color = 0;

	x1A = 44;	// Координаты верхней левой точки левого треугольника
	y1A = 10;

	x2A = 88;	// Ограничения для левого треугольника
	y2A = 20;

	y1C = 20;	// Координаты нижней левой точки правого треугольника
	x1B = 70;

	y2C = 21;	// Ограничения для правого треугольника
	x2B = 108;

	if (rand_flag <= 4)
		color = White;
	else if (rand_flag <= 8)
		color = Grey;
	else if (rand_flag <= 12)
		color = Dark_Grey;
	else
		color = Question;

	for (int16_t x = 0; x < iConsoleWidth; x++)
	{
		for (int16_t y = 0; y < iConsoleHeight; y++)
		{
			if ((x >= iConsoleWidth / 5) && (x <= (iConsoleWidth - iConsoleWidth / 5)) &&
				(y >= iConsoleHeight / 6) && (y <= (iConsoleHeight - iConsoleHeight / 6)))
			{

				if (x >= x1A && y >= y1A)								// Рисуем левый треугольник
				{
					if (bufx == 0 || bufx == x - 2)
					{
						y1A++;
						bufx = x;
					}

					if (y <= y1C && x <= x1B)
					{
						console[y * iConsoleWidth + x] = color;
					}
					else
					{
						if (y >= 25 && y <= 30 && x >= 56 && x <= 96)	// Рисуем прямоугольник (в части треугольника)
							console[y * iConsoleWidth + x] = color;
						else
							console[y * iConsoleWidth + x] = Face;
					}
				}

				else if (x >= x2A && y <= y2A)							// Рисуем правый треугольник
				{
					if (bufx <= x - 2)
					{
						y2C--;
						bufx = x;
					}

					if (y >= y2C && y >= 9 && x <= x2B)
					{
						console[y * iConsoleWidth + x] = color;
					}
					else
						console[y * iConsoleWidth + x] = Face;
				}

				else if (y >= 25 && y <= 30 && x >= 56 && x<= 96)		// Рисуем прямоугольник
					console[y * iConsoleWidth + x] = color;

				else
				{
					console[y * iConsoleWidth + x] = Face;
				}
			}
			rand_flag = rand() % 17;
		}
	}
}

bool game_over(wchar_t* console, wchar_t a)
{
	int16_t rand_flag = rand() % 10;

	for (int16_t x = 0; x < iConsoleWidth; x++)
	{
		for (int16_t y = 0; y < iConsoleHeight; y++)
		{
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)							// Для скипа сообщения нажмите Enter
				return true;

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
	return false;
}


void map_pulling(wstring& map)
{
	//map += L"##############################";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"#............................#";
	//map += L"##############################";

	map += L"####################################################################################################";
	map += L"#..................................................................................................#";
	map += L"#.............?...............................................?....................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#................?...........................?.....................................................#";
	map += L"####################################################################################################";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"#..................................................................................................#";
	//map += L"####################################################################################################";
}

bool corners(float& fEyeX, float& fEyeY, int16_t& nTestX, int16_t& nTestY)
{
	bool bBoundary = false;

	vector <pair <float, float>> p;

	for (int8_t tx = 0; tx < 2; tx++)
		for (int8_t ty = 0; ty < 2; ty++)						// Проходим по всем 4м рёбрам
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

	return bBoundary;
}

void open_map(wchar_t* console, wstring map)
{
	int16_t nx, nx1, ny, ny1;

	for (nx = (int16_t)fPlayerX, nx1 = (int16_t)fPlayerX; nx1 < iMapWidth; nx1++, nx++)
		for (ny = (int16_t)fPlayerY, ny1 = (int16_t)fPlayerY + 13; ny1 > (int16_t)fPlayerY; ny1--, ny++)
		{
			if (nx1 > iMapWidth)
			{
				console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';
				continue;
			}

			if (ny1 >= iMapHeight)
			{
				console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';

				/*int16_t EndY = ny - iMapHeight;
				console[(ny + 2 - (int16_t)fPlayerY + EndY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = '#';*/

				continue;
			}

			if (map[(ny1 - 2) * iMapWidth + nx1 - 1] == '@' || map[(ny1 - 2) * iMapWidth + nx1 - 1] == '!')
				console[(ny + 1 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 30] = '.';
			else
				console[(ny + 1 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 30] = map[(ny1 - 2) * iMapWidth + nx1 - 1];

		/*	if (ny1 * iMapWidth + nx1 <= 6000)
			{
				
			}

			else
			{
				console[(ny + 1 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 30] = ' ';
			}*/
		}
	console[((int16_t)fPlayerX + 41) * iConsoleWidth + (int16_t)fPlayerY] = 'P';
}

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter)
{
	char startTime[80];
	time_t seconds = time(NULL);
	strftime(startTime, 80, "%A %d %B %Y %H:%M:%S", localtime(&seconds));
	ofstream file;
	file.open("save.txt", ios_base::app); // запись в конец файла
	file << startTime << " " << (int16_t)fPlayerX << " " << (int16_t)fPlayerY << " " << (int16_t)fPlayerA
		<< " " << Time << " " << iObiliscCounter << endl;
	file.close();

}

void continue_game(audiere::OutputStreamPtr sound)  // открытие сохранений, но не выходит передать в game() параментры, чтоб телепортнуло куда надо...
{
	ifstream file("save.txt");
	string line;
	bool exit = 0;
	int16_t iObiliscCounter, Time, menu, whil = 0;

	iObiliscCounter = Time = 0;

	if (file.is_open())
	{
		cout << "ALL SAVES: \n";

		while (!exit)
		{
			while (getline(file, line))
			{
				cout << "\nSave [" << ++whil << "] " << line;
			}

			file.close();
			file.open("save.txt");

			cout << "\nChoose an action >> ";
			try
			{
				cin >> menu;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The character entered is not a number!";
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}


			if (menu <= whil && menu > 0)
			{
				/*file.seekg(0, file.beg);*/
				for (int16_t i = 0; i < menu; i++)
				{
					for (int16_t j = 0; j < 5; j++)
						file >> line;

					file >> fPlayerX;
					file >> fPlayerY;
					file >> fPlayerA;
					file >> Time;
					file >> iObiliscCounter;
				}


				exit = 1;
			}

			else
			{
				whil = 0;
				cout << "\nChoose again!\n";
				//system("cls");
			}
		}
	}

	file.close();
	sound->stop();
	game(fPlayerX, fPlayerY, fPlayerA, Time, iObiliscCounter);
}

void game(float fX, float fY, float fA, int16_t Time, int16_t iObiliscSave)//сама игра
{

	// Создаём буфер экрана
	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;									// Карта
	float fStopwatch = Time;						// Таймер
	int16_t iScreamDelay = 0;						// Задержка для воспроизведения скримера
	int16_t iRunDelay = 0;							// Задержка для востановления выносливости
	bool bZFlag = false;							// Флаг того, что кнопку нажали
	bool bMinimap = true;							// Миникарта вкл
	int16_t iMinimapDelay = 50;						// Задержка при откл и вкл миникарты
	float fSpeedBoost = 4.0f;						// Доп скорость при беге
	int16_t iRunTime = 0;							// Время бега
	int16_t iMessageDelay = 0;						// Задерка для вывода след сообщения
	int16_t iObiliscCounter = iObiliscSave;			// Количество обелисков
	/*int16_t YOU = 'U';*/

	map_pulling(map);

	// Воспроизводим музыку
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// Для начала нужно открыть AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/Apocryphos, Kammarheit, Atrium Carceri - Cavern of Igneous Flame.mp3", true); // Создаем поток для нашего звука
	sound->play();															// Проигрываем наш звук
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	// Открываем файл со звуком шагов
	audiere::AudioDevicePtr d1 = audiere::OpenDevice();
	audiere::OutputStreamPtr s1 = OpenSound(d1, "sounds/stone_walk3.ogg", false);		// Создаем поток для нашего звука
	int16_t iWalkDelay = 0;

	// Открываем файл с шепотом
	audiere::AudioDevicePtr d2 = audiere::OpenDevice();
	audiere::OutputStreamPtr s2 = OpenSound(d2, "sounds/whisper.ogg", false);			// Создаем поток для нашего звука

	// Открываем файл с зловещими звуками :D
	audiere::AudioDevicePtr d3 = audiere::OpenDevice();
	audiere::OutputStreamPtr s3 = OpenSound(d3, "sounds/ominous-sounds.ogg", false);	// Создаем поток для нашего звука

	// Открываем файл с голосом
	audiere::AudioDevicePtr d4 = audiere::OpenDevice();
	audiere::OutputStreamPtr s4 = OpenSound(d4, "sounds/voice.ogg", false);			// Создаем поток для нашего звука

	// Открываем файл со смехом
	audiere::AudioDevicePtr d5 = audiere::OpenDevice();
	audiere::OutputStreamPtr s5 = OpenSound(d5, "sounds/strashnye-zvuki-dyavolskiy-smeh.ogg", false);			// Создаем поток для нашего звука

	// Открываем файл со звуком портала
	audiere::AudioDevicePtr d6 = audiere::OpenDevice();
	audiere::OutputStreamPtr s6 = OpenSound(d6, "sounds/portal.ogg", true);			// Создаем поток для нашего звука

	// Открываем файл со звуком закрытия портала
	audiere::AudioDevicePtr d7 = audiere::OpenDevice();
	audiere::OutputStreamPtr s7 = OpenSound(d7, "sounds/exit_from_portal.ogg", false);			// Создаем поток для нашего звука

	int32_t iSoundEffectDelay = 100;

	auto aTimePoint1 = chrono::system_clock::now();
	auto aTimePoint2 = chrono::system_clock::now();

	// Игровой цикл
	while (true)
	{
		if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '%' || iObiliscCounter == 5)    // Символ конца игры
		{
			if (game_over(console, 0x256C))
			{
				//delete[] console;
				//return;
			}
		}

		else if (GetAsyncKeyState((unsigned short)'X') & 0x8000)		// Клавишей "U" сохраняем координаты и время игры
		{
			open_map(console, map);
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '!' && iScreamDelay <= 25)    // Символ скримера
		{
			if (iScreamDelay == 0)
			{
				screamer(console);
				s5->play();
				s5->setVolume(0.6f);
			}

			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
				iScreamDelay = 100;

			iScreamDelay++;
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '?' && iMessageDelay == 0)    // Символ сообщения
		{
			wchar_t a[5] = { 'R', 'U', 'N', '!', '?' };
			letter(console, a, 5);
			_getch();

			if (GetAsyncKeyState(VK_RETURN) & 0x8000)							// Для скипа сообщения нажмите Enter
				iMessageDelay++;
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '*')	// Обелиск
		{
			s7->play();															// Проигрывается музыка исчезновения
			s7->setVolume(0.6f);
			iObiliscCounter++;
			map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] = '.';		// Исчезает обелиск

			int16_t del = 0;

			for (int16_t i = 0; i < 7; i++)										// Удаления звуков обелиска
			{
				for (int16_t j = 0; j < 7; j++)
				{
					del = ((int16_t)fPlayerY - 3 + j) * iMapWidth + (int16_t)fPlayerX - 3 + i;

					if (del >= 0)
					{
						if (map[del] == '@')
							map[del] = '.';
					}
				}

			}
			/*fPlayerX = 5.0f;													// Телепорт игрока
			fPlayerY = 80.0f;*/
		}

		else
		{
			fStopwatch = clock() / 1000.0f;
			iScreamDelay = 0;

			if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] != '?')	// Для повторого подбора сообщения
			{
				iMessageDelay = 0;
			}

			aTimePoint2 = chrono::system_clock::now();
			chrono::duration<float> elapsedTime = aTimePoint2 - aTimePoint1;
			aTimePoint1 = aTimePoint2;
			float fElapsedTime = elapsedTime.count();

			if (GetAsyncKeyState(VK_TAB) & 0x8000)		// Клавишей "TAB" вкл/выкл миникарту
			{
				if (bMinimap && iMinimapDelay == 50)
				{
					bMinimap = false;
					iMinimapDelay = 0;
				}

				else if (iMinimapDelay == 50)
				{
					bMinimap = true;
					iMinimapDelay = 0;
				}
			}

			if (GetAsyncKeyState((unsigned short)'U') & 0x8000)		// Клавишей "U" сохраняем координаты и время игры
				save(fPlayerX, fPlayerY, (int16_t)fStopwatch, iObiliscCounter);

			if (GetAsyncKeyState((unsigned short)'A') & 0x8000)		// Клавишей "A" поворачиваем по часовой стрелке
				fPlayerA -= (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// Клавишей "D" поворачиваем против часовой стрелки
				fPlayerA += (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'W') & 0x8000)		// Клавишей "W" идём вперёд
			{
				if (GetAsyncKeyState((unsigned short)'Z') & 0x8000)
					bZFlag = true;

				if (bZFlag)
				{
					if (iRunTime == 0 && iRunDelay == 0)
					{
						fSpeed += fSpeedBoost;

					}

					iRunTime++;

					if (iRunTime == 300)
					{
						fSpeed -= fSpeedBoost;
						iRunDelay = 1000;
					}

					else if (iRunTime > 300)
					{
						if (iRunDelay == 0)
						{
							iRunTime = 0;
							bZFlag = false;
						}

						else
						{
							iRunDelay--;
						}
					}
				}


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
				bool bObiliskFound = false;

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

					else if (map[nTestY * iMapWidth + nTestX] == '*')
					{
						bHitWall = true;
						bObiliskFound = true;
						bBoundary = corners(fEyeX, fEyeY, nTestX, nTestY);
					}

					else if (map[nTestY * iMapWidth + nTestX] == '#')	// Проверяем, не является ли ячейка луча стеной
					{
						bHitWall = true;
						bBoundary = corners(fEyeX, fEyeY, nTestX, nTestY);
					}



					//Вычисляем дистанцию потолка и пола
					int16_t iCeiling = (float)(iConsoleHeight / 2.0) - iConsoleWidth / ((float)fDistanceToWall);
					int16_t iFloor = iConsoleHeight - iCeiling;

					short siShade;

					if (bObiliskFound == false)
					{
						if (fDistanceToWall <= fDepth / 4.0f)        siShade = 0x2588; // Если стенка близко, то рисуем 
						else if (fDistanceToWall < fDepth / 3.0f)    siShade = 0x2593; // светлую полоску
						else if (fDistanceToWall < fDepth / 2.0f)    siShade = 0x2592; // Для отдалённых участков 
						else if (fDistanceToWall < fDepth)           siShade = 0x2591; // рисуем более темную
						else                                         siShade = ' ';
					}

					else
					{
						siShade = 0x2248;
					}

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
				iWalkDelay = 0;
			}

			else if ((int16_t)fSpeed == SPEED)
			{
				if(iWalkDelay == 23)
					iWalkDelay = -1;
			}

			else if ((int16_t)fSpeed == SPEED + (int16_t)fSpeedBoost)
			{
				if (iWalkDelay == 15)
					iWalkDelay = -1;
			}

			iWalkDelay++;

			////Обелиск
			if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '@')
			{
				s6->play();
				s6->setVolume(0.6f);
			}

			// Проигрывание звуков
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

			if (iMinimapDelay < 50)											// Задержка для вкл/выкл миникарты
			{
				iMinimapDelay++;
			}

			if (bMinimap)
			{
				// Миникарта
				int16_t nx, nx1, ny, ny1;

				for (nx = (int16_t)fPlayerX, nx1 = (int16_t)fPlayerX; nx1 < (int16_t)fPlayerX + 26; nx1++, nx++)
					for (ny = (int16_t)fPlayerY, ny1 = (int16_t)fPlayerY + 13; ny1 > (int16_t)fPlayerY; ny1--, ny++)
					{
						if (nx1 > iMapWidth)
						{
							console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';
							continue;
						}

						if (ny1 >= iMapHeight)
						{
							console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';

							if (ny1 == iMapHeight)
							{
								console[(ny + 2 - (int16_t)fPlayerY - 1) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = '#';
								console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = map[(ny1 - 2) * iMapWidth + nx1 - 1];
							}

							continue;
						}

						if (ny1 * iMapWidth + nx1 <= iMapHeight*iMapWidth)
						{
							if (map[(ny1 - 2) * iMapWidth + nx1 - 1] == '@' || map[(ny1 - 2) * iMapWidth + nx1 - 1] == '!')
								console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = '.';
							else
								console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = map[(ny1 - 2) * iMapWidth + nx1 - 1];
						}

						else
						{
							console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';
						}
					}
				console[13 * iConsoleWidth + 2] = 'A';

				// Обводка миникарты
				int16_t iMapCorner = 0x03A3;
				for (nx = 0; nx < 28; nx++)
				{
					for (ny = 1; ny < 16; ny++)
					{
						if (nx == 0)
							console[ny * iConsoleWidth] = iMapCorner;
						else if (ny == 1)
							console[ny * iConsoleWidth + nx] = iMapCorner;
						else if (ny == 15)
							console[ny * iConsoleWidth + nx] = iMapCorner;
						else if (nx == 27)
							console[ny * iConsoleWidth + nx] = iMapCorner;
					}
				}
			}
			// Вывод координат и таймера
			swprintf_s(console, 90, L"X=%3.2f, Y=%3.2f, A=%3.2f, Time: %3.3f, Find all obelisks [%d|5], Speed: %2.2f", fPlayerX,
				fPlayerY, fPlayerA, fStopwatch, iObiliscCounter, fSpeed);
		}

		// Вывод на экран
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
}

void authors()
{
	system("cls");
	cout <<
		"|--------------------------------------------------------------------|\n"
		"|                             AUTHORS                                |\n"
		"|               laynholt                  marco_dragan               |\n"
		"|               https://github.com/VariableRiw/MyGame                |\n"
		"|                                                                    |\n"
		"|--------------------------------------------------------------------|\n";

}

void control() 
{
	system("cls");

	cout <<
		"|--------------------------------------------------------------------|\n"
		"|                            W - forward                             |\n"
		"|                            S - back                                |\n"
		"|                            Z - run                                 |\n"
		"|                            A - left turn                           |\n"
		"|                            D - right turn                          |\n"
		"|                            U - game save                           |\n"
		"|                           TAB - minimap on|off                     |\n"
		"|--------------------------------------------------------------------|\n";
}