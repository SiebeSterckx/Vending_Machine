#include<iostream>
#include<string>


using namespace std;

void betaalCash(double cashsaldo, double totalPrice) {
cout << "Je hebt gekozen om cash te betalen" << endl;
				double betaald = 0.0;
				while (cashsaldo < totalPrice){
					cout << "Voer het bedrag in dat je insteekt (geef een getal met '.' als komma)" << endl;
					cin >> betaald;
					cout << "\033[2J\033[1;1H";
					cashsaldo += betaald;
					
					if (cashsaldo < totalPrice) {
            			cout << "Je moet nog " << totalPrice - cashsaldo << "€ betalen." << endl;
        			}
        			if (cashsaldo > totalPrice) {
            			cout << "Betaling succesvol uitgevoerd!";
            			cout << endl << "Hier is je wisselgeld van " <<cashsaldo-totalPrice<< "€" << endl;
        			}
        			if (cashsaldo == totalPrice) {
            			cout << "Je hebt gepast betaald";
            			cout << endl << "Betaling succesvol uitgevoerd!" << endl;
        			}
				}
}
