//
//  DocumentProcessor.cpp
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/14/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#include "DocumentProcessor.h"

DocumentProcessor::DocumentProcessor()
{
    loadStopWords();
}

void DocumentProcessor::loadStopWords()
{
    ifstream in;
    in.open("stopwords.txt");
    string s;
    while(!in.eof())
    {
        in >> s;
        stopWords.insert(s);
    }
}


inline bool DocumentProcessor::isStop(string& word)
{
    if(word.size() <= 15)
    {
        unordered_set<string>::iterator it;
        it = stopWords.find(word);
        if(it != stopWords.end()) //how to error check
        {
            return true;
        } else
        {
            return false;
        }
    } else
    {
        return false;
    }
}


string& DocumentProcessor::stem(string& word)
{
    return word;
}

string DocumentProcessor::cleanDate(string date)
{
    return "0";
}

string& DocumentProcessor::toAlpha(string& word)
{
    string merp = "skjfd&lt;lkdjfd";
    for(int i = 0; i < merp.length(); i++)
    {
        if(ispunct(word[word.size()-1]))
        {
            //erase
        }
        if(merp[i] == '&')
        {
            int split = merp.find_first_of(';', i);
            cout << split << endl;
            merp = merp.erase(i, split-i);
        } else if (!isalpha(merp[i]))
        {
            merp.erase(i, 1);

        }
    }
    cout << merp << endl;
    return word;
}


string& DocumentProcessor::cleanWord(string& word)
{
    word[0]=tolower(word[0]);
    if(ispunct(word[word.size()-1])) word.erase(word.size()-1);
    //transform(word.begin(), word.end(), word.begin(), ::tolower);
    //Way to ignore line if begins with | or # or {
    if(isalpha(word[0]) && !isStop(word) && word.size()>1 && word.size()<20)
    {
        Porter2Stemmer::stem(word);
        return word;
    } else
    {
        word = "0";
        return word;
    }

}

DocumentProcessor::~DocumentProcessor()
{
    
}