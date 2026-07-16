#include <iostream>
#include <vector>
using namespace std;

/*
Most Voting Algorithm (Boyer-Moore)
Easy idea:
- Keep one candidate and one count.
- If the current number matches the candidate, increase the count.
- If it is different, decrease the count.
- When the count becomes 0, choose a new candidate.
- At the end, the remaining candidate is the possible majority element.
- Then we still check it once more to confirm it really appears more than n/2 times.
*/

int majorityElement(vector<int> &nums)
{
    // with Brute Force approach
    // int n = nums.size()-1;
    // unordered_map<int,int>mp;
    // for(int i = 0; i <= n; i++){
    //     mp[nums[i]]++;
    // }
    // for(auto it : mp){
    //     if(it.second > n/2) return it.first;
    //   }
    //   return 0;

    // optimal approach
    int freq = 0;
    int element = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
        {
            element = nums[i];
            freq++;
        }
        else if (nums[i] == element)
        {
            freq++;
        }
        else
            freq--;
    }
    return element;
}
int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);

    cout << "Majority element: " << result << endl;
    return 0;
}