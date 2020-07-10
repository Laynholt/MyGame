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

int16_t iConsoleWidth = 150;								// ������ �������
int16_t iConsoleHeight = 40;								// ������ �������
int16_t iMapWidth = 50;										// ������ �����
int16_t iMapHeight = 100;									// ������ �����

float fPlayerX = 1.0f;
float fPlayerY = 1.0f;
float fPlayerXBuf = fPlayerX;
float fPlayerYBuf = fPlayerY;
float fPlayerA = 0.0f;										// ����������� ������
float fSpeed = 4.0f;										// �������� ������������

float fFoV = 3.14159f / 4.0f;								// ���� ������
float fDepth = 75.0f;										// ������������ ��������� ������

#endif // !_LIBFUNVAR_H_

