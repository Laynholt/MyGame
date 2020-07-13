#include <iostream> 
#include <fstream> 
#include <string>  
#include <vector> 
#include <Windows.h>	
#include <io.h>		// ��� ������� _setmode
#include <fcntl.h>	// ��� ��������� _O_U16TEXT
#include <codecvt>	// ��� ������ � ������� codecvt_utf8 ������

using namespace std;

int wmain(){
	const int N = 29, //�����
		      M = 93; // ������� � ������
	// ������������ ������������ ������ ����� � ������ � ������ �������
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	wifstream in(L"data.txt");
	wofstream out(L"res.txt");

	// ������� ���������, ���������� ������ � ������ ������� ���
	// �������������� �������� ��� ������ �� ����� � ��������� UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	out.imbue(utf8_locale);	 // ��������� ��� ����� � ������ �������
	in.imbue(utf8_locale);	 // ��������� ��� ����� � ������ �������

	vector<wstring> read(N); 
    wstring read_t;
	int j, i = 0;

	while (getline(in, read_t)) {
		read[i] = read_t;
		i++;
	}
	
	for (int j = 0; j < M; j++) {
		for (i = 0; i < N; i++) {
			out << read[i][j];
		//	wcout << read[i][j];
		}
		out << endl;
		//wcout << endl;
	}

	in.close();
	out.close();
	system("pause");
	return 0;
}