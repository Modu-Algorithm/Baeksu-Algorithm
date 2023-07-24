/*
    Title: IOIOI
    Link: https://www.acmicpc.net/problem/5525
    Approach:
        (시간초과)
        - 2N+1 길이의 IOIOI...를 준비한다.
        - 문자열을 슬라이스하면서 준비한 문자열과 동일한지 검사한다.
        (통과)
        - Pn은 IOI가 n번 이어진 문자열이다.
        - IOI의 개수를 카운트하여 문자열 비교 횟수를 단축한다.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int subCount = 0;
    int count = 0;
    for (int i=0; i<M-1; i++) {
        if (S.substr(i, 3) == "IOI") {
            subCount++;
            i++;
            if (subCount == N) {
                count++;
                subCount--;
            }
        } else {
            subCount = 0;
        }
    }

    cout << count;
}