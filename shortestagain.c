#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define V 5

int mindistance(bool visited[],int dist[])
{
    int min=INT_MAX,min_index=0;
    for(int v=0;v<V;v++)
    {
        if(visited[v]==false && dist[v]<=min)
            min_index=v,min=dist[v];
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    bool visited[V];
    int dist[V];
    for(int i=0;i<V;i++)
        visited[i]=false,dist[i]=INT_MAX;
    dist[src]=0;
    for(int count=0;count<V;count++)
    {
        int u=mindistance(visited,dist);
        visited[u] = true;
        for(int v=0;v<V;v++)
        {
            if(!visited[v] && graph[u][v] && graph[v]>graph[u]+graph[u][v] && dist[u]!=INT_MAX)
                dist[v] = dist[u]+graph[u][v];
        }
    }
    for(int i=0;i<V;i++)
        printf("%d\n",dist[i]);
}

int main()
{
    int graph[V][V] = {
        {0,1,4,0,0},
        {1,0,3,1,0},
        {4,3,0,1,3},
        {0,1,1,0,1},
        {0,0,3,1,0}
    };
    dijkstra(graph,0);
    return 0;
}