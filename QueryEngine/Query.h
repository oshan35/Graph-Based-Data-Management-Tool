#include<iostream>
#include<vector>
#include<map>
#include <sstream>
#include <algorithm>

using namespace std;

class Query{
    protected:
    vector<string> select;
    string from;

    public:
    virtual void queryDecoder(string queryString) = 0;
};