//Amanda Elvarsdottir
//This file contains the methods mentioned in PG6. head and defines what they do
//This file also contians the main method where we put our inputs.
//This program is very similar to PG4 in many ways where I used some of the methods there
//to help me with the methods here.

#include <iostream>
#include <string>
#include <cstdlib>
#include "HashTable.h"
#include "DRT.h"
#include "PG6.h"
using namespace std;

int main(int argc, char** argv) {
	Studs = new HashTable(100003);
	while (ProcessCommand());
	delete Studs;
	return 0;
}

//This method will process a command.
bool ProcessCommand() { //same as in pg4 except no printing.
	string cmd;
	getline(cin, cmd);
	if (cmd == "EXIT") return false;
	else if (cmd.substr(0, 3) == "ADD") AddCommand(cmd);
	else if (cmd.substr(0, 6) == "REMOVE") RemoveCommand(cmd);
	else if (cmd.substr(0, 6) == "LOOKUP") LookupCommand(cmd);
	else cout << "Invalid command" << endl;
	return true;
}

//This method handles the adding of a command. 
void AddCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* T = Studs->search(k);
	if (T->getdata() == "") {
		Studs->modify(k, "1"); //This will add string k to the library. Opposite of RemoveCommand
		cout << "One copy of " << k << " has been added to the library." << endl;
	}
	else {
		string l = to_string(stoi(T->getdata()) + 1);
		Studs->modify(k, l);
		cout << "One copy of " << k << " has been added to the library." << endl;
	}
}

//This methods Removes the command from the library
void RemoveCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* T = Studs->search(k);
	if (T->getdata() == "")
		cout << "\"" << k << "\" does not exist in the library." << endl;
	else {
		if (T->getdata() == "1") {
			delete T;
			T = Studs->modify(k, "");
		}
		else {
			string d = to_string(stoi(T->getdata()) - 1);
			delete T;
			T = Studs->modify(k, d);
		}
		cout << "1 copy of \"" << k << "\" has been removed from the library." << endl;
		delete T;
	}
}

//This method will look for the command in the library and tell us if it's there or not and then how many copies of it.
void LookupCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* T = Studs->search(k);
	if (T->getdata() == "") { //if there is an empty data
		cout << k << " does not exist in the library." << endl;
	}else{
		cout << "Name:  " << k << "     Copies:       " << T->getdata() << endl;
	}
}