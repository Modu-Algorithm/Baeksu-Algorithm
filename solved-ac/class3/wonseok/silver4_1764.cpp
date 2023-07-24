/*
    Title: 듣보잡
    Link: https://www.acmicpc.net/problem/1764
    Approach: 해시맵을 이용해 이미 등록된 값이 있는지 검사한다.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    map<string, int> mapSeen;
    vector<string> found;

    for (int i=0; i<N; i++) {
        string name;
        cin >> name;

        mapSeen[name] = 1;
    }

    for (int i=0; i<M; i++) {
        string name;
        cin >> name;

        if (mapSeen.find(name) != mapSeen.end()) found.push_back(name); 
    }

    sort(found.begin(), found.end());

    cout << found.size() << endl;
    for (auto name : found) cout << name << endl;
}