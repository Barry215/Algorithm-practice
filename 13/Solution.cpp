#include <iostream>
#include <algorithm>

using namespace std;

int getMaxDPDoubleArr(int num, int capacity, int *value, int *volume) {
    int dp[num][capacity + 1];
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0) {
                dp[i][j] = j >= volume[i] ? value[i] : 0;
            } else if (j < volume[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - volume[i]] + value[i]);
            }
//            printf("%3d ",dp[i][j]);
        }
//        cout << "" << endl;
    }

    return dp[num - 1][capacity];
}

int getMaxSingleArr(int num, int capacity, int *value, int *volume) {
    int dp[capacity + 1];
    for (int i = 0; i < num; i++) {
        for (int j = capacity; j >= 0; j--) {
            if (i == 0) {
                dp[j] = j >= volume[i] ? value[i] : 0;
            } else if (j >= volume[i]) {
                dp[j] = max(dp[j], dp[j - volume[i]] + value[i]);
            }
        }
    }
    return dp[capacity];
}

int getMaxValue(int num, int capacity) {
    int value[num];
    int volume[num];
    if (num == 0) {
        return 0;
    }
    for (int j = 0; j < num; j++) {
        cin >> value[j];
    }
    for (int j = 0; j < num; j++) {
        cin >> volume[j];
    }
    return getMaxSingleArr(num, capacity, value, volume);
}

int main() {
    int c, num, capacity;

    cin >> c;

    int result[c];
    for (int i = 0; i < c; i++) {
        cin >> num >> capacity;
        result[i] = getMaxValue(num, capacity);
    }
    for (int i = 0; i < c; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
