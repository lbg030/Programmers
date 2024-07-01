#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // vector<vector<int>> answer;
    vector<vector<int>> matrix(arr1.size(), vector<int>(arr2[0].size(), 0));
    // matrix[2][2] = 3;
    // cout << arr1[0][0] << " " << arr2[0][0] << endl;
    // cout << arr2[0].size() << endl;
    for(int i=0; i<arr1.size(); i++) {
        for(int j=0; j<arr2[0].size(); j++) {
            matrix[i][j] = arr1[i][j] + arr2[i][j];
            
            // cout << arr1[i][j] << " " << arr2[i][j] << " " << endl;
        }
    }
    return matrix;
}