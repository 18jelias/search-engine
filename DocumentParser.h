//
//  DocumentParser.h
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/13/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#ifndef DocumentParser_h
#define DocumentParser_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "tinyxml2.h"
#include "WordRef.h"
#include <vector>
#include "Page.h"
#include "DocumentProcessor.h"
#include "AVLTreeIndex.h"
#include "IndexInterface.h"
#include <sstream>

using namespace std;
using namespace tinyxml2;

class DocumentParser {
    
private:
    XMLDocument doc;
    XMLNode* pos = &doc;
    
public:
    DocumentParser();
    pair<int,int> parse(string fileName, IndexInterface*& index, unordered_map<string, Page>& docInfo);
    string setID();
    string setWords();
    string setUsername();
    string setDate();
    string setTitle();
    ~DocumentParser();
    
    
    
};

#endif /* DocumentParser_h */
