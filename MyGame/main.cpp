#include "LibFunVar.h"

int16_t iConsoleWidth = 150;							// ������ �������
int16_t iConsoleHeight = 40;							// ������ �������
int16_t iMapWidth = 50;									// ������ �����
int16_t iMapHeight = 100;								// ������ �����

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;									// ����������� ������
float fSpeed = 4.0f;									// �������� ������������

float fFoV = 3.14159f / 4.0f;							// ���� ������
float fDepth = 75.0f;

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
	float iStopwatch = 0;
	int16_t iScreanDelay = 0;
	int16_t iObiliscCounter = 0;

	map_pulling(map);

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

	// ��������� ���� �� ������
	audiere::AudioDevicePtr d5 = audiere::OpenDevice();
	audiere::OutputStreamPtr s5 = OpenSound(d5, "strashnye-zvuki-dyavolskiy-smeh.ogg", false);			// ������� ����� ��� ������ �����

	// ��������� ���� �� ������ �������
	audiere::AudioDevicePtr d6 = audiere::OpenDevice();
	audiere::OutputStreamPtr s6 = OpenSound(d6, "portal.ogg", true);			// ������� ����� ��� ������ �����

	// ��������� ���� �� ������ �������� �������
	audiere::AudioDevicePtr d7 = audiere::OpenDevice();
	audiere::OutputStreamPtr s7 = OpenSound(d7, "exit_from_portal.ogg", false);			// ������� ����� ��� ������ �����

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

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '!' && iScreanDelay <= 25)    // ������ ��������
		{
			if (iScreanDelay == 0)
			{
				screamer(console);
				s5->play();
				s5->setVolume(0.6f);
			}

			iScreanDelay++;
		}

		else if (map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] == '*')	// �������
		{
			s7->play();															// ������������� ������ ������������
			s7->setVolume(0.6f);
			iObiliscCounter++;
			map[(int16_t)fPlayerY * iMapWidth + (int16_t)fPlayerX] = '.';		// �������� �������
			/*fPlayerX = 5.0f;													// �������� ������
			fPlayerY = 80.0f;*/
		}

		else
		{
			iStopwatch = clock() / 1000.0f;
			iScreanDelay = 0;

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

			else if (iWalkDelay == 23)
			{
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
			swprintf_s(console, 80, L"X=%3.2f, Y=%3.2f, A=%3.2f, Time: %3.3f, Find all obelisks [%d|5]", fPlayerX,
				fPlayerY, fPlayerA, iStopwatch, iObiliscCounter);
		}

		// ����� �� �����
		console[iConsoleHeight * iConsoleWidth - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, console, iConsoleHeight * iConsoleWidth, { 0,0 }, &dwBytesWritten);
	}
	
	return 0;
}