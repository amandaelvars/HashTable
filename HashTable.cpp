//Amanda Elvarsdottir
//This file will define the methods we declared in the header file HashTable.h
#include <iostream>
#include <string>
#include <cstdlib>
#include "HashTable.h"
#include "DRT.h"
#include "HashNode.h"
using namespace std;

HashTable::HashTable(int sz) { //Constructor

    HS = sz;
    table = new HashNode * [HS];
    for (int i = 0; i < HS; i++)
        table[i] = NULL;
}

HashTable::~HashTable() { //Destructor

    for (int i = 0; i < HS; i++)
        delete table[i];
    delete[] table;
}

int HashTable::hf(string key) {

    int val = 0;
    for (int i = 0; i < key.length(); i++) {
        int ch = key[i];
        if (ch == 0) ch = 256;
        val = (val * 256 + ch) % HS;
    }
    return val;
}

//This will add a node to the table, similar to adding in HashNode
DRT* HashTable::add(string key, string data) { //very similar to sample code
    int j = hf(key);
    if (table[j] == NULL) {
        DRT* T = new DRT("", "", "");
        table[j] = new HashNode(key, data);
        return T;
    }else{
        return table[j]->addnode(key, data);
    }
}

//searches the tree for the given key
DRT* HashTable::searchnode(string key) { 

    int val = hf(key);
    if (!table[val]) return new DRT("", "", "");
    return table[val]->searchnode(key);
}

//removes an item from the list
DRT* HashTable::remove(string key) { 
    int j = hf(key);
    if (!table[j]) { //If there is no node on the table, it should just return.
        return new DRT("", "", "");
    }else{ //else remove
        return table[j]->remove(key, NULL, table[j]);
    }
}

//Database search method
DRT* HashTable::search(string key) { 
      //checks to see if we're searching on the empty string, if so builds a DRT with first() and last (), otherwise calls searchnode

    if (key == "") return new DRT("", "", "");
    return searchnode(key);
}

//Database modify method
DRT* HashTable::modify(string key, string data) {

    if (key == "") return new DRT("", "", "");
    if (data == "") return remove(key);
    return add(key, data);
}