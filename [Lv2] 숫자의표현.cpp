#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for(int i = 1; i < 1 + ((int) n / 2); ++i){
    // for(int i = 1; i < 2; ++i){
        int sum = i;
        int p = 0;
        while(sum < n){
            // cout << "I: " << i <<" Sum : " << sum << " p: " << p << endl;
            sum += (i + p + 1);
            // cout << "Sum : " << sum << endl;
            if(sum == n){
                // cout << "i : " << i << " p : " << p << endl;
                answer += 1;
            }
            ++p;
        }   
    }
    
    return answer;
}