/*
733. Flood Fill
Easy

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]

 

Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], newColor < 216
    0 <= sr < m
    0 <= sc < n


*/

class Solution
{
public:
    inline bool isSafe(int x, int y, int m, int n)
    {
        if (x >= 0 and y >= 0 and x < m and y < n)
            return true;
        return false;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];

        vector<vector<int>> vis(m, vector<int>(n, 0));

        vis[sr][sc] = 1;
        image[sr][sc] = newColor;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            int size = q.size();
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dx[4] = {1, 0, 0, -1};
            int dy[4] = {0, -1, 1, 0};
            while (size--)
            {
                for (int i = 0; i < 4; i++)
                {
                    int X = x + dx[i];
                    int Y = y + dy[i];

                    if (isSafe(X, Y, m, n) and !vis[X][Y] and image[X][Y] == oldColor)
                    {
                        image[X][Y] = newColor;
                        vis[X][Y] = 1;
                        q.push({X, Y});
                    }
                }
            }
        }
        return image;
    }
};