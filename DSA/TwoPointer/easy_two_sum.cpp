#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            cout << arr[left] << " " << arr[right] << '\n';
            return 0;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    cout << "No pair found\n";
    return 0;
}
