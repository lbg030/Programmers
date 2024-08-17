#include <string>
#include <vector>

using namespace std;


long long solution(int n) {
    long long answer = 0;
    int pibo[n+1];
    pibo[0] = 1;
    pibo[1] = 1;
    for(int i=2; i<n+1; ++i){
        pibo[i] = (pibo[i-2] + pibo[i-1]) % 1234567;
    }
    answer = pibo[n];
    return answer;
}