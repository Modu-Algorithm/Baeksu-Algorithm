/*
    Title: Four Squares 
    Link: https://www.acmicpc.net/problem/17626
    Approach:
        - 모든 수는 4개 이하의 제곱수로 표현이 되므로 가장 큰 제곱수부터 찾는다.
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;



int main() {
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> memo(n+1, 0);
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    for (int i=3; i<=n; i++) {
        memo[i] = memo[i-1] + 1;
        for (int j=1; j*j <= i; j++) {
            memo[i] = min(memo[i], memo[i-j*j]+1);
        }
    }

    cout << memo[n];
}