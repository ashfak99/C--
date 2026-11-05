#include<bits/stdc++.h>
using namespace std;

#define InputPair pair<pair<int,int>,int>
#define unOdrMap unordered_map<int,int>

InputPair threeSum(vector<int>& nums, int target, unOdrMap& freq)
{
    int n=nums.size();
    if(n<3) return {{-1,-1},-1};
    for(int i=0; i<n-2; i++)
    {
        int resultant=target-nums[i];
        int left=i+1;
        while (left<n-1)
        {
            int complement=resultant-nums[left];
            auto it = freq.find(complement);
            if(it!=freq.end() && it->second!=i && it->second!=left)
            {
                return {{i,left},it->second};
            }
            left++;
        }
    }
    return {{-1,-1},-1};
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , target;
    cin>>n>>target;

    vector<int> nums(n);
    unOdrMap freq;
    freq.reserve(n*2);

    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    for(int i=0; i<n; i++)
        freq[nums[i]]=i;
    
    InputPair result = threeSum(nums,target,freq);

    if(result.first.first==-1)
        cout<<"IMPOSSIBLE";
    else 
        cout<<result.first.first+1<<" "<<result.first.second+1<<" "<<result.second+1;
    return 0;
}