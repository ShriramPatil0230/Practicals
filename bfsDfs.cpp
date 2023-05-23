#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <omp.h>

using namespace std;

void parallelBFS(vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    queue<int> bfsQueue;

    visited[start] = true;
    bfsQueue.push(start);

    while (!bfsQueue.empty()) {
        int currVertex = bfsQueue.front();
        bfsQueue.pop();

        cout << currVertex << " "; // Print visited vertex

        #pragma omp parallel for
        for (int neighbor : graph[currVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                bfsQueue.push(neighbor);
            }
        }
    }
}

// void parallelDFS(vector<vector<int>>& graph, int start) {
//     int numVertices = graph.size();
//     vector<bool> visited(numVertices, false);
//     stack<int> dfsStack;

//     visited[start] = true;
//     dfsStack.push(start);

//     while (!dfsStack.empty()) {
//         int currVertex = dfsStack.top();
//         dfsStack.pop();

//         cout << currVertex << " "; // Print visited vertex

//         #pragma omp parallel for
//         for (int neighbor : graph[currVertex]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 dfsStack.push(neighbor);
//             }
//         }
//     }
// }

int main() {
    vector<vector<int>> graph = {
        {1, 4},
        {0, 2},
        {1},
        {1},
        {0, 5},
        {8}
    };

    int startVertex = 0;

    cout << "Parallel Breadth First Search (BFS):" << endl;
    parallelBFS(graph, startVertex);
    cout << endl;

    // cout << "Parallel Depth First Search (DFS):" << endl;
    // parallelDFS(graph, startVertex);
    // cout << endl;

    return 0;
}
