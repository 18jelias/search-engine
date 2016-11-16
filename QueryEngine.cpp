//
//  QueryEngine.cpp
//  SearchEngine
//
//  Created by Michelle Aphaiyarath on 4/22/16.
//  Copyright © 2016 Michelle Aphaiyarath. All rights reserved.
//

#include "QueryEngine.h"

QueryEngine::QueryEngine()
{
    split = new QueryParser();
}

vector<Result>& QueryEngine::search(string& query, IndexInterface*& index, unordered_map<string, Page>& docInfo)
{
    this->docInfo = docInfo;
    vector<string> s = split->parseSearchWords(query);
    string word = s[0];
    if(s.size() == 1 && (!split->isAnd(s.at(0)) && !split->isNot(s.at(0)) && !split->isOr(s.at(0))))
    {
        WordRef r = index->get(s[0]);
        auto it = r.getRefs().begin();
        while(it != r.getRefs().end())
        {
            results_map.insert(pair<string, int>(it->first,it->second));
            ++it;
        }
        return setResults(results_map, query);
        
    } else if(s.size() == 1 && (split->isAnd(s.at(0)) || split->isNot(s.at(0)) || split->isOr(s.at(0))))
    {
        Result r;
        vector<Result> l;
        l.push_back(r);
        cout << "Please enter a proper query" << endl;
        return l;
    } else if(s.size() > 1 && word[0] != '(' && (!split->isAnd(s.at(0)) && !split->isNot(s.at(0)) && !split->isOr(s.at(0))))
    {
        Result r;
        vector<Result> l;
        l.push_back(r);
        cout << "Please enter a proper query" << endl;
        return l;
    }
    int i = 0;
    while(i < s.size())
    {
        if(split->isAnd(s.at(i)))
        {
            ++i;
            while(i < s.size() && (!split->isOr(s.at(i)) || !split->isNot(s.at(i))))
            {
                WordRef r = index->get(s.at(i));
                if(results_map.empty())
                {
                    WordRef m = index->get(s.at(i+1));
                    mapIntersection(r.getRefs(), m.getRefs(), results_map);
                    ++i;

                } else
                {
                    mapIntersection(r.getRefs(), results_map, results_map);
                }
                ++i;
            }
        } else if(split->isOr(s.at(i)))
        {
            while(i < s.size() && (!split->isAnd(s.at(i)) || !split->isNot(s.at(i))))
            {
                WordRef r = index->get(s.at(i));
                if(results_map.empty())
                {
                    auto it = r.getRefs().begin();
                    while(it != r.getRefs().end())
                    {
                        results_map.insert(pair<string, int>(it->first,it->second));
                        ++it;
                    }
                } else
                {
                    mapUnion(r.getRefs(), results_map, results_map);
                }
                ++i;
            }
        } else if(split->isNot(s.at(i)))
        {
            while(i < s.size() && (!split->isOr(s.at(i)) || !split->isAnd(s.at(i))))
            {
                
                WordRef r = index->get(s.at(i));
                if(results_map.empty())
                {
                    cout << "Please enter other search terms in order to complete a not search" << endl;
                } else
                {
                    mapDifference(r.getRefs(), results_map, results_map);
                }
                ++i;
            }
        }
    }
    return setResults(results_map, query);
}

vector<Result>& QueryEngine::setResults(unordered_map<string, int>& refs, string s)
{
    result.clear();
    
    auto it = refs.begin();
    for(int i = 0; i < refs.size() && it !=refs.end(); i++)
    {
        Result r(it->first, it->second, s);
        Page n = docInfo.at(it->first);
        r.setDate(n.getDate());
        r.setTitle(n.getTitle());
        r.setUsername(n.getUsername());
        r.setPageWordCount(n.getNumOfWords());
        r.setFrequency(it->second);
        result.push_back(r);
        ++it;
    }
    
    return result;
}

unordered_map<string, int>& QueryEngine::sortResults(unordered_map<string, int>& refs)
{
    return results_map;
}

void QueryEngine::mapUnion(unordered_map<string, int>& map1, unordered_map<string, int>& map2, unordered_map<string, int>& endmap)
{
    auto it1 = map1.begin();
    auto it2 = map2.begin();
    
    while (it1 != map1.end())
    {
        endmap.insert(pair<string, int>(it1->first, it1->second));
        it1++;
    }
    while(it2 != map2.end())
    {
        auto findIt = map1.find(it2->first);
        if(findIt != map1.end())
        {
            endmap.at(it2->first) = it2->second + findIt->second;
        } else
        {
            endmap.insert(pair<string, int>(it2->first,it2->second));
        }
        it2++;
    }
}

void QueryEngine::mapIntersection(unordered_map<string, int>& map1, unordered_map<string, int>& map2, unordered_map<string, int>& endmap)
{
    auto it1 = map1.begin();
    
    while (it1 != map1.end())
    {
        auto findIt = map2.find(it1->first);
        if(findIt != map2.end())
        {
            endmap.insert(pair<string, int>(it1->first, min(findIt->second, it1->second)));
        }
        it1++;
    }
}

void QueryEngine::mapDifference(unordered_map<string, int>& map1, unordered_map<string, int>& map2, unordered_map<string, int>& endmap)
{
    auto it1 = map1.begin();
    auto it2 = map2.begin();
    
    while(it1 != map1.end())
    {
        auto findIt = map2.find(it1->first);
        if(findIt == map2.end())
        {
            endmap.insert(pair<string, int>(it1->first, it1->second));
        }
        it1++;
    }
    
    while(it2 != map2.end())
    {
        auto findIt = map1.find(it2->first);
        if(findIt == map1.end())
        {
            endmap.insert(pair<string, int>(it2->first, it2->second));
        }
        it2++;
    }
}

QueryEngine::~QueryEngine()
{
    
}