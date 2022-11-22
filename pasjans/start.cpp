#include "start.h"
#include "continuation.h"
#include "gameplay.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

roz s;
cards c;
//gameplay g;
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
		c.create_cards();
		c.table();
		break;
	case 2:
		system("cls");
		break;
	case 3:
		s.autor();
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
		s.start();
	}
	
	
		



}
