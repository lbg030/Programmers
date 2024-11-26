#include <iostream>


int main() {
    int T;
    std::cin >> T;
    
    while (T--) {
        int sum = 0;
        int N;
        std::cin >> N;
        for (int i = 1; i <= N; i += 2) {
            sum += i;
        }
        std::cout << sum << '\n';
    }
}