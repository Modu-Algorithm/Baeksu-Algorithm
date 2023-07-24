/*
    Title: 토마토
    Link: https://www.acmicpc.net/problem/7576
    Approach;
        - 토마토 좌표와 지난 일수를 담는 클래스를 만든다.
        - 위 클래스를 이용해 BFS로 탐색한다.
        - 마지막에 남아 있는 인스턴스의 지난 일수가 최소 일수이다.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Point {
public:
    Point(int x, int y): x(x), y(y) {};

    Point Up() { return Point(x, y+1); }
    Point Down() { return Point(x, y-1); }
    Point Left() { return Point(x-1, y); }
    Point Right() { return Point(x+1, y); }

    int x, y;
};

class Spread {
public:
    Spread() {};
    Spread(Point p, int days): p(p), days(days) {};

    Spread Up() { return Spread(p.Up(), days+1); }
    Spread Down() { return Spread(p.Down(), days+1); }
    Spread Left() { return Spread(p.Left(), days+1); }
    Spread Right() { return Spread(p.Right(), days+1); }

    Point p = Point(0,0);
    int days = 0;
};


class Tray {
public:
    Tray(int width, int height)
    :width(width), height(height) 
    {
        tray = vector<vector<int>>(height, vector<int>(width, -1));
    }

    int Get(const Point &p) {
        return tray[p.y][p.x];
    }

    void Set(int val, const Point &p) {
        tray[p.y][p.x] = val;

        if (val == 1) {
            ripe++;
            Spread sprd = Spread(p, 0);
            tomatoes.push(sprd);
        } else if (val == 0) {
            unripe++;
        }
    }

    void Change(int val, const Point &p) {
        tray[p.y][p.x] = val;
    }

    int WaitUntilAllRipe() {
        Spread current;
        while (!tomatoes.empty()) {
            current = tomatoes.front();
            tomatoes.pop();

            for (Spread next : vector<Spread>{
                    current.Up(), current.Down(), 
                    current.Left(), current.Right(),
                }
            ) {
                if (next.p.x < 0 || next.p.y < 0) continue;
                if (next.p.x >= width || next.p.y >= height) continue;
                if (Get(next.p) != 0) continue;

                Change(1, next.p);
                unripe--; ripe++;

                tomatoes.push(next);
            }
        }

        return current.days;
    }

    bool IsAllRipe() { return unripe == 0; }

private:
    int width, height;
    int ripe = 0;
    int unripe = 0;

    vector<vector<int>> tray;
    queue<Spread> tomatoes;
};

int main() {
    int width, height;
    cin >> width >> height;

    Tray tray(width, height);
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            int tomato;
            cin >> tomato;

            Point p = Point(x, y);
            tray.Set(tomato, p);
        }
    }

    int days = tray.WaitUntilAllRipe();
    if (tray.IsAllRipe()) cout << days << '\n';
    else cout << -1 << '\n';
}