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
#include "Graph.hpp"
#include "Libraries/ProgressBar.hpp"

using namespace std;

int main(){
   srand(time(nullptr));
   string filename;
   int num_of_vert;
   cout << "Give the number of vertices between 1..50: " << endl;
   try{
      cin >> num_of_vert;
      if(not(cin.good()))
         throw invalid_argument("You can pass only integer type");
      if(num_of_vert < 1 or num_of_vert > 50)
         throw invalid_argument("Too low/too high number ");

   } catch(exception &e){
      cerr << e.what();
      exit(EXIT_FAILURE);
   }

   auto *G = new Graph();
   G->loadGraph();
   G->printList();
   G->printPredList();
   G->isAdjoint();
   G->isLine();
   if(G->getAdjointStatus())
      cout<<"Graph is adjoint;"<<endl;
   else
      cout<<"Graph is not adjoint;"<<endl;
   if(G->getLineStatus())
      cout<<"Graph is line graph;"<<endl;
   else
      cout<<"Graph is not line graph;"<<endl;
   G->transformToOriginal();
   G->printOriginalList();
   G->saveOriginalGraph();

   /*ProgressBar progressBar(100000, 100); int adj_counter = 0, line_counter = 0;
   for(int i=0; i<100000;i++){
      auto *G = new Graph(2);
      //G->printMatrix();
      //G->printList();
      //G->printPredList();
      G->isAdjoint();
      G->isLine();
      if(G->getAdjointStatus())
         adj_counter++;
      if(G->getLineStatus())
         line_counter++;
      G->transformToOriginal();
      //G->printOriginalList();
      //G->saveOriginalGraph();
      delete G;
      ++progressBar;
      progressBar.display();
   }
   progressBar.done();
   cout<< endl<< adj_counter << line_counter<<endl;
    */

   return 0;
}