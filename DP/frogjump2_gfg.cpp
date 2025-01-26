#include<bits/stdc++.h>
using namespace std;
int recursion(int index,vector<int>& n,int k){
    if(index==0){
        return 0;
    }
    int minstep=INT_MAX;
    int jump;
    for(int j=1;j<=k;j++){
        if(index-j>=0){
            jump=recursion(index-j,n,k)+abs(n[index]-n[index-j]);
            minstep=min(minstep,jump);
        }
    }
    return minstep;
}
int memoisation(int index,vector<int>& n,int k,vector<int>& memo){
    if(index==0)
        return 0;
    if(memo[index]!=-1)
        return memo[index];
    int minstep=INT_MAX;
    int jump;
    for(int j=1;j<=k;j++){
        if(index-j>=0){
            jump=memoisation(index-j,n,k,memo)+abs(n[index]-n[index-j]);
            minstep=min(minstep,jump);
        }
    }
    return memo[index]=minstep;
}
int tabulation(vector<int>& n, int k,vector<int> &tab) {
    int size = n.size();
    tab[0] = 0; 
    for (int i = 1; i < size; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                tab[i] = min(tab[i], tab[i - j] + abs(n[i] - n[i - j]));
            }
        }
    }

    return tab[size - 1]; 
}
int main(){
    vector<int> n{10, 30, 40, 50, 20};
    int k=3;
    cout<<recursion(n.size()-1,n,k)<<endl;
    vector<int> memo(n.size(),-1);
    cout<<memoisation(n.size()-1,n,k,memo)<<endl;
    vector<int> tab(n.size(),INT_MAX);
    cout<<tabulation(n,k,tab);
}