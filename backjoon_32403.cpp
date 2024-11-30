// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, T;
    cin >> N >> T;

    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        cout << arr[i] << " ";
    }

    return 0;
}