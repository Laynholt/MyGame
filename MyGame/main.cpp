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
float fBufPlayerA = fPlayerA;
float fSpeed = SPEED;									// �������� ������������
float fSpeedCamera = 5.0f;								// �������� ������
int16_t iStamina = STAMINA_MAX;							// ������������ ������

float fFoV = 3.14159f / 1.78f;							// ���� ������
float fDepth = 26.0f;

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	srand(time(NULL));
	system("mode con cols=150 lines=40");					// ��������� ������ ���� �� 150 �� 40

	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);	// �������� ������������ ������ �������
	COORD maxWindow = GetLargestConsoleWindowSize(out_handle);
															
	HWND window_header = GetConsoleWindow();					// ���������� � � ������ �� ������
	SetWindowPos(window_header, HWND_TOP, maxWindow.X, maxWindow.Y, 1101, 690, NULL);
																// ��������� �������� ������ �������
	SetWindowLong(window_header, GWL_STYLE, GetWindowLong(window_header, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
																// ����������� �� ����� ��������� � ������	
	//������� ������ ����������� ��������
	SMALL_RECT zeroWindow = { 0, 0, 0, 0 };
	COORD zBuffer = { 1, 1 };
	SetConsoleWindowInfo(out_handle, TRUE, &zeroWindow);
	SetConsoleScreenBufferSize(out_handle, zBuffer);

	//� ��� ����� �������� �������� �� ������ ���
	COORD bufferSize = { iConsoleWidth, iConsoleHeight };
	SMALL_RECT windowSize = { 0, 0, iConsoleWidth - 1, iConsoleHeight - 1 };
	SetConsoleScreenBufferSize(out_handle, bufferSize);
	SetConsoleWindowInfo(out_handle, TRUE, &windowSize);

	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];

	static const TCHAR* ConsoleTitle = TEXT("Lost in the Maze");		// ������ �������� �������
	SetConsoleTitle(ConsoleTitle);

	menu(console);

	delete[] console;

	return 0;
}