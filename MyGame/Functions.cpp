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
		for (int16_t y = 0; y < iConsoleHeight; y++) //куку
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

	//Öâåòà
	int16_t White = 0x2588;
	int16_t Grey = 0x2591;
	int16_t Dark_Grey = 0x2592;
	int16_t Question = 0x00BF;
	int16_t Face = 0x2261;

	int16_t color = 0;

	x1A = 44;	// Êîîðäèíàòû âåðõíåé ëåâîé òî÷êè ëåâîãî òðåóãîëüíèêà
	y1A = 10;

	x2A = 88;	// Îãðàíè÷åíèÿ äëÿ ëåâîãî òðåóãîëüíèêà
	y2A = 20;

	y1C = 20;	// Êîîðäèíàòû íèæíåé ëåâîé òî÷êè ïðàâîãî òðåóãîëüíèêà
	x1B = 70;

	y2C = 21;	// Îãðàíè÷åíèÿ äëÿ ïðàâîãî òðåóãîëüíèêà
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

				if (x >= x1A && y >= y1A)								// Ðèñóåì ëåâûé òðåóãîëüíèê
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
						if (y >= 25 && y <= 30 && x >= 56 && x <= 96)	// Ðèñóåì ïðÿìîóãîëüíèê (â ÷àñòè òðåóãîëüíèêà)
							console[y * iConsoleWidth + x] = color;
						else
							console[y * iConsoleWidth + x] = Face;
					}
				}

				else if (x >= x2A && y <= y2A)							// Ðèñóåì ïðàâûé òðåóãîëüíèê
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

				else if (y >= 25 && y <= 30 && x >= 56 && x<= 96)		// Ðèñóåì ïðÿìîóãîëüíèê
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
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)							// Äëÿ ñêèïà ñîîáùåíèÿ íàæìèòå Enter
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
		for (int8_t ty = 0; ty < 2; ty++)						// Ïðîõîäèì ïî âñåì 4ì ð¸áðàì
		{
			float vx = (float)nTestX + tx - fPlayerX;			// Êîîðäèíàòû âåêòîðà,
			float vy = (float)nTestY + ty - fPlayerY;			// âåäóùåãî èç íàáëþäàòåëÿ â ðåáðî
			float d = sqrt(vx * vx + vy * vy);					// Ìîäóëü ýòîãî âåêòîðà
			float dot = (fEyeX * vx / d) + (fEyeY * vy / d);	// Ñêàëÿðíîå ïðîèçâåäåíèå (åäèíè÷íûõ âåêòîðîâ)
			p.push_back(make_pair(d, dot));						// Ñîõðàíÿåì ðåçóëüòàò â ìàññèâ
		}
	// Ìû áóäåì âûâîäèòü äâà áëèæàéøèõ ðåáðà, ïîýòîìó ñîðòèðóåì èõ ïî ìîäóëþ âåêòîðà ðåáðà
	sort(p.begin(), p.end(), [](const pair <float, float>& left, const pair <float, float>& right) {return left.first < right.first; });

	float fBound = 0.005;							// Óãîë, ïðè êîòîðîì íà÷èíàåì ðàçëè÷àòü ðåáðî.
	if (acos(p.at(0).second) < fBound) bBoundary = true;
	if (acos(p.at(1).second) < fBound) bBoundary = true;

	return bBoundary;
}

void open_map(wchar_t* console, wstring map)
{
	int16_t nx, nx1, ny, ny1;
	int16_t check = 0;
	int16_t EndX, EndY;
	EndX = iConsoleWidth - iConsoleWidth / 5;
	EndY = iConsoleHeight - iConsoleHeight / 6;

	for (nx = 0; nx < EndX; nx++)
	{
		for (ny=0; ny< EndY; ny++)
		{
			check = ((int16_t)fPlayerY - EndY / 2 + ny) * iMapWidth + (int16_t)fPlayerX - EndX / 2 + nx;

			if (check > 0)
			{
				//console[(ny + iConsoleWidth / 2) * iConsoleWidth + nx + iConsoleWidth / 2] = check;
			}

			else
			{
				//console[(ny + iConsoleWidth / 2) * iConsoleWidth + nx + iConsoleWidth / 2] = ' ';
			}
		}
	}
	console[iConsoleHeight/2 * iConsoleWidth + iConsoleWidth/2] = 'U';
}

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter)
{
	char startTime[80];
	time_t seconds = time(NULL);
	strftime(startTime, 80, "%A %d %B %Y %H:%M:%S", localtime(&seconds));
	wofstream file;
	file.open(L"save.txt", ios_base::app); // çàïèñü â êîíåö ôàéëà
	file << startTime << " " << (int16_t)fPlayerX << " " << (int16_t)fPlayerY << " " << (int16_t)fPlayerA
		<< " " << Time << " " << iObiliscCounter << endl;
	file.close();

}

void continue_game(audiere::OutputStreamPtr sound)  // îòêðûòèå ñîõðàíåíèé, íî íå âûõîäèò ïåðåäàòü â game() ïàðàìåíòðû, ÷òîá òåëåïîðòíóëî êóäà íàäî...
{
	wifstream file(L"save.txt");
	wstring line;
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
				wcout << L"\nSave [" << ++whil << "] " << line;
			}

			file.close();
			file.open(L"save.txt");

			wcout << L"\nChoose an action >> ";
			try
			{
				wcin >> menu;
				wcin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw L"The character entered is not a number!";
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
				wcout << L"\nChoose again!\n";
				//system("cls");
			}
		}
	}

	file.close();
	sound->stop();
	game(fPlayerX, fPlayerY, fPlayerA, Time, iObiliscCounter);
}

void game(float fX, float fY, float fA, int16_t Time, int16_t iObiliscSave)//ñàìà èãðà
{

	// Ñîçäà¸ì áóôåð ýêðàíà
	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;									// Êàðòà
	float fStopwatch = Time;						// Òàéìåð
	int16_t iScreamDelay = 0;						// Çàäåðæêà äëÿ âîñïðîèçâåäåíèÿ ñêðèìåðà
	int16_t iRunDelay = 0;							// Çàäåðæêà äëÿ âîñòàíîâëåíèÿ âûíîñëèâîñòè
	bool bZFlag = false;							// Ôëàã òîãî, ÷òî êíîïêó íàæàëè
	bool bMinimap = true;							// Ìèíèêàðòà âêë
	int16_t iMinimapDelay = 50;						// Çàäåðæêà ïðè îòêë è âêë ìèíèêàðòû
	float fSpeedBoost = 4.0f;						// Äîï ñêîðîñòü ïðè áåãå
	int16_t iRunTime = 0;							// Âðåìÿ áåãà
	int16_t iMessageDelay = 0;						// Çàäåðêà äëÿ âûâîäà ñëåä ñîîáùåíèÿ
	int16_t iObiliscCounter = iObiliscSave;			// Êîëè÷åñòâî îáåëèñêîâ
	int16_t iSaveDelay = 0;							// çàäåðæêà äëÿ ñîõðàíåíèÿ
	/*int16_t YOU = 'U';*/

	map_pulling(map);

	// Âîñïðîèçâîäèì ìóçûêó
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// Äëÿ íà÷àëà íóæíî îòêðûòü AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/Apocryphos, Kammarheit, Atrium Carceri - Cavern of Igneous Flame.mp3", true); // Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà
	sound->play();															// Ïðîèãðûâàåì íàø çâóê
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	// Îòêðûâàåì ôàéë ñî çâóêîì øàãîâ
	audiere::AudioDevicePtr d1 = audiere::OpenDevice();
	audiere::OutputStreamPtr s1 = OpenSound(d1, "sounds/stone_walk3.ogg", false);		// Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà
	int16_t iWalkDelay = 0;

	// Îòêðûâàåì ôàéë ñ øåïîòîì
	audiere::AudioDevicePtr d2 = audiere::OpenDevice();
	audiere::OutputStreamPtr s2 = OpenSound(d2, "sounds/whisper.ogg", false);			// Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà

	// Îòêðûâàåì ôàéë ñ çëîâåùèìè çâóêàìè :D
	audiere::AudioDevicePtr d3 = audiere::OpenDevice();
	audiere::OutputStreamPtr s3 = OpenSound(d3, "sounds/ominous-sounds.ogg", false);	// Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà

	// Îòêðûâàåì ôàéë ñ ãîëîñîì
	audiere::AudioDevicePtr d4 = audiere::OpenDevice();
	audiere::OutputStreamPtr s4 = OpenSound(d4, "sounds/voice.ogg", false);			// Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà

	// Îòêðûâàåì ôàéë ñî ñìåõîì
	audiere::AudioDevicePtr d5 = audiere::OpenDevice();
	audiere::OutputStreamPtr s5 = OpenSound(d5, "sounds/strashnye-zvuki-dyavolskiy-smeh.ogg", false);			// Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà

	// Îòêðûâàåì ôàéë ñî çâóêîì ïîðòàëà
	audiere::AudioDevicePtr d6 = audiere::OpenDevice();
	audiere::OutputStreamPtr s6 = OpenSound(d6, "sounds/portal.ogg", true);			// Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà

	// Îòêðûâàåì ôàéë ñî çâóêîì çàêðûòèÿ ïîðòàëà
	audiere::AudioDevicePtr d7 = audiere::OpenDevice();
	audiere::OutputStreamPtr s7 = OpenSound(d7, "sounds/exit_from_portal.ogg", false);			// Ñîçäàåì ïîòîê äëÿ íàøåãî çâóêà

	int32_t iSoundEffectDelay = 100;

	auto aTimePoint1 = chrono::system_clock::now();
	auto aTimePoint2 = chrono::system_clock::now();

	// Èãðîâîé öèêë
	while (true)
	{
		if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '%' || iObiliscCounter == 5)    // Ñèìâîë êîíöà èãðû
		{
			if (game_over(console, 0x256C))
			{
				//delete[] console;
				//return;
			}
		}

		else if (GetAsyncKeyState((unsigned short)'X') & 0x8000)		// Êëàâèøåé "U" ñîõðàíÿåì êîîðäèíàòû è âðåìÿ èãðû
		{
			open_map(console, map);
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '!' && iScreamDelay <= 25)    // Ñèìâîë ñêðèìåðà
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

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '?' && iMessageDelay == 0)    // Ñèìâîë ñîîáùåíèÿ
		{
			wchar_t a[5] = { L'Á', L'Å', L'Ã', L'È', '!' };
			letter(console, a, 5);
			_getch();

			if (GetAsyncKeyState(VK_RETURN) & 0x8000)							// Äëÿ ñêèïà ñîîáùåíèÿ íàæìèòå Enter
				iMessageDelay++;
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '*')	// Îáåëèñê
		{
			s7->play();															// Ïðîèãðûâàåòñÿ ìóçûêà èñ÷åçíîâåíèÿ
			s7->setVolume(0.6f);
			iObiliscCounter++;
			map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] = '.';		// Èñ÷åçàåò îáåëèñê

			int16_t del = 0;

			for (int16_t i = 0; i < 7; i++)										// Óäàëåíèÿ çâóêîâ îáåëèñêà
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
			/*fPlayerX = 5.0f;													// Òåëåïîðò èãðîêà
			fPlayerY = 80.0f;*/
		}

		else
		{
			fStopwatch = clock() / 1000.0f;
			iScreamDelay = 0;

			if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] != '?')	// Äëÿ ïîâòîðîãî ïîäáîðà ñîîáùåíèÿ
			{
				iMessageDelay = 0;
			}

			aTimePoint2 = chrono::system_clock::now();
			chrono::duration<float> elapsedTime = aTimePoint2 - aTimePoint1;
			aTimePoint1 = aTimePoint2;
			float fElapsedTime = elapsedTime.count();

			if (GetAsyncKeyState(VK_TAB) & 0x8000)		// Êëàâèøåé "TAB" âêë/âûêë ìèíèêàðòó
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

			if (GetAsyncKeyState((unsigned short)'U') & 0x8000)		// Êëàâèøåé "U" ñîõðàíÿåì êîîðäèíàòû è âðåìÿ èãðû
			{
				if (iSaveDelay == 0 || iSaveDelay + 5 <= (int16_t)fStopwatch)
				{
					save(fPlayerX, fPlayerY, (int16_t)fStopwatch, iObiliscCounter);
					iSaveDelay = (int16_t)fStopwatch;
				}
			}

			if (GetAsyncKeyState((unsigned short)'A') & 0x8000)		// Êëàâèøåé "A" ïîâîðà÷èâàåì ïî ÷àñîâîé ñòðåëêå
				fPlayerA -= (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// Êëàâèøåé "D" ïîâîðà÷èâàåì ïðîòèâ ÷àñîâîé ñòðåëêè
				fPlayerA += (fSpeedCamera * 0.5f) * fElapsedTime;

			if (GetAsyncKeyState((unsigned short)'W') & 0x8000)		// Êëàâèøåé "W" èä¸ì âïåð¸ä
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

				if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '#')  // Åñëè ñòîëêíóëèñü ñî ñòåíîé, òî îòêàòûâàåì øàã
				{
					fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
					fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
				}
			}

			if (GetAsyncKeyState((unsigned short)'S') & 0x8000)		// Êëàâèøåé "S" èä¸ì íàçàä
			{
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
				if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '#')  // Åñëè ñòîëêíóëèñü ñî ñòåíîé, íî îòêàòûâàåì øàã
				{
					fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
					fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
				}
			}

			for (int16_t x = 0; x < iConsoleWidth; x++)
			{
				// Íàõîäèì ðàññòîÿíèå äî ñòåíêè â íàïðàâëåíèè fRayAngle 
				float fRayAngle = (fPlayerA - fFoV / 2.0f) + ((float)x / (float)iConsoleWidth) * fFoV;	// Íàïðàâëåíèå ëó÷à
				float fDistanceToWall = 0.0f;															// Äèñòàíöèÿ äî ñòåíû
				bool bHitWall = false;																	// Äîñòèãíóë ëè ëó÷ ñòåíêó
				bool bBoundary = false;																	// Äîñòèãíóë ëè ëó÷ ãðàíèöó ìåæäó ñòåíàìè
				bool bObiliskFound = false;

				float fEyeX = sinf(fRayAngle);													// Êîîðäèíàòû åäèíè÷íîãî âåêòîðà
				float fEyeY = cosf(fRayAngle);

				while (!bHitWall && fDistanceToWall < fDepth)		// Ïîêà ìû íå ñòîëêíóëèñü ñî ñòåíîé è äèñòàíöèÿ äî ñòåíû ìåíüøå ìàêñèìàëüíàÿ äèñòàíöèÿ îáçîðà
				{
					fDistanceToWall += 0.1f;

					int16_t nTestX = (int16_t)(fPlayerX + fEyeX * fDistanceToWall);								// Òî÷êà íà èãðîâîì ïîëå
					int16_t nTestY = (int16_t)(fPlayerY + fEyeY * fDistanceToWall);								// â êîòîðóþ ïîïàë ëó÷

					if (nTestX < 0 || nTestX >= iMapWidth || nTestY < 0 || nTestY >= iMapHeight)
					{																					// Åñëè ìû âûøëè çà çîíó
						bHitWall = true;
						fDistanceToWall = fDepth;
					}

					else if (map[nTestY * iMapWidth + nTestX] == '*')
					{
						bHitWall = true;
						bObiliskFound = true;
						bBoundary = corners(fEyeX, fEyeY, nTestX, nTestY);
					}

					else if (map[nTestY * iMapWidth + nTestX] == '#')	// Ïðîâåðÿåì, íå ÿâëÿåòñÿ ëè ÿ÷åéêà ëó÷à ñòåíîé
					{
						bHitWall = true;
						bBoundary = corners(fEyeX, fEyeY, nTestX, nTestY);
					}



					//Âû÷èñëÿåì äèñòàíöèþ ïîòîëêà è ïîëà
					int16_t iCeiling = (float)(iConsoleHeight / 2.0) - iConsoleWidth / ((float)fDistanceToWall);
					int16_t iFloor = iConsoleHeight - iCeiling;

					short siShade;

					if (bObiliskFound == false)
					{
						if (fDistanceToWall <= fDepth / 4.0f)        siShade = 0x2588; // Åñëè ñòåíêà áëèçêî, òî ðèñóåì 
						else if (fDistanceToWall < fDepth / 3.0f)    siShade = 0x2593; // ñâåòëóþ ïîëîñêó
						else if (fDistanceToWall < fDepth / 2.0f)    siShade = 0x2592; // Äëÿ îòäàë¸ííûõ ó÷àñòêîâ 
						else if (fDistanceToWall < fDepth)           siShade = 0x2591; // ðèñóåì áîëåå òåìíóþ
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
							// Òî æå ñàìîå ñ ïîëîì - áîëåå áëèçêèå ÷àñòè ðèñóåì áîëåå çàìåòíûìè ñèìâîëàìè
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

			// Çâóê øàãîâ ñ íåáîëüøîé çàäåðæêîé
			if ((fPlayerXBuf != fPlayerX || fPlayerYBuf != fPlayerY) && iWalkDelay == 0)
			{
				fPlayerXBuf = fPlayerX;
				fPlayerYBuf = fPlayerY;
				s1->play();														// Ïðîèãðûâàåì çâóê øàãîâ
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

			////Îáåëèñê
			if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '@')
			{
				s6->play();
				s6->setVolume(0.6f);
			}

			// Ïðîèãðûâàíèå çâóêîâ
			if (iSoundEffectDelay == 0)
			{
				int16_t q = rand() % 3;

				if (q == 0)
				{
					s2->play();														// Ïðîèãðûâàåì øåïîò
					s2->setVolume(0.4f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}

				else if (q == 1)
				{
					s3->play();														// Ïðîèãðûâàåì çëîâåùèå çâóêè
					s3->setVolume(0.6f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}

				else if (q == 2)
				{
					s4->play();														// Ïðîèãðûâàåì ãîëîñ
					s4->setVolume(0.6f);
					iSoundEffectDelay = 5000 + rand() % 1000;
				}
			}

			iSoundEffectDelay--;

			if (iMinimapDelay < 50)											// Çàäåðæêà äëÿ âêë/âûêë ìèíèêàðòû
			{
				iMinimapDelay++;
			}

			if (bMinimap)
			{
				// Ìèíèêàðòà
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

				// Îáâîäêà ìèíèêàðòû
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
			// Âûâîä êîîðäèíàò è òàéìåðà
			swprintf_s(console, 90, L"X=%3.2f, Y=%3.2f, A=%3.2f, Time: %3.3f, Find all obelisks [%d|5], Speed: %2.2f", fPlayerX,
				fPlayerY, fPlayerA, fStopwatch, iObiliscCounter, fSpeed);
		}

		// Âûâîä íà ýêðàí
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
}

void authors()
{
	system("cls");
	wcout <<
		L"|--------------------------------------------------------------------|\n"
		"|                          Ðàçðàáîò÷èêè                              |\n"
		"|               laynholt                  marco_dragan               |\n"
		"|               https://github.com/VariableRiw/MyGame                |\n"
		"|                                                                    |\n"
		"|--------------------------------------------------------------------|\n";

}

void control() 
{
	system("cls");

	wcout <<
		L"|---------------------------------------------------------------------|\n"
		"|                            W - Èäòè âïåð¸ä                          |\n"
		"|                            S - Èäòè íàçàä                           |\n"
		"|                            Z - Áåæàòü                               |\n"
		"|                            A - Ïîâåðíóòüñÿ âëåâî                    |\n"
		"|                            D - Ïîâåðíóòüñÿ âïðàâî                   |\n"
		"|                            U - Ñîõðàíèòü èãðó                       |\n"
		"|                           TAB - Âêë./Âûêë. ìèíèêàðòó                |\n"
		"|                            X - Ïîêàçàòü êàðòó                       |\n"
		"|---------------------------------------------------------------------|\n";
}
