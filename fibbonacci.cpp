#include<bits/stdc++.h>
using namespace std;
int recursion(int n){
    if(n<=1)
        return n;
    return recursion(n-1)+recursion(n-2);
}
int memoisation(int n,vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=memoisation(n-1,dp)+memoisation(n-2,dp);
    
}
void tabulation(int n,vector<int> &tab){
    for(int i=2;i<n;i++){
        tab[i]=tab[i-1]+tab[i-2];
        cout<<tab[i]<<" ";
    }
}
int main(){
    int n=10;
    vector<int> memo(n+1,-1);
    vector<int> tab(n+1,0);
    cout<<"Recursion: ";
    for(int i=0;i<n;i++){
        cout<<recursion(i)<<" ";
    }
    cout<<endl<<"Memoisation: ";
    for(int i=0;i<n;i++){
        cout<<memoisation(i,memo)<<" ";
    }
    cout<<endl<<"Tabulation: ";
    tab[0]=0;
    tab[1]=1;
    cout<<tab[0]<<" "<<tab[1]<<" ";
    tabulation(n,tab);
}