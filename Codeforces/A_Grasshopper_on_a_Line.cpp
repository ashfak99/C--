#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    int x,k;
    cin>>t;
    while (t--)
    {
        cin>>x>>k;
        if(x%k!=0)
        {
            cout<<1<<"\n"<<x<<"\n";
        }
        else{
            cout<<2<<"\n"<<x-1<<" "<<1<<"\n";
        }
    }
    return 0;
}