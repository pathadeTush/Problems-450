class node
{
public:
    int city;
    int stops;
    int cost;
    node(int a, int b, int c)
    {
        cost = a;
        stops = b;
        city = c;
    }
};

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        //1. Create an Adjacency List
        vector<vector<vector<int>>> adjList(n);

        //example :
        //0 : {1, 100}, {2, 500}
        //1 : {2, 100}
        //2 :

        for (auto f : flights)
        {
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            adjList[from].push_back({to, cost});
            //from : source
            //to : dest
            //cost: cost from 'from' to 'to'
        }

        //2. Create a queue for performing BFS
        queue<vector<int>> q;

        //3. Push source in q as {src, money spent so far, number of stops b/w current city and source}
        q.push({src, 0, -1});
        //Note : if {A, B} are two directly connected cities, then number of stops b/w them is Zero,
        //so for convenience i'm assuming number of stops b/w A and A as -1

        int minCost = INT_MAX; //this keeps track of minimum cost

        while (!q.empty())
        {
            vector<int> curStation = q.front();
            q.pop();

            int curCity = curStation[0];
            int curCost = curStation[1];
            int curK = curStation[2]; //this is the number of stops seen so far from source to current city

            if (curCity == dst)
            {
                minCost = min(minCost, curCost);
                continue;
            }

            for (auto p : adjList[curCity])
            {
                //we include a city in our route only if :
                // > it doesn't exceed number of stops alloted
                // > it keeps cost less than mincost
                //***
                if (curK + 1 <= k and curCost + p[1] < minCost)
                    q.push({p[0], p[1] + curCost, curK + 1});
            }
        }

        return minCost == INT_MAX ? -1 : minCost;
    }

    // ***
    // We could have just normally pushed cities and tested the conditons at the time of popping them from q
    //But what we did is more effecient bcoz, this prevents from inserting the false cities beforehand and keeps the size of q small, (simply, we are saving many PUSH and POP operations).
};
