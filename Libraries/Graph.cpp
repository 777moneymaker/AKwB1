/**
 * This is a Graph module. It contains Graph class with all of it's methods.
 * Written for Bioinformatics Algorithms class.
 * Purpose: Check if loaded Graph is Line Graph. Make transformation. Save to file.
 * @author Miłosz Chodkowski
 * @version 1.0 15/11/2019
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <tuple>
#include "Graph.hpp"

/**
 * This is Graph class initializer method.
 * @param nv = number of vertices that Graph should have.
 */
Graph::Graph(int nv){
   this->num_of_vert = nv;
   this->createMatrix();
   this->createList();
   this->createPredList();
}



/**
 * Public function for getting object status.
 * @return Adjacency status.
 */
bool Graph::getAdjointStatus(){
   return this->adjoint_status;
}

/**
 * Public function for getting object status.
 * @return Line status.
 */
bool Graph::getLineStatus(){
   return this->line_status;
}

/**
 * Method checks does two lists share any element.
 * @param first = First list.
 * @param second = Second list.
 * @return True if lists share element, else False.
 */
bool Graph::doesHaveAnyPred(const vector<int> &first, const vector<int> &second){
   for(auto k : first)
      for(auto l : second) // we found common predecessor. Graph is not line graph
         if(k == l)
            return true;
   return false;
}

/**
 * Method prints list of successors for every vertex in Graph.
 */
void Graph::printOriginalList(){
   if(not(this->adjoint_status)) return void();
   cout << "Original Graph: "<<endl;
   for(const auto &i : this->original_list){
      if(i.empty()) continue;
      for(const int &j: i)
         cout<< j << ' ';
      cout << endl;
   }
}

/**
* Method gets adjacency status of G. If True, then it performs transformation to original graph H.
* Main rule of transformation is to build a list of edges containing edges (1, 2),(3, 4),...,(n-1, n).
* Next step is to make a change in those elements such that list will contain only edges that
* are present in original graph H.
*/
void Graph::transformToOriginal(){
   int nv = this->num_of_vert;  vector<tuple<int, int, int> > edge_list;
   if(not(this->adjoint_status)){
      cout << "Can't transform Graph that is not adjoint" << endl;
      return;
   }
   // build a graph with additional vertices
   for(int i = 0, new_vertex = 1; i < nv; i++, new_vertex++){
      edge_list.emplace_back(tuple<int, int, int>(new_vertex++, i+1, new_vertex));
   }
   // transform graph
   for(int i = 0; i < nv; i++){
      for(int j = 0; j < nv; j++){
         if(this->adj_matrix[i][j] == 1){
            auto compare = get<0>(edge_list[j]);
            get<0>(edge_list[j]) = get<2>(edge_list[i]);
            for(auto &tup : edge_list){
               if(get<0>(tup) == compare){
                  get<0>(tup) =  get<2>(edge_list[i]);
               }
               if(get<2>(tup) == compare){
                  get<2>(tup) = get<2>(edge_list[i]);
               }
            }
         }
      }
   }
   for(const auto &tup : edge_list){
      int index = get<0>(tup) - 1, val = get<2>(tup);
      this->original_list[index].push_back(val);
   }
}

/**
 * Method checks for adjacency status of graph G, and sets it for False if G is not adjoint.
 * The rule is to check if any vertices (i, j) : i != j have common successors.
 * G is adjoint only if any vertices (i, j) have 0 common successors or have equal number of them.
 *
 */
void Graph::isAdjoint(){
   if(this->multigraph_status){
      this->adjoint_status = false;
      return void();
   }
   int nv = this->num_of_vert, size = 0, common_els = 0;
   for(int i = 0; i < nv; i++){
      // checks if there is any vertex that has any successors
      if(not(this->adj_list[i].empty()))
         for(int j = 0; j < nv; j++){
            if (i == j) continue;
            common_els = 0;
            for(int k = 0; k < (int)this->adj_list[i].size(); k++){
               for(int l = 0; l < (int)this->adj_list[j].size(); l++){
                  // sets the number of our common elements
                  if(this->adj_list[i].size() >= this->adj_list[j].size())
                     size = (int)this->adj_list[i].size();
                  else
                     size = (int)this->adj_list[j].size();
                  // if we found common element, then we increment
                  if(this->adj_list[i][k] == this->adj_list[j][l])
                     common_els++;
               }
            }
            // graph not adjoint; common elements for two vertices are not equal and this is not empty set
            if((common_els not_eq size) and
               (common_els not_eq 0)){
               this->adjoint_status = false;
               return void();
            }
         }
   }
   return void();
}

/**
 * Method checks for line status of graph G, and sets it for False if G is not line.
 * The rule is to check if any vertices (i, j) : i != j have any common predecessors.
 * G is line only if any vertices (i, j) that have common successors don't have any common predecessors.
 */
void Graph::isLine(){
   int nv = this->num_of_vert, size = 0, common_els = 0;
   // if graph is not adjacent, then it can't be line
   if(not(this->adjoint_status)){
      this->line_status = false;
      return void();
   }
   for(int i = 0; i < nv; i++){
      for(int j = 0; j < nv; j++){
         if(i == j) continue;
         common_els = 0;
         for(int k = 0; k < (int)this->adj_list[i].size(); k++){
            for(int l = 0; l < (int)this->adj_list[j].size(); l++){
               // sets the number of our common elements
               if(this->adj_list[i].size() >= this->adj_list[j].size())
                  size = (int)this->adj_list[i].size();
               else
                  size = (int)this->adj_list[j].size();
               // if we found common element, then we increment
               if(this->adj_list[i][k] == this->adj_list[j][l])
                  common_els++;
            }
         }
         // if common elements for two vertices are equal or if this is an empty set
         if((common_els == size) or (common_els == 0)){
            /*If we find a common successors, then we must compare list of predecessors for both of it's vertices.
            Then if we find any common predecessor, we know that graph is not line graph*/
            bool status = this->doesHaveAnyPred(this->pred_list[i], this->pred_list[j]);
            if(status){
               this->line_status = false;
               return void();
            }
         }
      }
   }
   return void();
}

/**
 * Method creates n^2 size matrix based on number of vertices of graph G.
 */
void Graph::createMatrix(){
   int nv = this->num_of_vert;
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++)
         this->adj_matrix[i][j] = (int)random() % 2; // randomize matrix/create random graph
   return void();
}

/**
 * Method prints adjacency matrix for graph G.
 */
void Graph::printMatrix(){
   int nv = this->num_of_vert;
   cout << "Number of vertices " << nv << endl;
   for(int i = 0; i < nv; i++){
      for(int j = 0; j < nv; j++)
         cout << this->adj_matrix[i][j] << " ";
      cout << endl;
   }
   return void();
}

/**
 * Method clears matrix by setting every cell to 0.
 */
void Graph::clearMatrix(){
   int nv = this->num_of_vert;
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++)
         this->adj_matrix[i][j] = 0;
   return void();
}

/**
 * Method creates list that is based on indexes of adjacency matrix of graph G.
 */
void Graph::createList(){
   int nv = this->num_of_vert;
   this->clearList();
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++){
         if(this->adj_matrix[i][j] == 1){
            // pushes index of current column + 1 (current vertex)
            this->adj_list[i].push_back(j + 1);
         }
         // if value is bigger than 1, then G is a multigraph
         if(this->adj_matrix[i][j] > 1){
            this->multigraph_status = true;
            this->adjoint_status = false;
            for(int k = 0; k < this->adj_matrix[i][j]; k++){
               this->adj_list[i].push_back(j + 1);
            }
         }
      }
   return void();
}

/**
 * Method creates list of predecessors for each vertex v.
 */
void Graph::createPredList(){
   int nv = this->num_of_vert;
   this->clearPredList();
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++){
         if(this->adj_matrix[i][j] >= 1)
            // pushes index of current column + 1 (current vertex)
            this->pred_list[j].push_back(i + 1);
      }
   return void();
}

/**
 * Method prints list of successors of every vertex v.
 */
void Graph::printList(){
   int nv = this->num_of_vert;
   cout << endl << "Successors" << endl;
   for(int i = 0; i < nv; i++){
      cout << i + 1 << ":";
      for(int j = 0; j < (int)adj_list[i].size(); j++)
         cout << "-> " << this->adj_list[i][j];
      cout << endl;
   }
   return void();
}

/**
 * Method prints list of predecessors of every vertex v.
 */
void Graph::printPredList(){
   int nv = this->num_of_vert;
   cout << endl << "Predecessors" << endl;
   for(int i = 0; i < nv; i++){
      cout << i + 1 << ":";
      for(auto j : this->pred_list[i])
         cout << "-> " << j;
      cout << endl;
   }
   return void();
}

/**
 * Method clears list of successors for every vertex v.
 */
void Graph::clearList(){ //resets list to be empty
   for(auto &vec : this->adj_list){
      vec.resize(1);
      vec.clear();
   }
   return void();
}

/**
 * Method clears list of predecessors for every vertex v.
 */
void Graph::clearPredList(){
   for(auto &vec : this->pred_list){
      vec.resize(1);
      vec.clear();
   }
   return void();
}

/**
 * Method saves graph H (graph after transformation) to file 'graph_original.txt'.
 * First it counts how many vertices we have. It adds every index of list of successors of original graph.
 * Then it adds every vertex in this list only if it's not present in list.
 * Last step is to save the graph.
 */
void Graph::saveOriginalGraph(){
   vector<int> counter;
   if(not(this->adjoint_status))
      return void();
   for(int i = 0; i < 50 ; i++){
      if(not(this->original_list[i].empty())){
         if(not(count(counter.begin(), counter.end(), (i+1))))
            counter.push_back(i+1);
         for(int j = 0; j < (int)this->original_list[i].size(); j++){
            if(not(count(counter.begin(), counter.end(), this->original_list[i][j])))
               counter.push_back(this->original_list[i][j]);
         }
      }
   }
   int nv = (int)counter.size();
   fstream file("graph_original.txt", fstream::out|fstream::trunc);
   if(file.good()){
      file << nv << endl; //read first line which is our number of vertices
      for(auto &i : this->original_list){
         if(i.empty()){
            file<<endl;
            continue;
         }
         for(auto &j : i){
            file << j << ' ';
         }
         file << "/" << endl;
      }
      file.close();
   }else{
      cout << "Error while opening the file" << endl;
      return void();
   }
   cout << endl << "Graph Saved!" << endl;
   return void();
}

/**
* Method loads graph G (graph before transformation) from file 'graph.txt'.
* First cleras the matrix and loads number of vertices. Next it pushes every vertex to matrix.
* Last step is to save the graph.
*/
void Graph::loadGraph(){
   string val; int nv = 0; fstream file("graph.txt", ios::in);
   if(file.good()){
      this->clearMatrix();
      // reads number of vertices (first line)
      file >> val;
      nv = this->num_of_vert = stoi(val);
      for(int i = 0; i < nv;){
         for(int j = 0; j < nv; j++){
            // read the number
            file >> val;
            // if end of number then go to next line(vertex),
            if(val == "/"){
               // set columns to zero, and empty our 'val' variable
               i++;
               j = 0;
               val = "0";
            }
            // if number is good then put '1' in the column which the number is pointing (number - 1, starting from 0)
            if(stoi(val) not_eq 0)
               this->adj_matrix[i][stoi(val) - 1] += 1;
         }
      }
      this->createList();
      this->createPredList();
   }else{
      cout << "Error while opening the file" << endl;
   }
   return void();
}





