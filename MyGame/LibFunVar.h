#ifndef _LIBFUNVAR_H_
#define _LIBFUNVAR_H_
#define _CRT_SECURE_NO_WARNINGS

#include <io.h>
#include <fcntl.h>
#include <ctime>
#include <chrono>
#include <vector>
#include <conio.h>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <audiere.h>
#include <Windows.h>
#include <algorithm>

#include "resource1.h"

using namespace std;

#define SPEED 4

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
extern float fSpeedCamera;					// Скорость поворота

extern float fFoV;							// Угол обзора
extern float fDepth;

void map_pulling(wstring& map);
bool corners(float& fEyeX, float& fEyeY, int16_t& nTestX, int16_t& nTestY);

void screamer(wchar_t* console);
bool game_over(wchar_t* console, wchar_t a);
void letter(wchar_t* console, wchar_t* message, int32_t size_message);
void open_map(wchar_t* console, wstring map);

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter);
void game(float fX = 1.0f, float fY = 1.0f, float fA = 1.0f, int16_t Time = 0, int16_t iObiliscSave = 0);
void continue_game(audiere::OutputStreamPtr sound);
void authors();
void control();

#endif // !_LIBFUNVAR_H_

