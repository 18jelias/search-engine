//
//  Page.cpp
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/14/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//


#include "Page.h"

Page::Page()
{
    
}

Page::Page(string id, string username, string title, string date, int numOfWords)
{
    this->id = id;
    this->username = username;
    this->title = title;
    this->date = date;
    this->numOfWords = numOfWords;
}

void Page::setID(string id)
{
    this->id = id;
}

string Page::getID()
{
  return id;
}

void Page::setUsername(string username)
{
    this->username = username;
}

string Page::getUsername()
{
    return username;
}

void Page::setTitle(string title)
{
    this->title = title;
}

string Page::getTitle()
{
    return title;
}

void Page::setDate(string date)
{
    this->date = date;
}

string Page::getDate()
{
    return date;
}

void Page::setNumOfWords(int num)
{
    this->numOfWords = num;
}

int Page::getNumOfWords()
{
    return numOfWords;
}

ostream& operator<<(ostream& os, const Page& p)
{
    os << p.title << "|" << p.username << "|" << p.date << "|" << p.numOfWords << endl;
    return os;
}

Page::~Page()
{
    
}