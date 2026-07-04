// Recursion ->
// Base Case ->
// Stack Overflow || Stack Space 
// Recursion Tree Creation 
// Recursion -> when a function call itself until a specific Condition meets in called recursion 


#include<iostream>
using namespace std;

void printNameNTimes(int n){
    if(n==0) return;
    cout << "Count " << n  << " Nitesh Prajapati" << endl;
    printNameNTimes(n-1);
}
void PrintOneToN(int n , int i){
     if(i>n) return;
     cout << i << endl;
     PrintOneToN(n,i+1);
}
void printNtoOne(int n){
    if(n==0) return;
    cout << n << endl;
    printNtoOne(n-1);
}
void printOneToNbackTrack(int n ){
    if(n==0) return;
    printOneToNbackTrack(n-1);
    cout << n << endl;
}
int main(){
    int i = 0;
    // printNameNTimes(5);
    // PrintOneToN(5,1);
    // printNtoOne(5);
    printOneToNbackTrack(5);
    return 0;
}