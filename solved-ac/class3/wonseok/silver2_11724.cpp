/*
    Title: 연결 요소의 개수
    Link: https://www.acmicpc.net/problem/11724
    Approach:
        - 연결요소란 단절되지 않은 그래프 하나를 의미한다. (임의의 V1 -> V2 경로가 존재)
        - 방문 여부를 기록하는 배열을 하나 둔다.
        - 순차적으로 방문할 Queue를 하나 둔다.
        - 노드를 순회하며 방문하지 않은 노드를 Queue에 추가한다.
        - Queue가 비어 있으면 연결요소 하나를 찾은 것이다.
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int size) {
        vertex = vector<set<int>>(size+1);
    };

    void Connect(int from, int to) {
        vertex[from].insert(to);
        vertex[to].insert(from);
    }

    set<int> GetConnected(int n) {
        return vertex[n];
    }

private:
    vector<set<int>> vertex;
};

int main() {
    int numVertex, numEdge;
    cin >> numVertex >> numEdge;

    Graph graph(numVertex);
    for (int i=0; i<numEdge; i++) {
        int from, to;
        cin >> from >> to;

        graph.Connect(from, to);
    }

    queue<int> q;
    vector<bool> visited(numVertex+1, false);

    int numComponents = 0;
    for (int i=1; i<=numVertex; i++) {
        if (visited[i]) continue;

        for (int vertex : graph.GetConnected(i)) q.push(vertex);
        
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            if (visited[currentVertex]) continue;

            for (int vertex : graph.GetConnected(currentVertex)) {
                if (visited[vertex]) continue;
                q.push(vertex);
            }

            visited[currentVertex] = true;
        }

        visited[i] = true;
        numComponents++;
    }

    cout << numComponents;
}
