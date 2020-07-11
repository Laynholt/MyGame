#ifndef _LIBFUNVAR_H_
#define _LIBFUNVAR_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <cstdint>
#include <vector>
#include <audiere.h>
#include <conio.h>
#include <Windows.h>
#include "resource.h"

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

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter);
void game(float fX = 1.0f, float fY = 1.0f, float fA = 1.0f, int16_t Time = 0, int16_t iObiliscSave = 0);
void authors();
void continue_game();

#endif // !_LIBFUNVAR_H_

