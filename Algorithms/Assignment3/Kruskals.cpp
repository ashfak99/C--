#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int parent[N], sz[N];

void make(int v)
{
    parent[v]=v;
    sz[v]=1;
}

int find(int v)
{
    if(parent[v]==v)
        return parent[v];
    
    return parent[v]=find(parent[v]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
            swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

int main()
{
    int n,m, total_cost=0;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>m;

    vector<pair<int,pair<int,int>>> edges;
    for (int i = 0; i < m; i++)
    {
        cout<<"Enter the both end vertices and weightage: ";
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i <= n; i++)
    {
        make(i);
    }
    cout<<"Spanning tree endvertices: \n";
    cout<<"V1 V2\n";
    for(auto& edge:edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<"Total cost: "<<total_cost<<endl;
}