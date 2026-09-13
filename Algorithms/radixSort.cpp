#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void countingSort(vector<int>& arr, int exp)
{
    int n=arr.size();

    vector<int> count(10,0);

    for(int i=0; i<n; i++)
    {
        int digit=(arr[i]/exp)%10;
        count[digit]++;
    }

    for(int i=1; i<10; i++)
    {
        count[i]+=count[i-1];
    }

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--)
    {
        int digit=(arr[i]/exp)%10;
        ans[count[digit]-1]=arr[i];
        count[digit]--;
    }

    for(int i=0; i<n; i++)
    {
        arr[i]=ans[i];
    }
}

void radixSort(vector<int>& arr)
{
    int maxVal=*max_element(arr.begin(),arr.end());
    for(int exp=1; maxVal/exp>0; exp*=10)
    {
        countingSort(arr,exp);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}