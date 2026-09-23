#include <iostream>
using namespace std;

bool checkPalindrome(string &str, int start, int end)
{
    cout << str[start] << " " << str[end] << endl;
    if (start >= end)
        return true;
    if (str[start] != str[end])
    {
        cout << str[start] << " " << str[end] << endl;
        return false;
    }
    return checkPalindrome(str, start + 1, end - 1);
}

int main()
{
    string str = "abcddcba";
    int n = str.length() - 1;
    bool isPalindrome = checkPalindrome(str, 0, n);
    if (isPalindrome == true)
        cout << str << " <- is a Palindrome" << endl;
    else
        cout << str << " <- is Not a Palindrome" << endl;
    return 0;
}
