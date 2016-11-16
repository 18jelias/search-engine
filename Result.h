//
//  Result.h
//  SearchEngine
//
//  Created by Michelle Aphaiyarath on 4/22/16.
//  Copyright © 2016 Michelle Aphaiyarath. All rights reserved.
//

#ifndef Result_h
#define Result_h

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "tinyxml2.h"

using namespace std;

class Result
{
public:
    friend ostream& operator<(ostream& os, const Result& r);
    friend ostream& operator>(ostream& os, const Result& r);
    
    // getters and setters
    
    Result();
    Result(string id, int frequency, string query);
    string getID();
    void setID (string id);
    string getDate();
    void setDate (string date);
    string getTitle();
    void setTitle (string title);
    string getUsername();
    void setUsername (string username);
    string& getWord();
    void setFrequency(int frequency);
    int getFrequency();
    void setWord (string& Word);
    void setPageWordCount(int frequency);
    string getExtendedResults();
    void findRelevancy();
    friend ostream& operator<<(ostream& os, const Result& r);
    ~Result();
    
private:
    string id;
    string date;
    string query;
    string title;
    string username;
    int frequency;
    string word;
    string extendedResults;
    int wordCount;
    float relevancy;
};

#endif /* Result_h */
