#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right

int row_num, col_num;

bool valid(int i, int j)
{
    if (i < 0 || i >= row_num || j < 0 || j >= col_num)
        return false;
    return true;
}

void bfs_on_2D_grid(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + dir[i].first;
            int cj = par_j + dir[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> row_num >> col_num;
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    bfs_on_2D_grid(si, sj);

    cout << level[di][dj] << endl;

    return 0;
}