#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Q: 만약 cycle이 T보다 크면 ?
vector<int> calculate_divisor(int T);
int calculate_gcd(int cycle, const vector<int>& t_divisor);

vector<int> calculate_divisor(int T) {
    vector<int> ans;
    // T의 제곱근까지만 반복하여 약수 찾기
    for(int i = 1; i * i <= T; i++) {
        if(T % i == 0) {
            ans.push_back(i);
            if(i * i != T) {  // 중복 방지
                ans.push_back(T / i);
            }
        }
    }
    sort(ans.begin(), ans.end());  // 정렬된 결과 반환
    return ans;
}

int calculate_gcd(int cycle, const vector<int>& t_divisor) {
    // cycle보다 큰 첫 번째 약수를 찾음
    auto it = lower_bound(t_divisor.begin(), t_divisor.end(), cycle);
    
    // cycle이 가장 작은 약수보다 작은 경우
    if (it == t_divisor.begin()) {
        return *it - cycle;
    }
    // cycle이 가장 큰 약수보다 큰 경우
    if (it == t_divisor.end()) {
        return cycle - t_divisor.back();
    }
    
    // cycle과 가장 가까운 두 약수 사이에 있는 경우
    int right_diff = *it - cycle;
    int left_diff = cycle - *(it-1);
    return min(left_diff, right_diff);
}

int main() 
{
    int N,T;
    vector<int> t_divisor;
    cin >> N >> T;
    int cnt=0;
    
    t_divisor = calculate_divisor(T);
    sort(t_divisor.begin(), t_divisor.end());
    
    // for(const auto& n : t_divisor){
    //   cout << n << endl;
    // }
    
    for(int i=0; i<N; i++){
      int cycle;
      cin >> cycle;
      if(cycle >= T){
        cnt += cycle - T;
      }
      else{
        cnt += calculate_gcd(cycle, t_divisor);
        // cout << "res: " << calculate_gcd(cycle, t_divisor) << endl;
      }
    }
    cout << cnt << endl;
    return 0;
}