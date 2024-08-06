#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    int N,ans_x,ans_y,cur_x,cur_y;
    cin >> N;
    cin >> ans_x >> ans_y;
    for(int i=1;i<N;++i){
        cin >> cur_x >> cur_y;
        if(cur_y < ans_y){
            ans_x = cur_x;
            ans_y = cur_y;
        }
    }
    cout << ans_x << " " << ans_y;
   return 0;
}