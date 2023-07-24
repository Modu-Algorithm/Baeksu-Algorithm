/*
    Title: 케빈 베이컨의 6단계 법칙
    Link: https://www.acmicpc.net/problem/1389
    Approach:
        - Floyd Warshall 알고리즘을 통해 모든 사람 간의 최단 경로를 구한다.
        - 각 사람의 베이컨 수를 구하고, 가장 작은 사람을 출력한다.
    Mistakes:
        - 양방향 그래프이므로 두 방향 모두 연결해야 한다
        - 무한대에서 더할 경우 오버플로우가 발생한다.
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

#define INTMAX 1000

using namespace std;

int main() {
    int numUser, numRelation;
    cin >> numUser >> numRelation;

    vector<vector<int>> distance;
    distance = vector<vector<int>>(numUser, vector<int>(numUser, INTMAX));

    // Initialize matrix
    for (int i=0; i<numRelation; i++) {
        int from, to;
        cin >> from >> to;

        from--; to--;
        distance[from][to] = 1;
        distance[to][from] = 1;
    }

    // Floyd Warshall
    for (int k=0; k<numUser; k++) {
        for (int source=0; source<numUser; source++) {
            for (int dest=0; dest<numUser; dest++) {
                int current = distance[source][dest];
                int intermediate = distance[source][k] + distance[k][dest];

                distance[source][dest] = min(current, intermediate);               
            }
        }
    }

    // Bacon Number
    vector<int> bacon(numUser, 0);
    for (int r=0; r<numUser; r++) {
        for (int c=0; c<numUser; c++) {
            if (distance[r][c] == INTMAX) continue;
            bacon[r] += distance[r][c];
        }
    }

    // Find mininum
    int minValue = numeric_limits<int>::max();
    int minPerson = -1;
    for (int i=0; i<numUser; i++) {
        if (bacon[i] == 0) continue;
        if (bacon[i] < minValue) {
            minValue = bacon[i];
            minPerson = i+1;
        }
    }

    cout << minPerson;
}