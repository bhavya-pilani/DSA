#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;


template<typename T>
class Graph{
    public:
        unordered_map<T,list<pair<int,int> > >adjList;

        void addEdge(T u,T v,int wt,bool direction){
            if(direction==1){
                adjList[u].push_back({v,wt});
            }
            else{
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }

        }
        void bfsTraversal(T src,unordered_map<T,bool>&vis){
            queue<T>q;
            q.push(src);
            vis[src]=true;

            while(!q.empty()){
                T front=q.front();
                cout<<front<<" ";
                q.pop();

                for(auto i: adjList[front]){
                    if(!vis[i.first]){
                        q.push(i.first);
                        vis[i.first]=true;
                    }
                }
            }
    
        }

        
        void dfs(T src , unordered_map<T,bool> &vis){
            vis[src]=true;
            cout<<src<<" ";

            for(auto nbr: adjList[src]){
                if(!vis[nbr.first]){
                    dfs(nbr.first,vis);
                }
            }
        }
};

int main(){
    Graph<char> g;
 
    g.addEdge('a','b',5,0);
    g.addEdge('a','c',10,0);
    g.addEdge('b','c',15,0);
    g.addEdge('c','d',20,0);
    g.addEdge('c','e',20,0);


   cout<<"BFS tarversal:";
    unordered_map<char,bool>vis;
    for(char i='a';i<='e';i++){
        if(!vis[i]){
            g.bfsTraversal(i,vis);
        }}

cout<<endl;
unordered_map<char,bool>vis2;

cout<<"DFS tarversal:";
    g.dfs('a',vis2);
    
    return 0;
}