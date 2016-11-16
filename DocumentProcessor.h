//
//  DocumentProcessor.h
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/14/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#ifndef DocumentProcessor_h
#define DocumentProcessor_h

#include <stdio.h>
#include <string>
#include "WordRef.h"
#include <map>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include "porter2_stemmer.h"

using namespace std;

class DocumentProcessor {
    
private:
    unordered_set<string> stopWords;
    
public:
    DocumentProcessor();
    inline bool isStop(string& word);
    void loadStopWords();
    string& stem(string& word);
    string cleanDate(string date);
    string& cleanWord(string& word);
    string& toAlpha(string& word);
    ~DocumentProcessor();
    
};

#endif /* DocumentProcessor_h */
