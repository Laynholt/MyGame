#include "LibFunVar.h"

int16_t iConsoleWidth = 150;							// ������ �������
int16_t iConsoleHeight = 40;							// ������ �������
int16_t iMapWidth = 100;								// ������ �����
int16_t iMapHeight = 50;								// ������ �����

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;									// ����������� ������
float fSpeed = SPEED;									// �������� ������������
float fSpeedCamera = 4.0f;								// �������� ������

float fFoV = 3.14159f / 1.78f;							// ���� ������
float fDepth = 26.0f;

int main()
{
	srand(time(NULL));
	system("mode con cols=150 lines=40");					// ��������� ������ ���� �� 150 �� 40
	bool exit = 1;
	char choose = ' ';
	int16_t index = 0;
	int32_t value = 0;

	static const TCHAR* ConsoleTitle = TEXT("Lost in the Maze");		// ������ �������� �������
	SetConsoleTitle(ConsoleTitle);

	// ������������� ������
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// ��� ������ ����� ������� AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/menu.ogg", true); // ������� ����� ��� ������ �����
	sound->play();															// ����������� ��� ����
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	while (exit)
	{
		cout <<
			"|--------------------------------------------------------------------|\n"
			"|                          1.NEW GAME                                |\n"
			"|                        2.CONTINUE GAME                             |\n"
			"|                           3.AURORS                                 |\n"
			"|                           4.CONTROL                                |\n"
			"|--------------------------------------------------------------------|\n";
		cout << "\nChoose an action >> ";
		choose = _getch();
		switch (choose)
		{
		case '1':
			sound->stop();
			game();  //������ ����
			break;
		case '2':
			continue_game(sound); //������ �����������, ����������� ����� �� U, ���� �� ��������
			break;
		case '3':
			authors();  // ������ ���
			break;
		case '4':
			control();
			break;
		default:
			cout << "\nChoose again!\n";
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}