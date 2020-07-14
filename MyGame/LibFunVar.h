#ifndef _LIBFUNVAR_H_
#define _LIBFUNVAR_H_
#define _CRT_SECURE_NO_WARNINGS

// ��� ������
#include <io.h>      // ��� ������� _setmode
#include <fcntl.h>   // ��� ��������� _O_U16TEXT
#include <codecvt>   // ��� ������ � ������� codecvt_utf8 ������
// ����������
#include <vector>
#include <string>
// �����
#include <ctime>
#include <chrono>
// ����/����� + ������
#include <conio.h>
#include <fstream>
#include <iostream>
// ������������� ������ ������
#include <cstdint>
// ����� + �������
#include <audiere.h>
#include <Windows.h>
// ���������
#include <algorithm>
// ��� ������
#include "resource.h"


using namespace std;

#define SPEED 5

extern int16_t iConsoleWidth;				// ������ �������
extern int16_t iConsoleHeight;				// ������ �������
extern int16_t iMapWidth;					// ������ �����
extern int16_t iMapHeight;					// ������ �����

extern float fPlayerX;
extern float fPlayerY;
extern float fPlayerXBuf;
extern float fPlayerYBuf;
extern float fPlayerA;						// ����������� ������
extern float fSpeed;						// �������� ������������
extern float fSpeedCamera;					// �������� ��������

extern float fFoV;							// ���� ������
extern float fDepth;

// ������� ���������, ���������� ������ � ������ ������� ���
// �������������� �������� ��� ������ �� ����� � ��������� UTF-8
const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

void color_meny(int8_t choose, wstring arr_for_meny[], int8_t num_str);

void map_pulling(wstring& map);
bool corners(float& fEyeX, float& fEyeY, int16_t& nTestX, int16_t& nTestY);

void screamer(wchar_t* console);
bool game_over(wchar_t* console, wchar_t a);
void letter(wchar_t* console);
void open_map(wchar_t* console, wstring map);

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter);
void game(float fX = 1.0f, float fY = 1.0f, float fA = 1.0f, int16_t Time = 0, int16_t iObiliscSave = 0);
void continue_game(audiere::OutputStreamPtr sound);
void authors();
void control();

#endif // !_LIBFUNVAR_H_

