#include<bits/stdc++.h>
using namespace std;

int subArraySum(vector<int>& nums, int target)
{
    int n = nums.size();
    int sum=0, result=0;
    int left=0,right=0;
    while (right<n)
    {
        sum+=nums[right];
        while (sum>target && left<=right)
        {
            sum-=nums[left];
            left++;
        }

        if(sum==target)
            result++;
        right++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,target;
    cin>>n>>target;

    vector<int> nums(n);

    for(int i=0; i<n; i++)
        cin>>nums[i];
    
    int result = subArraySum(nums, target);
    cout<<result;
    return 0;
}