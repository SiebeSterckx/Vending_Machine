#include<iostream>
#include<string>
//#include "menu.h"

using namespace std;

// Alle waarden van de opties array
string opties[] = {
    " 1   cola    2€", 
    " 2   sprite  2€", 
    " 3   fanta   2€", 
    " 4   water   1,5€", 
    " 5   agrum   2€", 
    " 6   stella  2€", 
    " 7   koffie  2,5€", 
    " 8   thee    2,5€"
};

string getOption(int choice) {
    return opties[choice - 1];
}

int choice() {
    const char HL = 120;
    const char VL = 179; 

    int size = sizeof(opties) / sizeof(opties[0]);
    
    for (int x = 0; x < size; ++x) {
        int spacesToAdd = 75 - opties[x].length();
        
        cout << char(VL) << opties[x];

        for (int i = 0; i < spacesToAdd; i++) {
            cout << " "; 
        }

        cout << char(VL) << endl;
        cout << char(VL);
        for (int i = 0; i < 75; i++) {
            cout << " "; 
        }
        cout << char(VL) << endl;
    }
    return 0;
}

void menu() {
    const char RT = 218; 
    const char LT = 191;
    const char LB = 192; 
    const char RB = 217;
    const char HL = 196;
    const char VL = 179; 

    cout << char(RT);
    cout << char(HL);
    cout << char(HL);
    cout << char(LT)  << "   MENU   " << char (RT);
    for (int i = 0; i < 61; i++) {
        cout << char(HL);
    }
    cout << LT << endl;
    
    cout << char(VL) << "  " << char(LB) << char(HL) << char(HL) << char(HL) << char(HL) << char(HL)
    << char(HL) << char(HL) << char(HL)  << char(HL) << char(HL) << char (RB) 
    << "                                                             " <<char(VL) << endl;
    
    choice();

    for (int i = 0; i < 8; i++) {
        cout << char(VL);
        for (int j = 0; j < 75; j++) {
            cout << " ";
        }
        cout << char(VL) << endl;
    }
    
    cout << LB;
    for (int i = 0; i < 75; ++i) {
        cout << HL;
    }
    
    cout << RB;
    for (int i = 0; i < 75; ++i) {
        cout << HL;
    }
}

