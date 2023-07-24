/*
    Title: 헌내기는 친구가 필요해
    Link: https://www.acmicpc.net/problem/21736
    Approach:
        - 주인공의 위치를 기점으로 BFS로 이동 가능 영역을 탐색한다.
          - 벽을 만나면 큐에 그만 넣는다.
        - 탐색 중 사람(P)를 만나면 카운팅한다.
    Note:
        - x, y 좌표와 vector의 row, col 둘을 혼동하여 오답 해결에 많은 시간을 소비했다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Point {
public:
    Point(): x(0), y(0) {};
    Point(int x, int y): x(x), y(y) {};

    int x, y;
};

class Map {
public:
    Map(vector<string> rows): map(rows) {
        for (int row=0; row<rows.size(); row++) {
            size_t col = rows[row].find('I');
            if (col != string::npos) {
                myLocation = Point(col, row);
                break;
            }
        }

        height = rows.size();
        width = rows[0].length();
    };

    char Get(Point &p) {return map[p.y].at(p.x);}
    
    int GetPeople() {
        queue<Point> q;
        vector<vector<bool>> visited(width, vector<bool>(height, false));
        
        q.push(myLocation);
        visited[myLocation.x][myLocation.y] = true;

        int numPeople = 0;
        while (!q.empty()) {
            Point here = q.front();
            q.pop();

            if (Get(here) == 'X') continue;
            if (Get(here) == 'P') numPeople++;

            Point right = Point(here.x+1, here.y);
            Point down = Point(here.x, here.y+1);
            Point left = Point(here.x-1, here.y);
            Point up = Point(here.x, here.y-1);

            for (Point p : vector<Point>{right, down, left, up}) {
                if (p.x < 0 || p.y < 0) continue;
                if (p.x >= width || p.y >= height) continue;
                if (visited[p.x][p.y]) continue;
                
                q.push(p);
                visited[p.x][p.y] = true;
            }
        }

        return numPeople;
    }

    Point GetMyLocation() { return myLocation; }

private:
    vector<string> map;
    Point myLocation;
    int width, height;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> rows;
    for (int r=0; r<n; r++) {
        string row;
        cin >> row;

        rows.push_back(row);
    }

    Map map(rows);
    int numPeople = map.GetPeople();
    if (numPeople == 0) cout << "TT";
    else cout << numPeople;
}