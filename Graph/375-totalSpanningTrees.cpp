/*
Total number of Spanning Trees in a Graph

    Difficulty Level : Hard
    Last Updated : 17 May, 2018

If a graph is a complete graph with n vertices, then total number of spanning trees is n(n-2) where n is the number of nodes in the graph. In complete graph, the task is equal to counting different labeled trees with n nodes for which have Cayley’s formula.

What if graph is not complete?
Follow the given procedure :-
STEP 1: Create Adjacency Matrix for the given graph.
STEP 2: Replace all the diagonal elements with the degree of nodes. For eg. element at (1,1) position of adjacency matrix will be replaced by the degree of node 1, element at (2,2) position of adjacency matrix will be replaced by the degree of node 2, and so on.
STEP 3: Replace all non-diagonal 1’s with -1.
STEP 4: Calculate co-factor for any element.
STEP 5: The cofactor that you get is the total number of spanning tree for that graph.

Consider the following graph:
kirchoff-formula

Adjacency Matrix for the above graph will be as follows:
kirchoff-matrix

After applying STEP 2 and STEP 3, adjacency matrix will look like
kirchoff-theorem


The co-factor for (1, 1) is 8. Hence total no. of spanning tree that can be formed is 8.
NOTE- Co-factor for all the elements will be same. Hence we can compute co-factor for any element of the matrix.

This method is also known as Kirchhoff’s Theorem. It can be applied to complete graphs also.
*/

#include <bits/stdc++.h>
using namespace std;

int degree(int v, int **grp, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (grp[v][i])
            count++;

    return count;
}

int totalSpanTree(int **grp, int n)
{
    int **mat = new int *[n];

    // create a laplacian matrix
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mat[i][j] = degree(i, grp, n);
            }
            else if (grp[i][j])
                mat[i][j] = -1;
            else
                mat[i][j] = 0;
        }
    }

    int totalSpanningTree; // total spanning tree = cofactor of any diagonal element of laplacian matrix

    // Now to find determinant is hard. Don't know algo to find

    return 0;
}
int main()
{
    int n;
    cin >> n;

    int **grp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        grp[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> grp[i][j];
    }

    cout << totalSpanTree(grp, n) << endl;
    delete grp[n];
    return 0;
}