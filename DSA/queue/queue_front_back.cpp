#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    q.pop();
    q.pop();

    cout << "Front element after pop: " << q.front() << endl;

    return 0;
}
