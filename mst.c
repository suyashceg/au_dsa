#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
 
// Number of vertices in the graph
#define V 5

int min_dist(bool visited[], int dist[])
{
    int min_dist = INT_MAX,min_index = 0;
    for(int i=0;i<V;i++)
        if(min_dist>=dist[i] && visited[i]!=true)
            min_dist = dist[i],min_index=i;
    return min_index;
}

int mst(int g[V][V])
{
    int parent[V];
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;
    dist[0] = 0;
    parent[0] = -1;

    for(int count=0;count<V-1;count++)
    {
        int u = min_dist(visited,dist);
        visited[u] = true;
        for(int v=0;v<V;v++)
        {
            if(!visited[v] && g[u][v] && g[u][v]<dist[v])
            {
                parent[v] = u;
                dist[v] = g[u][v];
            }
        }
    }    
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               g[i][parent[i]]);
}

int main()
{
     int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    mst(graph);
 
    return 0;
}

