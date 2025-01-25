#include<bits/stdc++.h>
using namespace std;
int recursion(int index,vector<int> &n){
    if(index==0)
        return 0;
    int left=recursion(index-1,n)+abs(n[index]-n[index-1]);
    int right=INT_MAX;
    if(index>1)
        right=recursion(index-2,n)+abs(n[index]-n[index-2]);
    return min(left,right);
}
int memoisation(int index,vector<int>& n,vector<int>& memo){
    if(index==0)
        return 0;
    if(memo[index]!=-1)
        return memo[index];
    int left=memoisation(index-1,n,memo)+abs(n[index]-n[index-1]);
    int right=INT_MAX;
    if(index>1)
        right=memoisation(index-2,n,memo)+abs(n[index]-n[index-2]);
    return memo[index]=min(left,right);
}
int tabulation(vector<int>& n,vector<int> &tab){
    tab[0]=0;
    for(int i=1;i<n.size();i++){
        int left=tab[i-1]+abs(n[i]-n[i-1]);
        int right=INT_MAX;
        if(i>1)
            right=tab[i-2]+abs(n[i]-n[i-2]);
        tab[i]=min(left,right);
    }
    return tab[n.size()-1];
}

int main(){
    vector<int> n{20, 30, 40, 20};
    int c=0;
    cout<<recursion(n.size()-1,n)<<endl;
    vector<int> memo(n.size(),-1);
    cout<<memoisation(n.size()-1,n,memo)<<endl;
    vector<int> tab(n.size(),0);
    cout<<tabulation(n,tab);
}