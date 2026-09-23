#include<bits/stdc++.h>
using namespace  std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        vector<int> nums(n);
        int temp;
        int countZero=0;

        for (int i = 0; i < n; i++)
        {
            cin>>temp;
            if(temp==0) countZero++;
            nums[i]=temp;
        }
        
        if(nums[0]==0)
        {
            if(nums[n-1]==0)
            {
                cout<<0<<"\n";
            }
            else{
                if(countZero>=2)
                {
                    cout<<1<<"\n";
                }
                else{
                    cout<<-1<<"\n";
                }
            }
        }
        else{
            if(nums[n-1]==0)
            {
                if(countZero>=2)
                {
                    cout<<1<<"\n";
                }
                else{
                    cout<<-1<<"\n";
                }
            }
            else{
                if(countZero>=2)
                {
                    cout<<2<<"\n";
                }
                else{
                    cout<<-1<<"\n";
                }
            }
        }
    }
    return 0;
}