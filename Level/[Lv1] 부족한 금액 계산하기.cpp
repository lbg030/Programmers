#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    // 3 6 9 12
    long long answer = 0;
    for(int i=1; i <= count; ++i){
        answer += (i * price);
        // cout << answer << endl;
    }
    // cout << answer << endl;    
    answer = (money > answer) ? 0 : answer - money;
    return answer;
}