#include "LibFunVar.h"

int16_t iConsoleWidth = 150;							// Ширина консоли
int16_t iConsoleHeight = 40;							// Высота консоли
int16_t iMapWidth = 50;									// Ширина карты
int16_t iMapHeight = 100;								// Высота карты

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;									// Направление игрока
float fSpeed = SPEED;									// Скорость передвижения
float fSpeedCamera = 4.0f;								// Скорость камеры

float fFoV = 3.14159f / 1.78f;							// Угол обзора
float fDepth = 26.0f;

int main()
{
	srand(time(NULL));
	system("mode con cols=150 lines=40");					// Фиксируем размер окна на 150 на 40
	bool exit = 1;
	int16_t choose = 0, index = 0;
	int32_t value = 0;

	static const TCHAR* ConsoleTitle = TEXT("Lost in the Maze");		// Меняем название консоли
	SetConsoleTitle(ConsoleTitle);

	// Воспроизводим музыку
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// Для начала нужно открыть AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/menu.ogg", true); // Создаем поток для нашего звука
	sound->play();															// Проигрываем наш звук
	sound->setVolume(0.5f);
	sound->setRepeat(true);

	while (exit)
	{
		cout <<
			"|--------------------------------------------------------------------|\n"
			"| 1.		     NEW GAME                                        |\n"
			"| 2.		  CONTINUE GAME                                      |\n"
			"| 3.		     AURORS                                          |\n"
			"| 4.			   		                             |\n"
			"|--------------------------------------------------------------------|\n";
		cout << "\nChoose an action >> ";
		choose = _getch();
		switch (choose)
		{
		case '1':
			sound->stop();
			game();  //запуск игры
			break;
		case '2':
			continue_game(sound); //взятие сохраненией, сохраниться можно на U, либо на обелиске
			break;
		case '3':
			authors();  // просто так
			sound->stop();
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