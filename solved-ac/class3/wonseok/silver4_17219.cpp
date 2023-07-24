/*
    Title: 비밀번호 찾기
    Link: https://www.acmicpc.net/problem/17219
    Approach: 해시맵을 통해 비밀번호를 저장 / 찾기
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int numPasswords, numFind;
    cin >> numPasswords >> numFind;

    map<string, string> passwords;
    for (int i=0; i<numPasswords; i++) {
        string site, password;
        cin >> site >> password;

        passwords[site] = password;
    }

    for (int i=0; i<numFind; i++) {
        string site;
        cin >> site;

        cout << passwords[site] << endl;
    }
}