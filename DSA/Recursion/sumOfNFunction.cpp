#include <iostream>
using namespace std;

int sumOfNfun(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumOfNfun(n - 1);
}

int main()
{
    cout << sumOfNfun(10) << endl;
    return 0;
}
