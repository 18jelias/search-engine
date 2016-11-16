//
//  QueryEngine.h
//  SearchEngine
//
//  Created by Michelle Aphaiyarath on 4/22/16.
//  Copyright © 2016 Michelle Aphaiyarath. All rights reserved.
//

#ifndef QueryEngine_h
#define QueryEngine_h

#include "QueryParser.h"
#include "Result.h"
#include <stdio.h>
#include <vector>
#include "AVLTreeIndex.h"
#include "WordRef.h"
#include <unordered_map>
#include "Page.h"
#include <cmath>
#include "IndexInterface.h"

using namespace std;

class QueryEngine
{
private:
    QueryParser* split;
    vector<Result> result;
    unordered_map<string, Page> docInfo;
    unordered_map<string, int> results_map;
    

    
public:
    QueryEngine();
    vector<Result>& search(string& query, IndexInterface*& tree, unordered_map<string, Page>& docInfo);
    
    void mapUnion(unordered_map<string, int>& map1, unordered_map<string, int>& map2, unordered_map<string, int>& endmap);
    void mapIntersection(unordered_map<string, int>& map1, unordered_map<string, int>& map2, unordered_map<string, int>& endmap);
    void mapDifference(unordered_map<string, int>& map1, unordered_map<string, int>& map2, unordered_map<string, int>& endmap);
    
    vector<Result>& setResults(unordered_map<string, int>& refs, string s);
    unordered_map<string, int>& sortResults(unordered_map<string, int>& refs);
    ~QueryEngine();
    
};

#endif /* QueryEngine_h */
