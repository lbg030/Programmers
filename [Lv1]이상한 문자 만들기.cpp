#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    // cout << toupper(s) << endl;
    int i = 0;
    int cnt = 0;
    
    while(i<s.size()){
        if(s[i] == ' '){
            ++i;
            answer += ' ';
            cnt = 0;
            continue;
        }
        if(cnt%2==0){
            answer += toupper(s[i]);
        }
        else{
            answer += tolower(s[i]);
        }
        ++i;
        ++cnt;
    }
    
    return answer;
}