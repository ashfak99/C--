#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    unordered_map<int, int> mp;
    mp.reserve(n * 2);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int comp = target - x;

        if(mp.count(comp))
        {
            cout << mp[comp] + 1 << " " << i + 1;
            return 0;
        }

        mp[x] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}