//
//  UserInterface.cpp
//  SearchEngine
//
//  Created by Hailey Phelps on 4/26/16.
//  Copyright © 2016 Hailey Phelps. All rights reserved.
//

#include "UserInterface.h"

UserInterface::UserInterface()
{
    structure = 2;
    numOfPagesParsed = 0;
    numOfWords = 0;
    //parseDocument();
    //load(indexFileName);
    //tree.inOrder();
    //save(indexFileName);
    //loadDocInfo(docInfoFileName);
    //saveDocInfo(docInfoFileName);
    //printDocInfo();
    //cout << "pages parsed; " << numOfPagesParsed << endl;
    //cout <<  "tree size: " << tree.getSize() << endl;

    
}

int UserInterface::getIndexSize()
{
    return index->getSize();
}

void UserInterface::displayMainMenu()
{
    
    bool run = true;
    
    while(run)
    {
        cout << "---------- Search Engine Main Menu ----------" << endl << endl;
        
        cout << "Please select an action" << endl;
        cout << "1: Enter a search query" << endl;
        cout << "2: Display index statistics" << endl;
        cout << "3: Add a file to the index" << endl;
        cout << "4: Choose a data structure (AVL or Hash Table)" << endl;
        cout << "5: Clear index" << endl;
        cout << "6: Exit program" << endl;
        cout << "Enter selection: ";
        cin >> state;
        
        //enter the search query and call search
        if(state == 1)
        {
            cout << endl << endl;
            if(index==nullptr)
            {
                if (structure == avl) {
                    index = new AVLTreeIndex;
                } else if (structure == hash)
                {
                    index = new HashTable;
                    
                }
                cout << "Please wait. Loading index..." << endl;
                add(wikibookName);
                cout << "Load complete" << endl << endl;
            }
            cout << "Please enter search query: " << endl;
            string searchWord = "";
            cin.ignore();
            getline(cin, searchWord, '\n');
            cout << endl;
            cout << "Searching for: " << searchWord << endl;
            vector<Result> r = engine.search(searchWord, index, docInfo);
            for(int i = 0; i < r.size(); i++)cout << r.at(i);
            cout << "Click any key to return to the main menu." << endl;
            cin.ignore();
            /*string input;
            cout << "intput:" << input << endl;
            getline(cin, input);
            for(int i = 0; i < r.size(); i++)
            {
                cout << input << " " << r.at(i).getID() << endl;
                if(input == r.at(i).getID())
                {
                    cout << "HI" << endl;
                    cout << r.at(i).getExtendedResults() << endl;
                }
                    
            } */
            cout << endl;
        }
        
        //displays index stats (# of pages, # of words, top 50 words)
        else if(state == 2)
        {
            cout << endl << endl;
            cout << "Number of pages parsed: " << numOfPagesParsed << endl;
            cout << "Number of words parsed: " << getNumOfWords() << endl;
            cout << "Top 50 most frequent words: " << endl;
            cout << "Click any key to return to the main menu";
            cin.ignore();
            cout << endl;
        }
        
        //prompts for file path to add and call add
        else if(state == 3)
        {
            cout << endl << endl;
            cout << "Please enter the file path to be added: ";
            string addedFile;
            cin.ignore();
            getline(cin, addedFile);
            cout << "Adding " << addedFile << " to index. Please wait." << endl;
            if(index==nullptr)
            {
                if (structure == avl) {
                    index = new AVLTreeIndex;
                } else if (structure == hash)
                {
                    index = new HashTable;
                    
                }
                add(wikibookName);
                add(addedFile);
            }

            cout << "File loaded. Thank you for waiting." << endl;
            cout << "Click any key to return to the main menu";
            cin.ignore();
            cout << endl;
        }
        
        //prompts to choose data structure
        else if(state == 4)
        {
            cout << endl << endl;
            cout << "Please choose a structure" << endl;
            cout << "1: AVL tree (default)" << endl;
            cout << "2: Hash table" << endl;
            cout << "Enter selection: ";
            int chosenStructure;
            cin.ignore();
            cin >> structure;
            
            if(chosenStructure == 1)
            {
                structure = 2;
            }
            
            else if(chosenStructure == 2)
            {
                structure = 1;
            }
            
            else
            {
                cout << "Invalid selection. Please try again: ";
                cin >> structure;
            }
            cout << "Click any key to return to the main menu";
            cin.ignore();
            cout << endl;
        }
        
        //clears entire index
        else if(state == 5)
        {
            cout << "Index has been successfully cleared." << endl;
            cout << "Click any key to return to the main menu";
            cin.ignore();
            cout << endl;
            
        }
        
        //exits the loop
        else if(state == 6)
        {
            run = false;
        }
        
        else
        {
            cout << "Invalid selection. Please try again: " << endl;
            cout << "Click any key to return to the main menu";
            cin.ignore();
            cout << endl;
        }
    }
}

void UserInterface::save(string indexFileName)
{
    ofstream output(indexFileName);
    index->print(output);
    output.close();
}

void UserInterface::load(string indexFileName)
{
    string temp;
    string word;
    string id;
    int frequency;
    string ignore;
    ifstream input(indexFileName);
    while(!input.eof())
    {
        getline(input, temp);
        if(temp != "")
        {
            int startPos = 0;
            int pos = temp.find(' ');
            word = temp.substr(0,pos);
            startPos = pos+1;
            pos = temp.find(' ', startPos);
            id = temp.substr(startPos, pos-startPos);
            startPos = pos+1;
            frequency = stoi(temp.substr(startPos));
            index->insert(word, id, frequency);
        }
        
    }
    input.close();
}

int UserInterface::getNumOfWords()
{
    return numOfWords;
}

int UserInterface::getPages()
{
    return 0;
}

void UserInterface::getTopWords()
{
    
}

void UserInterface::add(string fileName)
{
    pair<int, int> x=parser.parse(fileName, index, docInfo);
    numOfPagesParsed +=x.first;
    numOfWords +=x.second;

}

void UserInterface::clear()
{
    
}

void UserInterface::displayResults()
{
    
}

void UserInterface::printDocInfo()
{
    auto it = docInfo.begin();
    for(int i = 0; i < docInfo.size() && it != docInfo.end(); i++)
    {
        cout << it->first << "|" << it->second;
        ++it;
    }
}

void UserInterface::saveDocInfo(string fileName)
{
    ofstream output(fileName);
    auto it = docInfo.begin();
    for(int i = 0; i < docInfo.size() && it != docInfo.end(); i++)
    {
        output << it->first << "|" << it->second;
        ++it;
    }

    output.close();
    
}

void UserInterface::loadDocInfo(string fileName)
{
    string temp;
    string id;
    string title;
    string username;
    string date;
    int numOfWords;
    
    ifstream input(fileName);
    while(!input.eof())
    {
        getline(input, temp);
        if(temp != "")
        {
            int startPos = 0;
            int pos = temp.find('|');
            id = temp.substr(0,pos);
            startPos = pos+1;
            pos = temp.find('|', startPos);
            title = temp.substr(startPos, pos-startPos);
            startPos = pos+1;
            pos = temp.find('|', startPos);
            username = temp.substr(startPos, pos-startPos);
            startPos = pos+1;
            pos = temp.find('|', startPos);
            date = temp.substr(startPos, pos-startPos);
            startPos = pos+1;
            numOfWords = stoi(temp.substr(startPos));
            docInfo.insert(pair<string, Page>(id, Page(id, username, title, date, numOfWords)));
        }
        
    }
    input.close();
}

void UserInterface::parseDocument()
{
    add(wikibookName);
}

void UserInterface::checkBooleans()
{
    unordered_map<string, int> map1;
    unordered_map<string, int> map2;
    unordered_map<string, int> map3;
    
    map1.insert(pair<string, int>("23", 10));
        map1.insert(pair<string, int>("42", 2));
        map1.insert(pair<string, int>("3", 4));
        map1.insert(pair<string, int>("324", 4));
        map1.insert(pair<string, int>("1", 2));
        map1.insert(pair<string, int>("24", 5));
        map1.insert(pair<string, int>("48", 3));
        map1.insert(pair<string, int>("40", 2));
        map1.insert(pair<string, int>("9", 7));
        map1.insert(pair<string, int>("10", 12));
        map1.insert(pair<string, int>("3", 4));
    
        map2.insert(pair<string, int>("23", 8));
        map2.insert(pair<string, int>("34", 3));
        map2.insert(pair<string, int>("2653", 20));
        map2.insert(pair<string, int>("10", 4));
        map2.insert(pair<string, int>("48", 2));
        map2.insert(pair<string, int>("4", 5));
        map2.insert(pair<string, int>("15", 15));
    
    engine.mapDifference(map1, map2, map3);
    
    auto it = map3.begin();
    while(it != map3.end())
    {
        cout << "Page num: " << it->first << " frequency: " << it->second << endl;
        it++;
    }
    
}

UserInterface::~UserInterface()
{
    
}
