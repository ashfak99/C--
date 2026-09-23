#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        if(a+b==c) cout<<"+"<<"\n";
        else cout<<"-"<<"\n";
    }
    return 0;
}