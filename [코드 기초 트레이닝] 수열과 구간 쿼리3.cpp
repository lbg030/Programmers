#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(const auto& elem : queries){
        int ch_1 = elem[0];
        int ch_2 = elem[1];
        
        int tmp;
        tmp = arr[ch_1];
        arr[ch_1] = arr[ch_2];
        arr[ch_2] = tmp;
        
        // cout << ch_1 << " " << ch_2 << endl
        
    }
    return arr;
}