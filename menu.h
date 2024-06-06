
using namespace std;


string allebestellingen(string allchoices) {
	
        stringstream ss(allchoices);
        string item;
        if (!allchoices.empty()) {
            cout << endl << "Dit zijn je eerder bestelde drankjes:";
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
            cout << endl << "Je hebt nog geen andere drankjes besteld";
        }

}
