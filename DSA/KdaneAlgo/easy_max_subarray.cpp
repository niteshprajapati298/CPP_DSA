#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int maxEnding = arr[0];
    int maxSoFar = arr[0];
    for (int i = 1; i < n; i++) {
        maxEnding = max(arr[i], maxEnding + arr[i]);
        maxSoFar = max(maxSoFar, maxEnding);
    }
    cout << maxSoFar << '\n';
    return 0;
}
