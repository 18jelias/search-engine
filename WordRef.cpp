//
//  WordRef.cpp
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/12/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#include "WordRef.h"

WordRef::WordRef()
{
    
}

WordRef::WordRef(string word, string pageNum)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    this->word = word;
    refs.insert(make_pair(pageNum, 1));
    frequency++;
    
}

WordRef::WordRef(string word, string pageNum, int frequency)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    this->word = word;
    refs.insert(make_pair(pageNum, frequency));
    this->frequency+=frequency;
    
}

WordRef& WordRef::operator=(const WordRef& wr)
{
    refs.clear();
    this->word = wr.word;
    this->frequency = wr.frequency;
    this->refs = wr.refs;
    /*for(int i = 0; i < wr.refs.size(); i++)
    {
        this->refs.insert(make_pair(wr.refs.at(pageNum).first, wr.refs.at(pageNum).first));
    }*/
    return *this;
}

WordRef::WordRef(const WordRef& wr)
{
    this->word = wr.word;
    this->frequency = wr.frequency;
    this->refs = wr.refs;
    /*for(int i = 0; i < wr.refs.size(); i++)
    {
        this->refs.insert(wr.refs.at(i));
    }*/
}

void WordRef::remove(string pageNum)
{
    frequency = frequency - refs.at(pageNum);
    refs.erase(pageNum);
}

void WordRef::sort()
{
    //how to sort frequencies
}

void WordRef::add(string pageNum)
{
    unordered_map<string, int>::iterator it = refs.find(pageNum);
    if(it != refs.end())
    {
        refs.at(pageNum) = refs.at(pageNum)+1;
    } else
    {
        refs.insert(make_pair(pageNum, 1));
    }
    frequency++;
}

void WordRef::add(string pageNum, int frequency)
{
    unordered_map<string, int>::iterator it = refs.find(pageNum);
    if(it != refs.end())
    {
        refs.at(pageNum) = refs.at(pageNum)+frequency;
    } else
    {
        refs.insert(make_pair(pageNum, frequency));
    }
    this->frequency+=frequency;
}

unordered_map<string,int>& WordRef::getRefs()
{
    return refs;
}

string WordRef::getPageNum()
{
    return 0;
}

string WordRef::getWord()
{
    return word;
}

int WordRef::getFrequency()
{
    return frequency;
}
       
bool WordRef::containsPage(string pageNum)
{
    unordered_map<string, int>::iterator it = refs.find(pageNum);
    if(it != refs.end())
    {
       return true;
    } else
    {
        return false;
    }
}

void WordRef::increaseFrequency(string pageNum)
{
    unordered_map<string,int>::iterator it = refs.find(pageNum);
    if(it != refs.end())
    {
        refs.at(pageNum) = refs.at(pageNum)++;
    } else
    {
        refs.insert(make_pair(pageNum, 1));
    }
    frequency++;
}

void WordRef::printWord()
{
    auto it = refs.begin();
    for(int i = 0; i < refs.size() && it != refs.end(); i++)
    {
        cout << it->second << " occurence of " << word << " on page " << it->first << endl;
        ++it;
    }
    cout << "Total frequency of " << word << ": " << frequency << endl;
}

ostream& operator<<(ostream& os, const WordRef& wr)
{
    auto it = wr.refs.begin();
    for(int i = 0; i < wr.refs.size() && it !=wr.refs.end(); i++)
    {
        os << wr.word << " " << it->first << " " << it->second << endl;
        ++it; 
    }
    return os;
}

ostream& operator<(ostream& os, const WordRef& wr)
{
    os << wr.word;
    return os;
}

WordRef::~WordRef()
{
    
}