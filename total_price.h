#include<iostream>
#include<string>
#include <sstream>


using namespace std;

// The '&' should pass back the updated value of totalPrice to the main.cpp
void total_price(string allchoices, double& totalPrice) {
    stringstream ss(allchoices);
    string item;
    while (getline(ss, item, ',')) {
        istringstream itemStream(item);
        int selectedchoice;
        if (itemStream >> selectedchoice) {
            if (selectedchoice >= 1 && selectedchoice <= 8) {
                string option = getOption(selectedchoice);
                cout << endl << option;

                // Here, the price is extracted from the string
                istringstream optionStream(option);
                string word;
                while (optionStream >> word) {
                    // Check if the last character is a euro sign
                    if (!word.empty() && word[word.size() - 1] == '€') {
                        string priceStr = word.substr(0, word.size() - 1); // Remove euro sign

                        // Replace comma with period
                        for (size_t i = 0; i < priceStr.size(); ++i) {
                            if (priceStr[i] == ',') {
                                priceStr[i] = '.';
                            }
                        }
                        // Convert string to double using atof
                        double price = atof(priceStr.c_str()); 
                        totalPrice += price; // Add to total price
                        break; // We found the prize, so we're exiting the while loop
                    }
                }
            }
        }
    }
    cout << endl << endl << "Total price: " << totalPrice << "€" << endl;
}
