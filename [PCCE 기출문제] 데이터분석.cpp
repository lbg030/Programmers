#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<vector<int>> pre_data;
    map<string, int> sort_idx;
    
    sort_idx["code"] = 0;
    sort_idx["date"] = 1;
    sort_idx["maximum"] = 2;
    sort_idx["remain"] = 3;
    
    // int preprocessed_idx = sort_idx[val_ext]
    int sorting_method = sort_idx[ext];
    for (const auto& elem : data) {
        if(elem[sorting_method] < val_ext){
            pre_data.push_back(elem);
        }

    }

    int sorted = sort_idx[sort_by];
    sort(pre_data.begin(), pre_data.end(), [sorted](const vector<int>& a, const vector<int>& b) {
        return a[sorted] < b[sorted];
    });
    
    return pre_data;
}