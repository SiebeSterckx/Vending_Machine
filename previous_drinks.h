#include<iostream>
#include<string>
#include <sstream>


using namespace std;

void previous_drinks(string allchoices) {        
		stringstream ss(allchoices);
        string item;
        if (!allchoices.empty()) {
            cout << endl << "These are your previously ordered drinks:";
            while (getline(ss, item, ',')) {
                istringstream itemStream(item);
                int selectedchoice;
                if (itemStream >> selectedchoice) {
                    if (selectedchoice >= 1 && selectedchoice <= 8) {
                        cout << endl << getOption(selectedchoice);
                    }
                }
            }
        } else {
            cout << endl << "You haven't ordered any drinks yet";
        }
    }
