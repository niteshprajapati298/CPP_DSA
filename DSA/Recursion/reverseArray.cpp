#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60};

    cout << "Vector values Before Reversal: ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    reverse(arr, 0, arr.size() - 1);

    cout << "Vector values After Reversal: ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
