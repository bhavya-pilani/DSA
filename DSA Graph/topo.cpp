#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>

using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>>adjList;

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
            for(auto i:adjList){
                cout<<i.first<<" {";
                for(auto j: i.second){
                    cout<<j<<" ";
                }
                cout<<"}"<<endl;
            }
        }

        void topoSort(int src,unordered_map<int,bool>&vis,stack<int>& st){
            vis[src]=true;

            for(auto nbr:adjList[src]){
                if(!vis[nbr]){
                    topoSort(nbr,vis,st);
                }
            }
            st.push(src);
        }

        void topoSortBFS(int n){
            queue<int>q;
            unordered_map<int,int>indegree;

            for(auto i:adjList){
                for(auto nbr:i.second){
                    indegree[nbr]++;
                }
            }

            for(int node=0;node<n;node++){
                if(indegree[node]==0){
                    q.push(node);
                }
            }

            while(!q.empty()){
                int frontNode=q.front();
                q.pop();
                cout<<frontNode<<" ";

                for(auto nbr:adjList[frontNode]){
                    indegree[nbr]--;

                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }

        }
};



int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(2,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(5,7,1);

    g.printadjList();

    unordered_map<int,bool>vis;
    stack<int>st;

    // for(int node=0;node<=7;node++){
    //     if(!vis[node]){
    //         g.topoSort(node,vis,st);
    //     }
    // }

    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    int n=8;
    g.topoSortBFS(n);


}

