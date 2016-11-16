//
//  Page.h
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/14/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#ifndef Page_h
#define Page_h

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Page {
    
    friend ostream& operator<<(ostream& os, const Page& p);
private:
    string id;
    string username;
    string title;
    string date;
    int numOfWords;
    
    
public:
    Page();
    Page(string id, string username, string title, string date, int numOfWords);
    void setID(string id);
    string getID();
    void setUsername(string username);
    string getUsername();
    void setTitle(string title);
    string getTitle();
    void setDate(string date);
    string getDate();
    void setNumOfWords(int num);
    int getNumOfWords();
    ~Page();
    
};

#endif /* Page_h */
