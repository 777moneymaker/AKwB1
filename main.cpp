#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vertex{
public:
    int key;
};


class Graph{
public:
    int num_of_vert;
    Vertex **adj_matrix = new Vertex*[50];

    Graph(int num_of_vert=0){
        this->num_of_vert = num_of_vert;
        for(int i=0;i<50;i++){
            adj_matrix[i] = new Vertex[50];
        }
    }

    void saveGraph(){
        // TODO saves graph to txt file
    }

    void loadGraph(){
        // TODO loads graph from txt
    }

    void clearGraph()_{
        // TODO sets all keys to 0
    }

};


int main() {
    auto *G = new Graph;

    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++) {
            G->adj_matrix[i][j].key = 0;
        }
    }

    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            cout<<G->adj_matrix[i][j].key;
        }
        cout<<endl;
    }
    return 0;
}