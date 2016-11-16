//
//  SearchEngine.h
//  SearchEngine
//
//  Created by Jacquelyn Elias on 4/26/16.
//  Copyright © 2016 Jacquelyn Elias. All rights reserved.
//

#ifndef SearchEngine_h
#define SearchEngine_h

#include <stdio.h>
#include <string>
#include "UserInterface.h"

using namespace std;

class SearchEngine {
    
private:
    UserInterface ui;
    
public:
    SearchEngine();
    void run();
    ~SearchEngine();
    
    
};

#endif /* SearchEngine_h */
