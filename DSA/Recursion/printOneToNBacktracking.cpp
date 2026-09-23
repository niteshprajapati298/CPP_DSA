#include <iostream>
using namespace std;

void printOneToNBacktrack(int n)
{
    if (n == 0)
        return;
    printOneToNBacktrack(n - 1);
    cout << n << endl;
}

int main()
{
    printOneToNBacktrack(5);
    return 0;
}
