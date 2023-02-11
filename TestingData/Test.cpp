#include<iostream>
#include<variant>
#include <string>
#include<vector>
using namespace std;


int main() {
    vector<string> inputLines;
    std::string input;
    cout<<"cluster>";
    while (std::getline(std::cin, input)) {
        if(input == "END"){
            break;
        }else if(input.back()==';'){
            inputLines.push_back(input);
            break;
        }
        inputLines.push_back(input);
    }

    for(int i=0;i<inputLines.size();i++){
        cout<<inputLines[i]<<endl;
    }
    return 0;
}