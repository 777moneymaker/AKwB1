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
    srand(time(nullptr));
    string filename; int iters;
    cout<<"Give the number of vertices between 1..50 : "<<endl;
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
    if(G->isAdjoint())
        cout<<"Graph is adjoint! "<<endl;
    else{
        cout<<"Graph not adjoint"<<endl;
        exit(0);
    }
    G->printList();

    return 0;
}