#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

// A의 min값과 B의 max값의 곱
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    for(int i=0; i<A.size(); ++i){
        // cout << A[i] << " " << B[i] << endl;
        answer += (A[i] * B[i]);
    }
    return answer;
}