#include<bits/stdc++.h>
using namespace std;
bool vis[105];
bool pathvis[105];
vector<int> adj_list[105];
bool hasCycle = false;
int n, e;

void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;
    for(int child: adj_list[src])
    {
        if(vis[child] && pathvis[child])
            hasCycle = true;
        if(!vis[child]){
            dfs(child);
        }
    }

    pathvis[src] = false;
}

int main()
{
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));

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