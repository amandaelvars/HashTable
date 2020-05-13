//Amanda Elvarsdottir
// Header file for DRT that declares the prototypes for the methods defined in DRT.cpp

#ifndef _DRT_
#define _DRT_
#include <string>
using namespace std;

class DRT {

private:
    string data;
    string next;
    string prev;

public:

    DRT(string d, string n, string p);
    string getdata();
    string getnext();
    string getprev();

};



#endif
