/*
    Title: 구간 합 구하기 4
    Link: https://www.acmicpc.net/problem/11659
    Approach: 누적합을 저장해두었다가 sum[i, j] = sum[j] - sum[i-1]임을 이용한다.
*/

#include <vector>
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    // N: 수의 개수, M: 합을 구해야 하는 횟수
    int N, M;
    cin >> N >> M;

    vector<int> accumulate; accumulate.push_back(0);
    int sum = 0;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;

        sum += num;
        accumulate.push_back(sum);
    }

    for (int i=0; i<M; i++) {
        int start, end;
        cin >> start >> end;

        cout << accumulate[end] - accumulate[start-1] << '\n';
    }
}