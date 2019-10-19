#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

bool bfs(vector<vector<long>> & rGraph, int s, int t, vector<long> & parent) 
{ 
    int V = rGraph.size();
    // Create a visited array and mark all vertices as not visited 
    vector<bool> visited(V, false);
  
    // Create a queue, enqueue source vertex and mark source vertex 
    // as visited 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<V; v++) 
        { 
            if (!visited[v] && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    // If we reached sink in BFS starting from source, then return 
    // true, else false 
    return visited[t]; 
} 
  
// Returns the maximum flow from s to t in the given graph 
long fordFulkerson(vector<vector<long>> & graph, int s, int t) 
{ 
    int u, v; 
    int V = graph.size();
  
    // Create a residual graph and fill the residual graph with 
    // given capacities in the original graph as residual capacities 
    // in residual graph 
    
    // Residual graph where rGraph[i][j] indicates  
                     // residual capacity of edge from i to j (if there 
                     // is an edge. If rGraph[i][j] is 0, then there is not)
    vector<vector<long>> rGraph(V, vector<long>(V));
    for (u = 0; u < V; u++) 
        for (v = 0; v < V; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    // This array is filled by BFS and to store path
    vector<long> parent(V);
  
    long max_flow = 0;  // There is no flow initially 
  
    // Augment the flow while tere is path from source to sink 
    while (bfs(rGraph, s, t, parent)) 
    { 
        // Find minimum residual capacity of the edges along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        long path_flow = LONG_MAX; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]);
            //cout << v << " ";
        }
        
        //cout << " - " << path_flow << endl;
  
        // update residual capacities of the edges and reverse edges 
        // along the path 
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
  
        // Add path flow to overall flow 
        max_flow += path_flow; 
    } 
  
    // Return the overall flow 
    return max_flow; 
} 

int main() {
    
    // n + source + drain
    int n; cin >> n;
    vector<vector<long>> towns(n+2, vector<long>(n+2, 0));
    
    // read prices
    vector<long> town_prices;
    long price;
    for(int i = 0; i < n; i++) {
        cin >> price;
        town_prices.push_back(price);
    }
    
    // init graph
    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        towns[x][y] = town_prices[y-1] - town_prices[x-1];
        towns[y][x] = town_prices[x-1] - town_prices[y-1];
    }
    
    // init drain
    for (int i = 0; i < n; i++) {
        towns[i+1][n+1] = LONG_MAX;
    }
    
    // init sources
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        towns[0][x] = LONG_MAX;
        towns[x][n+1] = 0;
    }
    
    cout << fordFulkerson(towns, 0, n+1);
    
    return 0;
}