#include<bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj_list[105];

int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}