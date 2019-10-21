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

using namespace std;

int main() {
    string filename; string iters;
    cout<<"Give the number of vertices: "<<endl;
    cin >> iters;
    auto *G = new Graph(stoi(iters));
    G->printMatrix();
    G->printList();
    G->loadGraph();
    G->printMatrix();
    G->printList();
    

    return 0;
}