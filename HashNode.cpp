//Amanda Elvarsdottir
//This file will define what we declare in the header file HashNode.h

#include <iostream>
#include <string>
#include <cstdlib>
#include "HashNode.h"
#include "DRT.h"
using namespace std;

//Constructor
HashNode::HashNode(string key, string data) {

	k = key; d = data; next = NULL;
}

//Destructor
HashNode::~HashNode() { //destructor

	delete next;
}

//searches the tree for the given key
DRT* HashNode::searchnode(string key) {

	if (k == key) return new DRT(d, "", "");
	if (!next) return new DRT("", "", "");
	return next->searchnode(key);
}

//It it'll add if this is the key, if not it'll send add to the next node.
DRT* HashNode::addnode(string key, string data) {
	if (k == key) {
		DRT* T = new DRT(d, "", "");
		d = data;
		return T;
	}
	else if (next) { //If there is a next, but also we we don't have a key
		return next->addnode(key, data);
	}
	else { //if we don't have a key or a next.
		next = new HashNode(key, data);
		next->setnext(NULL);
		return new DRT("", "", "");
	}
}

string HashNode::getk() { return k; }
string HashNode::getd() { return d; }

//Same as with the addnode, if it is key then remove, else is should tell next node to remove.
DRT* HashNode::remove(string key, HashNode* p, HashNode*& listhead) {
	if (k == key) {
		DRT* T = new DRT(this->getd(), "", "");
		if (p == NULL) { //if we are on a head
			if (next) { //if we have a next noe
				listhead = next;
				next = NULL;
				delete this;
				return T;
			}else{
				listhead = NULL;
				delete this;
				return T;
			}
		}else { //If this is not the head
			if (next) {
				p->setnext(next);
				next = NULL;
				delete this;
				return T;
			}else{
				p->setnext(NULL);
				delete this;
				return T;
			}
		}
	}else{ //if there is no next, and the node isn't in this list.
		if (!next) {
			return new DRT("", "", "");
		}else{ //then it should force the next node to remove.
			return next->remove(key, this, listhead);
		}
	}
	
}


void HashNode::setnext(HashNode* p) { next = p; }