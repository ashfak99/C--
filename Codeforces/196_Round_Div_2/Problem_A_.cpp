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
        int l,r;
        cin>>l>>r;

        int ans=0;

        if(l>0 || r<0)
            ans=abs(l-r);
        else
            ans=max(0,abs(l+r)-1);
        
        cout<<ans<<"\n";
    }
    return 0;
}