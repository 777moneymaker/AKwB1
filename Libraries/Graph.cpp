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
#include <random>
#include "Graph.h"


    Graph::Graph(int nv){
        this->num_of_vert = nv;
        this->createMatrix();
        this->createList();
    }

    /*bool Graph::isAdjoint() {
     // TODO compare all x,y pairs of Vertices and give result
        int nv = this->num_of_vert;
        bool adjoint_status = true;
        for (int i = 0; i < nv; i++) {
            for (int j = 0; j < nv; j++) {
                if (i == j)
                    continue;
                if (!this->compareLists(this->adj_list[i], this->adj_list[j]))
                    adjoint_status = false;
            }
        }
        return adjoint_status;
    }*/
    //bool Graph::compareLists(int first[], int second[])



    /*int *Graph::findMissing(int first[], int second[], int n, int m) {
     // TODO compare two lists, find elements that are missing
        int *missing_elements;
        if(n>m)
            missing_elements = new int[n];
        else
            missing_elements = new int[m];
        for (int i = 0; i < n; i++){
            int j;
            for (j = 0; j < m; j++)
                if (first[i] == second[j])
                    break;
            if (j == m)
                missing_elements[i] = first[i];
        }
        return missing_elements;
    }*/

    void Graph::createMatrix(){ //creates N^2 size matrix based on number of vertices
        int nv = this->num_of_vert;
        for(int i=0; i<nv; i++)
            for(int j=0; j<nv; j++)
                this->adj_matrix[i][j] = (int)random() % 2; // randomize matrix/create random graph
    }

    void Graph::printMatrix(){
        int nv = this->num_of_vert;
        cout<<"Number of vertices "<< nv <<endl;
        for(int i=0; i<nv; i++){
            for(int j=0; j<nv; j++)
                cout<<this->adj_matrix[i][j]<<" ";
            cout<<endl;
        }
    }

    void Graph::clearMatrix(){ // sets whole matrix to '0'
        int nv = this->num_of_vert;
        for(int i=0; i<nv; i++)
            for(int j=0; j<nv; j++)
                this->adj_matrix[i][j]= 0;
    }

    void Graph::createList(){ // creates list that is based on indexes of adjacency matrix
        int nv = this->num_of_vert;
        this->clearList();
        for(int i=0; i<nv; i++)
            for(int j=0; j<nv; j++)
                if(this->adj_matrix[i][j] == 1)
                    this->adj_list[i].push_back(j+1); // pushes index of current column + 1 (current vertex)
    }

    void Graph::printList(){
        int nv = this->num_of_vert;
        cout<<endl<<"Number of vertices: "<<nv<<endl;
        for(int i=0; i<nv; i++){
            cout<<i+1<<":";
            for(int j=0; j<adj_list[i].size(); j++){
                cout<<"-> "<<this->adj_list[i][j];
            }
            cout<<endl;
        }
    }

    void Graph::clearList() { //resets list to be empty
        for(int i=0; i<50; i++){
            this->adj_list[i].resize(1);
            this->adj_list[i].clear();
        }
    }

    void Graph::addArc(int tail, int head){
        // TODO test function, upgrade if needed
        this->adj_matrix[tail-1][head-1] = 1;
    }
    void Graph::removeArc(int tail, int head){
        // TODO test function, upgrade if needed
        this->adj_matrix[tail-1][head-1] = 0;
    }


    void Graph::saveGraph() {
        fstream file; int nv = this->num_of_vert;
        file.open("graph.txt", ios::out);
        if (file.good()) {
            file.clear();
            file << nv << endl; //read first line which is our number of vertices
            for (int i = 0; i < nv; i++) {
                for (int j = 0; j < nv; j++) {
                    if (this->adj_matrix[i][j] == 1) // if our column for current vertex is == 1,
                        file << j + 1 << " ";        // then saves it as our vertex
                    if (j == (this->num_of_vert - 1)) // if at end of columns-
                        file << "/";                  // set end of adj list for this vertex
                }
                file << endl;
            }
            file.close();
        } else {
            cout << "Error while opening the file" << endl;
        }
    }
    void Graph::loadGraph(){
        string val; int nv = this->num_of_vert; fstream file;
        file.open("graph.txt", ios::in);
        if(file.good()){
            this->clearMatrix();
            file>>val; // reads number of vertices (first line)
            this->num_of_vert = stoi(val); nv = stoi(val);

            for(int i=0; i<nv; ){
                for(int j=0; j<nv; j++){
                    file>>val; // read the number
                    if(val == "/") {    // if end of number then go to next line(vertex),
                        i++;            // set columns to zero, and empty our 'val' variable
                        j = 0;
                        val = "0";
                    }
                    if(stoi(val) != 0) // if number is good then put '1' in the column which the number is pointing
                        this->adj_matrix[i][stoi(val)-1] = 1; // (number - 1, starting from 0)
                }
            }
            this->createList();
        }else{
            cout<<"Error while opening the file"<<endl;
        }
    }





