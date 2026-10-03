#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> P;

// Breadth First Search
vector<int> bfs(vector<vector<int>>& adj)
{
    int n = adj.size() - 1;
    int start = 1;

    vector<bool> visited(n + 1, false);

    queue<int> q;

    vector<int> bfsVector;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        bfsVector.push_back(node);

        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsVector;
}


// Depth First Search
void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ls)
{
    visited[start] = true;
    ls.push_back(start);

    for (auto neighbor : adj[start])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, ls);
        }
    }
}


vector<int> dfsGraph(vector<vector<int>>& adj)
{
    int n = adj.size() - 1;
    int start = 1;

    vector<bool> visited(n + 1, false);

    // Initially empty vector
    vector<int> ls;

    dfs(start, adj, visited, ls);

    return ls;
}


   //PRIM'S AGORITHMS

int primsAlgorithm(vector<vector<P>>& adj)
{
    int v=adj.size();
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,0});

    vector<bool> inMST(v,false);

    int sum=0;
    while (!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        int wt=p.first;
        int node=p.second;
        if(inMST[node]){
            continue;}
        inMST[node]=true;
        sum+=wt;
        for(auto& temp:adj[node])
        {
            int neighbour=temp.first;
            int neighbour_wt=temp.second;
            if (!inMST[neighbour])
            {
                pq.push({neighbour_wt, neighbour});
            }
        }
    }
    return sum;
}


int main()
{
    int n, m;

    cout << "Please enter the number of vertices and edges : ";
    cin >> n >> m;

    // 1-based indexing
    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v,w;

        cout << "Enter the both endvertices and weight : ";
        cin >> u >> v >> w;

        // Undirected graph
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int cost=primsAlgorithm(adj);

    cout<<"Cost : "<<cost;

    return 0;
}