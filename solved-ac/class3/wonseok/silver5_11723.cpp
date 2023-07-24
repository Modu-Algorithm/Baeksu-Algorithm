/*
    Title: 집합
    Link: https://www.acmicpc.net/problem/11723
    Approach: int의 2진수 표현으로 비트마스킹을 통해 값을 검사한다.
        - map으로 구현할 경우 시간초과로 실패한다.
*/

#include <iostream>

using namespace std;

class Set {
public:
    Set() {};

    void Add(int x) { 
        unsigned int bit = getBit(x);
        bits |= bit;
    }
    void Remove(int x) { 
        unsigned int bit = getBit(x);
        bits &= ~bit;
    }  
    bool Check(int x) {
        unsigned int bit = getBit(x); 
        return (bits & bit) != 0U;
    }
    void Toggle(int x) {
        unsigned int bit = getBit(x);
        bits ^= bit;
    }
    void All() {
        unsigned int bit = (1U << 20) - 1U;
        bits |= bit;
    }
    void Empty() { 
        bits &= 0U;
    }

private:
    unsigned int getBit(int x) {
        return 1U << (x-1);
    }
    unsigned int bits = 0U;
};



int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int numCommands;
    cin >> numCommands;

    Set s;
    for (int i=0; i<numCommands; i++) {
        string command;
        int x;

        cin >> command;

        if (command == "add") {
            cin >> x;
            s.Add(x);
        }
        else if (command == "remove") {
            cin >> x;
            s.Remove(x);
        }
        else if (command == "check") {
            cin >> x;
            cout << s.Check(x) << '\n';
        }
        else if (command == "toggle") {
            cin >> x;
            s.Toggle(x);
        } 
        else if (command == "all") s.All();
        else if (command == "empty") s.Empty();
    }
}