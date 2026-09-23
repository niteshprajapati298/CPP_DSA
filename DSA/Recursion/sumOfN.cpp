#include <iostream>
using namespace std;

int sumOfN(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl;
        return 0;
    }
    sumOfN(i - 1, sum + i);
    return 0;
}

int main()
{
    sumOfN(10, 0);
    return 0;
}
