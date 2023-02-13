#include<bits/stdc++.h>
using namespace std;

class Graph{
    int num_vertices=0;
    list<int> *adjvertlist;
    bool *visited;

    public:
    Graph(int v){
        num_vertices=v;
        adjvertlist=new list<int>[v];
        visited=new bool[v];
    }
    void addEdge(int src,int dest){
        adjvertlist[src].push_front(dest);
    }
    void DFS(int vert){
        visited[vert]=true;
        list<int> adjlist=adjvertlist[vert];
        cout<<vert<<" ";
        list<int>::iterator i;
        for(i=adjlist.begin();i!=adjlist.end();++i){
            if(!visited[*i]){
                DFS(*i);
            }
        }
    }
};

int main(){
    Graph g1(9);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(0,3);
    g1.addEdge(1,4);
    g1.addEdge(2,5);
    g1.addEdge(2,6);
    g1.addEdge(3,7);
    g1.addEdge(3,8);
    g1.DFS(0);
}