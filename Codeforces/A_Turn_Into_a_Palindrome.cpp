#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        char c;
        cin>>n>>c;
        string pali;
        cin>>pali;
        int cost=0;
        for(int i=0; i<n/2; i++)
        {
            if(pali[i]==pali[n-i-1]) continue;

            if(pali[i]==c || pali[n-i-1]==c) cost+=1;
            else cost+=2;
        }
        cout<<cost<<"\n";
    }
    return 0;
}