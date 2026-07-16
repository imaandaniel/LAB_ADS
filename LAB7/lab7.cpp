#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;

    Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
};

void addEdge(Node** adj, int u, int v, int w) {
    Node* newNode = new Node(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dijkstra(Node** adj, int V, int src, int* dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d > dist[u])
            continue;

        Node* current = adj[u];
        while (current != nullptr) {
            int v = current->vertex;
            int w = current->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }

            current = current->next;
        }
    }
}

int main() {
    int src = 0;
    int V = 5;

    Node* adj[5] = {nullptr};

    addEdge(adj, 0, 2, 8);
    addEdge(adj, 0, 1, 4);

    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 4, 6);
    addEdge(adj, 1, 0, 4);

    addEdge(adj, 2, 1, 3);
    addEdge(adj, 2, 3, 2);
    addEdge(adj, 2, 0, 8);

    addEdge(adj, 3, 4, 10);
    addEdge(adj, 3, 2, 2);

    addEdge(adj, 4, 3, 10);
    addEdge(adj, 4, 1, 6);

    int dist[5];

    dijkstra(adj, V, src, dist);

    cout << "Shortest distances from starting vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "To vertex " << i << " -> Unreachable\n";
        } else {
            cout << "To vertex " << i << " -> Total Weight: " << dist[i] << "\n";
        }
    }

    for (int i = 0; i < V; ++i) {
        Node* current = adj[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}