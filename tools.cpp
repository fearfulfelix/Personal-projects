#include "tools.h"
#include "Colours.h"
#include <iostream>
using namespace std;
namespace sict {

	int getint(int min, int max)
	{
		int i;
		int j = 0;

		while (j != 1) {
			setColor(14);
			cout << "your choice: ";
			setColor(7);
			cin >> i;
			setColor(14);
			if (i > max || i < min) {
				cout << "thats not valid! Try again!" << endl;
			}
			else {
				j = 1;
			}

		}
		return i;
	}
	void pause(){
		setColor(7);
		system("PAUSE");
		system("CLS");
	}
	bool yes()
	{
		char dump[5];
		setColor(14);
		cout << "(Y/N)" << endl;
		setColor(7);
		cin.clear();
		cin >> dump;
		if (dump[0] != 'y' && dump[0] != 'Y') {
			return false;
		}
		return true;
	}
}