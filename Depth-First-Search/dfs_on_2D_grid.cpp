#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];

vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};// up, down, left, right

int row_num, col_num;

bool valid(int i, int j){
    if(i < 0 || i >= row_num || j < 0 || j >= col_num)
        return false;
    return true;    
}

void dfs_on_2D_grid(int si, int sj)// source index(i,j)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for(int i =0; i < 4; i++){
        int ci = si + dir[i].first;// ci-> child i
        int cj = sj + dir[i].second; // cj -> child j
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs_on_2D_grid(ci, cj);
    }
}
int main()
{
    cin >> row_num >> col_num;
    // input the grid of '.'
    for(int i = 0; i < row_num; i++)
    {
        for(int j = 0; j < col_num; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int si, sj;
    cin >> si >> sj;

    dfs_on_2D_grid(si, sj);

    // for(int i = 0; i < row_num; i++)
    // {
    //     for(int j = 0; j < col_num; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;

}