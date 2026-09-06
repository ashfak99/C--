#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& nums)
{
    int n=nums.size();
    for (int i = 0; i <n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]);
        }
    }
}

void selectionSort(vector<int>& nums)
{
    int n=nums.size();
    for(int i=0; i<n-1; i++)
    {
        int min=nums[i];
        int loc=i;
        for(int j=i+1; j<n; j++)
        {
            if(min>nums[j])
            {
                min=nums[j];
                loc=j;
            }
        }
        swap(nums[i],nums[loc]);
    }
}

int insertionSort(vector<int>& nums)
{
    int n=nums.size();
    for (int i = 1; i < n; i++)
    {
        int key=nums[i];
        int j=i-1;
        while (j>-1 && nums[j]>key)
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the size of array ";
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the element of array : ";
        cin>>nums[i];
    }
    insertionSort(nums);
    for(int n : nums)
    {
        cout<<n<<"\t";
    }
    return 0;
}