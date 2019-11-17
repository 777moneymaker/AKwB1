/**
 * This is a Graphing hpp library. It contains Graph class with all of it's methods..
 * Written for Bioinformatics Algorithms class.
 * Purpose: Check if loaded Graph is Line Graph. Make transformation. Save to file.
 * @author Miłosz Chodkowski
 * @version 1.0 15/11/2019
 */

#ifndef SJP_GRAPH_GRAPH_H
#define SJP_GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <tuple>

using namespace std;

class Graph{
private:
   int num_of_vert = 0;
   int adj_matrix[50][50] = {0};

   bool adjoint_status = true;
   bool line_status = true;
   bool multigraph_status = false;

   vector<int> adj_list[50];
   vector<int> original_list[50];
   vector<int> pred_list[50];

   /**
    * Method checks does two lists share any element.
    * @param first = First list.
    * @param second = Second list.
    * @return True if lists share element, else False.
    */
   bool doesHaveAnyPred(const vector<int> &first, const vector<int> &second);

   /**
    * Method clears list of successors for every vertex v.
    */
   void clearList();

   /**
    * Method clears list of predecessors for every vertex v.
    */
   void clearPredList();

   /**
    * Method creates list that is based on indexes of adjacency matrix of graph G.
    */
   void createList();

   /**
    * Method creates list of predecessors for each vertex v.
    */
   void createPredList();

   /**
    * Method clears matrix by setting every cell to 0.
    */
   void clearMatrix();


   void changeIndexes();
public:
   /**
    * This is Graph class initializer method.
    * @param nv = number of vertices that Graph should have.
    */
   explicit Graph(int nv = 5);

   /**
    * Public function for getting object status.
    * @return Adjacency status.
    */
   bool getAdjointStatus();

   /**
    * Public function for getting object status.
    * @return Line status.
    */
   bool getLineStatus();

   /**
    * Method gets adjacency status of G. If True, then it performs transformation to original graph H.
    * Main rule of transformation is to build a list of edges containing edges (1, 2),(3, 4),...,(n-1, n).
    * Next step is to make a change in those elements such that list will contain only edges that
    * are present in original graph H.
    */
   void transformToOriginal();

   /**
    * Method prints list of successors for every vertex in Graph.
    */
   void printOriginalList();

   /**
    * Method checks for adjacency status of graph G, and sets it for False if G is not adjoint.
    * The rule is to check if any vertices (i, j) : i != j have common successors.
    * G is adjoint only if any vertices (i, j) have 0 common successors or have equal number of them.
    *
    */
   void isAdjoint();

   /**
    * Method checks for line status of graph G, and sets it for False if G is not line.
    * The rule is to check if any vertices (i, j) : i != j have any common predecessors.
    * G is line only if any vertices (i, j) that have common successors don't have any common predecessors.
    */
   void isLine();

   /**
    * Method creates n^2 size matrix based on number of vertices of graph G.
    */
   void createMatrix();

   /**
    * Method prints adjacency matrix for graph G.
    */
   void printMatrix();

   /**
    * Method prints list of successors of every vertex v.
    */
   void printList();

   /**
    * Method prints list of predecessors of every vertex v.
    */
   void printPredList();

   /**
    * Method saves graph H (graph after transformation) to file 'graph_original.txt'.
    * First it counts how many vertices we have. It adds every index of list of successors of original graph.
    * Then it adds every vertex in this list only if it's not present in list.
    * Last step is to save the graph.
    */
   void saveOriginalGraph();

   /**
    * Method loads graph G (graph before transformation) from file 'graph.txt'.
    * First cleras the matrix and loads number of vertices. Next it pushes every vertex to matrix.
    * Last step is to save the graph.
    */
   void loadGraph();
};


#endif //SJP_GRAPH_GRAPH_H
