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
private:
   int num_of_vert = 0;
   int adj_matrix[50][50] = {0};

   bool adjoint_status = true;
   bool line_status = true;
   bool multigraph_status = false;

   vector<int> adj_list[50];
   vector<vector<int> > original_list;
   vector<int> pred_list[50];
   vector<vector<int> > edge_list;

   bool doesHaveAnyPred(const vector<int> &first, const vector<int> &second);

   void clearList();
   void clearPredList();
   void createList();
   void createPredList();
   void clearMatrix();

public:
   explicit Graph(int nv = 5);

   bool getAdjointStatus();
   bool getLineStatus();

   void transformToOriginal();
   void printOriginalList();
   void isAdjoint();
   void isLine();
   void createMatrix();
   void printMatrix();
   void printList();
   void printPredList();
   void saveOriginalGraph();
   void loadGraph();
};


#endif //SJP_GRAPH_GRAPH_H
