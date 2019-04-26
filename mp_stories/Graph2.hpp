#include <queue>
#include <algorithm>
#include <string>
#include <list>

/**
 * Returns an std::list of vertex keys that creates any shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 * 
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 * 
 * You should use undirected edges. Hint: There are no edge weights in the Graph.
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  // TODO: Part 3
  std::list<std::string> path;

  //CROSS EDGE = -1  DISC EDGE = 5   UNDISCOVERED EDGE = 1 (DEFAULT)

  //queue for the traversal
  std::queue<V> bfs;

  //map for adjacent vertices
  std::unordered_map<V, std::list<V>> adjVertices;

  //map for distances
  std::unordered_map<V, int> distances;

  //map for predecessor
  std::unordered_map<V, V> predecessor;

  for(std::pair<std::string, V_byRef> v : vertexMap){

  	//init adj vertices
  	std::list<V> list;
  	std::pair<V, std::list<V>> temp1(v.second,list);
  	adjVertices.insert(temp1);

  	//init distances
  	std::pair<V, int> temp2(v.second,-1);
  	distances.insert(temp2);

  	//init predecessor !!do this each time while loop tries to check pred
  	//std::pair<V, V> temp3(v.second,Vertex("UND"));
  	//predecessor.insert(temp3);

  }

 	//set up adjacent vertices list
  	for(std::pair<std::string, V_byRef> v : vertexMap){

  		std::list<std::reference_wrapper<E>> incident_edges = incidentEdges(v.first);

  			//std::cout<<"V:"<<v.first<<" indicent edges:"<<incident_edges.size()<<std::endl;

  			for(std::reference_wrapper<E> e : incident_edges){

  				//std::cout<<"Vertex:"<<v.first<<" indicent edge S:"<<e.get().source()<<" D:"<<e.get().dest()<<std::endl;

  				if(e.get().dest().key() == v.first){
  					//push vertex at destination into adj vertices

  					//std::cout<<"V:"<<v.first<<" adj vertex:"<<e.get().dest()<<std::endl;

  					adjVertices[v.first].push_back(e.get().source());
  				}

  				if(e.get().source().key() == v.first){

  					adjVertices[v.first].push_back(e.get().dest());
  				}
  		}
  	}
  	//std::cout<<std::endl;
  	///////////////////////////

  	// for(std::pair<std::string, V_byRef> v : vertexMap){

  	// 	//std::cout<<"V:"<<v.first<<" adj vertices:"<<adjVertices[v.second].size()<<std::endl;
  	// 	std::list<V> list = adjVertices[v.second];
  	// 	std::cout<<"V:"<<v.first<<" adj Vertices:";
  	// 	for(V i : list){
  	// 		std::cout<<i<<" ";
  	// 	}
  	// 	std::cout<<std::endl;

  	// }
  	
  	//std::cout<<"Contents of distances"<<std::endl;
  	//for(std::pair<V, int> t : distances){
  		//std::cout<<t.first.key()<<" "<<t.second<<std::endl;
  	//}
  	//std::cout<<std::endl;
  	//////////////////////////

  	
  	//put starting vertex in the queue and begin bfs
  	bfs.push(vertexMap.at(start));

  	V init = bfs.front();

  	//std::cout<<"Initial V:"<<init.key()<<std::endl;
  	//set predecessor -> init for predecessor here
  	predecessor.emplace(init, init);

  	//set distance
  	distances[init] = 0;

  	//do bfs
  	while(!bfs.empty()){

  		V current = bfs.front();

  		//std::cout<<"Searching V:"<<current.key()<<std::endl;

  		std::list<V> adj_verts = adjVertices[current];

  		//std::cout<<"Vertex "<<current.key()<<" has "<<adj_verts.size()<<" adj vert"<<std::endl;
  		
  		for(V adj_vertex : adj_verts){

  			//std::cout<<"Dist check in loop V:"<<adj_vertex.key()<<" d="<<distances[adj_vertex]<<std::endl;

  			//check if adj vertex has been visited
  			if(distances[adj_vertex] == -1){

  				bfs.push(adj_vertex);

  				//std::cout<<"adding V:"<<adj_vertex.key()<<" to bfs"<<std::endl;
  				//std::cout<<"bfs size:"<<bfs.size()<<std::endl;

  				//set distance
  				distances[adj_vertex] = distances[current] + 1;

  				//set predecessor (only needs to get set up once)
  				predecessor.emplace(adj_vertex, current);

  				//find edge from edgelist and set edge weight to mark edge as discovery edge
  				//MAY NOT NEED THIS

  				//end vertex is reached
  				if(end == adj_vertex.key()){
  					break;
  				}

  			}
  			//std::cout<<std::endl;
  		}
  		//std::cout<<"removing V:"<<bfs.front().key()<<" from bfs"<<std::endl;
  		bfs.pop();

  	}

  	
  	//go through vertex and predecessor map to build path
  	V last_v = vertexMap.at(end); 

  	while(last_v.key() != start){

  		path.push_front(last_v.key());

  		last_v = predecessor.at(last_v);

  	}

  	path.push_front(start);

  return path;
}




