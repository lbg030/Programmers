#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());
    
    for(const auto& v : d){
        if(sum + v <= budget){
            answer += 1;
            sum += v;
        }
        else{
            return answer;
        }
    }
    return answer;
}