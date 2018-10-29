#include <iostream>
#include <vector>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<pair<int, int>> adj_list[], int vertex_one, int vertex_two, int weight)
{
    adj_list[vertex_one].push_back(make_pair(vertex_two, weight));
    adj_list[vertex_two].push_back(make_pair(vertex_one, weight));
}

void dijkstra (vector<pair<int, int>> adj_list[], int num_vertices, int source_vertex)
{
    /*Init */
    vector<int> min_dist (num_vertices, INT_MAX);
    vector<bool> processed_vertex (num_vertices, false);
    min_dist[source_vertex] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next_elem_queue;
    next_elem_queue.push(make_pair(0, source_vertex));

    /*Dijkstra's Algorithm*/
    while(!next_elem_queue.empty())
    {
        int cur_vertex = next_elem_queue.top().second;
        next_elem_queue.pop();
        processed_vertex [cur_vertex] = true;
        for (auto& adj_vertex: adj_list[cur_vertex])
        {
            if (!processed_vertex[adj_vertex.first] && min_dist[cur_vertex]+adj_vertex.second < min_dist[adj_vertex.first])
            {
                min_dist[adj_vertex.first] = min_dist[cur_vertex]+adj_vertex.second;
                next_elem_queue.push(make_pair(min_dist[adj_vertex.first], adj_vertex.first));
            }
        }
    }

    /*Display all-points shortest distance from source*/
    for (int i=0; i<num_vertices; i++)
    {
        cout<<"vertex_ID:"<<i<<": "<<min_dist[i]<<"\n";
    }
}

int main(int argc, char** argv)
{
    int num_vertices = 9;
    vector<pair<int, int>> adj_list[num_vertices];
    addEdge(adj_list, 0, 1, 4); 
    addEdge(adj_list, 0, 7, 8); 
    addEdge(adj_list, 1, 2, 8); 
    addEdge(adj_list, 1, 7, 11); 
    addEdge(adj_list, 2, 3, 7); 
    addEdge(adj_list, 2, 8, 2); 
    addEdge(adj_list, 2, 5, 4); 
    addEdge(adj_list, 3, 4, 9); 
    addEdge(adj_list, 3, 5, 14); 
    addEdge(adj_list, 4, 5, 10); 
    addEdge(adj_list, 5, 6, 2); 
    addEdge(adj_list, 6, 7, 1); 
    addEdge(adj_list, 6, 8, 6); 
    addEdge(adj_list, 7, 8, 7); 
    dijkstra(adj_list, num_vertices, 0); 
    return 0;
}