//88 27
//90 29
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

int main(){
	int q = 0, n = 10, q1 = 0;

	/*
	for (int j = 0; j < n; j++){
		system("cls");
		for (int i = 0; i < q; i++){
			cout << endl;
		}
		cout << "RUN!";
		Sleep(100);
		q++;
	}
	q = 0;
	*/
	/*
	for (int j = 0; j < 40; j++){
		system("cls");
		for (int i = 0; i < n; i++){
			cout << endl;
		}
		for (int i = 0; i < q; i++){
			cout << " ";
		}
		cout << "loading...";
		Sleep(100);
		q++;
	}
*/
	for (int j = 0; j < n; j++){
		system("cls");
		for (int i = 0; i < q; i++){
			cout << endl;
		}
		for (int i = 0; i < 40; i++){
			cout << " ";
		}
		cout << "loading...";
		Sleep(190);
		q++;
	}
	q = 40;
	q1 = 0;
	for (int j = 0; j < 20; j++){
		system("cls");
		for (int i = 0; i < 10; i++){
			cout << endl;
		} 
		for (int i = 0; i < q; i++){
			cout << " ";
		}
		cout << "loadi";
		for (int i = 0; i < q1; i++){
			cout << "  ";
		}
		cout << "ng...";
		Sleep(190);
		q--;
		q1++;
	}

	system("pause");
	return 0;
}