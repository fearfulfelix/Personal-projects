#include "filemanagement.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Colours.h"
#include "tools.h"
using namespace std;
namespace sict {

	void view() {
		string line;
		ifstream list;
		int i = 0;
		setColor(15);
		cout << "Finding file...";
		list.open("list.txt", ios::out);
		if (list.is_open()) {
			setColor(10);
			cout << "Found!" << endl;
			system("CLS");
			cout << "***Your to-do list***" << endl;
			setColor(11);
			while (getline(list, line)) {
				i++;
				cout << i << ')' << line << endl;
			}
		}
		else {
			setColor(4);
			cout << "Couldnt find it!" << endl;
			setColor(10);
			cout<< "Create new list?" << endl;
			if (yes()) {
				createlist();
			}
		}
		pause();
	}

	void createlist() {
		setColor(6);
		ofstream list;
		cout << "Creating file...";
		list.open("list.txt");
		if (list.is_open()) {
			cout << " Done!" << endl;
			list.close();
		}
		else {
			cout << "Failed!!" << endl;
		}
	}

	void writelist() {
			char reminder[255];
			setColor(14);
			cout << "Write your reminder here: ";
			setColor(7);
			cin.get();
			cin.getline(reminder, 254);
			cin.clear();
			setColor(11);
			cout << endl << "You wrote: " << endl << '"' << reminder << '"' << endl << "Would you like to add this to your list?" << endl;
			if (yes()) {
				cout << "Writing...";
				ofstream list;
				list.open("list.txt", std::ios_base::app);
				list << reminder << endl;
				list.close();
				cout << "done!" << endl;
			}
			else {
				cout << "Discarded!" << endl;
			}
			pause();
	}

	void finish() {
		string line;
		fstream list;
		string linetodelete;
		int temp;
		int i = 0;
		int j = 0;
		setColor(6);
		list.open("list.txt", ios::out| ios_base::app | ios::in);
		if (list.is_open()) {
			while (getline(list, line)) {
				i++;
				cout << i << ")" << line << endl;
			}
		}
		cout << endl << "Pick a number to delete: ";
		cin >> temp;
		if (cin.fail()) {
			cout << "Something went wrong!";
			cin.clear();
		}
		else {
			i = 0;
			cout << "You picked: ";
			list.clear();
			list.seekg(0, ios::beg);
			while (getline(list,line)) {
				if (i +1 == temp) {
					cout << line << endl << "Is this correct?";
					if (yes()) {
						linetodelete = line;
						list.clear();
						list.seekg(0, ios::beg);
					}
					else {
						cout << "Aborted!" << endl;
					}
					
				}
			i++;
			}
			if (linetodelete[0] != '/0') {
				list.clear();
				list.seekg(0, ios::beg);
				ofstream temp;
				temp.open("temp.txt", std::ios_base::app);
				while (getline(list, line)) {
					if (line != linetodelete) {
						temp << line << endl;
					}
				}
				list.close();
				temp.close();
				remove("list.txt");
				rename("temp.txt", "list.txt");
				cout << "File modified!" << endl;
			}
		}
		pause();
	}

	void deletelist() {
		ifstream list;
		setColor(6);
		int status = 1;
		cout << "Do you really want to delete your list?" << endl;
		if (yes()) {
			setColor(6);
			list.close();
			cout << "Deleting file...";

			if (remove("list.txt") == 0) {
				cout << "File deleted!" << endl;
			}
			else {
				cout << "Unknown error! File not deleted!" << endl;
			}
		}
		pause();
	}
}