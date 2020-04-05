#include<iostream>
#include<unordered_map>
#include<cstring>
#include<list>
using namespace std;


template<typename T>
class Graph{
	unordered_map<T,list<T> > adjList;

public:
	Graph(){

	}
	 void addEdge(T u , T v , bool bidir = true){
	 	adjList[u].push_back(v);
	 	if(bidir){
	 		adjList[v].push_back(u);
	 	}
	 }
	 void printAdjList(){

	 	for(auto row : adjList){
	 		T key = row.first;
	 		cout<<key<<"->";

	 		for(T element : row.second){
	 			cout<<element<<",";
	 		}
	 		cout<<"\n";

	 	}
	 }
};


int main(){
	Graph<string>g;
	g.addEdge("Hyderabad","Mumbai");
	g.addEdge("Hyderabad","Goa");
	g.addEdge("Mumbai","Bengaluru");
	g.addEdge("Mumbai","Kerala");
	g.addEdge("Mumbai","Chennai");
	g.addEdge("Hyderabad","Bengaluru");

	g.printAdjList();

}