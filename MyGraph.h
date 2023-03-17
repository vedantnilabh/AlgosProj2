//
// Created by Vedant Nilabh on 3/15/23.
//

#ifndef ALGOSPROJ2_MYGRAPH_H
#define ALGOSPROJ2_MYGRAPH_H
#include <vector>
#include <ostream>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
class MyGraph {
public:
    MyGraph(int n);
    MyGraph(const MyGraph& g);
    bool AddEdge(int a, int b, float w);
    void output(ostream& os);
    pair<vector<int>, float> HW2Prog(int s, int t, bool printMST);
    vector<vector<int>> adjList;
    vector<vector<float>> weightList;

};


#endif //ALGOSPROJ2_MYGRAPH_H
