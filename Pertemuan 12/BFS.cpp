#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V; // No. of vertices

	vector<list<int>> adj;
public:
	Graph(int V); // Constructor

	void addEdge(int v, int w);
  
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V,false);

	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << "(V" << s << ")"<<endl;
		queue.pop_front();


		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(5);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(1, 3);
	g.addEdge(0, 1);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(4);

	return 0;
}
