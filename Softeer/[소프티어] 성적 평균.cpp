#include <iostream>
#include <iomanip>

using namespace std;

void calculate_mean(const int S[], const int& start, const int& end){
    float summing= 0.00f;
    double res = 0.00f;
    double factor = 100.0;
    
    if(start == end){
        res = S[start-1];
        cout << fixed << setprecision(2) << res << endl;
        return;
    }
    
    for(size_t i =start; i<end+1; ++i){
        summing += S[i-1];
    }
    // cout << "Summing: " << summing << endl;
    res = (double)summing / (end - start + 1);
    cout << fixed << setprecision(2) << res << endl;
    
    // return res;
}

int main(int argc, char** argv)
{
    //N : 학생 수, K: 구간 수
    int N,K, start, end;
    cin >> N >> K;

    // 학생의 성적 S
    int S[N];
    for(size_t i=0; i<N; ++i){
        int s;
        cin >> s;
        S[i] = s;
    }

    for(size_t i=0; i<K; ++i){
        cin >> start >> end;
        calculate_mean(S, start, end);
    }
        
    

   return 0;
}