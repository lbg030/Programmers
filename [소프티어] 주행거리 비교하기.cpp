#include<iostream>

// Initial Code
using namespace std;

int main(int argc, char** argv)
{
    int A,B;
    cin >> A >> B;
    if(A == B){
        cout << "same" << endl;
    }
    else{
        char res = (A > B) ? 'A' : 'B';
        cout << res << endl;
    }
    
   return 0;
}

// Trying to Clean code
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 비교 결과를 출력하는 함수
void print_comparison_result(int A, int B) {
    if (A == B) {
        cout << "same" << endl;
    } else {
        char result = (A > B) ? 'A' : 'B';
        cout << result << endl;
    }
}

int main() {
    int A, B;

    // 사용자로부터 두 정수를 입력받음
    cin >> A >> B;

    // 비교 결과를 출력하는 함수 호출
    print_comparison_result(A, B);

    return 0;
}
