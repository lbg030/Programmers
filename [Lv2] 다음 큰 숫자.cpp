#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 15 -> 7, 1 -> 3, 1 -> 1, 1

pair<string, int> decimal_to_bin(int n){
    string res;
    string char_res;
    int share, residual, one_cnt = 0;
    while(n > 1){
        share = n / 2;
        residual = n % 2;
        char_res = to_string(residual);
        res += char_res;
        n = share;
        
        if(n == 1){
            res += (to_string(n));
            one_cnt++;
        }
        if(char_res == "1"){
            one_cnt++;
        }
    }
    reverse(res.begin(), res.end());
    return make_pair(res, one_cnt);
}



int solution(int n) {
    int answer = 0;
    int one_cnt = 0;
    pair<string, int> bin, check_nextnum;
    bin = decimal_to_bin(n);
    // cout << bin.first << endl;
    // cout << "One: "<< bin.second << endl;
    one_cnt = bin.second;
    while(true){
        n++;
        check_nextnum = decimal_to_bin(n);
        // cout << "n: " << n << " one: " << check_nextnum.second << endl;
        if(one_cnt == check_nextnum.second){
            answer = n;
            break;
        }
    }
    return answer;
}