#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H = 10;
int W = 10;

int main() 
{
    int N;
    cin >> N;
    vector<vector<bool>> bool_mask{100, vector<bool>(100, false)};

    for(int i=0; i<N; i++){
      int width, height;

      cin >> width >> height;
      // bool_mask[height::height+H][width::width+W] = true;
      for(int k = height; k < height+H; k++){
        for(int j = width; j < width+W; j++){
          bool_mask[k][j] = true;
        }
      }
    }
    
    int ans = 0;
    for(const auto& n : bool_mask){
      int count_2 = count(n.begin(), n.end(), true);
      ans += count_2;
      // for(const auto& nn : n){
      //   if(nn == true){
      //     ans++;
      //   }
      // }
    }
    
    cout << ans;
    
    return 0;
}