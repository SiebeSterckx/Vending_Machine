#include<iostream>
#include<string>

using namespace std;

string options[] = {
    " Nr:1  Cola    2€    Stock: 20", 
    " Nr:2  Sprite  2€    Stock: 20", 
    " Nr:3  Fanta   2€    Stock: 20", 
    " Nr:4  Water   1,5€  Stock: 20", 
    " Nr:5  Agrum   2€    Stock: 20", 
    " Nr:6  Stella  2€    Stock: 20", 
    " Nr:7  Coffee  2,5€  Stock: 20", 
    " Nr:8  Tea     2,5€  Stock: 20"
};

string getOption(int choice) {
    return options[choice - 1];
}

int choice() {
    const char HL = 120;
    const char VL = 179; 

    int size = sizeof(options) / sizeof(options[0]);
    
    for (int x = 0; x < size; ++x) {
        int spacesToAdd = 45 - options[x].length();
        
        cout << char(VL) << options[x];

        for (int i = 0; i < spacesToAdd; i++) {
            cout << " "; 
        }

        cout << char(VL) << endl;
        cout << char(VL);
        for (int i = 0; i < 45; i++) {
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

	cout << endl;
    cout << char(RT);
    cout << char(HL);
    cout << char(HL);
    cout << char(LT)  << "   MENU   " << char (RT);
    for (int i = 0; i < 31; i++) {
        cout << char(HL);
    }
    cout << LT << endl;
    
    cout << char(VL) << "  " << char(LB) << char(HL) << char(HL) << char(HL) << char(HL) << char(HL)
    << char(HL) << char(HL) << char(HL)  << char(HL) << char(HL) << char (RB) 
    << "                               " <<char(VL) << endl;
    
    choice();

    
    
    cout << LB;
    for (int i = 0; i < 45; ++i) {
        cout << HL;
    }
    
    cout << RB;
    
}

