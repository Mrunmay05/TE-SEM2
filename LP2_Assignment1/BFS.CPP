#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;

	// lists
	vector<list<int> > adj;

public:
	Graph(int V);

	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int src, int dest)
{
	adj[src].push_back(dest);
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V, false);

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		
		for (auto adjecent : adj[s]) {
			if (!visited[adjecent]) {
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

int main()
{
	Graph g(9);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(2, 6);
    g.addEdge(2,7);
    g.addEdge(3,8);

	cout << "Following is Breadth First Traversal: "<<endl;
	g.BFS(0);

	return 0;
}
