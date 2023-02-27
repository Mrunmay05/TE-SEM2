#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    vector<vector<int>> adj_mat;

public:
    const int weight_limit = RAND_MAX ;
    int edges = 0;

    Graph(int v)
    {
        vertices = v;
        this->adj_mat = vector<vector<int>>(this->vertices, vector<int>(this->vertices, 1e9));
    }

    
    int get_edges()
    {
        return this->edges;
    }

    void add_edge(int s, int d, int w)
    {
        edges++;
        adj_mat[s][d] = w;
    }


    int minvertex(vector<int> &value, vector<bool> &processed)
    {
        int min = 1e9;
        int vertex;
        for (int i = 0; i < vertices; i++)
        {
            if (processed[i] == false && value[i] < min)
            {
                min = value[i];
                vertex = i;
            }
        }
        return vertex;
    }

    void dijkstras()
    {
        vector<int> parent(vertices);
        vector<int> weight(vertices, 1e9);
        vector<bool> processed(vertices, false);

        parent[0] = -1;
        weight[0] = 0;

        for (int i = 0; i < vertices - 1; i++)
        {

            int u = minvertex(weight, processed);
            processed[u] = true;

            for (int j = 0; j < vertices; j++)
            {
                if (adj_mat[u][j] != 1e9 && processed[j] == false && weight[u] != 1e9 && (weight[u] + adj_mat[u][j] < weight[j]))
                {
                    weight[j] = weight[u] + adj_mat[u][j];
                    parent[j] = u;
                }
            }
        }
        cout << "Printing shortest path from index 0 to all other vertices :" << endl;
        time_t start, end;
        ios_base::sync_with_stdio(false);
        time(&start);
        path_print(parent, weight);
        time(&end);
        double time_taken = double(end - start);
        cout << "The time taken to print the single source shortest path is " << time_taken << setprecision(5);
        cout << " sec " << endl;
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (adj_mat[i][j] == 1e9)
                    cout << "INF"
                         << "     ";
                else
                    cout << adj_mat[i][j] << "     ";
            }
            cout << endl;
        }
    }
    int minDistance(int dist[], bool sptSet[])
    {

        int V = this->vertices;
        // Initialize min value
        int min = 1e9, min_index;

        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
            {
                min = dist[v];
                min_index = v;
            }

        return min_index;
    }
    
    void path_print(vector<int> &parent, vector<int> &weight)
    {
        for (int i = 0; i < vertices; i++)
        {
            vector<int> temp;
            temp.push_back(i);
            int par = parent[i];
            while (par != -1)
            {
                temp.push_back(par);
                par = parent[par];
            }
            for (int j = temp.size() - 1; j > 0; j--)
            {
                cout << temp[j] << "->";
            }
            cout << temp[0];
            cout << "      weight = " << weight[i];
            cout << endl;
        }
    }
};
int main()
{
   cout<<"<--------Menu-------->"<<endl;
   int choice;
   cin >> choice;

   for(int )
   
   return 0;
};