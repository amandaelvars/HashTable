//Amanda Elvarsdottir
//This is the base class that has methods for the DRT classes.
#ifndef _DATABASE_
#define _DATABASE_

#include <string>
#include "DRT.h"
using namespace std;

class DRT;
class Database {

public:

    virtual DRT* search(string key) = 0;

    virtual DRT* modify(string key, string data) = 0;

};

#endif