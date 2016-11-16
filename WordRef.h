//
//  WordRef.h
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/12/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#ifndef WordRef_h
#define WordRef_h

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class WordRef
{
    
    friend ostream& operator<<(ostream& os, const WordRef& wr);
    friend ostream& operator<(ostream& os, const WordRef& wr);
    
private:
    string word;
    unordered_map<string,int> refs;
    int frequency = 0;
    
    
public:
    WordRef();
    WordRef(string word, string pageNum);
    WordRef(string word, string pageNum, int frequency);
    WordRef& operator=(const WordRef& wr);
    WordRef(const WordRef& wr);
    bool containsPage(string pageNum);
    void remove(string pageNum);
    void sort();
    void add(string pageNum);
    void add(string pageNum, int frequency);
    string getPageNum();
    string getWord();
    int getFrequency();
    unordered_map<string,int>& getRefs();
    void increaseFrequency(string pageNum);
    void printWord();
    ~WordRef();
    
    
};

#endif /* WordRef_h */
