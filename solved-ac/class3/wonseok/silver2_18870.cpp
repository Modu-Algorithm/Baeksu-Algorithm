/*
    Title: 좌표 압축
    Link: https://www.acmicpc.net/problem/18870
    Approach:
        - 중복을 제거하고 배열을 정렬한다.
        - 배열을 순회하며 압축한 좌표를 해시맵에 기록한다.
          - 현재 인덱스가 압축한 좌표이다.
    Note:
        - unique는 연속된 중복 원소를 뒤로 보내버린다. 정렬을 먼저 해야 제대로 동작한다.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> coordinates(num);
    for (int i=0; i<num; i++) {
        int x;
        cin >> x;

        coordinates[i] = x;
    }

    vector<int> uniqueCoors(coordinates);
    sort(uniqueCoors.begin(), uniqueCoors.end());
    auto last = unique(uniqueCoors.begin(), uniqueCoors.end());
    uniqueCoors.erase(last, uniqueCoors.end());

    map<int, int> compressed;
    for (int i=0; i<uniqueCoors.size(); i++) {
        int x = uniqueCoors[i];
        compressed[x] = i;
    }

    for (auto num : coordinates) cout << compressed[num] << " ";
}