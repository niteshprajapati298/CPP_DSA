#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    int maxSum = sum;
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        if (sum > maxSum) maxSum = sum;
    }
    cout << maxSum << '\n';
    return 0;
}
