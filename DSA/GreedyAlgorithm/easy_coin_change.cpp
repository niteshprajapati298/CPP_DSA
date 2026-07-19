#include <iostream>
#include <vector>
using namespace std;

int main() {
    int amount;
    cin >> amount;
    vector<int> coins = {25, 10, 5, 1};
    int count = 0;
    for (int coin : coins) {
        count += amount / coin;
        amount %= coin;
    }
    cout << count << '\n';
    return 0;
}
