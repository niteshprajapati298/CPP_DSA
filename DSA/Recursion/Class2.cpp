// Recursion ->
// Base Case ->
// Stack Overflow || Stack Space
// Recursion Tree Creation
// Recursion -> when a function call itself until a specific Condition meets in called recursion

#include <iostream>
#include <vector>
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
int sumOfNfun(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumOfNfun(n - 1);
}
int factOfN(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factOfN(n - 1);
}
void reverse(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}
bool checkPalindrome(string &str , int start , int end){
    cout << str[start] << " " << str[end] << endl;
    if(start>=end) return true;
    if(str[start] != str[end]){
        cout << str[start] << " " << str[end] << endl;
        return false;
    }
    return checkPalindrome(str,start+1,end-1);    
}


int main()
{
    // sumOfN(10,0);
    // cout << sumOfNfun(10) << endl;
    // cout << "Factorial : " << factOfN(30);

    // vector<int> arr = {10, 20, 30, 40, 50 ,60}; // Create vector with initial values

    // // Display vector values
    // cout << "Vector values Before Reversal: ";
    // for(auto it : arr){
    //     cout << it << " ";
    // }
    // cout << endl;
    // reverse(arr,0,arr.size()-1);
    // cout << "Vector values After Reversal: ";
    // for(auto it : arr){
    //     cout << it << " ";
    // }
    string str = "abcddcba";
    int n = str.length()-1;
    bool isPalindrome = checkPalindrome(str,0,n);
    if(isPalindrome == true) cout << str <<" <- is a Palindrom" << endl;
    else cout << str << " <- is Not a Palindrome" << endl;
    return 0;
}