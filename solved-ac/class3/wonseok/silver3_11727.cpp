/*
    Title: 2xn 타일링 2
    Link: https://www.acmicpc.net/problem/11727
    Approach: 
        - f(n) = f(n-1) + 2*f(n-2)임을 이용한다.
            - f(n-1)은 2x1 직사각형으로 시작하는 경우
            - f(n-2)는 2x2 또는 1x2 직사각형으로 시작하는 경우
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int getAnswer(int n) {
    for (int i=memo.size(); i<=n; i++) {
        int answer = memo[i-1] + 2 * memo[i-2];
        memo.push_back(answer % 10007);
    }

    return memo[n];
}

int main() {
    memo.push_back(0);
    memo.push_back(1);
    memo.push_back(3);

    int width;
    cin >> width;

    cout << getAnswer(width) << endl;
}