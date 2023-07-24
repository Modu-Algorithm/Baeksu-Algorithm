/*
    Title: 쉬운 최단거리
    Link: https://www.acmicpc.net/problem/14940
    Approach:
        - 목표지점으로부터 BFS 탐색을 하며 거리를 업데이트한다.
    Mistakes:
        - 도달할 수 없는 땅은 -1로 출력해야 한다.
        - rows와 cols의 순회에 잘못된 값을 넣었다.
        - Point(x, y)에 행과 열을 대응시키려면 (col, row) 순서여야 한다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Point {
public:
    Point(int x, int y): x(x), y(y) {};
    int x, y;
};

class Move {
public:
    Move(Point p, int dist): point(p), distance(dist) {}; 

    Move Left() { 
        return Move(
            Point(point.x-1, point.y),
            distance+1
        );
    }

    Move Right() {
        return Move(
            Point(point.x+1, point.y),
            distance+1
        );
    }

    Move Up() {
        return Move(
            Point(point.x, point.y-1),
            distance+1
        );
    }

    Move Down() {
        return Move(
            Point(point.x, point.y+1),
            distance+1
        );
    };
    
    Point point;
    int distance; 
};

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> map(rows, vector<int>(cols));
    vector<vector<bool>> visit(rows, vector<bool>(cols, false));

    Point start = Point(0, 0);
    for (int r=0; r<rows; r++) {
        for (int c=0; c<cols; c++) {
            int val;
            cin >> val;

            if (val == 2) start = Point(c, r);
            if (val == 0) visit[r][c] = true;
            map[r][c] = val;
        }
    }

    queue<Move> q;

    map[start.y][start.x] = 0;
    q.push(Move(start, 0));
    visit[start.y][start.x] = true;

    Move move = Move(start, 0);
    while (!q.empty()) {
        move = q.front(); q.pop();
        
        for (Move m : vector<Move>{move.Left(), move.Right(), move.Up(), move.Down()}) {
            if (m.point.x < 0 || m.point.y < 0) continue;
            if (m.point.x >= cols || m.point.y >= rows) continue;
            if (visit[m.point.y][m.point.x]) continue;

            map[m.point.y][m.point.x] = m.distance;
            q.push(m);
            visit[m.point.y][m.point.x] = true;
        }
    }

    for (int r=0; r<rows; r++) {
        for (int c=0; c<cols; c++) {
            if (!visit[r][c]) map[r][c] = -1;
            cout << map[r][c] << " ";
        }
        cout << '\n';
    }
}