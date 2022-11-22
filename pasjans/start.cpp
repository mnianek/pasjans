#include "start.h"
#include "continuation.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

roz r;
cards c;

void roz::start()
{	
	system("cls");
	cout << "-=Pasjans=-"<<endl;
	cout << "^^Menu^^" << endl;
	cout << "1*Graj" << endl;
	cout << "2*Jak graæ?" << endl;
	cout << "3*Autor\n" << endl;
	cin >> a;
	switch (a) 
	{
	case 1:
		system("cls");
		c.table();
		break;
	}
}
void roz::autor() {
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;;
	cout << "Program napisany przez Jana Czernieckiego\nWszelkie prawa zastrze¿one 2022." << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;

}
void roz :: accadmin() {
	string pass;
	string command;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
	cout << "trwa logowanie do admina... \n   podaj has³o: ";
	cin >> pass;
	if (pass == "admin") {
		system("color 2");
		admin = true;
		
	}
	else {
		cout << "z³e has³o..."<<endl;
		Sleep(1000);
		cout << "restarowanie aplikacji";
		r.start();
	}
	
	
		



}
