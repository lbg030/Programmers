#include <iostream>
#include <vector>
// #include <algorithm>

int T = 3;
using namespace std;

int main() {
    // vector<int> matrix;
    
    // while(T--){
    //     int N;
    //     cin >> N;
    //     matrix.push_back(N);
    // }
    // sort(matrix.begin(), matrix.end());
    
    // cout << matrix[1] << endl;


// 버블 정렬
    int arr[3];
    for(int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<T;i++){
        for(int j=0; j<T-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << arr[1] << endl;
}