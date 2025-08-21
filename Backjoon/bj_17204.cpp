#include <iostream>
using namespace std;

int main() 
{
    int N,K;
    cin >> N >> K;
    int point_list[N];
    int point;
    int cnt = 0;
    int max_point = N+1;
    bool flag = false;
    
    for(int i=0; i<N; i++){
      cin >> point;
      point_list[i] = point;
    }
    
    int start = point_list[0];
    cnt++;
    while(max_point){
      max_point--;
      if(start == K){
        flag = true;
        break;
      }
      else{
        start = point_list[start];
        cnt++;
      }
    }
    cnt = flag ? cnt : -1;
    cout << cnt << endl;
    // for(const auto& n : point_list){
    //   cout << n << endl;
    // }
    
    return 0;
}