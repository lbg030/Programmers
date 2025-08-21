#include <string>
#include <vector>
#include <iostream>

using namespace std;

int lcm(int a, int b, int max_common){
    return a * b / max_common;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int min_mul = 1;
    int max_common = 1;

    for(int i=1; i<=n; ++i){
        if(n % i == 0 and m % i ==0){
            max_common = i;
        }
    }
    min_mul = lcm(n,m,max_common);

    answer.push_back(max_common);
    answer.push_back(min_mul);
    return answer;
}
