//
// Created by Vedant Nilabh on 3/15/23.
//

#include "MyGraph.h"
#include <float.h>

MyGraph::MyGraph(int n) {
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        vector<float> temp2;
        adjList.push_back(temp);
        weightList.push_back(temp2);
    }

}
MyGraph::MyGraph(const MyGraph &g) {
    adjList = g.adjList;


}
bool MyGraph::AddEdge(int a, int b, float w) {
    if(a < 0 || b < 0 || a >= adjList.size() || b >= adjList.size()) {
        return false;
    }
    // else if - check if edge already exists
    else if(find(adjList[a].begin(), adjList[a].end(), b) != adjList[a].end()) {
        return false;
    }
    adjList[a].push_back(b);\
    weightList[a].push_back(-w);
    adjList[b].push_back(a);
    weightList[b].push_back(-w);
    return true;
}
void MyGraph::output(ostream &os) {
    os << "Number of vertices: " << adjList.size() << endl;
    // Each subsequent line prints an edge. print the smallest vertex first, followed by the larger vertex and then the weight
    for(int i = 0; i < adjList.size(); i++) {
        for(int j = 0; j < adjList[i].size(); j++) {
            if(i < adjList[i][j]) {
                os << i << " " << adjList[i][j] << " " << -weightList[i][j] << endl;
            }
        }
    }

}
pair<vector<int>, float> MyGraph::HW2Prog(int s, int t, bool printMST) {
    pair<vector<int>, vector<float>> MST;
    vector<int> nearest;
    vector<float> distance;
    vector<bool> InY;

    // initialize nearest, distance, and InY
    nearest.push_back(0);
    distance.push_back(0);
    InY.push_back(true);
    for (int i = 1; i < adjList.size(); i++) {
        nearest.push_back(0);
        // if there is an edge from 0 to i, set distance[i] to the weight of the edge else set it to infinity
        auto found = find(adjList[0].begin(), adjList[0].end(), i);
        if (found != adjList[0].end()) {
            distance.push_back(weightList[0][found - adjList[0].begin()]);
        } else {
            distance.push_back(FLT_MAX);
        }
        InY.push_back(false);
    }
    for (int count = 1; count < adjList.size(); count++) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int i = 1; i < adjList.size(); i++) {
            // find the vertex i that is not in Y and has the smallest distance[i]
            if (InY[i] == false && distance[i] < min) {
                min = distance[i];
                minIndex = i;
            }
        }
        // add nearest[minIndex] and minIndex to MST
        MST.first.push_back(nearest[minIndex]);
        MST.first.push_back(minIndex);
        MST.second.push_back(min);
        InY[minIndex] = true;
        for (int i = 1; i < adjList.size(); i++) {
            auto it = find(adjList[minIndex].begin(), adjList[minIndex].end(), i);
            if (it != adjList[minIndex].end()) {
                // if there is an edge from minIndex to i, update distance[i] if necessary
                int index = it - adjList[minIndex].begin(); {
                    if (weightList[minIndex][index] < distance[i]) {
                        distance[i] = weightList[minIndex][index];
                        nearest[i] = minIndex;
                    }
                }
            }
        }


    }
    if (printMST) {
        cout << "MST: " << endl;
        for (int i = 0; i < MST.second.size(); i++) {
            cout << MST.first[i * 2] << " " << MST.first[i * 2 + 1] << " " << -MST.second[i] << endl;
        }
    }
    // using DFS to find the path from s to t on the MST
    pair<vector<int>, float> res;
    vector<vector<int>> edges;
    vector<vector<float>> weights;
    for (int i = 0; i < adjList.size(); i++) {
        vector<int> temp;
        edges.push_back(temp);
    }
    for (int i = 0; i < adjList.size(); i++) {
        vector<float> temp;
        weights.push_back(temp);
    }

    for (int i = 0; i < MST.first.size(); i += 2) {
        edges[MST.first[i]].push_back(MST.first[i + 1]);
        edges[MST.first[i + 1]].push_back(MST.first[i]);
    }
    for(int i = 0; i < MST.first.size(); i += 2) {
        weights[MST.first[i]].push_back(MST.second[i / 2]);
        weights[MST.first[i + 1]].push_back(MST.second[i / 2]);
    }
    vector<bool> visited;
    for (int i = 0; i < adjList.size(); i++) {
        visited.push_back(false);
    }
    vector<int> stackVector;
    vector<float> weightVector;
    stackVector.push_back(s);
    visited[s] = true;
while (!stackVector.empty()) {
        int top = stackVector.back();
        if (top == t) {
            break;
        }
        bool found = false;
        for (int i = 0; i < edges[top].size(); i++) {
            if (!visited[edges[top][i]]) {
                // if the vertex is not visited, push it to the stack
                stackVector.push_back(edges[top][i]);
                weightVector.push_back(weights[top][i]);
                visited[edges[top][i]] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            // if there is no unvisited vertex adjacent to the top vertex, pop the top vertex

            stackVector.pop_back();
            weightVector.pop_back();

        }
    }



    res.first = stackVector;
    float max = -FLT_MAX;
    // finding the minimum weight (max because we are using -G) of the edges on the path
    for (int i = 0; i < weightVector.size(); i++) {
        if (weightVector[i] > max) {
            max = weightVector[i];
        }
    }
    res.second = -max;
    return res;
}
















