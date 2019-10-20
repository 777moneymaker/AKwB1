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
        this->num_of_vert = nv; //

        for(int i=0;i<nv;i++){
            for(int j=0;j<nv;j++) {
                this->adj_matrix[i][j] = rand() % 2;
            }
        }
    }
    void Graph::saveGraph(){
        fstream file; int nv = this->num_of_vert;
        file.open("graph.txt", ios::out);

        if(file.good()){
            file.clear();
            file<<nv<<endl;

            for(int i=0;i<nv;i++){
                for(int j=0;j<nv;j++){

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
            this->clearGraph();
            file>>val;
            this->num_of_vert = stoi(val); nv = stoi(val);

            for(int i=0;i<nv;i++){
                for(int j=0;j<nv;j++){
                    file>>val;
                    if(val == "/") {
                        i++;
                        j = 0;
                        val = "0";
                    }
                    if(stoi(val) != 0)
                        this->adj_matrix[i][stoi(val)-1] = 1; ;
                }
            }
        }else{
            cout<<"Error while opening the file"<<endl;
        }
    }
    void Graph::printGraph(){
        int nv = this->num_of_vert;
        cout<<"Number of vertices "<< nv <<endl;
        for(int i=0;i<nv;i++){
            for(int j=0;j<nv;j++){
                cout<<this->adj_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void Graph::clearGraph(){
        int nv = this->num_of_vert;
        for(int i=0;i<nv;i++){
            for(int j=0;j<nv;j++) {
                this->adj_matrix[i][j]= 0;
            }
        }
    }
    void Graph::addArc(int tail, int head){
        this->adj_matrix[tail][head] = 1;
    }
    void Graph::removeArc(int tail, int head){
        this->adj_matrix[tail][head] = 0;
    }



