//
//  DocumentParser.cpp
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/13/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#include "DocumentParser.h"

DocumentParser::DocumentParser()
{

}


pair<int,int> DocumentParser::parse(string fileName, IndexInterface*& index, unordered_map<string, Page>& docInfo)
{
    int numOfParsedPages = 0;
    int numOfWords = 0;
    if(doc.LoadFile(fileName.c_str()) == 0)
    {
        DocumentProcessor processor;
        pos = &doc;
        pos = pos->FirstChildElement("mediawiki")->FirstChildElement("page");
        while(pos != nullptr)
        {
            numOfParsedPages++;
            string id = setID();
            string words = setWords();
            if(words != "No words")
            {
                istringstream stringStream(words);
                do{
                    string s;
                    stringStream >> s;
                    s=processor.cleanWord(s);
                    if(s!= "0")
                    {
                        index->insert(s,id);
                        numOfWords++;
                    }
                } while (stringStream);
                docInfo.insert(pair<string, Page>(setID(), Page(setID(), setUsername(), setTitle(), setDate(), numOfWords)));
            }
            pos=pos->NextSiblingElement("page");
        }
    }
    return pair<int,int>(numOfParsedPages, numOfWords);
}


string DocumentParser::setID()
{
    if(pos->FirstChildElement("id"))
    {
        XMLElement* ID = pos->FirstChildElement("id")->ToElement();
        return ID->GetText();
    } else
    {
        return "No ID";
    }
}

string DocumentParser::setWords()
{
    //How to deal with empty text
    if((pos->FirstChildElement("revision")->FirstChildElement("text")->GetText()!=nullptr) && (pos->FirstChildElement("revision")->FirstChildElement("text")))
    {
        XMLElement* text = pos->FirstChildElement("revision")->FirstChildElement("text")->ToElement();
        return text->GetText();
    } else
    {
        return "No words";
    }
}

string DocumentParser::setUsername()
{
    if(pos->FirstChildElement("revision")->FirstChildElement("contributor")->FirstChildElement("username"))
    {
        XMLElement* username = pos->FirstChildElement("revision")->FirstChildElement("contributor")->FirstChildElement("username")->ToElement();
        return username->GetText();
    } else
    {
        return "No username";
    }
    
}

string DocumentParser::setDate()
{
    if(pos->FirstChildElement("revision")->FirstChildElement("timestamp"))
    {
        XMLElement* date = pos->FirstChildElement("revision")->FirstChildElement("timestamp")->ToElement();
        return date->GetText();
    } else{
        return "No date";
    }
}

string DocumentParser::setTitle()
{
    if(pos->FirstChildElement("title"))
    {
        XMLElement* title = pos->FirstChildElement("title")->ToElement();
        return title->GetText();
    } else{
        return "No title";
    }
}

DocumentParser::~DocumentParser()
{
    
}