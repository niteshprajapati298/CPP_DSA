#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    vector<int> arr = {10, 15, 12, 29, 17};

    for (auto it : arr)
    {
        q.push(it);
    }

    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << endl;
        temp.pop();
    }

    return 0;
}
