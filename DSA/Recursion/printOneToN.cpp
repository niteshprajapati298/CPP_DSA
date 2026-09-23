#include <iostream>
using namespace std;

void printOneToN(int n, int i)
{
    if (i > n)
        return;
    cout << i << endl;
    printOneToN(n, i + 1);
}

int main()
{
    printOneToN(5, 1);
    return 0;
}
