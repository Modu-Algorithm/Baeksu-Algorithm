/*
    Title: 토마토
    Link: https://www.acmicpc.net/problem/7569
    Approach:
        - 다음 토마토의 위치와 지난 일수를 담은 클래스를 만든다.
        - 위 클래스를 이용해 BFS로 탐색한다
        - 가장 마지막에 기록된 일수가 최소 일수이다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Point {
public:
    Point(int x, int y, int z): x(x), y(y), z(z) {};

    Point Up() { return Point(x, y, z+1); }
    Point Down() { return Point(x, y, z-1); }
    Point Left() { return Point(x-1, y, z); }
    Point Right() { return Point(x+1, y, z); }
    Point Front() { return Point(x, y+1, z); }
    Point Back() { return Point(x, y-1, z); }

    int x, y, z;
};

class Spread {
public:
    Spread() {};
    Spread(Point p, int days): p(p), days(days) {};
    Spread(const Spread &other) {
        p = other.p;
        days = other.days;
    }

    Spread Up() { return Spread(p.Up(), days+1); }
    Spread Down() { return Spread(p.Down(), days+1); }
    Spread Left() { return Spread(p.Left(), days+1); }
    Spread Right() { return Spread(p.Right(), days+1); }
    Spread Front() { return Spread(p.Front(), days+1); }
    Spread Back() {return Spread(p.Back(), days+1); }  

    Point p = Point(0,0,0);
    int days = 0;
};

class Tray {
public:
    Tray() {};

    Tray(int width, int height) {
        tray = vector<vector<int>>(height, vector<int>(width, -1));
    }

    int Get(int x, int y) {
        return tray[y][x];
    }

    void Set(int val, int x, int y) {
        tray[y][x] = val;
    }

private:
    vector<vector<int>> tray;
};

class Trays {
public:
    Trays(int width, int depth, int height)
    :width(width), depth(depth), height(height) 
    {
        trays = vector<Tray>(height, Tray(width, depth));
    }

    int Get(const Point &p) {
        return trays[p.z].Get(p.x, p.y);
    }

    void Set(int val, const Point &p) {
        trays[p.z].Set(val, p.x, p.y);

        if (val == 1) {
            ripe++;
            Spread sprd = Spread(p, 0);
            tomatoes.push(sprd);
        } else if (val == 0) {
            unripe++;
        }
    }

    void Change(int val, const Point &p) {
        trays[p.z].Set(val, p.x, p.y);
    }

    int WaitUntilAllRipe() {
        Spread current;
        while (!tomatoes.empty()) {
            current = tomatoes.front();
            tomatoes.pop();

            for (Spread next : vector<Spread>{
                    current.Up(), current.Down(), 
                    current.Left(), current.Right(),
                    current.Front(), current.Back(),
                }
            ) {
                if (next.p.x < 0 || next.p.y < 0 || next.p.z < 0) continue;
                if (next.p.x >= width || next.p.y >= depth || next.p.z >= height) continue;
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
    int width, depth, height;
    int ripe = 0;
    int unripe = 0;

    vector<Tray> trays;
    queue<Spread> tomatoes;
};

int main() {
    int width, depth, height;
    cin >> width >> depth >> height;

    Trays trays(width, depth, height);
    for (int z=0; z<height; z++) {
        for (int y=0; y<depth; y++) {
            for (int x=0; x<width; x++) {
                int tomato;
                cin >> tomato;

                Point p = Point(x, y, z);
                trays.Set(tomato, p);
            }
        }
    }

    int days = trays.WaitUntilAllRipe();
    if (trays.IsAllRipe()) cout << days << '\n';
    else cout << -1 << '\n';
}