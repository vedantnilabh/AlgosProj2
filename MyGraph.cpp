//
// Created by Vedant Nilabh on 3/15/23.
//

#include "MyGraph.h"

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
    weightList[a].push_back(w);
    adjList[b].push_back(a);
    weightList[b].push_back(w);
    return true;
}
void MyGraph::output(ostream &os) {

}
pair<vector<int>, float> MyGraph::HW2Prog(int s, int t, bool printMST) {
    pair<vector<int>, float> res;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << " : ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }






    return pair<vector<int>, float>();
}

