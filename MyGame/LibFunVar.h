#ifndef _LIBFUNVAR_H_
#define _LIBFUNVAR_H_
#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_WINNT 0x0500

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
#define TURBO_BOOST 5

extern int16_t iConsoleWidth;				// ������ �������
extern int16_t iConsoleHeight;				// ������ �������
extern int16_t iMapWidth;					// ������ �����
extern int16_t iMapHeight;					// ������ �����

extern float fPlayerX;
extern float fPlayerY;
extern float fPlayerXBuf;
extern float fPlayerYBuf;
extern float fPlayerA;						// ����������� ������
extern float fBufPlayerA;
extern float fSpeed;						// �������� ������������
extern float fSpeedCamera;					// �������� ��������

extern float fFoV;							// ���� ������
extern float fDepth;

// ������� ���������, ���������� ������ � ������ ������� ���
// �������������� �������� ��� ������ �� ����� � ��������� UTF-8
const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

void menu(wchar_t* console);
void color_meny(int8_t choose, wstring arr_for_meny[], int8_t num_str);
void clearScreen();
void variable_default(bool AllObeliscs[], bool AllMessages[]);

void map_pulling(wstring& map);
bool corners(float& fEyeX, float& fEyeY, int16_t& nTestX, int16_t& nTestY);

void screamer(wchar_t* console);
bool game_over(wchar_t* console, wchar_t a);
void epilogue(wchar_t* console, int16_t iObiliscCounter, bool type, int16_t n = 20);
int16_t letter(wchar_t* console, int16_t iObeliscCount, int16_t n = 0);
void controls_info(wchar_t* console);
void message_info(wchar_t* console, bool AllMessages[]);
void open_map(wchar_t* console, wstring map);

void save(float fPlayerX, float fPlayerY, int16_t Time, int16_t iObiliscCounter, int16_t MessageCount, bool AllMessange[], bool AllObeliscs[]);
void game(wchar_t* console, bool AllObeliscs[], bool AllMessages[], float fX = 1.0f, float fY = 1.0f, float fA = 1.0f, int16_t Time = 0, int16_t iObiliscSave = 0,
    int16_t iMessangeCount = 0, bool bFromSave = false);
bool continue_game(wchar_t* console, audiere::OutputStreamPtr sound, bool AllObeliscs[], bool AllMessages[]);
void authors();
void control();

#endif // !_LIBFUNVAR_H_