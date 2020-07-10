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

int16_t iConsoleWidth = 150;								// Ширина консоли
int16_t iConsoleHeight = 40;								// Высота консоли
int16_t iMapWidth = 50;										// Ширина карты
int16_t iMapHeight = 100;									// Высота карты

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;										// Направление игрока
float fSpeed = 4.0f;										// Скорость передвижения

float fFoV = 3.14159f / 4.0f;								// Угол обзора
float fDepth = 75.0f;										// Максимальная дистанция обзора

#endif // !_LIBFUNVAR_H_

