//
//  Result.cpp
//  SearchEngine
//
//  Created by Michelle Aphaiyarath on 4/22/16.
//  Copyright © 2016 Michelle Aphaiyarath. All rights reserved.
//


#include "Result.h"

Result::Result()
{
    
}

Result::Result(string id, int frequency, string word)
{

    this->id = id;
    this->frequency = frequency;
    this->word = word;
}

string Result::getExtendedResults()
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLNode* pos = &doc;
    
    string fileName = "multiplepages.xml";
    
    if(doc.LoadFile(fileName.c_str()) == 0)
    {
        pos = pos->FirstChildElement("mediawiki")->FirstChildElement("page");
        while(pos->FirstChildElement("id")->GetText() != id)
        {
            pos = pos->NextSiblingElement("id");
        }
        return pos->FirstChildElement("text")->GetText();
    } else{
        return "0";
    }
}

string Result::getID()
{
    return id;
}

void Result::setID (string id)
{
    this -> id = id;
}

string Result::getDate()
{
    return date;
}

void Result::setDate (string date)
{
    this -> date = date;
}

string Result::getTitle()
{
    return title;
}

void Result::setTitle (string title)
{
    this -> title = title;
}

string Result::getUsername()
{
    return username;
}

void Result::setUsername (string username)
{
    this -> username = username;
}

string& Result::getWord()
{
    return word;
}

void Result::setWord (string& Word)
{
    this -> word = word;
}

void Result::setFrequency(int frequency)
{
    this->frequency = frequency;
}

int Result::getFrequency()
{
    return frequency;
}

void Result::setPageWordCount(int frequency)
{
    this->frequency = wordCount;
}
ostream& operator<<(ostream& os, const Result& r)
{
    //Out of range error with vector
    os << "Title: " << r.title << "(ID: " << r.id << ")" << endl;
    os << "Author: " << r.username << endl;
    os << "This page contains " << r.frequency << " occurences of '" << r.word << "'." << endl<<endl;
    
    return os;
}

void Result::findRelevancy()
{
    
}

ostream& operator<(ostream& os, const Result& r)
{
    os << r.wordCount;
    return os;
}

ostream& operator>(ostream& os, const Result& r)
{
    os << r.wordCount;
    return os;
}

Result::~Result()
{
    
}
