// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool canColor(int vert, bool graph[101][101], int color[], int v, int col)
{
    for(int k=0; k<v; k++)
    {
        if(k!=vert && graph[k][vert]==1 && color[k]==col)
            return false;
    }
    
    return true;
}

bool solve(int vert, bool graph[101][101], int m, int v, int color[])
{
    if(vert == v)
        return true;
    
    for(int i=1; i<=m; i++)
    {
        if(canColor(vert, graph, color, v, i))
        {
            color[vert]=i;
            if(solve(vert+1, graph, m, v, color))
                return true;
            color[vert]=0;

        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int v)
{
    int color[v]={0};
    
    if(solve(0, graph, m, v, color))
        return true;
        
    return false;
    // your code here
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends