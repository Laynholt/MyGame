#ifndef _LIBFUNVAR_H_
#define _LIBFUNVAR_H_

#include <iostream>
#include <chrono>
#include <Windows.h>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <audiere.h>
#include <ctime>

using namespace std;


extern int16_t iConsoleWidth;				// Ширина консоли
extern int16_t iConsoleHeight;				// Высота консоли
extern int16_t iMapWidth;					// Ширина карты
extern int16_t iMapHeight;					// Высота карты

extern float fPlayerX;
extern float fPlayerY;
extern float fPlayerXBuf;
extern float fPlayerYBuf;
extern float fPlayerA;						// Направление игрока
extern float fSpeed;						// Скорость передвижения

extern float fFoV;							// Угол обзора
extern float fDepth;

void screamer(wchar_t* console);
void game_over(wchar_t* console, wchar_t a);
void map_pulling(wstring& map);
bool corners(float& fEyeX, float& fEyeY, int16_t& nTestX, int16_t& nTestY);

#endif // !_LIBFUNVAR_H_

