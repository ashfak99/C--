#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        
        int maxKeep=0;

        for(int i=0; i<n; i++)
        {
            long long p=nums[i];
            int cnt=0;
            for(int j=0; j<n; j++)
            {
                if(nums[j]%p==0)
                    cnt++;
            }
            maxKeep=max(maxKeep,cnt);
        }
        cout<<n-maxKeep<<"\n";
    }
    return 0;
}