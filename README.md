Final Project Search Engine Classes, Data Members, and Member Functions

=================================================================================================================

Class SearchEngine:
Task: To run the program.
Data Members:
    UserInterface* ui
MemberFunctions:
    void run()

=================================================================================================================

Class UserInterface:
Task: Ask the user if they want maintenance or interactive mode. Print the number of pages/words and top 50 words, add documents, clear index, ask what structure, display results, display extended results, load and save persisted index.
Data Members:
    int state
    const int state_maintenance = 1
    const int state_interactive = 1
    const string persistedIndex
Member Functions:
    void displayMainMenu()
    void save(string fileName)
    void load(string fileName)
    int getPageStats()
    int getWordStats()
    vector<string> getTopWords()
    void add(string fileName)
    void clear()
    void displayResults()
    void displayExtendedResults()
    void saveDocInfo(string fileName)

=================================================================================================================

Class DocumentParser:
Task: Removes the stop words, stems the words, computes the frequency as it parses the documents and retrieves list of words/frequency per document
Data Members:
    vector<WordRef> ref
Member Functions:
    string removeStop(sring word)
    string stem(string word)
    int getFrequency(string word)
    vector<WordRef> parse(string titleName)
    map getDocInfo()
    void getID()
    void getText()
    void getUsername()
    void getDate()
    void getTitle()

=================================================================================================================

Class QueryEngine:
Task: Sends query to parser and returns vector of results, ranks results, and fills index
Data Members:
    vector<results> result
    IndexInterface* if
    QueryParser* split
    map docInfo
Member Functions:
    void loadIndex(string fileName, string structure)
    void createIndex(vector<WordRef>, string structure)
    void sortResults(vector<results> result)
    void setResults(vector<WordRef>)
    map getDocInfo()
    vector<results> search(string query)

=================================================================================================================

Class QueryParser:
Task: Checks for different types of searches. Tokenizes the query string. Sends info back to engine.
Data Members:
    string query
    vector<string> searchWords
Member Functions:
    bool ifAND(string query)
    bool ifNOT(string query)
    bool ifOR(string query)
    void setSearchWords()
    vector<string> getSearchWords()

=================================================================================================================

Class Result:
Task: Stores basic information for the result such as title, username, date, and search word
Data Members:
    string username
    string title
    string date
    string word
    int id
Member Functions:
    void setWord(string word)
    string getWord()
    void setTitle(string name)
    string getTitle()
    void setDate(string date)
    string getDate()
    void setID(int id)
    int getID()
    vector<string> getExtendedResult()
    void setUserName(string name)
    string getUserName()

=================================================================================================================

Class IndexInterface:
Task: Offer basic functionality for the index data structures
Member Functions:
    int getSize()
    bool isEmpty()
    void add(WordRef word)
    void clear()
    void delete(string word)
    bool contains(string word)
    string toString()
    WordRef get(string name)

=================================================================================================================

Class WordRef:
Task: To store frequency and page number for each word as well as sort by frequency
Data Members:
    string word
    vector<pair<int, int>> refs
Member Functions:
    void add(int, int)
    void remove(int)
    void sort()

=================================================================================================================
# search-engine
