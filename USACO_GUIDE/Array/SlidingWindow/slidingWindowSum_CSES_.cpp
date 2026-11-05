#include<bits/stdc++.h>
using namespace std;

#define VI vector<long long>

VI inputGenerator(int n, int x, int a, int b, int c)
{
    VI result(n);
    result[0]=x;
    for(int i=1; i<n; i++)
    {
        result[i]=((1LL*a*result[i-1])+b)%c;
    }
    return result;
}

VI windowsSumGenerator(VI nums, int k)
{
    int n=nums.size();
    long long sum=0;
    VI result;
    for (int i = 0; i < k; i++)
    {
        sum+=nums[i];
    }
    result.push_back(sum);
    for (int i = k; i < n; i++)
    {
        sum-=nums[i-k];
        sum+=nums[i];
        result.push_back(sum);
    }
    return result;
}

long long xorOperation(VI nums)
{
    long long result=nums[0];
    int n=nums.size();
    for(int i=1; i<n; i++)
        result=(result^nums[i]);
    return result;
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    int x,a,b,c;
    cin>>n>>k;
    cin>>x>>a>>b>>c;

    VI nums=inputGenerator(n,x,a,b,c);
    VI windowSums=windowsSumGenerator(nums,k);
    long long result=xorOperation(windowSums);
    cout<<result;
    return 0;
}