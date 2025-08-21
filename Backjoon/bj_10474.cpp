#include <iostream>
using namespace std;

int main() 
{
    while(true){
      int N, M;
      cin >> N >> M;
      if(N == 0 & M == 0){
        break;
      }
      int share, divisor;
      
      share = N / M;
      divisor = N % M;
      
      cout << share << " " << divisor << " / " << M << endl;
    }
    return 0;
}