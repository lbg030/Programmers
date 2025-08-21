#include <iostream>
using namespace std;

int solve(int N, int K){
  int cnt = 0;

  for(int i=1; i<N+1; i++){
    if(N%i==0){
      cnt++;
      if(cnt == K){
        return i;
      }
    }
  }
  return 0;
}


int main() 
{
    int N,K, ans;
    cin >> N >> K;
    ans = solve(N,K);
    cout << ans;
    return 0;
}