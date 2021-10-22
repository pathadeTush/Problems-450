class Solution
{
public:
    int areaOfHistogram(vector<int> v)
    {
        int leftBoundary[v.size()];
        int rightBoundary[v.size()];

        leftBoundary[0] = -1;

        stack<int> s; // stores the index
        s.push(0);

        // for left bound
        for (int i = 1; i < v.size(); i++)
        {

            while (!s.empty() and v[s.top()] >= v[i])
                s.pop();

            if (s.empty())
                leftBoundary[i] = -1;
            else
                leftBoundary[i] = s.top();

            s.push(i);
        }

        while (s.size() > 0)
            s.pop();

        rightBoundary[v.size() - 1] = v.size();
        s.push(v.size() - 1);

        // for right bound
        for (int i = v.size() - 2; i >= 0; i--)
        {

            while (!s.empty() and v[s.top()] >= v[i])
                s.pop();

            if (s.empty())
                rightBoundary[i] = v.size();
            else
                rightBoundary[i] = s.top();

            s.push(i);
        }

        // width = rb - lb - 1
        // area = width * v[i]

        int maxArea = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int width = rightBoundary[i] - leftBoundary[i] - 1;

            //cout << width << " " << i << endl;

            maxArea = max(maxArea, v[i] * width);
        }

        return maxArea;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {

        vector<int> histogram;
        histogram.assign(m, 0);

        int maxarea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // cout << M[i][j] << " ";

                if (M[i][j] == 1)
                    histogram[j]++;
                else
                    histogram[j] = 0;

                //cout << histogram[j] << " " << j << " " << M[i][j] << " ";
            }

            cout << endl;

            int k = areaOfHistogram(histogram);
            maxarea = max(maxarea, k);
            // cout << k << " ";
        }

        return maxarea;
    }
};