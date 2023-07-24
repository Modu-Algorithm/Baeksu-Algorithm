/*
    Title: 리모컨
    Link: https://www.acmicpc.net/problem/1107
    Approach:
        (구현이 오래 걸림)
        - 최고 자릿수부터 시작하여 가장 가까운 자릿수를 찾는다.
        - 위, 아래로 거리가 같은 경우 아직 알 수 없으므로 모두 큐에 넣는다.
        - 일의 자리까지 과정을 반복한다.
        - 큐에서 가장 거리가 가까운 수가 정답이다.
        (브루트포스)
        - 가능한 모든 경우를 찾아본다. 
        - 최대 6자리 수이므로 1,000,000개(6자리)만 검사하면 된다.
    Mistake:
        - 100번대에서 +/-로 도달하는 경우와 비교해야 한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

vector<bool> keys = vector<bool>(10, true);
int minDistance = numeric_limits<int>::max();
int minChannel = 0;

// digit 번째 자리에 해당하는 수를 구한다.
int getDigit(int digit, int n) {
    int result = n;

    for (int i=0; i<digit-1; i++) n /= 10;

    return n % 10;
}

int getDigits(int n) {
    int digits = 0;
    
    while (n != 0) {
        digits ++;
        n /= 10;
    }

    return digits;
}

void findMin(int channel, int target, int depth) {
    if (depth == 6) return; 
    
    channel *= 10;
    for (int i=0; i<10; i++) {
        if (!keys[i]) continue;

        int channelToCheck = channel + i;
        int distance = abs(target-channelToCheck) + (depth+1);
        if (distance < minDistance) {
            minDistance = distance;
            minChannel = channelToCheck;
        } 

        findMin(channelToCheck, target, depth+1);
    }
}

int main() {
    int channel, numBroken;
    cin >> channel >> numBroken;

    for (int i=0; i<numBroken; i++) {
        int keyBroken;
        cin >> keyBroken;

        keys[keyBroken] = false;
    }

    int stepDistance = abs(channel - 100);
    findMin(0, channel, 0);
    if (stepDistance < minDistance) cout << stepDistance << '\n';
    else cout << minDistance << '\n';
}