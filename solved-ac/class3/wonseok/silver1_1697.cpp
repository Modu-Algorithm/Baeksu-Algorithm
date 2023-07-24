/*
    Title: 숨바꼭질
    Link: https://www.acmicpc.net/problem/1697
    Approach:
        - 현재 위치에서 방문 가능한 모든 좌표를 큐에 담는다.
        - 큐에서 꺼낸 후, 다시 방문 가능한 좌표를 담는다.
            - 이미 방문한 곳은 담지 않는다.
    Note:
        - 입력 범위를 잘 확인하여 메모리를 절약하도록 한다.
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000

using namespace std;

class Node {
public:
    Node(int x, int time): x(x), time(time) {};

    int x, time;
};

int main() {
    unsigned int start, target;
    cin >> start >> target;

    queue<Node> q;
    vector<bool> visit(100001);

    Node node = Node(start, 0);
    visit[start] = true;
    while (node.x != target) {
        Node back = Node(node.x-1, node.time+1);
        Node front = Node(node.x+1, node.time+1);
        Node fold = Node(node.x*2, node.time+1);

        for (Node &n : vector<Node>{back, front, fold}) {
            if (n.x > MAX || n.x < 0) continue;
            if (visit[n.x]) continue;

            q.push(n);
            visit[n.x] = true;
        }

        node = q.front(); q.pop();
    }

    cout << node.time;
}