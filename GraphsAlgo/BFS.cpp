#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int V;

	//Array of linked lists of size V

	list<int> *adjList;
public:

	Graph(int v){
		V=v;
		adjList = new list<int>[V];
	}

	void addEdge(int u,int v, bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			for(int node : adjList[i]){
				cout<<node<<",";
			}
			cout<<"\n";
		}
	}
	void bfs(int src){
		//Traversing all the nodes of the graph
		queue<int> q;
		bool *visited = new bool[V+1]{0};
		int *distance = new int[V+1]{0};
        int *parent = new int[V+1];

        for(int i=0;i<V;i++)
        {
        	parent[i]=-1;
        }
		q.push(src);
		visited[src]=true;
		while(!q.empty()){
			int node = q.front();
			cout<<node<<" ";
			q.pop();

			for(int neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour]=true;
					distance[neighbour] = distance[node]+1;
					parent[neighbour] = node;
				}
			}
		}
		cout<<"\n";
		//Printing the distances of every node from source
		for(int i=0;i<V;i++){
			cout<<i<<" "<<"node having distance "<<distance[i]<<endl;
		}

	}
};





int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);

	g.bfs(0);
	return 0;
}
