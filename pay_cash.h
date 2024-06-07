#include<iostream>
#include<string>


using namespace std;

void pay_cash(double cashbalance, double totalPrice) {
cout << "You have chosen to pay in cash" << endl;
				double payed = 0.0;
				while (cashbalance < totalPrice){
					cout << "Enter the amount you're putting in (provide a number with '.' as decimal)" << endl;
					cin >> payed;
					cout << "\033[2J\033[1;1H";
					cashbalance += payed;
					
					if (cashbalance < totalPrice) {
            			cout << "You still need to pay " << totalPrice - cashbalance << "€" << endl;
        			}
        			if (cashbalance > totalPrice) {
            			cout << "Payment has been successful!";
            			cout << endl << "Here is your change of " <<cashbalance-totalPrice<< "€" << endl << endl;
        			}
        			if (cashbalance == totalPrice) {
            			cout << "You have paid appropriately";
            			cout << endl << "Payment has been successful!" << endl << endl;
        			}
				}
}
