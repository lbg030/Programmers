#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    string watermelon[2] = {"수", "박"};
    // bool div_two;
    
    for(int i = 0; i<n; ++i){
        // div_two = (i % 2 == 0) ? True : False;
        answer += (watermelon[i % 2]);
    }
    
    return answer;
}