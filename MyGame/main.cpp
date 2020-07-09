#include <iostream>
#include <chrono>
#include <Windows.h>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <audiere.h>
#include <ctime>

using namespace std;

int16_t iConsoleWidth = 150;								// ������ �������
int16_t iConsoleHeight = 40;								// ������ �������
int16_t iMapWidth = 50;										// ������ �����
int16_t iMapHeight = 100;									// ������ �����

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;										// ����������� ������
float fSpeed = 4.0f;										// �������� ������������

float fFoV = 3.14159f / 4.0f;								// ���� ������
float fDepth = 75.0f;										// ������������ ��������� ������

int main()
{
	srand(time(NULL));
	system("mode con cols=150 lines=40");					// ��������� ������ ���� �� 150 �� 40

	// ������ ����� ������
	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;

	map += L"##################################################";
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

	// ��������� ���������� �����
	//int16_t iMaxShards = 

	// ������������� ������
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// ��� ������ ����� ������� AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "Apocryphos, Kammarheit, Atrium Carceri - Cavern of Igneous Flame.mp3", true); // ������� ����� ��� ������ �����
	sound->play();															// ����������� ��� ����
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	// ��������� ���� �� ������ �����
	audiere::AudioDevicePtr d1 = audiere::OpenDevice();
	audiere::OutputStreamPtr s1 = OpenSound(d1, "stone_walk3.ogg", false);		// ������� ����� ��� ������ �����
	int16_t iWalkDelay = 0;

	// ��������� ���� � �������
	audiere::AudioDevicePtr d2 = audiere::OpenDevice();
	audiere::OutputStreamPtr s2 = OpenSound(d2, "whisper.ogg", false);			// ������� ����� ��� ������ �����

	// ��������� ���� � ��������� ������� :D
	audiere::AudioDevicePtr d3 = audiere::OpenDevice();
	audiere::OutputStreamPtr s3 = OpenSound(d3, "ominous-sounds.ogg", false);	// ������� ����� ��� ������ �����

	// ��������� ���� � �������
	audiere::AudioDevicePtr d4 = audiere::OpenDevice();
	audiere::OutputStreamPtr s4 = OpenSound(d4, "voice.ogg", false);			// ������� ����� ��� ������ �����

	int32_t iSoundEffectDelay = 100;

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
			fPlayerA -= (fSpeed * 0.5f) * fElapsedTime;

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)		// �������� "D" ������������ ������ ������� �������
			fPlayerA += (fSpeed * 0.5f) * fElapsedTime;

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
			fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
			if (map[(int)fPlayerY * iMapWidth + (int)fPlayerX] == '#') { // ���� ����������� �� ������, �� ���������� ���
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
					//--
					vector <pair <float, float>> p;

					for (int tx = 0; tx < 2; tx++)
						for (int ty = 0; ty < 2; ty++)						// �������� �� ���� 4� �����
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
					//--
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

				if (bBoundary)		siShade = 0x2551; // 2502

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

		//for (int16_t nx = 0; nx < iMapWidth; nx++)
		//	for (int16_t ny = 0; ny < iMapHeight; ny++)
		//	{
		//		console[(ny + 1) * iConsoleWidth + nx] = map[ny * iMapWidth + nx];
		//	}
		//console[((int)fPlayerX + 1) * iConsoleWidth + (int)fPlayerY] = 'U';

		// ����� �� �����
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
	
	return 0;
}