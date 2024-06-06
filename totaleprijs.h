#include<iostream>
#include<string>
#include <sstream>


using namespace std;

// De '&' dient op de geüpdated waarde van totalPrice terug door te geven aan de main.cpp
void totalePrijs(string allchoices, double& totalPrice) {
	
	    stringstream ss(allchoices);
        string item;
		while (getline(ss, item, ',')) {
            istringstream itemStream(item);
            int selectedchoice;
            if (itemStream >> selectedchoice) {
                if (selectedchoice >= 1 && selectedchoice <= 8) {
                    string option = getOption(selectedchoice);
                    cout << endl << option;

                    // Hier wordt de prijs uit de string gehaald
                    istringstream optionStream(option);
                    string word;
                    string lastToken;
                    while (optionStream >> word) {
                        lastToken = word;
                    }
                    
                    // Controleren of het laatste token een prijs is
                    if (!lastToken.empty() && lastToken[lastToken.size() - 1] == '€') {
                        string priceStr = lastToken.substr(0, lastToken.size() - 1); // Verwijder het euroteken

                        // Vervang komma door punt
                        for (size_t i = 0; i < priceStr.size(); ++i) {
                            if (priceStr[i] == ',') {
                                priceStr[i] = '.';
                            }
                        }
                        // Zet string om naar double m.b.v. atof
                        double price = atof(priceStr.c_str()); 
                        totalPrice += price; // Add to total price
                    }
                }
            }
        }
        cout << endl << endl << "Totale prijs: " << totalPrice << "€" << endl;
}
