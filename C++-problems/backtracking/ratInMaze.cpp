// rat in maze problem

#include <bits/stdc++.h>
using namespace std;

// returns true if we can move to x, y position else returns false
bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
        return true;
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **soln)
{
    if (x == n - 1 && y == n - 1)
    {
        soln[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        soln[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, soln))
            return true;
        if (ratInMaze(arr, x, y + 1, n, soln))
            return true;
        soln[x][y] = 0;
        return false;
    }
    return false;
}
/*
maze:
1 0 1 0
1 1 1 1
0 1 1 0
0 0 1 1

soln:
1 0 0 0
1 1 1 0
0 0 1 0
0 0 1 1

*/
int main()
{

    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int **soln = new int *[n];
    for (int i = 0; i < n; i++)
        soln[i] = new int[n];

    if (ratInMaze(arr, 0, 0, n, soln))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << soln[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Path not found! :(";

    return 0;
}