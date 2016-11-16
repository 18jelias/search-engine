//
//  QueryParser.cpp
//  SearchEngine
//
//  Created by Michelle Aphaiyarath on 4/22/16.
//  Copyright © 2016 Michelle Aphaiyarath. All rights reserved.
//

#include "QueryParser.h"

QueryParser::QueryParser()
{
}

bool QueryParser::isAnd(string& s)
{
    if (s == "AND" || s == "aND")
    {
        return true;
    } else
    {
        return false;
    }
}

bool QueryParser::isNot(string& s)
{
    if (s == "NOT" || s == "nOT")
    {
        return true;
    } else
    {
        return false;
    }
}

bool QueryParser::isOr(string& s)
{
    if (s == "OR" || s == "oR")
    {
        return true;
    } else
    {
        return false;
    }
}

vector<string> QueryParser::parseSearchWords(string& word)
{
    vector<string> searchWords;
    string token;
    stringstream ss (word);
    while (ss >> token)
    {
        token[0]=tolower(token[0]);
        Porter2Stemmer::stem(token);
        searchWords.push_back (token);
    }
    return searchWords;
}

QueryParser::~QueryParser()
{
    
}
