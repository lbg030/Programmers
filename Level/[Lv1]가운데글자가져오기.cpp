#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = s.size() / 2;
    // cout << idx << endl;
    // cout << s.substr(idx-1, 2);
    (s.size() % 2 == 0) ? answer += s.substr(idx-1,2) : answer += (s[idx]);
    return answer;
}

int main() {
    cout << solution("abcde") << endl;
    cout << solution("qwer") << endl;

    return 0;
}
