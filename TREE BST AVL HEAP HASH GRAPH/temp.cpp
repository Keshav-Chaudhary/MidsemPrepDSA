#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath> // Include cmath for integer division
using namespace std;

struct Edge {
    int to;
    int Ai, Bi;
};

struct Node {
    int city;
    long long time;

    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int Ui, Vi, Bi, Ai;
        cin >> Ui >> Vi >> Bi >> Ai;
        graph[Ui].push_back({Vi, Ai, Bi});
        graph[Vi].push_back({Ui, Ai, Bi}); // Undirected road
    }

    vector<long long> dist(N + 1, numeric_limits<long long>::max());
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, 0});
    dist[1] = 0;

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.city == N) {
            cout << curr.time << endl;
            return 0;
        }

        for (const Edge& edge : graph[curr.city]) {
            long long travel_time = ((edge.Ai) / (curr.time + 1)) + edge.Bi;
            long long new_time = curr.time + travel_time;
            if (new_time < dist[edge.to]) {
                dist[edge.to] = new_time;
                pq.push({edge.to, new_time});
            }
        }
    }

    cout << -1 << endl; // Unable to reach city N
    return 0;
}
