#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same = 0;
    int diff = 0;
    
    stack<char> stack;
    
    for(int i=0; i<s.size(); ++i){
        char elem = s[i];
        // 비어있을 때에는 그냥 push
        if(stack.empty()){
            // cout << "Stack empty! i: " << i << " push elem: " << elem << endl;
            stack.push(elem);
            same++;
        }
        // 비어있지 않을 때
        else{
            // 같을 때에도 stack에 push
            if(stack.top() == elem){
                same++;
            }
            // 같지 않을 때
            else{
                diff++;
            }
        }
        if(same == diff){
            // 초기화
            same = 0;
            diff = 0;
            answer++;
            stack.pop();
        }
    }
    answer += (stack.empty()) ? 0 : 1;
    return answer;
}