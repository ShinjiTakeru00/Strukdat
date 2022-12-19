#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

bool foundDFSNode = false;

class Graph
{
  int numVertices;
  list<pair<int, int>> *adjMatrix;
  map<int, bool> visitedDfsNode;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    void BFS(int startVertex, int endVertex);
    void shortestPath(int src, int dest);
    void showMatrix();
    void DFS(int v, int end);
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjMatrix = new list<pair<int, int>>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest, int weight)
{
  adjMatrix[src].push_back(make_pair(dest, weight));
  adjMatrix[src].sort();
}

void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<pair<int, int>>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    // Fungsi memberhentikan BFS
    if (currVertex == endVertex)
    {
      break;
    }
    //
    cout <<  currVertex << " ";
    queue.pop_front();

    for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
    {
      int adjVertex = (*i).first;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
  cout << endl;
}

void Graph::shortestPath(int src, int dest)
{
    // Create a set to store vertices that are being
    // processed
    set<pair<int, int>> setds;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(numVertices, INF);
 
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till all shortest distance are finalized
       then setds will become empty    */
    while (!setds.empty())
    {

        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;
 
        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = adjMatrix[u].begin(); i != adjMatrix[u].end(); ++i)
        {   
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
            //    If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                {
                  setds.erase(setds.find(make_pair(dist[v], v)));
                }
 
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
 
    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < numVertices; ++i)
    {
      if (i == dest)
      {
        break;
      }
      
      printf("%d \t\t %d\n", i, dist[i]);
    }
}

void Graph::DFS(int v, int end)
{
    if (foundDFSNode == false)
    {
    // Mark the current node as visited and
    // print it
    visitedDfsNode[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<pair<int, int>>::iterator i;
 
    // for (i = adjMatrix[v].begin(); i != adjMatrix[v].end(); ++i)
    // {
    //   if (visitedDfsNode[(*i).first] == end)
    //   {
    //     foundDFSNode = true;
    //     break;
    //   }
    // }

      for (i = adjMatrix[v].begin(); i != adjMatrix[v].end(); ++i)
      {

        if (v == end)
        {
          foundDFSNode = true;
          // break;
        }
        if (!visitedDfsNode[(*i).first])
        {
          DFS((*i).first, end);
        }
      }
    }
    
    else
    {

    }
}

void Graph::showMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    list<pair<int, int>>::iterator it;

    int track = 0;
    int through = 0;
    for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
    {
      // int track = 0;
      int temp = (*it).first;
      if (through == 0)
      {
        while (track < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      else
      {
        while ((track + 1) < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      cout << "1 ";
      through++;
    }
    while ((numVertices - through) > 0)
    {
      through++;
      cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  Graph fp(22);
    fp.addEdge(0, 2, 9);
    fp.addEdge(2, 1, 3);
    fp.addEdge(2, 3, 4);
    fp.addEdge(3, 4, 2);
    fp.addEdge(3, 5, 11);
    fp.addEdge(5, 6, 2);
    fp.addEdge(6, 7, 1);
    fp.addEdge(7, 8, 1);
    fp.addEdge(5, 9, 1);
    fp.addEdge(9, 10, 3);
    fp.addEdge(10, 11, 3);
    fp.addEdge(11, 12, 9);
    fp.addEdge(0, 13, 3);
    fp.addEdge(13, 14, 3);
    fp.addEdge(14, 20, 4);
    fp.addEdge(14, 15, 4);
    fp.addEdge(15, 16, 3);
    fp.addEdge(15, 17, 11);
    fp.addEdge(17, 21, 3);
    fp.addEdge(17, 18, 3);
    fp.addEdge(18, 19, 4);

  cout << endl << "----------------BFS---------------" << endl;
  fp.BFS(0, 14);
  cout << endl << "----------------DFS---------------" << endl;
  fp.DFS(0, 14);
  cout << endl << endl << "----------------Dijkstra---------------" << endl;
  fp.shortestPath(0, 14);
  cout << endl << "----------------Adjacency Matrix----------------" << endl;
  fp.showMatrix();

  return 0;
}