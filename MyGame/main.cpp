#include "LibFunVar.h"

int16_t iConsoleWidth = 150;							// Øèðèíà êîíñîëè
int16_t iConsoleHeight = 40;							// Âûñîòà êîíñîëè
int16_t iMapWidth = 200;								// Øèðèíà êàðòû
int16_t iMapHeight = 100;								// Âûñîòà êàðòû

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;									// Íàïðàâëåíèå èãðîêà
float fBufPlayerA = fPlayerA;
float fSpeed = SPEED;									// Ñêîðîñòü ïåðåäâèæåíèÿ
float fSpeedCamera = 5.0f;								// Ñêîðîñòü êàìåðû

float fFoV = 3.14159f / 1.78f;							// Óãîë îáçîðà
float fDepth = 26.0f;

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	srand(time(NULL));
	system("mode con cols=150 lines=40");					// Ôèêñèðóåì ðàçìåð îêíà íà 150 íà 40

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	/*HWND window_header = GetConsoleWindow();
	SetWindowPos(window_header, HWND_TOP, 0, 30, 1100, 690, NULL);*/

	static const TCHAR* ConsoleTitle = TEXT("Lost in the Maze");		// Ìåíÿåì íàçâàíèå êîíñîëè
	SetConsoleTitle(ConsoleTitle);

	menu();

	return 0;
}
