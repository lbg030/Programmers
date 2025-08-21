#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> split(string &inputs) {
    stringstream ss(inputs);
    string tmp;
    vector<int> ans;
    while (getline(ss, tmp, ' ')) {
        ans.push_back(stoi(tmp));
    }
    return ans;
}

int main() {
    int N, M;
    int cnt = 0;
    cin >> N >> M;
    cin.ignore(); // 버퍼에 남은 '\n' 제거
    
    vector<int> inputs;
    string inp;
    getline(cin, inp); // 한 줄 입력
    inputs = split(inp); // 공백 기준으로 숫자 분리
    
    for (int i = 0; i < inputs.size(); i++) {
        int cur = 0; // 합산값 초기화
        
        // j는 i부터 시작 (부분합이 i부터 시작되도록 수정)
        for (int j = i; j < inputs.size(); j++) {
            cur += inputs[j];
            if (cur == M) {
                cnt++;
                break; // 조건을 만족하면 종료
            }
            if (cur > M) {
                break; // 합이 M을 초과하면 더 이상 확인할 필요 없음
            }
        }
    }
    
    cout << cnt << endl; // 조건을 만족하는 개수 출력
    
    return 0;
}
