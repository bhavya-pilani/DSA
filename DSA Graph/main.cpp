#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adjList;

        void addEdge(int u,int v,bool direction){
            if(direction==1){
                adjList[u].push_back(v);
            }
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }

        }

        void printadjList(){
            for(auto i: adjList){
                cout<<i.first<<"->{ ";
                for(auto neighbour: i.second){
                    cout<<neighbour<<" ";
                }
                cout<<"}"<<endl;
            }
            
        }


};

int main(){

    Graph g;
    g.addEdge(1,2,0);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(2,4,1);

    g.printadjList();
    
    return 0;
}