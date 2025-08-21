#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath> //C++

using namespace std;

pair<unsigned long long, unsigned long long>divide(int n){
    unsigned long long share = n / 3;
    unsigned long long divided = n % 3;
    return make_pair(share, divided);
}

unsigned long long solution(int n) {
    unsigned long long answer = 0;
    string res = "";
    pair<unsigned long long, unsigned long long> cur;
    if(n<3){
        return n;
    }
    while(n >= 3){
        cur = divide(n);
        n = cur.first;
        res.insert(0, to_string(cur.second));
    }
    res.insert(0, to_string(cur.first));
    reverse(res.begin(), res.end());
    // cout << res << endl;
    // cout << res << endl;
    int cnt = 0;
    for(int i=res.size()-1;i>=0;--i){
        // cout << "Res: " <<res[i] -'0' << endl;
        // cout << "Pow: " << pow(3, cnt) << endl;
        answer += (pow(3, cnt) * (res[i] - '0'));
        cnt++;
        // cout << "Answer: "<< answer << endl;
    }
    
    return answer;
}