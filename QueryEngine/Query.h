#include<iostream>
#include<vector>
#include<map>
#include <sstream>
#include <algorithm>

using namespace std;

class Query{
    public:
    string select;
    string from;
    string queryId;

    public:
    Query(string queryId){
        this->queryId = queryId;
    }
    virtual void queryDecoder(string queryString) = 0;
    virtual void toString()=0;
};