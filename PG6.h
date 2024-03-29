//Amanda Elvarsdottir
// Header file for PG6 that declares the prototypes for the methods defined in PG6.cpp
#ifndef _PG6_
#define _PG6_

#include <string>
#include <cstdlib>
#include "Database.h"
using namespace std;

Database* Studs;

int main(int argc, char** argv);
bool ProcessCommand();
void Print();
void RPrint();
void AddCommand(string cmd);
void RemoveCommand(string cmd);
void LookupCommand(string cmd);

#endif