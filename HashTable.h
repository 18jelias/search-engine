//
//  HashTable.h
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/14/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//  Referenced https://www.quora.com/How-do-I-implement-hash-table-and-hash-map-in-c++

#ifndef HashTable_h
#define HashTable_h


#include <stdio.h>
#include "WordRef.h"
#include <functional>
#include <string>
#include <cstdlib>
#include "AVLTree.h"
#include "IndexInterface.h"

using namespace std;


class HashTable: public IndexInterface {

    
private:
 AVLTree** table;
 int size;
    
public:
    HashTable()
    {   
        size = 10;
        table = new AVLTree*[10];
 
    }
    
    HashTable(int size)
    {
        this->size = size;
        table = new AVLTree*[10];
        
    }
    
    bool contains(string& word)
    {
        int hashVal = (int) hash<string>{}(word);
        hashVal = hashVal % size;
        if(table[hashVal] == nullptr)
        {
            return false;
        } else
        {
            WordRef r = table[hashVal]->get(word);
            if(r.getWord() == word)
            {
                return true;
            } else
            {
                return false;
            }
        }
            
    }
    
    bool isEmpty()
    {
        int currentSize = getSize();
        if(currentSize == 0)
            return true;
        else
            return false;
    }
    
    int getSize()
    {
        int indexSize = 0;
        for(int i = 0; i < size; i++)
        {
            if(table[i] != nullptr)
            {
                indexSize+=table[i]->getSize();
            }
        }
        return indexSize;
    }
    
    void insert(string& word, string& pageNum)
    {
        int hashVal = (int) hash<string>{}(word);
        hashVal = hashVal % size;
        if (table[hashVal] == nullptr)
        {
            table[hashVal] = new AVLTree;
            table[hashVal]->insert(word, pageNum);
            
        }
        else
            table[hashVal]->insert(word, pageNum);
        
    }
    
    void insert(string& word, string& pageNum, int& frequency)
    {
        int hashVal = (int) hash<string>{}(word);
        hashVal = hashVal % size;
        if (table[hashVal] == nullptr)
        {
            table[hashVal] = new AVLTree;
            table[hashVal]->insert(word, pageNum);
            
        }
        else
            table[hashVal]->insert(word, pageNum, frequency);
        
    }

    
    void clear()
    {
        delete[] this;
    }
            

    WordRef& get(string& word)
    {
        int hashVal = (int) hash<string>{}(word);
        hashVal = hashVal % size;
        if (table[hashVal] == nullptr)
        {
            cout << "Value was not found" << endl;
            WordRef r;
            return r;
            
        }
        else
            return table[hashVal]->get(word);
    }
    
    void print(ofstream& x) {
        
        
    }
    
    ~HashTable()
    {
        
    }
    
};


#endif /* HashTable_h */
