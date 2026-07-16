#include <iostream>
#include <vector>
using namespace std;
void printS(int index, int n, vector<int> arr, vector<int> ds, int target, int s)
{
    if (index == n)
    {
        if (s == target)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    printS(index + 1, n, arr, ds, target, s + arr[index]);
    ds.pop_back();
    printS(index + 1, n, arr, ds, target, s);
}

int countSubSequence(int index, int n, vector<int> arr, vector<int> ds, int target, int s)
{
    if (index == n)
    {
        if (s == target)
        {
          return 1;
        }
        return 0;
    }
    // ds.push_back(arr[index]);
    int take = countSubSequence(index + 1, n, arr, ds, target, s + arr[index]);
    // ds.pop_back();
    int notTake = countSubSequence(index + 1, n, arr, ds, target, s);
    return take + notTake;
}


bool printSOnlyOnce(int index, int n, vector<int> arr, vector<int> ds, int target, int s)
{
    if (index == n)
    {
        if (s == target)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            return true;
        }
        return false;
    }
    ds.push_back(arr[index]);
    bool take = printSOnlyOnce(index + 1, n, arr, ds, target, s + arr[index]);
    if(take) return 1;
    else return 0;
    ds.pop_back();
    bool notTake = printSOnlyOnce(index + 1, n, arr, ds, target, s);
    if(notTake) return 1;
    else return 0;
    return take + notTake;
}
int main()
{
    vector<int> arr = {1, 2, 1, 1};
    int n = arr.size();
    int target = 2;
    vector<int> ds;
    cout << "count "<< countSubSequence(0, n, arr, ds, target, 0);
}