#include<bits/stdc++.h>
using namespace std;
int recursion(int index,vector<int> &nums){
    if(index<0)
        return 0;
    int pick=nums[index]+recursion(index-2,nums);
    int npick=recursion(index-1,nums);
    return max(pick,npick);
}
int memo(int index,vector<int> &nums,vector<int>& dp){
        if(index<0)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int left=nums[index]+memo(index-2,nums,dp);
        int right=0+memo(index-1,nums,dp);
        return dp[index]=max(left,right);
    }
int tabulation(vector<int> &nums,vector<int>&tab){
    if(nums.size()==0)
        return 0;
    if(nums.size()==1)
        return nums[0];
    if(nums.size()==2)
        return max(nums[0],nums[1]);
    tab[0]=nums[0];
    tab[1]=max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++){
        int l=nums[i]+tab[i-2];
        tab[i]=max(l,tab[i-1]);
    }
    return tab[nums.size()-1];
}
int main(){
    vector<int> nums{2,7,9,3,1};
    cout<<recursion(nums.size()-1,nums)<<endl;
    vector<int> dp(nums.size(),-1);
    cout<<memo(nums.size()-1,nums,dp)<<endl;
    vector<int> tab(nums.size(),0);
    cout<<tabulation(nums,tab);
}