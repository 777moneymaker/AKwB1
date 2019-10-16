#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

class Vertex{
public:
    int key;
};


class Graph{
public:
    int num_of_vert = 0;
    Vertex **adj_matrix = new Vertex*[50];

    Graph(int num_of_vert=5){
        this->num_of_vert = num_of_vert;
        for(int i=0;i<50;i++){
            this->adj_matrix[i] = new Vertex[50];
        }
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++) {
                this->adj_matrix[i][j].key = rand() % 2;
            }
        }
    }

    void saveGraph(int iters){
        fstream file;
        file.open("graph.txt", ios::out);
        if(file.good()){
            file.clear();
            file<<this->num_of_vert<<endl;
            for(int i=0;i<iters;i++){
                for(int j=0;j<iters;j++){
                    file<<this->adj_matrix[i][j].key<<" ";
                }
                file<<endl;
            }
            file.close();
        }else{
            cout<<"Error while opening the file"<<endl;
        }


    }

    void loadGraph(int iters){
        fstream file;
        file.open("graph.txt", ios::in);
        if(file.good()){
            file >> this->num_of_vert;
            for(int i=0;i<iters;i++){
                for(int j=0;j<iters;j++){
                    file>>this->adj_matrix[i][j].key;
                }
            }
        }else{
            cout<<"Error while opening the file"<<endl;
        }
    }

    void printGraph(int iters){
        cout<<"Number of vertices: "<<this->num_of_vert<<endl;
        for(int i=0;i<iters;i++){
            for(int j=0;j<iters;j++){
                cout<<this->adj_matrix[i][j].key<<" ";
            }
            cout<<endl;
        }
    }

    void clearGraph(){
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++) {
                this->adj_matrix[i][j].key = 0;
            }
        }
    }


};


int main() {
    auto *G = new Graph(10); string filename;

    G->printGraph(10);
    G->loadGraph(10);
    G->printGraph(10);

    return 0;
}