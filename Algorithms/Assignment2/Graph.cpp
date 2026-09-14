#include <iostream>
#include <vector>
#include <queue>

using namespace std;


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
void dfs(int start,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         vector<int>& ls)
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


int main()
{
    int n, m;

    cout << "Please enter the number of vertices and edges : ";
    cin >> n >> m;

    // 1-based indexing
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;

        cout << "Enter the both endvertices : ";
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // BFS
    cout << "BFS : ";

    vector<int> bfsResult = bfs(adj);

    for (int node : bfsResult)
    {
        cout << node << " ";
    }


    // DFS
    cout << "\nDFS : ";

    vector<int> dfsResult = dfsGraph(adj);

    for (int node : dfsResult)
    {
        cout << node << " ";
    }


    return 0;
}