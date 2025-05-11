#include<iostream>
using namespace std;

struct  Node
{
    int vertex,weight;
    Node *next;
};

class WeightedList{
    private:
    int vertices;
    Node **adjList;

    public:
    WeightedList(int vertices){
        this->vertices=vertices;
        adjList=new Node*[vertices];
        for(int i=0;i<vertices;i++){
            adjList[i]=nullptr;
        }
    }
    void addEdge(int u,int v,int weight){
        Node *newNode=new Node{v,weight,adjList[u]};
        adjList[u]=newNode;
        newNode=new Node{u,weight,adjList[v]};
        adjList[v]=newNode;
    }

    void deleteEdge(int u,int v){
        Node *temp=adjList[u],*prev=nullptr;
        while(temp !=nullptr &&temp->vertex !=v){
            prev=temp;
            temp=temp->next;
        }
        if(temp !=nullptr){
            if(prev==nullptr){
                adjList[u]=temp->next;
            }
            else{
                prev->next=temp->next;
                delete temp;
            }
        }
        temp=adjList[v],prev=nullptr;
        while (temp !=nullptr && temp->vertex !=u)
        {
          prev=temp;
          temp=temp->next;
        }
        if(temp !=nullptr){
            if(prev==nullptr){
                adjList[v]=temp->next;
            }else{
                prev->next=temp->next;
                delete temp;
            }
        }
        
    }

    void display(){
        cout <<"Adjacency List"<<endl;
        for(int i=0;i<vertices ;i++){
            cout<<i<<"->";
            Node *temp=adjList[i];
            while (temp)
            {
               cout<<"("<<temp->vertex<<","<<temp->weight<<")";
               temp=temp->next;
            }
            cout<<endl;
            
        }
    }

    // void freeMemory(){
    //     for(int i=0;i<vertices;i++){
    //         Node *temp=adjList[i];
    //         while (temp)
    //         {
    //           Node *next=temp->next;
    //           delete temp;
    //           temp next;
    //         }
            
    //     }
    //     delete[] adjList;
    // }
};

int main(){
    int vertices=5;
    WeightedList wl(vertices);
    wl.addEdge(0,1,2);
    wl.addEdge(0,3,6);
    wl.addEdge(1,2,3);
    wl.addEdge(2,4,7);

    wl.display();

    wl.deleteEdge(0,3);
    wl.display();
    // wl.freeMemory();

    return 0;
    
}