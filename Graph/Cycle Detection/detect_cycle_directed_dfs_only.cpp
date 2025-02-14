#include<bits/stdc++.h>
using namespace std;

bool vis[105];
int parent[105];
vector<int> adj_list[105];
bool hasCycle = false;
int n, e;

void dfs(int src)
{
    vis[src] = true;
    for(int child: adj_list[src])
    {
        if(vis[child] && parent[src] != child)
            hasCycle = true;
        if(!vis[child]){
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }

    if(hasCycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
}