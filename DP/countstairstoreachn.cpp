#include<bits/stdc++.h>
using namespace std;
int recursion(int n){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    int left=recursion(n-1);
    int right=recursion(n-2);
    return left+right;
}
int memoisation(int n,vector<int>& memo){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(memo[n]!=-1)
        return memo[n];
    return memo[n]=memoisation(n-1,memo)+memoisation(n-2,memo);
}
int tabulation(int n,vector<int> &tab){
    
    tab[0]=1;
    tab[1]=1;
    for(int i=2;i<=n;i++){
        tab[i]=tab[i-1]+tab[i-2];
    }
    return tab[n];
}
int main(){
    int n=3;
    int c=0;
    cout<<recursion(n)<<endl;
    vector<int> memo(n+1,-1);
    cout<<memoisation(n,memo)<<endl;
    vector<int> tab(n+1,0);
    cout<<tabulation(n,tab);
}