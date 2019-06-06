#include <iostream>
#include "Colours.h"
#include "menu.h"
using namespace std;
using namespace sict;

	int main() {
		int i = 0;
		setColor(10);
		while (i == 0) {
			i = menu();
		}
		return 0;
	}