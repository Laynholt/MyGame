#include "LibFunVar.h"

int16_t iConsoleWidth = 150;							// Ширина консоли
int16_t iConsoleHeight = 40;							// Высота консоли
int16_t iMapWidth = 100;								// Ширина карты
int16_t iMapHeight = 50;								// Высота карты

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
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	srand(time(NULL));
	system("mode con cols=150 lines=40");					// Фиксируем размер окна на 150 на 40
	bool exit = 1;
	char choose = ' ';
	int16_t index = 0;
	int32_t value = 0;

	static const TCHAR* ConsoleTitle = TEXT("Lost in the Maze");		// Меняем название консоли
	SetConsoleTitle(ConsoleTitle);

	// Воспроизводим музыку
	audiere::AudioDevicePtr device = audiere::OpenDevice();					// Для начала нужно открыть AudioDevice 
	audiere::OutputStreamPtr sound = OpenSound(device, "sounds/menu.ogg", true); // Создаем поток для нашего звука
	sound->play();															// Проигрываем наш звук
	sound->setVolume(0.5f);
	sound->setRepeat(true);
	/*
	for (j = 0; j < 20; j++){
		system("cls");
		for (i = 0; i < q; i++){
			wcout << endl;
		}
		for (i = 0; i < 67; i++){
			wcout << " ";
		}
		wcout << "Lost in the Maze";
		Sleep(100);
		q++;
	}
	q = 67;
	for (j = 0; j < 20; j++){
		system("cls");
		for (i = 0; i < 20; i++){
			wcout << endl;
		}
		for (i = 0; i < q; i++){
			wcout << " ";
		}
		wcout << "Lost in ";
		for (i = 0; i < q1; i++){
			wcout << "  ";
		}
		wcout << "the Maze";
		Sleep(150);
		q--;
		q1++;
	}
	system("cls");*/

	while (exit)
	{
		wcout <<
			L"|--------------------------------------------------------------------|\n"
			"|                          1.Новая игра                              |\n"
			"|                        2.Продолжить игру                           |\n"
			"|                         3.Разработчики                             |\n"
			"|                          4.Управление                              |\n"
			"|--------------------------------------------------------------------|\n";
		wcout << L"\nВыберете опцию >> ";
		choose = _getch();
		switch (choose)
		{
		case '1':
			wcout << L"Новая игра" << endl;
			sound->stop();
			game();  //запуск игры
			break;
		case '2':
			wcout << L"Продолжить игру" << endl;
			continue_game(sound); //взятие сохраненией, сохраниться можно на U, либо на обелиске
			break;
		case '3':
			wcout << L"Разработчики" << endl;
			authors();  // просто так
			break;
		case '4':
			wcout << L"Управление" << endl;
			control();
			break;
		default:
			wcout << L"\nНекорректный выбор! Попробуйте ещё раз.\n";
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
