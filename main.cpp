#include<iostream>
#include <string>
#include <sstream>
// Needed for atof
#include <cstdlib>

#include "menu.cpp"
#include "previous_drinks.h"
#include "total_price.h"
#include "pay_cash.h"



using namespace std;

// Function to convert integer to string using stringstream
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Main program
int main()
{
    char menucall = 'N';
    int menuchoice;
    string allchoices;


	// CHOICE SCREEN ------------------------------
    while (menucall == 'N' or menucall == 'n')
    {
        // Calling header file 'menu'
        menu();
        // All previously selected drinks are displayed, calling header file 'previous_drinks'
        previous_drinks(allchoices); 

        // The chosen item is stored in the 'menuchoice' variable
        cout << endl << endl << "What do you want? (1-8) ";
        cin >> menuchoice;
        // All selected items are stored in the 'allchoices' variable
        if (!allchoices.empty()) {
            allchoices += ",";
        }
        
        cout << "\033[2J\033[1;1H";

		// Show which choice has been made + ask to finalize or to still order
        if (menuchoice >= 1 && menuchoice <= 8) {
        // Extracting the stock count from the selected drink option
        string selectedOption = getOption(menuchoice);
        string stockPrefix = "Stock: ";
        int stockIndex = selectedOption.find(stockPrefix);
        if (stockIndex != string::npos) {
            int stockStart = stockIndex + stockPrefix.length();
            int endStockIndex = selectedOption.find_first_not_of("0123456789", stockStart);
            if (endStockIndex == string::npos) {
                endStockIndex = selectedOption.length();
            }
            string stockStr = selectedOption.substr(stockStart, endStockIndex - stockStart);
            int stock = atoi(stockStr.c_str());

            // Decreasing the stock count by 1
            if (stock > 0) {
                allchoices += intToString(menuchoice) + ",";
                cout << "You have chosen for: " << selectedOption << endl;
                stock--;

                // Updating the option string with the new stock count
                string updatedStock = selectedOption.substr(0, stockStart) + intToString(stock) + selectedOption.substr(endStockIndex);
                // Overwrite new string
                options[menuchoice - 1] = updatedStock;

            } else {
                cout << "The drink with number " << menuchoice << " is no longer in stock" << endl;
            }
        }
    } else {
        cout << "Invalid choice! There is no drink with number " << menuchoice << endl;
    }
        cout << endl << "Would you like to complete the order? (Y/N) ";
        cin >> menucall;
        cout << "\033[2J\033[1;1H";
    }


    // PAYMENT SCREEN ------------------------------
    if (menucall == 'Y' or menucall == 'y') {
    	// Check if transaction is successful, if not, the while loop will be executed again
    	while (true) {
        // All purchased drinks must be displayed
        char paymentmethod;
        double cashbalance = 0.0;
        char enoughcardbalance;
        double totalPrice = 0.0;
        if (!allchoices.empty()) {
        cout << "These are the drinks you ordered:";
        //cout << allchoices;
        
        // Provides total price and all selected drinks, calling header file 'total_price'
        total_price(allchoices, totalPrice);
        
        cout << endl << "Do you pay by card or cash? (R/S) ";
        cin >> paymentmethod;
        cout << "\033[2J\033[1;1H";

        // Pay in cash
        if (paymentmethod == 'S' || paymentmethod == 's') {
            	pay_cash(cashbalance, totalPrice); // Calling header file 'pay_cash'
				break; // Exit while loop if payment was successful
			} 
         
        // Pay by card
        else if (paymentmethod == 'R' || paymentmethod == 'r') {
            cout << "You have chosen to pay by card";
            cout << endl << "Do you have "<<totalPrice<< "€ in your bank account? (Y/N) ";
            cin >> enoughcardbalance;
            cout << "\033[2J\033[1;1H";

            if (enoughcardbalance == 'Y' || enoughcardbalance == 'y') {
                cout<< "Payment successfully processed!" << endl << endl;
                break; // Exit while loop if payment was successful
            } else if (enoughcardbalance == 'N' || enoughcardbalance == 'n') {
                cout << "Payment aborted due to insufficient balance!";
                cout << endl << "CHOOSE ANOTHER PAYMENT METHOD"<< endl << endl;
                // The loop is not interrupted, so the payment screen is shown again
            } else {
                cout << "The program was terminated due to an incorrect input :/" << endl << endl;
                break; // Exit while loop on incorrect input
            }
        } else {
            cout << endl << "The program was terminated due to an incorrect input :/" << endl << endl;
            break; // Exit while loop on incorrect input
        	}	
        
    	} else {
            cout << endl << "The program was terminated due to an incorrect input2 :/" << endl << endl;
             break; // Exit while loop on incorrect input
        	}
    	} 
	}
	
	// Terminate the program if anything other than Y, y, N, or n is typed
	else {
        cout << "The program was terminated due to an incorrect input :/" << endl << endl;
    }

	// END ------------------------------
    system("pause");
    return 0;
}

