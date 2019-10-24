//
// Created by Miłosz Chodkowski on 10/20/19.
//    ______ ______ ______                                                    _
//   |____  |____  |____  |                                                  | |
//       / /    / /    / /   _ __ ___   ___  _ __   ___ _   _ _ __ ___   __ _| | _____ _ __
//      / /    / /    / /   | '_ ` _ \ / _ \| '_ \ / _ | | | | '_ ` _ \ / _` | |/ / _ | '__|
//     / /    / /    / /    | | | | | | (_) | | | |  __| |_| | | | | | | (_| |   |  __| |
//    /_/    /_/    /_/     |_| |_| |_|\___/|_| |_|\___|\__, |_| |_| |_|\__,_|_|\_\___|_|
//                                                       __/ |
//

#ifndef SJP_GRAPH_GRAPH_H
#define SJP_GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Graph{
public:
    int num_of_vert = 0;
    int adj_matrix[50][50] = {0};
    vector<int> adj_list[50];

    explicit Graph(int nv=5);

    bool isAdjoint();

    void createMatrix();

    void printMatrix();

    void clearMatrix();

    void createList();

    void printList();

    void clearList();

    void addArc(int &tail, int &head);

    void removeArc(int &tail, int &head);

    void saveGraph();

    void loadGraph();
};


#endif //SJP_GRAPH_GRAPH_H
