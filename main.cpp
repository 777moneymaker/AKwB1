/**
 * This is a Graphing program. It contains Graph object.
 * Written for Bioinformatics Algorithms class.
 * Purpose: Check if loaded Graph is Line Graph. Make transformation. Save to file.
 * @author Miłosz Chodkowski
 * @version 1.0 15/11/2019
 */

#include <iostream>
#include <string>
#include "Libraries/Graph.hpp"

using namespace std;

int main(){
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
      cout<<"Graph is not line graph;"<<endl;;
   G->transformToOriginal();
   G->saveOriginalGraph();

   return 0;
}
