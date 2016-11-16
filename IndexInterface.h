//
//  IndexInterface.h
//  IndexInterface
//
//  Created by Hailey Phelps on 4/28/16.
//  Copyright © 2016 Hailey Phelps. All rights reserved.
//


// Index interface that calls the functions depending on whether the user is using an AVL tree or a hash table.

#ifndef IndexInterface_h
#define IndexInterface_h

#include <string>
#include <iostream>
#include "WordRef.h"
#include <stdio.h>
#include <fstream>

using namespace std;

class IndexInterface{
public:
    virtual ~IndexInterface() {};
    virtual void insert(string& word, string& pageNum) = 0;
    virtual void insert(string& word, string& pageNum, int& frequency) = 0;
    virtual bool contains(string& word) = 0;
    virtual WordRef& get(string& word) = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual void clear() = 0;
    virtual void print(ofstream& x) = 0;
   
    
};


#endif /* IndexInterface_h */