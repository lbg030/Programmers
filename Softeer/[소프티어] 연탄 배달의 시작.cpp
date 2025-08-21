#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    int N,minimum, current,prev, dis, min_dis;
    min_dis=1000000;
    cin >> N;
    cin >> prev;
    for(int i=1;i<N;i++){
        cin >> current;
        dis = current - prev;
        if(dis < min_dis){
            minimum = 1;
            min_dis = dis;
        }
        else if(dis == min_dis){
            minimum++;
        }
        prev = current;
    }
    cout << minimum << endl;
   return 0;
}