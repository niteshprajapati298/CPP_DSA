#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> freq;
    int target = n / 2;
    int value;
    int answer = -1;
    for (int i = 0; i < n; i++) {
        cin >> value;
        freq[value]++;
        if (freq[value] > target) {
            answer = value;
        }
    }
    if (answer == -1) {
        cout << "No majority element\n";
    } else {
        cout << answer << '\n';
    }
    return 0;
}
