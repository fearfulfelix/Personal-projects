#include <iostream>
#include "menu.h"
#include "tools.h"
#include "filemanagement.h"
#include "Colours.h"

using namespace std;
namespace sict {
	int menu() {
		cout << "Felix's To-Do List V1.A" << endl;
		setColor(3);
		cout << "1)View List" << endl
			<< "2)Add Item" << endl 
			<< "3)Delete Item" << endl 
			<< "4)Delete List" << endl 
			<< "5)Exit" << endl;
		switch (getint(1, 5)) {
		case 1: view(); break;
		case 2: writelist(); break;
		case 3: finish(); break;
		case 4: deletelist(); break;
		case 5: cout << "quit?" << endl;
			if (yes()) return 1;
			pause();
			break;
		default: cout << endl << "Yikes! You shouldnt be seeing this!" << endl; break;
		}
		return 0;
	}
}