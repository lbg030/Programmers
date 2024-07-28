#include<iostream>
#include <vector>

// using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Initial Code
int main(int argc, char** argv)
{
    int num;
    int voted;
    int share;
    int remainder;
    const int divided = 5;
    
    string five_over = "++++";
    string five_under = "|";
    
    cin >> num;
    for(int i=0; i<num; ++i){
        cin >> voted;
        share = voted / divided;
        remainder = voted % divided;
        
        for(int j=0; j<share; ++j){
            cout << five_over << " ";
        }
        for(int k=0; k<remainder; ++k){
            cout << five_under;
        }
        cout << endl;
    }
    return 0;
}

// Trying to Clean code
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int DIVISOR = 5;  // 나누는 수를 상수로 정의
const string FULL_BAR = "++++";
const string PARTIAL_BAR = "|";

// 주어진 투표 수를 시각적으로 출력하는 함수
void print_vote_bar(int votes) {
    int full_bars = votes / DIVISOR;
    int partial_bar = votes % DIVISOR;

    for (int i = 0; i < full_bars; ++i) {
        cout << FULL_BAR << " ";
    }
    for (int i = 0; i < partial_bar; ++i) {
        cout << PARTIAL_BAR;
    }
    cout << endl;
}

int main() {
    int num_cases;
    int votes;

    cin >> num_cases;  // 총 테스트 케이스 수 입력

    for (int i = 0; i < num_cases; ++i) {
        cin >> votes;  // 각 테스트 케이스에 대한 투표 수 입력
        print_vote_bar(votes);  // 투표 수에 대한 시각적 표현 출력
    }

    return 0;
}
