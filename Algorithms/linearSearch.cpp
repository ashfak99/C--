#include<iostream>
#include<vector>
using namespace std;

int linearSearchRecursive(vector<int>& nums, int i,int target)
{
    if (i==nums.size())
    {
        return -1;
    }
    if (nums[i]==target)
    {
        return i;
    }
    linearSearchRecursive(nums,i+1,target);
}

int linearSearch(vector<int>& nums, int target)
{
    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        if(nums[i]==target) return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Please enter the size of array : ";
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cout<<"Please enter the element of nums : ";
        cin>>nums[i];
    }

    int target;
    cout<<"Please Enter the target : ";
    cin>>target;

    int result = linearSearchRecursive(nums,0,target);
    if(result==-1)
    {
        cout<<"Element not found in array";
    }
    else{
         cout<<"Element found at index : "<<result;
    }
    
    return 0;
}