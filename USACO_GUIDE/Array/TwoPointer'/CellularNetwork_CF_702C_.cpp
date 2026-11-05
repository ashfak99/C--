#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<ll> tower(m);
    vector<ll> cities(n);

    for(int i=0; i<n; i++)
        cin>>cities[i];
    
    for(int i=0; i<m; i++)
        cin>>tower[i];

    ll ans=0;
    int j=0;
    for(int i=0; i<n; i++)
    {
        while(j+1<m && llabs(tower[j+1]-cities[i])<=llabs(tower[j]-cities[i]))
            j++;
        ans = max(ans, llabs(tower[j]-cities[i]));
    }

    cout<<ans;
    return 0;
}