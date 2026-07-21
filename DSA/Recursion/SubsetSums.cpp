#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
   void solve(vector<int>&arr, int index , int n , int sum ,vector<int>&ans){
      if(index >= n){
          ans.push_back(sum);
          return;
      }
      sum = sum+arr[index];
      solve(arr,index+1, n , sum, ans);
      sum = sum-arr[index];
      solve(arr,index+1, n , sum, ans);
      }
    vector<int> subsetSums(vector<int>& arr) {
     int sum = 0;
     int n = arr.size();
     int index = 0;
     vector<int>ans;
     solve(arr,index, n , sum, ans);
     return ans;
    }
};

void runTest(int id, vector<int> input, vector<int> expected) {
    Solution s;
    vector<int> got = s.subsetSums(input);
    sort(got.begin(), got.end());
    sort(expected.begin(), expected.end());
    cout << "Test " << id << ": ";
    if (got == expected) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
        cout << "  got:      ";
        for (int x : got) cout << x << " ";
        cout << endl << "  expected: ";
        for (int x : expected) cout << x << " ";
        cout << endl;
    }
}

int main() {
    runTest(1, {1, 2, 3}, {0, 1, 2, 3, 3, 4, 5, 6});
    runTest(2, {}, {0});
    runTest(3, {5}, {0, 5});
    runTest(4, {2, 3}, {0, 2, 3, 5});
    runTest(5, {1, 1, 1}, {0, 1, 1, 1, 2, 2, 2, 3});
    runTest(6, {-1, 2, 4}, {-1, 0, 1, 2, 3, 4, 5, 6});
    runTest(7, {0, 0}, {0, 0, 0, 0});
    return 0;
}
