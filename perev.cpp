//88 27
//90 29
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

int main(){
	
	ifstream in("f.txt");
	vector< vector<char> > B(29, vector<char>(90, 0));
	vector< vector<char> > A(90, vector<char>(29, 0));
	char ch;
	int i = 0, j = 0, q = 31;
	


	for (int i = 0; i < 90; i++) {
		for (int j = 0; j < 29; j++) { 
			A[i][j] = q;
			B[j][i] = A[i][j];
			cout << A[i][j];
		}
		q++;
		cout << endl;
	}

	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 90; j++) {

			cout << B[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}