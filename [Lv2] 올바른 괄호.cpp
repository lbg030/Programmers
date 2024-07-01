#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> my_vec;
    for(const auto& item : s){
        if(item == ')'){
            if(my_vec.empty()){
                return false;
            }else{
                my_vec.pop_back();
            }
        }else{
            my_vec.push_back('(');
        }
    }
    answer = (my_vec.empty()) ? true : false;
    return answer;
}