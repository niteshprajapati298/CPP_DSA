#include <iostream>
using namespace std;

void printNameNTimes(int n)
{
    if (n == 0)
        return;
    cout << "Count " << n << " Nitesh Prajapati" << endl;
    printNameNTimes(n - 1);
}

int main()
{
    printNameNTimes(5);
    return 0;
}
