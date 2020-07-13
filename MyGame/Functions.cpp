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

	//�����
	int16_t White = 0x2588;
	int16_t Grey = 0x2591;
	int16_t Dark_Grey = 0x2592;
	int16_t Question = 0x00BF;
	int16_t Face = 0x2261;

	int16_t color = 0;

	x1A = 44;	// ���������� ������� ����� ����� ������ ������������
	y1A = 10;

	x2A = 88;	// ����������� ��� ������ ������������
	y2A = 20;

	y1C = 20;	// ���������� ������ ����� ����� ������� ������������
	x1B = 70;

	y2C = 21;	// ����������� ��� ������� ������������
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

				if (x >= x1A && y >= y1A)								// ������ ����� �����������
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
						if (y >= 25 && y <= 30 && x >= 56 && x <= 96)	// ������ ������������� (� ����� ������������)
							console[y * iConsoleWidth + x] = color;
						else
							console[y * iConsoleWidth + x] = Face;
					}
				}

				else if (x >= x2A && y <= y2A)							// ������ ������ �����������
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

				else if (y >= 25 && y <= 30 && x >= 56 && x <= 96)		// ������ �������������
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
	map += L"#................................................................................................!?#";
	map += L"#.............?...............................................?....................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#..................................................................................................#";
	map += L"#.@@@@@@@@@@.............*******...................................................................#";
	map += L"#.@@@@@@@@@@.............*******...................................................................#";
	map += L"#.@@@@@@@@@@.............*******...................................................................#";
	map += L"#.@@@@@@@@@@.............*******...................................................................#";
	map += L"#.@@@@@@@@@@.......................................................................................#";
	map += L"#.@@@@@@@@@@.......................................................................................#";
	map += L"#.@@@@@@@@@@.......................................................................................#";
	map += L"#.@@@@@@@@@@.......................................................................................#";
	map += L"#.@@@@@@@@@@.......................................................................................#";
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
	map += L"#!...............?...........................?....................................................?#";
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

void open_map(wchar_t* console, wstring map)
{
	int16_t temp = 0;
	int16_t nx, nx1, ny, ny1;
	int16_t check = 0;
	int16_t EndX, EndY;
	EndX = iConsoleWidth - iConsoleWidth / 5;
	EndY = iConsoleHeight - iConsoleHeight / 6;

	for (nx = (int16_t)fPlayerX + iConsoleWidth / 5, nx1 = (int16_t)fPlayerX + iConsoleWidth / 5; nx1 < (int16_t)fPlayerX + EndX - 1; nx1++, nx++)
		for (ny = (int16_t)fPlayerY, ny1 = (int16_t)fPlayerY + EndY; ny1 > (int16_t)fPlayerY + 2; ny1--, ny++)
		{
			temp = (ny1 - (iConsoleHeight / 2 - 3)) * iMapWidth + nx1 - iConsoleWidth / 2 + 1;

			if (nx1 - (iConsoleWidth / 2 - 2) > iMapWidth)
			{
				console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';
				continue;
			}

			if (temp <= iMapHeight * iMapWidth && temp >= 0 && nx1 > (iConsoleWidth / 2 - 2))
			{
				if (map[temp] == '@' || map[temp] == '!') // ���� ��������� �� �������, 
					console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = '.';	// ������� �� ����� ���������� �� �����
				else
					console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = map[temp];
			}

			else
			{
				console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';
			}
		}

	// ������� �����
	int16_t iMapCorner1 = 0x2551;
	int16_t iMapCorner2 = 0x2550;
	for (nx = (iConsoleWidth / 5); nx < EndX; nx++)
	{
		for (ny = 1; ny < EndY; ny++)
		{
			if (nx == (iConsoleWidth / 5))							// ����� ������������ �������
				console[ny * iConsoleWidth + nx] = iMapCorner1;
			else if (ny == 1 && nx > (iConsoleWidth / 5))			// ������� �������������� �������
				console[ny * iConsoleWidth + nx] = iMapCorner2;
			else if (ny == EndY - 1 && nx > (iConsoleWidth / 5))	// ������ �������������� �������
				console[ny * iConsoleWidth + nx] = iMapCorner2;
			else if (nx == EndX - 1)								// ������ ������������ �������
				console[ny * iConsoleWidth + nx] = iMapCorner1;

			if (nx == (iConsoleWidth / 5) && ny == 1)
				console[ny * iConsoleWidth + nx] = 0x2554;			// ����� ������ ����
			else if (nx == EndX - 1 && ny == 1)
				console[ny * iConsoleWidth + nx] = 0x2557;			// ������ ������ ����
			else if (nx == (iConsoleWidth / 5) && ny == EndY - 1)
				console[ny * iConsoleWidth + nx] = 0x255A;			// ����� ������ ����
			else if (nx == EndX - 1 && ny == EndY - 1)
				console[ny * iConsoleWidth + nx] = 0x255D;			// ������ ������ ����
		}
	}
	console[(iConsoleHeight / 2 - 1) * iConsoleWidth + iConsoleWidth / 2] = 'A';
}

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter)
{
	char startTime[80];
	time_t seconds = time(NULL);
	strftime(startTime, 80, "%A %d %B %Y %H:%M:%S", localtime(&seconds));
	wofstream file;
	file.open(L"save.txt", ios_base::app); // ������ � ����� �����
	file << startTime << " " << (int16_t)fPlayerX << " " << (int16_t)fPlayerY << " " << (int16_t)fPlayerA
		<< " " << Time << " " << iObiliscCounter << endl;
	file.close();

}

void continue_game(audiere::OutputStreamPtr sound)  // �������� ����������, �� �� ������� �������� � game() ����������, ���� ������������ ���� ����...
{
	wifstream file(L"save.txt");
	wstring line;
	bool exit = 0;
	int16_t iObiliscCounter, Time, menu, whil = 0;

	iObiliscCounter = Time = 0;

	if (file.is_open())
	{
		wcout << L"\n��� ����������: ";

		while (!exit)
		{
			while (getline(file, line))
			{
				wcout << L"\n���������� [" << ++whil << "] " << line;
			}

			file.close();
			file.open(L"save.txt");

			wcout << L"\n\n�������� ������ ���������� >> ";
			try
			{
				wcin >> menu;
				wcin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw L"���������� ���� ���������� �� ����������!";
				}
			}
			catch (const char* exc)
			{
				wcout << exc << endl;
				wcin.clear();
				wcin.ignore(32767, '\n');
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
				wcout << L"\n���������� ��� ���!\n";
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

	wstring map;									// �����

	bool bZFlag = false;							// ���� ����, ��� ������ ������
	bool bMinimap = true;							// ��������� ���
	bool bMapIsOpen = false;						// ������� �������� �����

	float fStopwatch = Time;						// ������
	float fSpeedBoost = 4.0f;						// ��� �������� ��� ����

	int16_t iScreamDelay = 0;						// �������� ��� ��������������� ��������
	int16_t iRunTime = 0;							// ����� ����
	int16_t iRunDelay = 0;							// �������� ��� ������������� ������������
	int16_t iMinimapDelay = 50;						// �������� ��� ���� � ��� ���������
	int16_t iMessageDelay = 0;						// ������� ��� ������ ���� ���������
	int16_t iObiliscCounter = iObiliscSave;			// ���������� ���������
	int16_t iSaveDelay = 0;							// �������� ��� ����������
	int32_t iWalkDelay = 0;							// �������� ��� ������

	map_pulling(map);

	// ������������� ������
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// ��� ������ ����� ������� AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/apocryphos.mp3", true); // ������� ����� ��� ������ �����
	sound->play();															// ����������� ��� ����
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	// ��������� ���� �� ������ �����
	audiere::AudioDevicePtr d1 = audiere::OpenDevice();
	audiere::OutputStreamPtr s1 = OpenSound(d1, "sounds/walk.ogg", false);		// ������� ����� ��� ������ �����

	// ��������� ���� � �������
	audiere::AudioDevicePtr d2 = audiere::OpenDevice();
	audiere::OutputStreamPtr s2 = OpenSound(d2, "sounds/whisper.ogg", false);			// ������� ����� ��� ������ �����

	// ��������� ���� � ��������� ������� :D
	audiere::AudioDevicePtr d3 = audiere::OpenDevice();
	audiere::OutputStreamPtr s3 = OpenSound(d3, "sounds/ominous.ogg", false);	// ������� ����� ��� ������ �����

	// ��������� ���� � �������
	audiere::AudioDevicePtr d4 = audiere::OpenDevice();
	audiere::OutputStreamPtr s4 = OpenSound(d4, "sounds/voice.ogg", false);			// ������� ����� ��� ������ �����

	// ��������� ���� �� ������
	audiere::AudioDevicePtr d5 = audiere::OpenDevice();
	audiere::OutputStreamPtr s5 = OpenSound(d5, "sounds/smeh.ogg", false);			// ������� ����� ��� ������ �����

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
			game_over(console, 0x256C);
		}

		else if (GetAsyncKeyState((unsigned short)'X') & 0x8000 || bMapIsOpen == true)		// �������� "X" ���������� �����
		{
			if (!bMapIsOpen)
			{
				open_map(console, map);
				bMapIsOpen = true;
			}

			else
			{
				if (!((GetAsyncKeyState((unsigned short)'W')) || (GetAsyncKeyState((unsigned short)'S')) || (GetAsyncKeyState((unsigned short)'A'))
					|| (GetAsyncKeyState((unsigned short)'D')) & 0x8000))
						bMapIsOpen = false;
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

			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
				iScreamDelay = 100;

			iScreamDelay++;
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '?' && iMessageDelay == 0)    // ������ ���������
		{
			wchar_t a[5] = { L'�', L'�', L'�', L'�', '!' };
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

			if (GetAsyncKeyState(VK_TAB) & 0x8000)		// �������� "TAB" ���/���� ���������
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

			if (GetAsyncKeyState((unsigned short)'U') & 0x8000)		// �������� "U" ��������� ���������� � ����� ����
			{
				if (iSaveDelay == 0 || iSaveDelay + 5 <= (int16_t)fStopwatch)
				{
					save(fPlayerX, fPlayerY, (int16_t)fStopwatch, iObiliscCounter);
					iSaveDelay = (int16_t)fStopwatch;
				}
			}

			if (GetAsyncKeyState((unsigned short)'A') & 0x8000)		// �������� "A" ������������ �� ������� �������
				fPlayerA -= (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// �������� "D" ������������ ������ ������� �������
				fPlayerA += (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'W') & 0x8000)		// �������� "W" ��� �����
			{
				if (GetAsyncKeyState((unsigned short)'Z') & 0x8000)
				{
					if (iRunTime == 0 && iRunDelay == 0)
						bZFlag = true;
				}

				if (bZFlag)
				{
					if (iRunTime == 0 && iRunDelay == 0)
					{
						fSpeed += fSpeedBoost;

					}

					iRunTime++;

					if (iRunTime == 1000)
					{
						fSpeed -= fSpeedBoost;
						iRunDelay = 3000;
					}

					else if (iRunTime > 1000)
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
				iWalkDelay = clock() / 100;
			}

			else if (fPlayerXBuf == fPlayerX && fPlayerYBuf == fPlayerY)
			{
				iWalkDelay = 0;
			}

			else if ((int16_t)fSpeed == SPEED)
			{
				if (iWalkDelay + 5 <= (int32_t)clock() / 100)
					iWalkDelay = 0;
			}

			else if ((int16_t)fSpeed == SPEED + (int16_t)fSpeedBoost)
			{
				if (iWalkDelay + 1 <= (int32_t)clock() / 100)
					iWalkDelay = 0;
			}

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

			if (iMinimapDelay < 50)											// �������� ��� ���/���� ���������
			{
				iMinimapDelay++;
			}

			if (bMinimap)
			{
				// ���������
				int16_t nx, nx1, ny, ny1;


				// ��� 0 (x0,yn)
				for (nx = (int16_t)fPlayerX, nx1 = (int16_t)fPlayerX; nx1 < (int16_t)fPlayerX + 26; nx1++, nx++)
					for (ny = (int16_t)fPlayerY, ny1 = (int16_t)fPlayerY + 13; ny1 > (int16_t)fPlayerY; ny1--, ny++)
					{
						if (nx1 - 12 > iMapWidth)
						{
							console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';
							continue;
						}

						if(((ny1 - 8) * iMapWidth + nx1 - 13) <= iMapHeight * iMapWidth && ((ny1 - 8) * iMapWidth + nx1 - 13) >= 0 && nx1 > 12)
						{
							if (map[(ny1 - 8) * iMapWidth + nx1 - 13] == '@' || map[(ny1 - 8) * iMapWidth + nx1 - 13] == '!') // ���� ��������� �� �������, 
								console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = '.';	// ������� �� ����� ���������� �� �����
							else
								console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = map[(ny1 - 8) * iMapWidth + nx1 - 13];
						}

						else
						{
							console[(ny + 2 - (int16_t)fPlayerY) * iConsoleWidth + nx - (int16_t)fPlayerX + 1] = ' ';
						}
					}
				console[7 * iConsoleWidth + 14] = 'A';

				// ������� ���������
				int16_t iMapCorner1 = 0x2551;
				int16_t iMapCorner2 = 0x2550;
				for (nx = 0; nx < 28; nx++)
				{
					for (ny = 1; ny < 16; ny++)
					{
						if (nx == 0)											// ����� ������������ �������
							console[ny * iConsoleWidth] = iMapCorner1;
						else if (ny == 1)										// ������� �������������� �������
							console[ny * iConsoleWidth + nx] = iMapCorner2;
						else if (ny == 15)										// ������ �������������� �������
							console[ny * iConsoleWidth + nx] = iMapCorner2;
						else if (nx == 27)										// ������ ������������ �������
							console[ny * iConsoleWidth + nx] = iMapCorner1;

						if (nx == 0 && ny == 1)
							console[ny * iConsoleWidth] = 0x2554;				// ����� ������ ����
						else if (nx == 27 && ny == 1)
							console[ny * iConsoleWidth + nx] = 0x2557;			// ������ ������ ����
						else if (nx == 0 && ny == 15)
							console[ny * iConsoleWidth] = 0x255A;				// ����� ������ ����
						else if (nx == 27 && ny == 15)
							console[ny * iConsoleWidth + nx] = 0x255D;			// ������ ������ ����
					}
				}
			}
			// ����� ��������� � �������
			swprintf_s(console, 90, L"X=%3.2f, Y=%3.2f, A=%3.2f, �����: %3.3f, ������� ���������[%d|5], ��������: %2.2f", fPlayerX,
				fPlayerY, fPlayerA, fStopwatch, iObiliscCounter, fSpeed);
		}

		// ����� �� �����
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
}

void authors()
{
	system("cls");
	wcout <<
		L"|--------------------------------------------------------------------|\n"
		"|                          ������������                              |\n"
		"|               laynholt                  marco_dragan               |\n"
		"|                                                                    |\n"
		"|                   ��������� ������������� Javidx9                  |\n"
		"|               https://github.com/VariableRiw/MyGame                |\n"
		"|                                                                    |\n"
		"|--------------------------------------------------------------------|\n";

}

void control()
{
	system("cls");

	wcout <<
		L"|---------------------------------------------------------------------|\n"
		"|                            W - ���� �����                          |\n"
		"|                            S - ���� �����                           |\n"
		"|                            Z - ������                               |\n"
		"|                            A - ����������� �����                    |\n"
		"|                            D - ����������� ������                   |\n"
		"|                            U - ��������� ����                       |\n"
		"|                           TAB - ���./����. ���������                |\n"
		"|                            X - �������� �����                       |\n"
		"|---------------------------------------------------------------------|\n";
}