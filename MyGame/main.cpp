#include "LibFunVar.h"

int16_t iConsoleWidth = 150;							// ������ �������
int16_t iConsoleHeight = 40;							// ������ �������
int16_t iMapWidth = 200;								// ������ �����
int16_t iMapHeight = 100;								// ������ �����

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;									// ����������� ������
float fSpeed = SPEED;									// �������� ������������
float fSpeedCamera = 5.0f;								// �������� ������

float fFoV = 3.14159f / 1.78f;							// ���� ������
float fDepth = 26.0f;

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	srand(time(NULL));
	system("mode con cols=150 lines=40");					// ��������� ������ ���� �� 150 �� 40
	bool exit = 1;
	//char choose = ' ';
	int16_t index = 0;
	int32_t value = 0;

	int8_t choose = 1;
	const int8_t num_str = 4;
	wstring arr_for_meny[num_str] = {L"����� ����", L"���������� ����", L"������������", L"����������"};

	static const TCHAR* ConsoleTitle = TEXT("Lost in the Maze");		// ������ �������� �������
	SetConsoleTitle(ConsoleTitle);

	// ������������� ������
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// ��� ������ ����� ������� AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/menu.ogg", true); // ������� ����� ��� ������ �����
	sound->play();															// ����������� ��� ����
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	color_meny(choose, arr_for_meny, num_str);

	while (exit)
	{
		switch (_getch())
		{
		case 72: case 'w':
			choose = (choose > 1) ? --choose : 1;
			system("cls");
			color_meny(choose, arr_for_meny, num_str);
			break;
		case 80: case 's':
			choose = (choose < 4) ? ++choose : 4;
			system("cls");
			color_meny(choose, arr_for_meny, num_str);
			break;
		case 13:
			if (choose == 1) { sound->stop(); game(); } //������ ����
			else if (choose == 2) { continue_game(sound); } //������ �����������, ����������� ����� �� U
			else if (choose == 3) { authors(); }
			else if (choose == 4) { control(); }
			choose = 1;
			system("cls");
			color_meny(choose, arr_for_meny, num_str);
			break;
		}
	}
	return 0;
}
