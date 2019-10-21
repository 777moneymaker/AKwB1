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
#include "Graph.h"


    Graph::Graph(int nv){
        this->num_of_vert = nv;
        this->createMatrix();
        this->createList();
    }

    void Graph::createMatrix(){ //creates N^2 size matrix based on number of vertices
       int nv = this->num_of_vert;

        for(int i=0; i<nv; i++){
            for(int j=0; j<nv; j++) {
                this->adj_matrix[i][j] = rand() % 2;
            }
        }
    }

    void Graph::printMatrix(){
        int nv = this->num_of_vert;
        cout<<"Number of vertices "<< nv <<endl;
        for(int i=0; i<nv; i++){
            for(int j=0; j<nv; j++){
                cout<<this->adj_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void Graph::clearMatrix(){ // sets whole matrix to '0'
        int nv = this->num_of_vert;
        for(int i=0; i<nv; i++){
            for(int j=0; j<nv; j++) {
                this->adj_matrix[i][j]= 0;
            }
        }
    }

    void Graph::createList(){ // creates list that is based on indexes of adjacency matrix
        int nv = this->num_of_vert;
        for(int i=0; i<nv; i++){
            for(int j=0; j<nv; j++){
                if(this->adj_matrix[i][j] == 1){
                    this->adj_list[i][j] = j+1;
                }
            }
        }
    }

    void Graph::printList(){
        int nv = this->num_of_vert;
        cout<<endl<<"Number of vertices: "<<nv<<endl;
        for(int i=0; i<nv; i++){
            cout<<i+1<<":";
            for(int j=0; j<nv; j++){
                if(this->adj_list[i][j] != 0)
                    cout<<"-> "<<this->adj_list[i][j];
            }
            cout<<endl;
        }
    }

    void Graph::clearList() { //sets list to '0'
    int nv = this->num_of_vert;
        for(int i=0; i<nv; i++){
            for(int j=0; j<nv; j++){
                this->adj_list[i][j] = 0;
            }
        }
}

    void Graph::addArc(int tail, int head){
        this->adj_matrix[tail-1][head-1] = 1;
    }
    void Graph::removeArc(int tail, int head){
        this->adj_matrix[tail-1][head-1] = 0;
    }


    void Graph::saveGraph(){
        fstream file; int nv = this->num_of_vert;
        file.open("graph.txt", ios::out);

        if(file.good()){
            file.clear();
            file<<nv<<endl;

            for(int i=0; i<nv; i++){
                for(int j=0; j<nv; j++){

                    if(this->adj_matrix[i][j] == 1)
                        file<<j+1<<" ";

                    if(j==(this->num_of_vert-1))
                        file<<"/";
                }
                file<<endl;
            }
            file.close();
        }else{
            cout<<"Error while opening the file"<<endl;
        }


    }
    void Graph::loadGraph(){
        string val; int nv = this->num_of_vert; fstream file;
        file.open("graph.txt", ios::in);

        if(file.good()){
            this->clearMatrix();
            this->clearList();
            file>>val;
            this->num_of_vert = stoi(val); nv = stoi(val);

            for(int i=0; i<nv; i++){
                for(int j=0; j<nv; j++){
                    file>>val;
                    if(val == "/") {
                        i++;
                        j = 0;
                        val = "0";
                    }
                    if(stoi(val) != 0)
                        this->adj_matrix[i][stoi(val)-1] = 1; ;
                        this->adj_list[i][j] = stoi(val);
                }
            }
        }else{
            cout<<"Error while opening the file"<<endl;
        }
    }





