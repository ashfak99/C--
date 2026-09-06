#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int target)
{
    int low = 0, high=nums.size()-1;
    while (low<high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int binarySearchRecursive(vector<int>& nums, int target, int low, int high)
{
    int mid=(high+low)/2;
    if(nums[mid]==target) return mid;
    if(nums[mid]>target) return binarySearchRecursive(nums,target,low,mid-1);
    else return binarySearchRecursive(nums,target,mid+1,high);
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

    sort(nums.begin(),nums.end());

    int result = binarySearchRecursive(nums,target,0,n-1);
    if(result==-1)
    {
        cout<<"Element not found in array";
    }
    else{
         cout<<"Element found at index : "<<result;
    }
    
    return 0;
}