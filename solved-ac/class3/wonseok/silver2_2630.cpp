/*
    Title: 색종이 만들기
    Link: https://www.acmicpc.net/problem/2630
    Approach:
        - 한 색상만으로 이루어져 있는지 검사한다.
        - 아니라면, 4등분하여 재귀적으로 검사한다.
        - 크기가 1일 때에도 재귀를 종료한다.
*/
#include <iostream>
#include <vector>

using namespace std;

enum Color {
    WHITE = 0,
    BLUE = 1,
    UNKNOWN = 2,
};

class Paper {
public:
    Paper(int size) {
        cells = vector<vector<Color>>(size);
        for (int r=0; r<size; r++) {
            cells[r] = vector<Color>(size, WHITE);
        }
    };

    void Set(Color color, int row, int col) {
        cells[row][col] = color;
    }

    Color GetColor(int row, int col, int size) {
        Color color = cells[row][col];
        for (int r=row; r<row+size; r++) {
            for (int c=col; c<col+size; c++) {
                Color current = cells[r][c];
                if (color != current) return UNKNOWN;
            }
        }

        return color;
    }

    int GetSize() { return cells.size(); }

private:
    vector<vector<Color>> cells;
};

class PaperCutter {
public:
    PaperCutter(Paper &paper): paper(paper) {};

    void Cut() {
        cut(0, 0, paper.GetSize());
    }

    int GetWhite() { return white; }
    int GetBlue() { return blue; }
private:
    void cut(int row, int col, int size) {
        Color color = paper.GetColor(row, col, size);
        if (color == UNKNOWN) {
            int nextSize = size / 2;
            cut(row, col, nextSize);
            cut(row, col+nextSize, nextSize);
            cut(row+nextSize, col, nextSize);
            cut(row+nextSize, col+nextSize, nextSize);
            return;
        } 

        if (color == WHITE) white++;
        if (color == BLUE) blue++;
    }

    Paper &paper;
    int white = 0;
    int blue = 0;
};

int main() {
    int size;
    cin >> size;

    Paper paper(size);

    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            int numColor;
            cin >> numColor;

            paper.Set(static_cast<Color>(numColor), r, c);
        }
    }

    PaperCutter cutter(paper);
    cutter.Cut();

    cout << cutter.GetWhite() << '\n' << cutter.GetBlue();
}