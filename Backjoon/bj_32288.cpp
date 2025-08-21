#include <iostream>
#include <map>
using namespace std;

int main(){
    int N;
    string inputs;
    map<char, char> m;
    m['I'] = 'i';
    m['l'] = 'L';
    
    cin >> N;
    cin >> inputs;
    
    for(int i=0; i<N; i++){
        char inp = inputs[i];
        inputs[i] = m[inp];
    }
    cout << inputs;
    return 0;
}