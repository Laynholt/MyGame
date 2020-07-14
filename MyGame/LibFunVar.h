#ifndef _LIBFUNVAR_H_
#define _LIBFUNVAR_H_
#define _CRT_SECURE_NO_WARNINGS

// Для локали
#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
// Контейнеры
#include <vector>
#include <string>
// Время
#include <ctime>
#include <chrono>
// Ввод/Вывод + Потоки
#include <conio.h>
#include <fstream>
#include <iostream>
// Фиксированный формат данных
#include <cstdint>
// Аудио + Графика
#include <audiere.h>
#include <Windows.h>
// Алгоритмы
#include <algorithm>
// Для иконки
#include "resource.h"


using namespace std;

#define SPEED 5

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

// создаем константу, содержащую локаль с нужным фасетом для
// преобразования символов при чтении из файла в кодировке UTF-8
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

