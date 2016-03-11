/* c++11 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <iterator>
#include <utility>
#include <set>

using namespace std;

enum vertex_color {
	BLACK, GREY, WHITE
};

struct vertex_info {
	vertex_color color;
	set<int> adjlist;
	vertex_info() : color(BLACK), adjlist( set<int>() ) {}
};

//#define BLACK 0
//#define GREY 1
//#define WHITE 2

char DFS_visit(vector<vertex_info>& grafo, int vertex);

int main() {
	
	int t, n, m, a, b;
	bool found_cycle = false; // no cycle detected
	vector<vertex_info > grafo, grafo_transposto;

	// each vertex has a color and an adjacency list (set of vertex id's it points to)

	scanf("%i ", &t);
	while(t--) { // t test cases
		scanf("%i %i ", &n, &m);
		grafo.reserve(n+1); // n vertices indexed by id. 0th index unused
		
		for(int i = 1; i <= n; i++) {
			grafo[i] = vertex_info(); // initialize vertices to unexplored
		}
		
		//  read edges
		for(int i = 0; i < m; i++) {
			scanf("%i %i ", &a, &b);
			grafo[b].adjlist.insert(a); // edge (b, a) (a depends on b)
		}

		found_cycle = false; // as soon as a cycle is seen, DFS is unwound and we print SIM
		// run a DFS and look for return edges while exploring (open vertices in some adjacency you are exploring)
		for(int i = 1; i <= n; i++) { // outer DFS loop, make sure all vertices are explored
			if(grafo[i].color == BLACK) {
				if(DFS_visit(grafo, i) == 'Y') { // start a DFS tree at i
					found_cycle = true; // we found a cycle. exit
					break;
				}
			}
		}
		if(found_cycle)
			puts("SIM");
		else
			puts("NAO");

		grafo.erase( grafo.begin(), grafo.end() );
	}

	return 0;
}

char DFS_visit(vector<vertex_info>& grafo, int vertex) { // returns 'Y' if loop found, 'N' otherwise
	grafo[vertex].color = GREY; // color the vertex grey (being explored)
	for(auto it = grafo[vertex].adjlist.begin();
			 it != grafo[vertex].adjlist.end();
			 ++it ) 
	{ 
			// iterate through adjacency set of vertex i
		if( grafo[*it].color == BLACK ) {
			if( DFS_visit(grafo, *it) == 'Y')
				return 'Y'; // cycle found further down the recursion tree.
		}
		else if( grafo[*it].color == GREY ) {
			return 'Y'; // cycle found
		}
	}

	grafo[vertex].color = WHITE;
	return 'N'; // if we made it all the way here, we didnt find any cycle
}