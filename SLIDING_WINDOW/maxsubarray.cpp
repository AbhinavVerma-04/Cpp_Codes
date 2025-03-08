// MAX LENGTH SUBARRAY WITH SUM <=K

// 1-> O(N+N)
#include <bits/stdc++.h>
using namespace std;
int Sum(vector<int> &nums, int &k)
{
    int l=0;
    int r=0;
    int len=0;
    int sum=0;
    while(r<nums.size()){
        sum+=nums[r];
        while(sum>k){
            sum-=nums[l];
            l++;
        }
        len=max(len,r-l+1);
        r++;
    }
    return len;
}
int main()
{
    vector<int> nums{2, 5, 1, 7, 10};
    int k = 14;
    cout << Sum(nums, k);
}

// 2->O(N)
using namespace std;
int Sum(vector<int> &nums, int &k)
{
    int l=0;
    int r=0;
    int len=0;
    int sum=0;
    while(r<nums.size()){
        sum+=nums[r];
        if(sum>k){
            sum-=nums[l];
            l++;
        }
        len=max(len,r-l+1);
        r++;
    }
    return len;
}
int main()
{
    vector<int> nums{2, 5, 1, 7, 10};
    int k = 14;
    cout << Sum(nums, k);
}