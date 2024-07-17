#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;

bool compared(string a, string b){
    return a<b;
}


string solution(string X, string Y) {
    string answer = "";
    map<char, int> X_count_map;
    map<char, int> Y_count_map;
    vector<char> my_vec;
    
    for(int i=0; i<10; ++i){
        my_vec.push_back(i + '0');
    }
    
    // for(const auto& elem: my_vec){
    //     cout << elem << endl;
    // }
    
    // int char_count_num = count(X.begin(), X.end(), '1');
    // cout << char_count_num << endl;
    for(const auto& elem: my_vec){
        int x_count = count(X.begin(), X.end(), elem);
        int y_count = count(Y.begin(), Y.end(), elem);
        // cout << x_count << " " << y_count << endl;
        
        if(x_count !=0 and y_count !=0){
            if(x_count > y_count){
                for(int i=0; i<y_count; ++i){
                    answer += elem;
                }
            }else{
                for(int i=0; i<x_count; ++i){
                    answer += elem;
                }
            }
        }
    }
    
    int zero_cnt = count(answer.begin(), answer.end(), '0');
    
    if(answer.empty()){
        answer = "-1";
        return answer;
    }
    else if(zero_cnt == answer.size()){
        answer = "0";
        return answer;
    }
    else{
        sort(answer.begin(), answer.end(), greater<>());
    }
    
    return answer;
}