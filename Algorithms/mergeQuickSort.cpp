#include<iostream>
#include<vector>
using namespace std;


// Quick Search
int partition(vector<int>& nums, int low, int high)
{
    int pivot=nums[low], i=low, j=high;
    while (i<j)
    {
        while (i<=high && nums[i]<=pivot)
        {
            i++;
        }
        while (j>=low && nums[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[low],nums[j]);
    return j;
}

void quickSort(vector<int>& nums, int low, int high)
{
    if(low<high)
    {
        int index=partition(nums,low,high);
        quickSort(nums,low,index-1);
        quickSort(nums,index+1,high);
    }
}

//Merge Sort

void merge(vector<int>& nums, int low, int mid, int high)
{
    vector<int> temp;
    int left=low,right=mid+1;
    while (left<=mid && right<=high)
    {
        if(nums[left]<=nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left<=mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    
    while (right<=high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low; i<=high; i++)
    {
        nums[i]=temp[i-low];
    }
}

void mergeSort(vector<int>& nums, int low, int high)
{
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums,low,mid,high);
}

int main(int argc, char const *argv[])
{
    vector<int> nums={9,8,7,6,5,4,3};
    mergeSort(nums,0,nums.size()-1);
    for(int n : nums)
    {
        cout<<n<<"\t";
    }
    return 0;
}