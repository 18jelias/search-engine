//
//  UserInterface.h
//  SearchEngine
//
//  Created by Hailey Phelps on 4/26/16.
//  Copyright © 2016 Hailey Phelps. All rights reserved.
//

#ifndef UserInterface_h
#define UserInterface_h

#include <stdio.h>
#include <string>
#include <vector>
#include "WordRef.h"
#include <unordered_map>
#include "Page.h"
#include "DocumentParser.h"
#include "WordRef.h"
#include "AVLTreeIndex.h"
#include "fstream"
#include "QueryEngine.h"
#include <fstream>
#include "IndexInterface.h"
#include "HashTable.h"
#include <iostream>

using namespace std;

class UserInterface {
    
private:
    int state;
    const int hash = 1;
    const int avl = 2;
    int structure;
    const string indexFileName = "output.txt";
    const string docInfoFileName = "pages.txt";
    const string wikibookName = "multiplepages.xml";
    unordered_map<string, Page> docInfo;
    DocumentParser parser;
    QueryEngine engine;
    IndexInterface* index = nullptr;
    int numOfPagesParsed;
    int numOfWords;
    
public:
    UserInterface();
    void displayMainMenu();
    void save(string indexFileName);
    void load(string indexFileName);
    int getPages();
    int getNumOfWords();
    int getIndexSize();
    void getTopWords();
    void add(string fileName);
    void clear();
    void displayResults();
    void displayExtendedResults();
    void printDocInfo();
    void saveDocInfo(string fileName);
    void loadDocInfo(string fileName);
    void parseDocument();
    void checkBooleans();
    ~UserInterface();
};

#endif /* UserInterface_h */
