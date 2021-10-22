// int getMinDiff(int arr[], int n, int k)
// {
//     // height vector will have possible heights after modification
//     vector<pair<int, int>> heights; // index and modified heights

//     for (int i = 0; i < n; i++)
//     {
//         pair<int, int> p;

//         if (arr[i] >= k)
//         {
//             p.first = arr[i] - k;
//             p.second = i;
//             heights.push_back(p);
//         }

//         p.first = arr[i] + k;
//         p.second = i;
//         heights.push_back(p);
//     }

//     sort(heights.begin(), heights.end());
//     vector<int> visited(n); // vector to keep track of element which are visited already

//     int minDiff = INT_MAX, windowSize = 0, leftBoundary, rightBoundary;

//     for (int i = 0; i < heights.size(); i++)
//     {

//         if (!visited[heights[i].second])
//         {
//             if (windowSize == 0)
//                 leftBoundary = heights[i].first;
//             windowSize++;
//             visited[heights[i].second] = 1;
//         }

//         if (windowSize == n)
//         {
//             rightBoundary = heights[i].first;
//             minDiff = min(minDiff, (rightBoundary - leftBoundary));
//             windowSize = 0;
//             i = leftBoundary;
//             visited.clear();
//         }
//     }

//     return minDiff;
// }

int getMinDiff(int arr[], int n, int k)
{

    vector<pair<int, int>> heightPair; // stores possible heights after modification
    vector<int> visited(n);

    for (int i = 0; i < n; i++)
    {

        if (arr[i] - k >= 0)
        {
            heightPair.push_back({arr[i] - k, i});
        }
        heightPair.push_back({arr[i] + k, i});
    }

    sort(heightPair.begin(), heightPair.end());

    int count = 0;
    int left = 0;
    int right = 0;

    while (count < n && right < heightPair.size())
    {
        if (visited[heightPair[right].second] == 0)
            count++;

        visited[heightPair[right].second]++;
        right++;
    }

    int ans = heightPair[right - 1].first - heightPair[left].first;

    while (right < heightPair.size())
    {
        if (visited[heightPair[left].second] == 1)
            count--;

        visited[heightPair[left].second]--;
        left++;

        while (count < n && right < heightPair.size())
        {
            if (visited[heightPair[right].second] == 0)
                count++;

            visited[heightPair[right].second]++;
            right++;
        }

        if (count == n)
            ans = min(ans, (heightPair[right - 1].first - heightPair[left].first));
        else
            break;
    }

    return ans;
}