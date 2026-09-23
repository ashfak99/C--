#include<bits/stdc++.h>
using namespace std;

int getPeg(char c)
{
    return c=='S'?1:(c=='D' ? 2:3);
}

void towerOfHanoi(char s, char d, char e, int n, vector<vector<int>>& nums)
{
    if(n<=0) return;

    towerOfHanoi(s,e,d,n-1,nums);
    nums.push_back({getPeg(s), getPeg(d)});
    towerOfHanoi(e,d,s,n-1,nums);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<vector<int>> result;

    towerOfHanoi('S','E','D',n,result);
    cout<<result.size()<<"\n";
    for(auto r : result)
    {
        for(int n : r)
        {
            cout<<n<<" ";
        }
        cout<<"\n";
    }
    return 0;
}