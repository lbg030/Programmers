#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int is_fair = 1;
    
    for(int i=left; i<right+1; ++i){
        int is_fair = 1;
        for(int j = 1; j < (int) sqrt(i) + 1; ++j){
            // cout << "i: " << i << " sqrt(i) " << (int) sqrt(i) << endl;
            if(i % j == 0){
                is_fair *= -1;
                if(j < (i / j)){
                    // cout << i / j << " " << j << endl;
                    is_fair *= -1;
                }
            }
        }
        // cout << i * is_fair << endl;
        answer += (i * is_fair);
    }
    
    return answer;
}