#include <iostream>
using namespace std;

int main() 
{
  int N;
  cin >> N;
  int cnt = 0;
  
  while(true){

    if(N % 5 == 0){
      cnt += (N / 5);
      break;
    }
    
    if(N < 2){
      cnt = -1;
      break;
    }
    
    N -= 2;
    cnt++;

    // cout << N << " " << cnt << endl;
  }
  cout << cnt << endl;
  return 0;
}