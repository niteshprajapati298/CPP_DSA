#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    if (q.empty())
        cout << "Queue is empty" << endl;

    q.push(100);

    if (!q.empty())
        cout << "Queue is not empty. Front element: " << q.front() << endl;

    return 0;
}
