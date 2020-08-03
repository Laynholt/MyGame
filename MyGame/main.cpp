#include "LibFunVar.h"

int16_t iConsoleWidth = 150;							// Ширина консоли
int16_t iConsoleHeight = 40;							// Высота консоли
int16_t iMapWidth = 200;								// Ширина карты
int16_t iMapHeight = 100;								// Высота карты

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;									// Направление игрока
float fBufPlayerA = fPlayerA;
float fSpeed = SPEED;									// Скорость передвижения
float fSpeedCamera = 5.0f;								// Скорость камеры
int16_t iStamina = STAMINA_MAX;							// Выносливость игрока

float fFoV = 3.14159f / 1.78f;							// Угол обзора
float fDepth = 26.0f;

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	srand(time(NULL));
	//system("mode con cols=150 lines=40");					// Фиксируем размер окна на 150 на 40

	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);		// Получаем максимальный размер консоли
	COORD maxWindow = GetLargestConsoleWindowSize(out_handle);

	HWND window_header = GetConsoleWindow();					// Центрируем её и задаем ей размер
	SetWindowPos(window_header, HWND_TOP, maxWindow.X, maxWindow.Y, 1115, 690, NULL);
																// Запрещаем изменять размер консоли
	SetWindowLong(window_header, GWL_STYLE, GetWindowLong(window_header, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	wchar_t* console = new wchar_t[iConsoleHeight * iConsoleWidth];

	static const TCHAR* ConsoleTitle = TEXT("Lost in the Maze - beta v2.1 (PreRelease)");		// Меняем название консоли
	SetConsoleTitle(ConsoleTitle);

	menu(console);

	delete[] console;

	return 0;
}