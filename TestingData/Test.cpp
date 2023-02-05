#include<iostream>
#include<variant>

using namespace std;

int main(){
    variant<int,double,string> test = 1.45;

    cout<<test.index()<<endl;
}