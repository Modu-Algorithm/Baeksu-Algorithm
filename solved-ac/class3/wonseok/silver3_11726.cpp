/*
    Title: 2×n 타일링
    Link: https://www.acmicpc.net/problem/11726
    Approach: f(n) = f(n-1) + f(n-2)임을 이용한다. f(n)은 2xn 크기의 직사각형을 채우는 방법의 수이다.
        - f(n-1)은 2x1 직사각형으로 시작하는 경우
        - f(n-2)은 1x2 직사각형 2개로 시작하는 경우
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int getAnswer(int n) {
    for (int i=memo.size(); i<=n; i++) {
        int value = memo[i-1] + memo[i-2];
        memo.push_back(value % 10007);
    }

    return memo[n];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memo.push_back(0);
    memo.push_back(1);
    memo.push_back(2);

    int n;
    cin >> n;

    cout << getAnswer(n) << '\n';
}