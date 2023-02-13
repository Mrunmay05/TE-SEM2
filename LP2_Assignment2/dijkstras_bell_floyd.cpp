#include<bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node *next;

    public:
        Node(int data, Node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    friend class Graph;
};


class Graph
{
private:
    int vertices;
    int edges;
    Node **graph;
    bool *visited;
public:

    Graph(int vertices=0, int edges=0)
    {
        this->vertices = vertices;
        this->edges = edges;
        graph = new Node*[vertices];
        visited[vertices] = new bool[vertices];
        for(int i = 0; i < vertices; i++)
        {
            graph[i] = nullptr;
            visited[i] = false;
        }
    }
    void acceptGraph(){
        int source,destination;
        for(int i = 0; i < edges; i++)
        {
            cout<<"Enter the source: "<<endl;
            cin>>source;
            cout<<"Enter the destination: "<<endl;
            cin>>destination;
            addEdge(source,destination);
        }
    }
    void addEdge(int source, int destination)
    {
        Node *dest = new Node(destination);

        if(graph[source] == nullptr)
        {
            graph[source] = dest;
        }
        else
        {
            Node *temp = graph[source];
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = dest;
        }
    }
    void bfs(int src)
    {
        bool bvisited[vertices] = {false};
        queue<int>q;    
        q.push(src);    

        while(!q.empty())
        {
            src = q.front();
            cout<<src<<" ";
            q.pop();

            Node *start = graph[src];
            while(start != nullptr)
            {
                if(!bvisited[start->data])
                {
                    bvisited[start->data] = true;
                    q.push(start->data);
                }
                start = start->next;
            }


        }

    }
    void display()
    {
        for(int i = 0; i < vertices; i++)
        {
            cout<<i<<": ";
            Node *temp = graph[i];

            while(temp != nullptr)
            {
            cout<<temp->data<<" -> ";
            temp = temp->next;
            }
            cout<<endl;
        }
    }
    void dfs(int start)
    {
        visited[start] =true;
        cout<<start<<" ";
        Node *temp = graph[start];

        while(temp != nullptr)
        {
            if(!visited[temp->data])
                dfs(temp->data);
            temp = temp->next;
        }
    }
};

int main()
{


    int edges,vertices;
    cout<<"Enter the edges: ";
    cin>>edges;
    cout<<endl;
    cout<<"Enter the vertices: ";
    cin>>vertices;
    cout<<endl;
    Graph graph(vertices,edges);
    graph.acceptGraph();
    // graph.display();
    // graph.bfs(0);
    graph.dfs(0);

    return 0;
}