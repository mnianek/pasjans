#include "gameplay.h"
#include "continuation.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>		// czas
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstring>		//zamiana string na char
#include <algorithm>	//sortowanie tabeli

using namespace std;

struct waist			//elementy generowania karty
{
	char color;			// czarny/czerwony
	char suit;			// pik, trefl, kier, karo
	char number = '0';		// od 0 do 12 (talia sk³ada siê z 13 kart) A = 14, K=13, 12=D, 11=J, 2-10
	bool view;			// ods³oniêta (true) lub zakryta (false)
};
waist card[52];			//deklaracja tablicy kart



void cards::create_cards()
{
	int b = 0, r = 0, ko = 0, kr = 0, pk=0, tl=0;	// zmienne zawarte w tworzeniu kart
	srand(time(NULL));
	int lp = 52;			// zmienna mówi¹ca ile razy ma siê powtórzyæ petla (52 na talie + b³êdy)
	char pik[13] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };
	char karo[13] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };
	char kier[13] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };
	char trefl[13] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	

	
	
	for (int i = 0; i < lp; i++) { 
		if (r < 26 && b < 26)			//losuje, czy karta bedzie czerwona czy czarna
		{
			if (rand() % 2 == 0)
			{
				card[i].color = 'B';
				b++;
			}
			else
			{
				card[i].color = 'R';
				r++;
			}
		}
		else
		{
			if (r == 26) {
				card[i].color = 'B';
				b++;
			}
			else if (b == 26)
			{
				card[i].color = 'R';
				r++;
			}
		}
		
		
		if (card[i].color == 'R')				//losuje rodzaj karty(pik, trefl, kier, karo)
		{		
			if (ko < 13 && kr < 13) 
			{
				if (rand() % 2 == 0)
				{
					card[i].suit = '\x04';
					card[i].number = karo[n3];
					n3++;
					ko++;


				}
				else
				{
					card[i].suit = '\x03';
					card[i].number = kier[n4];
					n4++;
					kr++;

				}
			}
			else {
				if (ko == 13) {
					card[i].suit = '\x03';
					card[i].number = kier[n4];
					n4++;
					kr++;
				}
				else if (kr == 13)
				{
					card[i].suit = '\x04';
					card[i].number = karo[n3];
					n3++;
					ko++;
				}
			}
		}
		else
		{
			if (tl < 13 && pk < 13)
			{
				if (rand() % 2 == 0)
				{
					card[i].suit = '\x05';
					card[i].number = trefl[n2];
					n2++;
					tl++;
				}
				else
				{
					card[i].suit = '\x06';
					card[i].number = pik[n1];
					n1++;
					pk++;
				}
			}
			else {
				if (tl == 13) {
					card[i].suit = '\x06';
					card[i].number = pik[n1];
					n1++;
					pk++;
				}
				else if (pk == 13)
				{
					card[i].suit = '\x05';
					card[i].number = trefl[n2];
					n2++;
					tl++;
				}
			}
		}
		

		//wypisanie karty
		
		//cout <<card[i].color<<" ";
		//cout << card[i].suit << " ";
		//cout << card[i].number << endl;
	}	
}

void cards::table() {
	//******
	//1)Tworzenie sto³u w formie tablica
	//2)Zamiana tablicy na znaki 
	//3)Pokazanie kart wraz z oznaczeniami [czyt. create_cards()]
	//******
	srand(time(NULL));
	int tab[28];

	for (int i = 0; i < 28; i++)
	{
		tab[i] = rand() % 28 + 1;
		for (int j = 0; j < i; j++)
		{
			if (tab[j] == tab[i])
			{
				tab[i] = rand() % 28 + 1;
				j = -1; // -1 bo jest to pierwsze powtorzenie
			}
			
		}
	}
	//sort(tab, tab + 28);	//sprawdzenie czy dzia³a
	int number = 0, lpmo = 1;			//lpmo to zmienna wpisujaca liczby puste
	while (lpmo < 7) {
		for (int i = lpmo; i < 7; i++)
		{
			karta[i][(i - lpmo)].numKr = -1;
		}
		lpmo++;
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			while (karta[i][j].numKr == -1) {
				j++;
			}

			karta[i][j].numKr = tab[number];	//uzupelnianie pozycji miejsc
			number++;
		}
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << karta[i][j].numKr << " ";
		}
		cout << "\n";
	}
	//***KARTY***
	
	/*for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << karta[i][j].numKr << " ";
		}
		cout << "\n";
	}*/
	
	int ktora_karta = 0; //umieszcza parametry karty w karcie											   
	int wysokosc = 1;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 44; j++) {
			wyglad[j][i] = ' ';		//dodaje przerwe po lewej stronie
		}
	}
	
	
	for (int i = 0; i < 7; i++) {
		int ng = 6;	//zmienna do zmiany komorek w wierszu (tylko gorna czêœæ)									-----
		int ns = 5; //zmienna do zmiany komorek w wierszu (tylko œrodkowa czêœæ) || 5 zamiast 6 dla wygl¹du	   |     |
		int nd = 6;	//zmienna do zmiany komorek w wierszu (tylko dolna czêœæ)								   |     |
		for (int j = 0; j < 7; j++) {
			if (karta[i][j].numKr > 0) 
			{
				
				//********************************************************************
				//karta ma 6 wysokosci, 7 szerokoœci
				ktora_karta = karta[i][j].numKr-1;
				//**GÓRA**
				ng += 6;
				for (int i2 = ng - 5; i2 < ng; i2++)
				{
					wyglad[(i*6)+1][i2] = '-';
				}
				ng += 6;
				for (int i3 = ng - 5; i3 < ng; i3++)
				{
					wyglad[(i*6)+1][i3] = ' ';
				}
				ng += 6;

				//**ŒRODEK**
				wysokosc = (i * 6) + 6;
				for (int WysokoscPojKarty = (i * 6) + 2; WysokoscPojKarty < wysokosc; WysokoscPojKarty++) {
					wyglad[WysokoscPojKarty][ns] = '|';

					for (int i2 = ns + 1; i2 < ns + 6; i2++)
					{
						wyglad[WysokoscPojKarty][i2] = ' ';
						if (i2 == (ns + 3) && wysokosc - WysokoscPojKarty == 4) wyglad[WysokoscPojKarty][i2] = card[ktora_karta].color; //pokazuje kolor karty
						if (i2 == (ns + 3) && wysokosc - WysokoscPojKarty == 3) wyglad[WysokoscPojKarty][i2] = card[ktora_karta].suit; //pokazuje suit karty
						if (card[ktora_karta].number == '1')
						{
							if (i2 == (ns + 3) && wysokosc - WysokoscPojKarty == 2) wyglad[WysokoscPojKarty][i2] = '0'; //pokazuje wartoœæ karty
							if (i2 == (ns + 2) && wysokosc - WysokoscPojKarty == 2) wyglad[WysokoscPojKarty][i2] = '1'; //pokazuje wartoœæ karty
						}
						else
						{
							if (i2 == (ns + 3) && wysokosc - WysokoscPojKarty == 2) wyglad[WysokoscPojKarty][i2] = card[ktora_karta].number; //pokazuje wartoœæ karty
						}
						
					}
					
					wyglad[WysokoscPojKarty][ns + 6] = '|';

					for (int i3 = ns + 7; i3 < ns + 13; i3++)
					{
						wyglad[WysokoscPojKarty][i3] = ' ';
					}
				}
				ns += 10;
				/**DÓ£**/
				nd += 6;
				for (int i2 = nd - 5; i2 < nd; i2++)
				{
					wyglad[(i * 6) + 6][i2] = '-';
				}
				nd += 6;
				for (int i3 = nd - 5; i3 < nd; i3++)
				{
					wyglad[(i * 6) + 6][i3] = ' ';
				}
				nd += 6;
				ktora_karta++;
				//********************************************************************
			}
			else // ***jesli karty nie ma***
			{
				ng += 6;
				for (int i2 = ng - 5; i2 < ng; i2++)
				{
					wyglad[(i * 6) + 1][i2] = ' ';
				}
				ng += 6;
				for (int i3 = ng - 5; i3 < ng; i3++)
				{
					wyglad[(i * 6) + 1][i3] = ' ';
				}
				ng += 6;

				//**ŒRODEK**
				wysokosc = (i * 6) + 6;
				for (int WysokoscPojKarty = (i * 6) + 2; WysokoscPojKarty < wysokosc; WysokoscPojKarty++) {
					wyglad[WysokoscPojKarty][ns] = ' ';

					for (int i2 = ns + 1; i2 < ns + 6; i2++)
					{
						wyglad[WysokoscPojKarty][i2] = ' ';
						

					}
					
					wyglad[WysokoscPojKarty][ns + 6] = ' ';

					for (int i3 = ns + 7; i3 < ns + 13; i3++)
					{
						wyglad[WysokoscPojKarty][i3] = ' ';
					}
				}
				ns += 10;
				/**DÓ£**/
				nd += 6;
				for (int i2 = nd - 5; i2 < nd; i2++)
				{
					wyglad[(i * 6) + 6][i2] = ' ';
				}
				nd += 6;
				for (int i3 = nd - 5; i3 < nd; i3++)
				{
					wyglad[(i * 6) + 6][i3] = ' ';
				}
				nd += 6;
			}
			
		}
	}
	
	
	for(int i=5;i<80;i++)wyglad[43][i] = '-';
	

	//***Pokazanie sto³u kart***
	for (int i = 0; i < 44; i++) {
		for (int j = 0; j < 130; j++)
		{
			cout << wyglad[i][j];
		}
		cout << "\n";

	}

}

void cards::sprawdz() {
	//***Sprawdzanie tabeli***
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << karta[i][j].numKr << " ";
		}
		cout << "\n";
	}
}


