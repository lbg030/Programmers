#include <string>
#include <vector>
#include <cctype> 
#include <iostream>

using namespace std;

bool check(string s){
    cout << s.size() << endl;
    if(s.size() != 6 && s.size() != 4) return false;
    for(int i = 0; i<s.size(); ++i){
        if(isdigit(s[i]) == 0){
            // cout << isdigit(s[i]) << " " << i << endl;
            return false;
        }
    }
    return true;
}


bool solution(string s) {
    bool answer = check(s);
    return answer;
}