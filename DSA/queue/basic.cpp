#include <iostream>
#include <queue>
using namespace std;

// int main()
// {
//     queue<int> q;

//     for(int i = 0 ; i < 10; i ++){
//         q.push(i);
//     }

//     // Accessing the front and back elements
//     cout << "Front element: " << q.front() << endl;
//     cout << "Back element: " << q.back() << endl;

//     // Removing an element from the front
//     q.pop();
//     q.pop();

//     cout << "Front element after pop: " << q.front() << endl;

//     return 0;
// }

// int main()
// {
//     queue<int> q;

//     // Check whether the queue is empty
//     if (q.empty())
//         cout << "Queue is empty" << endl;

//     // Insert an element into the queue
//     q.push(100);

//     // Check the queue again
//     if (!q.empty())
//         cout << "Queue is not empty. Front element: "
//              << q.front() << endl;

//     return 0;
// }

// int main()
// {
//     queue<int> q;

//     // Insert two elements
//     q.push(10);
//     q.push(5);

//     // Display the current size
//     cout << "Size of queue: " << q.size() << endl;

//     // Remove the front element
//     q.pop();

//     // Display the updated size
//     cout << "Size of queue: " << q.size() << endl;

//     return 0;
// }
int main()
{
    queue<int> q;
    vector<int> arr = {10, 15, 12, 29, 17};
    for (auto it : arr)
    {
        q.push(it);
    }

    // Traversing a Queue
    // A queue does not provide iterators,
    // so its elements cannot be directly
    // traversed like a vector or list.
    //  To inspect all elements without modifying the original queue,
    //  we can create a copy and repeatedly access and remove its front element.
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << endl;
        temp.pop();
    }
}