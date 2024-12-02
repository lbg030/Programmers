#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Q: 만약 cycle이 T보다 크면 ?
vector<int> calculate_divisor(int T);
int calculate_gcd(int cycle, vector<int> t_divisor);

vector<int> calculate_divisor(int T){
  vector<int> ans = {1, T};
  vector<bool> check(T/2, true);
  for(int i=2; i<= (T / 2); i++){
    // if i 가 2고, T가 12라면, -> 2,4,6 3,6
    if(T % i == 0){
      for(int j=1; i*j<=T/2; j++){
        if(T % (i*j) == 0 && check[i*j]){
          check[i*j] = false;
          ans.push_back(i*j);
        }
      }
    }
  }
  return ans;
}

int calculate_gcd(int cycle, vector<int> t_divisor){

  vector<int> res;
  // T: 14 || n: 1,2,7,14 || cycle : 4 || 3,2, 3
  for(const auto& n : t_divisor){
    res.push_back(abs(cycle - n));
  }
  return *min_element(res.begin(), res.end());
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