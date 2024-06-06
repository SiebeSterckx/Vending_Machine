#include<iostream>
#include <string>
#include <sstream>
//#include <vector>
//#include <stdexcept>
// Nodig voor atof
#include <cstdlib>

#include "menu.cpp"
#include "vorigedrankjes.h"
#include "totaleprijs.h"
#include "betaalcash.h"



using namespace std;

// Functie om int om te zetten naar string m.b.v. stringstream
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Hoofdprogramma
int main()
{
    char menucall = 'N';
    int menuchoice;
    string allchoices;


	// Keuze pagina ------------------------------
    while (menucall == 'N' or menucall == 'n')
    {
        // Oproepen van subprogramma menu
        menu();
        // Hier worden alle eerder gekozen drankjes getoond
        vorigeDrankjes(allchoices); 

        // Het gekozen item word in de 'menuchoice' variabele gestoken
        cout << endl << "Wat is jouw keuze? (1-8) ";
        cin >> menuchoice;
        // Alle gekozen items worden in de 'allchoices' variabele gestoken
        if (!allchoices.empty()) {
            allchoices += ",";
        }
        allchoices += intToString(menuchoice);
        cout << "\033[2J\033[1;1H";

		// Laat zien welke keuze er gemaakt is + vraag om af te ronden
        if (menuchoice >= 1 && menuchoice <= 8) {
            cout << "Je hebt gekozen voor: " << getOption(menuchoice) << endl;
        } else {
            cout << "Ongeldige keuze! Er bestaat geen drankje met nummer " << menuchoice << endl;
        }
        cout << endl << "Wil je de bestelling afronden? (Y/N) ";
        cin >> menucall;
        //cout << "Debug: menucall = " << menucall << endl;
        cout << "\033[2J\033[1;1H";
    }


    // Betaal pagina ------------------------------
    if (menucall == 'Y' or menucall == 'y') {
    	// Check of transactie gelukt is, als dit niet gelukt is wordt de while lus opnieuw uitgevoerd
    	while (true) {
        // Hier moeten alle gekochte drankjes getoond worden
        char betalingswijze;
        double cashsaldo = 0.0;
        char kaartsaldo;
        double totalPrice = 0.0;
        if (!allchoices.empty()) {
        cout << "Dit zijn de drankjes die je hebt besteld:";
        
        // Geeft totale prijs en alle geselecteerde drankjes
        totalePrijs(allchoices, totalPrice);
        
        cout << endl << "Betaal je met kaart of cash? (K/C) ";
        cin >> betalingswijze;
        cout << "\033[2J\033[1;1H";

        // Betaal cash
        if (betalingswijze == 'C' || betalingswijze == 'c') {
            	betaalCash(cashsaldo, totalPrice);
				break; // Verlaat de while lus als de betaling geslaagd is
			} 
         
        // Betaal met kaart
        else if (betalingswijze == 'K' || betalingswijze == 'k') {
            cout << "Je hebt gekozen om te betalen met de kaart";
            cout << endl << "Heb je "<<totalPrice<< "€ op je bankrekening staan? (Y/N) ";
            cin >> kaartsaldo;
            cout << "\033[2J\033[1;1H";

            if (kaartsaldo == 'Y' || kaartsaldo == 'y') {
                cout<< "Betaling succesvol uitgevoerd!" << endl;
                break; // Verlaat de while lus als de betaling geslaagd is
            } else if (kaartsaldo == 'N' || kaartsaldo == 'n') {
                cout << "Betaling afgebroken door een ontoereikend saldo!";
                cout << endl << "KIES EEN ANDERE BETAALMETHODE"<< endl << endl;
                // De lus wordt niet onderbroken, dus het betalingsscherm wordt opnieuw getoond
            } else {
                cout << "Programma werd afgesloten door een verkeerde invoer :/" << endl;
                break; // Verlaat de lus bij verkeerde invoer
            }
        } 
        // Verkeerde invoer voor betalingswijze
        else {
            cout << endl << "Programma werd afgesloten door een verkeerde invoer :/" << endl;
            break; // Verlaat de lus bij verkeerde invoer
        }
        
    	} 
    } 
	}
	
	// Zeg dat programma afsluit als er iets anders dan Y,y,N,n getypt werd.
	else {
        cout << "Programma werd afgesloten door een verkeerde invoer :/" << endl;
    }

	// Einde ------------------------------
    return 0;
}

