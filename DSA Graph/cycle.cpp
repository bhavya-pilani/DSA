#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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
         
        bool checkCycleUndirectedBFS(int src){
            queue<int>q;
            unordered_map<int,int>vis;
            unordered_map<int,int>parent;

            q.push(src);
            parent[src]=-1;
            vis[src]=true;

            while(!q.empty()){
                int front=q.front();
                q.pop();

                for(auto nbr: adjList[front]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr]=true;
                        parent[nbr]=front;
                    }
                    else if(vis[nbr]==true && parent[front]!=nbr){
                        return true;
                    }

                }
            }
            return false;

        }
        bool checkCycleUndirectedBFS_2(int src){
            queue<int>q;
            unordered_map<int,int>vis;
            unordered_map<int,int>parent;

            q.push(src);
            parent[src]=-1;
            vis[src]=true;

            while(!q.empty()){
                int front=q.front();
                q.pop();

                for(auto nbr: adjList[front]){
                    if(parent[front]==nbr){
                        continue;
                    }
                    
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr]=true;
                        parent[nbr]=front;
                    }
                    else if(vis[nbr]==true){
                        return true;
                    }

                }
            }
            return false;

        }

        bool checkCycleUndirectedDFS(int src,int parent,unordered_map<int,int>&vis){
            
            vis[src]=true;

            for(auto nbr: adjList[src]){
                if(!vis[nbr]){
                    bool ans=checkCycleUndirectedDFS(nbr,src,vis);
                    if(ans){
                        return true;
                    }
                }
                else if(vis[nbr] && parent!=nbr){
                    return true;
                }
            }
            return false;
        }


};

int main(){

    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);
    g.addEdge(2,5,0);

    g.printadjList();
    int src=0;
    // bool isCyclic=g.checkCycleUndirectedBFS_2(src);
    unordered_map<int,int>vis;
    bool isCyclic=g.checkCycleUndirectedDFS(src,-1,vis);

    if(isCyclic){
        cout<<"Cycle present"<<endl;
    }
    else{
        cout<<"Cycle absent";
    }
    
    return 0;
}