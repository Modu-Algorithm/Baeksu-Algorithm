/*
    Title: 가장 가까운 세 사람의 심리적 거리
    Link: https://www.acmicpc.net/problem/20529
    Approach:
        - MBTI는 16개 종류이므로, 모두 균일하게 있더라도 33명부터는 반드시 동일한 타입이 3명이 존재한다.
        - 32명 이하는 브루트 포스로 모든 경우를 검사하고, 초과는 바로 0을 돌려준다,
    Note:
        - 비둘기집 원리: 들어갈 자리가 부족하면 중복이 발생한다.
*/
#include <iostream>
#include <vector>

using namespace std;

int getDistance(string a, string b) {
    int dist = 0;
    for (int i=0; i<a.length(); i++) {
        if (a.at(i) != b.at(i)) dist++;
    }
    
    return dist;
}

int main() {
    int tests;
    cin >> tests;

    for (int t=0; t<tests; t++) {
        int numPeople;
        cin >> numPeople;

        vector<string> MBTIs(numPeople);
        for (int i=0; i<numPeople; i++) cin >> MBTIs[i];

        if (numPeople > 32) {
            cout << "0" << '\n';
            continue;
        }

        int min = 10000;
        for (int i=0; i<numPeople; i++) {
            for (int j=i+1; j<numPeople; j++) {
                for (int k=j+1; k<numPeople; k++) {
                    int dist1 = getDistance(MBTIs[i], MBTIs[j]);
                    int dist2 = getDistance(MBTIs[i], MBTIs[k]);
                    int dist3 = getDistance(MBTIs[j], MBTIs[k]);

                    int sum = dist1 + dist2 + dist3;
                    if (sum < min) min = sum;
                }
            }
        }

        cout << min << '\n';
    }
}
