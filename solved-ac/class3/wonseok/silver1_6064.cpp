/*
    Title: 카잉 달력
    Link: https://www.acmicpc.net/problem/6064
    Approach:
        - 두 수 중 큰 숫자의 나머지를 기준으로 다른 한쪽을 구한다.
        - 두 수의 최소공배수를 초과하면 답은 존재하지 않는다.
*/
#include <iostream>

using namespace std;

int getGCD(int M, int N) {
    if (M % N == 0) return N;
    else return getGCD(N, M % N);
}

int getLCM(int M, int N) {
    return M*N / getGCD(M, N);
}

int getYear(int M, int N, int remM, int remN) {
    int lcm = getLCM(M, N);

    int year = remM;
    while (year <= lcm) {
        int modN = year % N;
        if (modN == 0) modN = N;
        if (modN == remN) break;

        year += M;
    }

    if (year > lcm) return -1;

    return year;
}

int main() {
    int numLine;
    cin >> numLine;

    for (int i=0; i<numLine; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        cout << getYear(M, N, x, y) << '\n';
    }
}