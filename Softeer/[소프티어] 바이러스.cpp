#include<iostream>


using namespace std;
const int thres = 1000000007;

int main(int argc, char** argv)
{
    // K를 ull로 선언하는게 포인트
    unsigned long long K;
    int P,N;
    
    cin >> K >> P >> N;

    while(N>0){
        K *= P;
        N -= 1;
        if(K > thres){
            K %= thres;
        }
    }
    
    cout << K << endl;
    return 0;
}