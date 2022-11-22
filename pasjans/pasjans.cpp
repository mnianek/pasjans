// pasjans.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "start.h"
#include "continuation.h"

using namespace std;

string command;

int main()
{
    setlocale(LC_CTYPE, "Polish");
    roz s;
    cards c;
    //s.start();
    c.create_cards();
    c.table();
    
    
    
    while (true) {
        cin >> command;
        if (command == "pokaz.tabele")c.sprawdz();
        if (command == "admin")s.accadmin();
        if (command == "autor")s.autor();
        if (command == "start")s.start();
    }
    

    return 0;
}


