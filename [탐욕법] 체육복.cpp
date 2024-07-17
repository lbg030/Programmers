#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 'lost'와 'reserve'에 동시에 있는 학생 제거
    vector<int> new_lost, new_reserve;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i : lost) {
        if (find(reserve.begin(), reserve.end(), i) != reserve.end()) {
            reserve.erase(find(reserve.begin(), reserve.end(), i));
        } else {
            new_lost.push_back(i);
        }
    }
    
    for (int i : reserve) {
        if (find(lost.begin(), lost.end(), i) == lost.end()) {
            new_reserve.push_back(i);
        }
    }
    
    lost = new_lost;
    reserve = new_reserve;
    
    // 체육복을 빌려주는 로직
    for (int i : reserve) {
        if (find(lost.begin(), lost.end(), i - 1) != lost.end()) {
            lost.erase(find(lost.begin(), lost.end(), i - 1));
        } else if (find(lost.begin(), lost.end(), i + 1) != lost.end()) {
            lost.erase(find(lost.begin(), lost.end(), i + 1));
        }
    }
    
    answer = n - lost.size();
    return answer;
}
