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
	int16_t katet = 25;
	int16_t side = 60;
	int16_t ki, si;
	int16_t xA, yA;

	ki = si = 0;
	xA = 14;
	yA = 5;

	for (int16_t x = 0; x < iConsoleWidth; x++)
	{
		for (int16_t y = 0; y < iConsoleHeight; y++)
		{
			if ((x >= iConsoleWidth / 5) && (x <= (iConsoleWidth - iConsoleWidth / 5)) &&
				(y >= iConsoleHeight / 6) && (y <= (iConsoleHeight - iConsoleHeight / 6)))
			{

				if (x >= xA && y >= yA)
				{
					console[y * iConsoleWidth + x] = 0x2588;
				}

				else
				{
					console[y * iConsoleWidth + x] = 0x2261;
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
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)							// ��� ����� ��������� ������� Enter
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
	map += L"##################################################";
	map += L"#...........?....................#...............#";
	map += L"#.#########......................#...#####.......#";
	map += L"#................###############.#...............#";
	map += L"#................................................#";
	map += L"#@@@@............................................#";
	map += L"#@@@@..###############...........................#";
	map += L"#@@@@..@@@@@@@...@@@*@@@..........################";
	map += L"#*@@@..@@@@@@@...@@@@@@@..##......#..............#";
	map += L"#@@@@..@@@@@@@...@@@@@@@..##......#.############.#";
	map += L"#@@@@..@@@*@@@...@@@@@@@..##......#.#..........#.#";
	map += L"#@@@@..@@@@@@@......@@@@@@##......#.#..####....#.#";
	map += L"#......@@@@@@@......@@@@@@##......#.#.##########.#";
	map += L"#......@@@@@@@......@@@@@@##......#.#............#";
	map += L"#...................@@@*@@##......#.##############";
	map += L"#...................@@@@@@##.....................#";
	map += L"#...@@@@@@@.....############.....................#";
	map += L"#...@@@@@@@......................................#";
	map += L"#...@@@@@@@................#.################....#";
	map += L"#...@@@*@@@................#.....................#";
	map += L"#...@@@@@@@................#.....................#";
	map += L"#...@@@@@@@................#.....................#";
	map += L"#...@@@@@@@................#.....................#";
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

bool corners(float& fEyeX, float& fEyeY, int16_t& nTestX, int16_t& nTestY)
{
	bool bBoundary = false;

	vector <pair <float, float>> p;

	for (int8_t tx = 0; tx < 2; tx++)
		for (int8_t ty = 0; ty < 2; ty++)						// �������� �� ���� 4� �����
		{
			float vx = (float)nTestX + tx - fPlayerX;			// ���������� �������,
			float vy = (float)nTestY + ty - fPlayerY;			// �������� �� ����������� � �����
			float d = sqrt(vx * vx + vy * vy);					// ������ ����� �������
			float dot = (fEyeX * vx / d) + (fEyeY * vy / d);	// ��������� ������������ (��������� ��������)
			p.push_back(make_pair(d, dot));						// ��������� ��������� � ������
		}
	// �� ����� �������� ��� ��������� �����, ������� ��������� �� �� ������ ������� �����
	sort(p.begin(), p.end(), [](const pair <float, float>& left, const pair <float, float>& right) {return left.first < right.first; });

	float fBound = 0.005;							// ����, ��� ������� �������� ��������� �����.
	if (acos(p.at(0).second) < fBound) bBoundary = true;
	if (acos(p.at(1).second) < fBound) bBoundary = true;

	return bBoundary;
}

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter)
{
	char startTime[80];
	time_t seconds = time(NULL);
	strftime(startTime, 80, "%A %d %B %Y %H:%M:%S", localtime(&seconds));
	ofstream file;
	file.open("save.txt", ios_base::app); // ������ � ����� �����
	file << startTime << " " << (int16_t)fPlayerX << " " << (int16_t)fPlayerY << " " << (int16_t)fPlayerA
		<< " " << Time << " " << iObiliscCounter << endl;
	file.close();

}

void continue_game(audiere::OutputStreamPtr sound)  // �������� ����������, �� �� ������� �������� � game() ����������, ���� ������������ ���� ����...
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
			cin >> menu;
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

void game(float fX, float fY, float fA, int16_t Time, int16_t iObiliscSave)//���� ����
{

	// ������ ����� ������
	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;
	float fStopwatch = Time;
	int16_t iScreamDelay = 0;
	int16_t iRunDelay = 0;
	bool bZFlag = false;
	float fSpeedBoost = 4.0f;
	int16_t iTimeBeforeRun = 0;
	int16_t iMessageDelay = 0;
	int16_t iObiliscCounter = iObiliscSave;

	map_pulling(map);

	// ������������� ������
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// ��� ������ ����� ������� AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/Apocryphos, Kammarheit, Atrium Carceri - Cavern of Igneous Flame.mp3", true); // ������� ����� ��� ������ �����
	sound->play();															// ����������� ��� ����
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	// ��������� ���� �� ������ �����
	audiere::AudioDevicePtr d1 = audiere::OpenDevice();
	audiere::OutputStreamPtr s1 = OpenSound(d1, "sounds/stone_walk3.ogg", false);		// ������� ����� ��� ������ �����
	int16_t iWalkDelay = 0;

	// ��������� ���� � �������
	audiere::AudioDevicePtr d2 = audiere::OpenDevice();
	audiere::OutputStreamPtr s2 = OpenSound(d2, "sounds/whisper.ogg", false);			// ������� ����� ��� ������ �����

	// ��������� ���� � ��������� ������� :D
	audiere::AudioDevicePtr d3 = audiere::OpenDevice();
	audiere::OutputStreamPtr s3 = OpenSound(d3, "sounds/ominous-sounds.ogg", false);	// ������� ����� ��� ������ �����

	// ��������� ���� � �������
	audiere::AudioDevicePtr d4 = audiere::OpenDevice();
	audiere::OutputStreamPtr s4 = OpenSound(d4, "sounds/voice.ogg", false);			// ������� ����� ��� ������ �����

	// ��������� ���� �� ������
	audiere::AudioDevicePtr d5 = audiere::OpenDevice();
	audiere::OutputStreamPtr s5 = OpenSound(d5, "sounds/strashnye-zvuki-dyavolskiy-smeh.ogg", false);			// ������� ����� ��� ������ �����

	// ��������� ���� �� ������ �������
	audiere::AudioDevicePtr d6 = audiere::OpenDevice();
	audiere::OutputStreamPtr s6 = OpenSound(d6, "sounds/portal.ogg", true);			// ������� ����� ��� ������ �����

	// ��������� ���� �� ������ �������� �������
	audiere::AudioDevicePtr d7 = audiere::OpenDevice();
	audiere::OutputStreamPtr s7 = OpenSound(d7, "sounds/exit_from_portal.ogg", false);			// ������� ����� ��� ������ �����

	int32_t iSoundEffectDelay = 100;

	auto aTimePoint1 = chrono::system_clock::now();
	auto aTimePoint2 = chrono::system_clock::now();

	// ������� ����
	while (true)
	{
		if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '%' || iObiliscCounter == 5)    // ������ ����� ����
		{
			if (game_over(console, 0x256C))
			{
				//delete[] console;
				//return;
			}
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '!' && iScreamDelay <= 25)    // ������ ��������
		{
			if (iScreamDelay == 0)
			{
				screamer(console);
				s5->play();
				s5->setVolume(0.6f);
			}

			iScreamDelay++;
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '?' && iMessageDelay == 0)    // ������ ���������
		{
			wchar_t a[5] = { 'R', 'U', 'N', '!', '?' };
			letter(console, a, 5);
			_getch();

			if (GetAsyncKeyState(VK_RETURN) & 0x8000)							// ��� ����� ��������� ������� Enter
				iMessageDelay++;
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '*')	// �������
		{
			s7->play();															// ������������� ������ ������������
			s7->setVolume(0.6f);
			iObiliscCounter++;
			map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] = '.';		// �������� �������

			int16_t del = 0;

			for (int16_t i = 0; i < 7; i++)										// �������� ������ ��������
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
			/*fPlayerX = 5.0f;													// �������� ������
			fPlayerY = 80.0f;*/
		}

		else
		{
			fStopwatch = clock() / 1000.0f;
			iScreamDelay = 0;

			if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] != '?')	// ��� ��������� ������� ���������
			{
				iMessageDelay = 0;
			}

			aTimePoint2 = chrono::system_clock::now();
			chrono::duration<float> elapsedTime = aTimePoint2 - aTimePoint1;
			aTimePoint1 = aTimePoint2;
			float fElapsedTime = elapsedTime.count();

			if (GetAsyncKeyState((unsigned short)'U') & 0x8000)		// �������� "U" ��������� ���������� � ����� ����
				save(fPlayerX, fPlayerY, (int16_t)fStopwatch, iObiliscCounter);

			if (GetAsyncKeyState((unsigned short)'A') & 0x8000)		// �������� "A" ������������ �� ������� �������
				fPlayerA -= (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// �������� "D" ������������ ������ ������� �������
				fPlayerA += (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'W') & 0x8000)		// �������� "W" ��� �����
			{
				if (GetAsyncKeyState((unsigned short)'Z') & 0x8000)
					bZFlag = true;

				if (bZFlag)
				{
					if (iTimeBeforeRun == 0 && iRunDelay == 0)
					{
						fSpeed += fSpeedBoost;

					}

					iTimeBeforeRun++;

					if (iTimeBeforeRun == 300)
					{
						fSpeed -= fSpeedBoost;
						iRunDelay = 1000;
					}

					else if (iTimeBeforeRun > 300)
					{
						if (iRunDelay == 0)
						{
							iTimeBeforeRun = 0;
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

				if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '#')  // ���� ����������� �� ������, �� ���������� ���
				{
					fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
					fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
				}
			}

			if (GetAsyncKeyState((unsigned short)'S') & 0x8000)		// �������� "S" ��� �����
			{
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
				if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '#')  // ���� ����������� �� ������, �� ���������� ���
				{
					fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
					fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
				}
			}

			for (int16_t x = 0; x < iConsoleWidth; x++)
			{
				// ������� ���������� �� ������ � ����������� fRayAngle 
				float fRayAngle = (fPlayerA - fFoV / 2.0f) + ((float)x / (float)iConsoleWidth) * fFoV;	// ����������� ����
				float fDistanceToWall = 0.0f;															// ��������� �� �����
				bool bHitWall = false;																	// ��������� �� ��� ������
				bool bBoundary = false;																	// ��������� �� ��� ������� ����� �������
				bool bObiliskFound = false;

				float fEyeX = sinf(fRayAngle);													// ���������� ���������� �������
				float fEyeY = cosf(fRayAngle);

				while (!bHitWall && fDistanceToWall < fDepth)		// ���� �� �� ����������� �� ������ � ��������� �� ����� ������ ������������ ��������� ������
				{
					fDistanceToWall += 0.1f;

					int16_t nTestX = (int16_t)(fPlayerX + fEyeX * fDistanceToWall);								// ����� �� ������� ����
					int16_t nTestY = (int16_t)(fPlayerY + fEyeY * fDistanceToWall);								// � ������� ����� ���

					if (nTestX < 0 || nTestX >= iMapWidth || nTestY < 0 || nTestY >= iMapHeight)
					{																					// ���� �� ����� �� ����
						bHitWall = true;
						fDistanceToWall = fDepth;
					}

					else if (map[nTestY * iMapWidth + nTestX] == '*')
					{
						bHitWall = true;
						bObiliskFound = true;
						bBoundary = corners(fEyeX, fEyeY, nTestX, nTestY);
					}

					else if (map[nTestY * iMapWidth + nTestX] == '#')	// ���������, �� �������� �� ������ ���� ������
					{
						bHitWall = true;
						bBoundary = corners(fEyeX, fEyeY, nTestX, nTestY);
					}



					//��������� ��������� ������� � ����
					int16_t iCeiling = (float)(iConsoleHeight / 2.0) - iConsoleWidth / ((float)fDistanceToWall);
					int16_t iFloor = iConsoleHeight - iCeiling;

					short siShade;

					if (bObiliskFound == false)
					{
						if (fDistanceToWall <= fDepth / 4.0f)        siShade = 0x2588; // ���� ������ ������, �� ������ 
						else if (fDistanceToWall < fDepth / 3.0f)    siShade = 0x2593; // ������� �������
						else if (fDistanceToWall < fDepth / 2.0f)    siShade = 0x2592; // ��� ��������� �������� 
						else if (fDistanceToWall < fDepth)           siShade = 0x2591; // ������ ����� ������
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

			// ���� ����� � ��������� ���������
			if ((fPlayerXBuf != fPlayerX || fPlayerYBuf != fPlayerY) && iWalkDelay == 0)
			{
				fPlayerXBuf = fPlayerX;
				fPlayerYBuf = fPlayerY;
				s1->play();														// ����������� ���� �����
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

			////�������
			if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '@')
			{
				s6->play();
				s6->setVolume(0.6f);
			}

			// ������������ ������
			if (iSoundEffectDelay == 0)
			{
				int16_t q = rand() % 3;

				if (q == 0)
				{
					s2->play();														// ����������� �����
					s2->setVolume(0.4f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}

				else if (q == 1)
				{
					s3->play();														// ����������� �������� �����
					s3->setVolume(0.6f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}

				else if (q == 2)
				{
					s4->play();														// ����������� �����
					s4->setVolume(0.6f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}
			}

			iSoundEffectDelay--;

			// ����� ��������� � �������
			swprintf_s(console, 90, L"X=%3.2f, Y=%3.2f, A=%3.2f, Time: %3.3f, Find all obelisks [%d|5], Speed: %2.2f", fPlayerX,
				fPlayerY, fPlayerA, fStopwatch, iObiliscCounter, fSpeed);
		}

		// ����� �� �����
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
}

void authors()//������ ���
{
	// ��������� ���� ��� ����

	system("cls");
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// ��� ������ ����� ������� AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/egg.ogg", false); // ������� ����� ��� ������ �����
	sound->play();															// ����������� ��� ����
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	cout << "|--------------------------------------------------------------------|\n"
		"|   		                 AUTHORS                                      |\n"
		"|  		                      |\n"
		"|   		         https://github.com/VariableRiw/MyGame          |\n"
		"|   			   		     |\n"
		"|--------------------------------------------------------------------|\n";
	system("pause");

}