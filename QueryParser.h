//
//  QueryParser.h
//  SearchEngine
//
//  Created by Michelle Aphaiyarath on 4/22/16.
//  Copyright © 2016 Michelle Aphaiyarath. All rights reserved.
//

#ifndef QueryParser_h
#define QueryParser_h

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include "porter2_stemmer.h"

using namespace std;

class QueryParser
{
public:
    QueryParser();
    bool isAnd(string& s);
    bool isNot(string& s);
    bool isOr(string& s);
    
    vector<string> parseSearchWords(string& word);
    ~QueryParser();
    
private:
    string query;
};


#endif /* QueryParser_h */
