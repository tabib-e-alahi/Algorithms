#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
        int a, b, c;
        Edge(int a, int b, int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

int dis[1005];

int main()
{
    int n ,e;
    cin >> n >> e;
    vector<Edge> edge_list;
    while(e--)
    {
        int a, b , c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b ,c));
        // edge_list.push_back(Edge(b, a ,c));// undirected only
    }
    for(int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    // here 0 is the source
    dis[0] = 0;

    for(auto ed: edge_list)
    {
        cout << ed.a << ed.b << ed.c << endl;
    }

}