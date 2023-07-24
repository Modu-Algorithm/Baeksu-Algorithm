/*
    Title: 1,2,3 더하기
    Link: https://www.acmicpc.net/problem/9095
    Note: F(n) = F(n-1) + F(n-2) + F(n-3)을 이용한다. 각각 1로 시작하는 경우, 2로 시작하는 경우, 3으로 시작하는 경우이다.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int getAnswer(int n) {
    if (n < memo.size()) return memo[n];

    for (int i=memo.size(); i<=n; i++) {
        int newAnswer = memo[i-1] + memo[i-2] + memo[i-3];
        memo.push_back(newAnswer);
    }

    return memo[n];
}

int main() {
    memo.push_back(0);
    memo.push_back(1);
    memo.push_back(2);
    memo.push_back(4);

    int numCases;
    cin >> numCases;

    for (int i=0; i<numCases; i++) {
        int num;
        cin >> num;

        cout << getAnswer(num) << endl;
    }
}