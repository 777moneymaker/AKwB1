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
#include <string>
#include <cstdlib>
#include <algorithm>
#include "Graph.hpp"

Graph::Graph(int nv){
   this->num_of_vert = nv;
   this->createMatrix();
   this->createList();
   this->createPredList();
}

bool Graph::getAdjointStatus(){
   return this->adjoint_status;
}
bool Graph::getLineStatus(){
   return this->line_status;
}
bool Graph::doesHaveAnyPred(const vector<int> &first, const vector<int> &second){
   for(auto k : first)
      for(auto l : second) // we found common predecessor. Graph is not line graph
         if(k == l)
            return true;
   return false;
}

void Graph::printOriginalList(){
   //this->createOriginalList();
   cout << "Original Graph: "<<endl;
   for(const auto &i : this->original_list){
      if(i.empty())
         continue;
      for(const int &j: i){
         cout<< j << ' ';
      }
      cout << endl;
   }
}
void Graph::transformToOriginal(){
   if(not(this->adjoint_status)){
      //cout<< "Can't transform Graph that is not adjoint!"<< endl;
      return;
   }
   int nv = this->num_of_vert; int new_vertex = 1;
   // build a graph with additional vertices
   for(int i = 0; i < nv; i++){
      this->edge_list.emplace_back(vector<int>());
      for(int j = 0; j < 2; j++, new_vertex++){
         this->edge_list[i].push_back(new_vertex);
      }
   }
   // transform graph
   for (int i = 0; i < nv; i++){
      for (int j = 0; j < (int)adj_list[i].size(); j++){
         int edge = this->adj_list[i][j] - 1;
         if (this->edge_list[i][1] < this->edge_list[edge][0])
           this->edge_list[edge][0] = this->edge_list[i][1];
         else
            this->edge_list[i][1] = this->edge_list[edge][0];
      }
   }
   // calculate what will be the max value of vectors that we need to emplace back
   auto max = *max_element(begin(this->edge_list[0]), end(this->edge_list[0]));
   for(int i=0; i<this->edge_list.size(); i++){
      auto temp_max = *max_element(begin(this->edge_list[i]), end(this->edge_list[i]));
      if(temp_max > max)
         max = temp_max;
   }
   // create original_list from list of edges
   for(int i = 0; i < max+1; i++){
      this->original_list.emplace_back(vector<int>());
      this->original_list[i].resize(0);
   }
   for(int i = 0; i < edge_list.size(); i++){
      this->original_list[this->edge_list[i][0]].push_back(this->edge_list[i][1]);
   }
}
void Graph::isAdjoint(){
   if(this->multigraph_status){
      this->adjoint_status = false;
      return void();
   }
   int nv = this->num_of_vert;
   int size = 0, common_els = 0;
   for(int i = 0; i < nv; i++){
      if(not(this->adj_list[i].empty()))  // checks if there is any vertex that has any successors
         for(int j = (i + 1); j < nv; j++){
            common_els = 0;
            for(int k = 0; k < (int)this->adj_list[i].size(); k++){
               for(int l = 0; l < (int)this->adj_list[j].size(); l++){
                  if(this->adj_list[i].size() >= this->adj_list[j].size()) // sets the number of our common elements
                     size = (int)this->adj_list[i].size();
                  else                                                     // sets the number of our common elements
                     size = (int)this->adj_list[j].size();
                  if(this->adj_list[i][k] == this->adj_list[j][l]) // if we found common element, then we increment
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
void Graph::isLine(){
   int nv = this->num_of_vert;
   int size = 0, common_els = 0;
   if(this->adjoint_status){ // if graph is not adjoint, then it's not line graph
      for(int i = 0; i < nv; i++){
         for(int j = (i + 1); j < nv; j++){
            common_els = 0;
            for(int k = 0; k < (int)this->adj_list[i].size(); k++){
               for(int l = 0; l < (int)this->adj_list[j].size(); l++){
                  if(this->adj_list[i].size() >= this->adj_list[j].size()) // sets the number of our common elements
                     size = (int)this->adj_list[i].size();
                  else                                                     // sets the number of our common elements
                     size = (int)this->adj_list[j].size();
                  if(this->adj_list[i][k] == this->adj_list[j][l]){
                     common_els++;  // if we found common element, then we increment
                  }
               }
            }
            if((common_els == size) or (common_els == 0)){ // if common elements for two vertices are equal or if this is an empty set

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
   }else{
      this->line_status = false;
   }
   return void();
}
void Graph::createMatrix(){ //creates N^2 size matrix based on number of vertices
   int nv = this->num_of_vert;
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++)
         this->adj_matrix[i][j] = (int)random() % 2; // randomize matrix/create random graph
   return void();
}
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
void Graph::clearMatrix(){ // sets whole matrix to '0'
   int nv = this->num_of_vert;
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++)
         this->adj_matrix[i][j] = 0;
   return void();
}
void Graph::createList(){ // creates list that is based on indexes of adjacency matrix
   int nv = this->num_of_vert;
   this->clearList();
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++){
         if(this->adj_matrix[i][j] == 1)
            this->adj_list[i].push_back(j + 1); // pushes index of current column + 1 (current vertex)
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
void Graph::createPredList(){
   int nv = this->num_of_vert;
   this->clearPredList();
   for(int i = 0; i < nv; i++)
      for(int j = 0; j < nv; j++){
         if(this->adj_matrix[i][j] >= 1)
            this->pred_list[j].push_back(i + 1); // pushes index of current column + 1 (current vertex)
      }
   return void();
}
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
void Graph::clearList(){ //resets list to be empty
   for(auto &vec : this->adj_list){
      vec.resize(1);
      vec.clear();
   }
   return void();
}
void Graph::clearPredList(){
   for(auto &vec : this->pred_list){
      vec.resize(1);
      vec.clear();
   }
   return void();
}
void Graph::saveOriginalGraph(){
   if(not(this->adjoint_status))
      return;
   int nv_counter = 0;
   for(auto &i : this->original_list)
      if(not(i.empty()))
         nv_counter++;
   fstream file; file.open("graph_original.txt");
   int nv = nv_counter;
   if(file.good()){
      file.clear();
      file << nv << endl; //read first line which is our number of vertices
      for(auto &i : this->original_list){
         if(i.empty())
            continue;
         for(auto &j : i){
            file << j << ' ';
         }
         file << "/" << endl;
      }
      file.close();
   }else{
      cout << "Error while opening the file" << endl;
   }
   return void();
}
void Graph::loadGraph(){
   string val;
   int nv = this->num_of_vert;
   fstream file;
   file.open("graph.txt", ios::in);
   if(file.good()){
      this->clearMatrix();
      file >> val; // reads number of vertices (first line)
      this->num_of_vert = stoi(val);
      nv = stoi(val);

      for(int i = 0; i < nv;){
         for(int j = 0; j < nv; j++){
            file >> val; // read the number
            if(val == "/"){    // if end of number then go to next line(vertex),
               i++;            // set columns to zero, and empty our 'val' variable
               j = 0;
               val = "0";
            }
            if(stoi(val) not_eq 0) // if number is good then put '1' in the column which the number is pointing
               this->adj_matrix[i][stoi(val) - 1] += 1; // (number - 1, starting from 0)
         }
      }
      this->createList();
      this->createPredList();
   }else{
      cout << "Error while opening the file" << endl;
   }
   return void();
}





