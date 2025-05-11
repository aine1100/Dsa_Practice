#include<iostream>
using namespace std;

class WeightedMatrix{
    private :
    int **adjMatrix;
    int vertices;

    public:
    WeightedMatrix(int vertices){
        this->vertices=vertices;

        adjMatrix=new int *[vertices];
        for(int i=0;i<vertices;i++){
            adjMatrix[i]=new int[vertices];
            for(int j=0;j<vertices;j++){
                adjMatrix[i][j]=0;//when we dont have an edge
            }
        }
    }
    void addEdge(int u,int v,int weight){
        if(u>=0 && v>=0 && u<vertices && v<vertices){
            adjMatrix[u][v]=weight;
            adjMatrix[v][u]=weight;
        }
    }

    void deleteEdge(int u,int v){
        if(u>=0&& v>=0 && u<vertices && v<vertices){
            adjMatrix[u][v]=0;
            adjMatrix[v][u]=0;
        }
    }

    void display(){
        cout <<"Weighted Matrix:\n";
        for(int i=0;i<vertices ;i++){
            for(int j=0;j<vertices;j++){
                cout<<adjMatrix[i][j]<<"";

            }
            cout<<endl;
        }
    }

    void freeMemory(){
        for(int i=0;i<vertices;i++){
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main(){
    int vertices=5;
    WeightedMatrix wm(vertices);
    wm.addEdge(0,1,2);
    wm.addEdge(0,3,6);
    wm.addEdge(1,2,3);
    wm.addEdge(2,4,7);

    wm.display();
    wm.deleteEdge(0,3);
    wm.display();

    wm.freeMemory();
    return 0;




}