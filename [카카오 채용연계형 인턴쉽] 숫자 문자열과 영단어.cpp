#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cctype>
#include <utility>

using namespace std;

string alpha_string[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

pair<bool, char> check(string tmp){
    for(int j = 0; j < 10; ++j) {
        if(alpha_string[j] == tmp) {
            return make_pair(true, (j + '0'));
        }
    }
    return make_pair(false, '-1');
}

int solution(string s) {
    string answer = "";
    string tmp = "";
    
    for(int i = 0; i < s.size(); ++i) {
        
        if(isdigit(s[i])) {
            answer += s[i];
        } else {
            tmp += s[i];
        }
        
        if(tmp != "") {
            pair<bool, char> res= check(tmp);

            if(res.first){
                answer += res.second;
                tmp = "";
            }
        }
    }

    unsigned long long res = stoull(answer);
    
    return res;
}