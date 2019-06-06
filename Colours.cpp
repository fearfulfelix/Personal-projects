#include "Colours.h"
#include <Windows.h>

using namespace std;
namespace sict {
	void setColor(int i)
	{
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(color, i);
	}
}