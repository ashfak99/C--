#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void heapify(vector<int>& nums, int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && nums[left]>nums[largest])
        largest=left;
    
    if(right<n && nums[right]>nums[largest])
        largest=right;
    
    if(largest!=i)
    {
        swap(nums[i],nums[largest]);
        heapify(nums,n,largest);
    }
}

void buildMaxHeap(vector<int>& nums)
{
    int n=nums.size();
    for(int i=floor(n/2)-1; i>=0; i--)
    {
        heapify(nums,n,i);
    }
}

void heapSort(vector<int>& nums)
{
    int n=nums.size();
    for (int i = n-1; i >=1; i--)
    {
        swap(nums[0],nums[i]);
        heapify(nums,i,0);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums={9,8,2,1,4,2,6};
    buildMaxHeap(nums);
    heapSort(nums);
    for(int n: nums)
    {
        cout<<n<<"\t";
    }
    return 0;
}