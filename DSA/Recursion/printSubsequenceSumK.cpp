#include<iostream>
#include <vector>
using namespace std;
void printS(int index , int n , vector<int>arr , vector<int>ds , int target , int s){
    if(index==n){
        if (s==target)
        {
            for(auto  it : ds){
            cout << it << " " ;
        } 
        cout << endl;
    } 
    return ;
}  
  ds.push_back(arr[index]);
  printS(index + 1, n, arr, ds, target, s + arr[index]);
  ds.pop_back();
  printS(index+1 , n , arr , ds , target ,s);
}
int main(){
    vector<int>arr = {1 ,2, 1,1};
    int n = arr.size();
    int target = 2;
    vector<int>ds;
    printS(0 , n , arr , ds , target ,0);
}