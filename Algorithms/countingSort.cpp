#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>
using namespace std;

vector<int> countingSort(vector<int>& arr)
{
    int n=arr.size();
    int maxVal=INT_MIN;

    for (int i = 0; i <n; i++)
    {
        maxVal=max(maxVal,arr[i]);
    }
    vector<int> countArray(maxVal+1,0);

    for (int i = 0; i <n; i++)
    {
        countArray[arr[i]]++;
    }
    
    for (int i = 1; i <= maxVal; i++)
    {
        countArray[i]+=countArray[i-1];
    }
    
    vector<int> ans(n);
    for (int i = n-1; i >=0; i--)
    {
        ans[countArray[arr[i]]-1]=arr[i];
        countArray[arr[i]]--;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2,5,3,0,2,3,0,3};
    vector<int> ans = countingSort(arr);

    for (int x : ans)
        cout << x << " ";
    return 0;
}