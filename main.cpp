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

#include <iostream>
#include <vector>
#include <string>
#include "Libraries/Graph.h"
#include "Libraries/ProgressBar.hpp"

using namespace std;

int main() {
    srand(time(nullptr));
    string filename; int iters;
    cout<<"Give the number of vertices between 1..50: "<<endl;
    try{
        cin >> iters;
        if(not(cin.good()))
            throw invalid_argument("You can pass only integer type");
        if(iters<1 or iters>50)
            throw invalid_argument("Too low/too high number ");

    }catch(exception &e) {
        cerr << e.what();
        exit(EXIT_FAILURE);
    }

    auto *G = new Graph(iters);
    G->loadGraph();
    G->printMatrix();
    G->printList();
    G->printPredList();
    G->getAdjointStatus();
    G->getLineStatus();

    // =========================
    // CODE BELOW IS A TEST CODE
    // =========================

    /*
    int graphs_to_create = 0, graph_size = 0;
    cout<< "Give number of graphs you want to create: "<<endl;
    cin >> graphs_to_create;
    cout<< "Give the size of graphs: "<<endl;
    cin>>graph_size;

    ProgressBar progressBar(graphs_to_create, 70);
    int count = 0;
    for(int i=0;i<graphs_to_create;i++){
        auto G = new Graph(graph_size);
        if(G->isAdjoint()) {
            count++;
        }
        delete G;
        ++progressBar;
        progressBar.display();
    }
    progressBar.done();
    cout<<"Number of adjoint graphs = "<<count<<endl;
    */

    return 0;
}