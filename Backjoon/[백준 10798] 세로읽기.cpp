#include <iostream>
#include <vector>


using namespace std;
int main(){
    vector<vector<char>> matrix;

    for(int i=0; i<5; i++){
        string str;
        cin >> str;
        matrix.push_back(vector<char>(str.begin(), str.end()));
    }
    
    int max_size = 0;
    for(int i=0; i<matrix.size(); i++){
        if(max_size < matrix[i].size()){
            max_size = matrix[i].size();
        }
    }
    
    string result;
    for(int i=0; i< max_size; i++){
        for(int j=0; j<matrix.size(); j++){
            if(matrix[j].size() > i){
                result += matrix[j][i];
            }
        }
    }
    cout << result << endl;
}