//Amanda Elvarsdottir
// Header file for HashNode that declares the prototypes for the methods defined in HashNode.cpp
#ifndef _HASHNODE_
#define _HASHNODE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "DRT.h"
using namespace std;

class DRT;
class HashNode {
private:
    string k; string d;
    HashNode* next;
public:
    HashNode(string key, string data); //constructor
    ~HashNode(); //destructor
    DRT* searchnode(string key); 
    DRT* addnode(string key, string data);
    string getk();
    string getd();
    DRT* remove(string key, HashNode* p, HashNode*& listhead);
    void setnext(HashNode* p);
};

#endif