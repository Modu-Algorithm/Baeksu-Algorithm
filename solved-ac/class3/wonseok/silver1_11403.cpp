/*
    Title: 경로 찾기
    Link: https://www.acmicpc.net/problem/11403
    Approach:
        - Floyd Warshall 알고리즘을 통해 정점 간 최단거리를 구한다.
        - 최단거리가 존재하지 않으면 경로가 존재하지 않는 것이다.
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int INTMAX = numeric_limits<int>::max();

int main() {
    int size;
    cin >> size;

    vector<vector<int>> graph(size, vector<int>(size, 0));
    vector<vector<int>> dist(size, vector<int>(size, INTMAX));

    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            int val;
            cin >> val;

            graph[r][c] = val;
            if (val > 0) dist[r][c] = val;
        }
    }

    for (int k=0; k<size; k++) {
        for (int source=0; source<size; source++) {
            for (int dest=0; dest<size; dest++) {
                if (dist[source][k] == INTMAX) continue;
                if (dist[k][dest] == INTMAX) continue;

                int current = dist[source][dest];
                int intermediate = dist[source][k] + dist[k][dest];

                dist[source][dest] = min(current, intermediate);
            }
        }
    }

    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            if (dist[r][c] == INTMAX) cout << "0 ";
            else cout << "1 ";
        }
        cout << '\n';
    }
}