#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

void quickSort(vector<pair<int, double>>& arr, int left, int right) {
    if (left >= right) return;
    
    int pivotIndex = left + (right - left) / 2;
    pair<int, double> pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    
    int storeIndex = left;
    for (int i = left; i < right; ++i) {
        if (arr[i].second > pivot.second || 
           (arr[i].second == pivot.second && arr[i].first < pivot.first)) {
            swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }
    swap(arr[storeIndex], arr[right]);
    
    quickSort(arr, left, storeIndex - 1);
    quickSort(arr, storeIndex + 1, right);
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    map<int, double> stages_user;
    
    int max_elem = *max_element(stages.begin(), stages.end());
    
    for(int i=1; i<= N; ++i){
        stages_user[i] = 0.0;
    }
    
    int num_user = stages.size();
    double proportion;
    
    for(const auto& stage : stages){
        if(stage <= N){
            stages_user[stage]++;
        }
    }
    
    // for(const auto& stage : stages_user){
    //     cout << stage.first << " " << stage.second << endl;
    // }
    
    for(auto& stage : stages_user){
        if(num_user != 0){
            proportion = stage.second / num_user;
            num_user -= stage.second;
            stages_user[stage.first] = proportion;
        }
        else{
            stages_user[stage.first] = 0.0;
        }
        
        // cout << stage.first << " " << stage.second << " " << proportion << endl;
    }
    

    vector<pair<int, double>> v(stages_user.begin(), stages_user.end());
    // 퀵정렬 사용
    quickSort(v, 0, v.size() - 1);
    
    for(auto& elem : v){
        // cout << elem.first << " " << elem.second << endl;
        if(elem.first <= N){
            answer.push_back(elem.first);
        }
    }
    
    return answer;
}