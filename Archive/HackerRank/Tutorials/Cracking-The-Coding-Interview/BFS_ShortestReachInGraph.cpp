#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

class Graph {
    private:
        vvi g;
        vi ds;
    public:
        Graph(int n) {
            g = vvi(n+1, vi());
            ds = vi(n, -1);
        }
    
        void add_edge(int u, int v) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            queue<int> q;
            vi al;
            int a, b;
            ds[start] = 0;
            q.push(start);
            while(!q.empty())
            {
                a = q.front();
                q.pop();
                al = g[a];
                for (int i = 0; i < al.size(); i++)
                {
                    b = al[i];
                    if (ds[b] == -1)
                    {
                        ds[b] = ds[a]+1;
                        q.push(b);
                    }
                }
            }
            for (int i = 0; i < ds.size(); i++)
            {
                if (ds[i] != -1)
                    ds[i] *= 6;
            }
            return ds;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}