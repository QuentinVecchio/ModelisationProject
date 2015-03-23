#pragma once
#include <iostream>

using namespace std;

void Erreur(string s) {
	cout << s.c_str() << endl;
}

void ErreurExit(string s) {
	cout << s.c_str() << endl;
	exit(1);
}
