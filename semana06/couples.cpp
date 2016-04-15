#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <utility>

using namespace std;

struct vertice {
	int destino;
	int dist_a, dist_b;
	vertice() {}
	vertice(int dest, int d_a, int d_b) : destino(dest), dist_a(d_a), dist_b(d_b) {}
	bool operator<(const vertice& rhs) const {
		if( (dist_a == -1) || (dist_b == -1) )
			return false;
		else if((rhs.dist_a == -1) || (rhs.dist_b == -1))
			return true;
		else
			return (dist_a + dist_b) < (rhs.dist_a + rhs.dist_b);

	}
};

int main() {
	
	int num_cities;
	cin >> num_cities;
	while( !cin.eof() ) {

		vector<int> v(num_cities+1);
		for(int i = 1; i <= num_cities; i++)
			cin >> v[i];//.destino;

		int num_queries;
		cin >> num_queries;

		for(int i = 0; i < num_queries; i++) {
			//for(int j = 1; j <= num_cities; j++)
			//	v[i].dist_a = v[i].dist_b = -1; // yet unreached

			int a, b;
			cin >> a >> b;

			//queue<int> q_a, q_b;
			map<int, vertice> search_a, search_b;

			//q_a.push(a);
			search_a.insert(make_pair(a, vertice(v[a], 0, -1)) );
			//v[a].dist_a = 0; //root of the search
			int current_a = a;
			//q_b.push(b);
			search_b.insert(make_pair(b, vertice(v[b], -1, 0)) );
			//v[b].dist_b = 0; //root of the search
			int current_b = b;

			int steps = 0; //steps taken so far. quit when > 10^4

			bool met = false;
			int min_dist = 0;
			if(current_a == current_b)
				met = true; //stupid
			bool done_a = false, done_b = false;

			while( !met ) {

				//a's search
				//search_a.insert(v[current_a], vertice() )
				if(!done_a) {
					if(search_b.find(v[current_a]) != search_b.end() ) { //found. search done. 
						min_dist = search_a[current_a].dist_a + search_b[current_a].dist_b;
						met = true;
						break;
					} else if(search_a.find(v[current_a]) != search_a.end() ) { //repeat: abandon this search}
						done_a = true;
					} else {
						search_a.insert(make_pair(v[current_a], vertice(v[current_a], search_a[current_a].dist_a, -1) ) );
						current_a = v[current_a];
					}
				}

				//b's search
				if(!done_b) {
					if(search_a.find(v[current_b]) != search_a.end() ) { //found. search done. 
						min_dist = search_b[current_b].dist_b + search_a[current_b].dist_a;
						met = true;
						break;
					} else if(search_b.find(v[current_b]) != search_b.end() ) { //repeat: abandon this search}
						done_b = true;
					} else {
						search_b.insert(make_pair(v[current_b], vertice(v[current_b], -1, search_b[current_b].dist_b) ) );
						current_b = v[current_b];
					}
				}


				if(steps >= 10000)
					break; // abandon all hope
				steps++;
			}

			if(met == true)
				cout << min_dist << endl;
			else
				cout << -1 << endl;
		}






		cin >> num_cities;
	}
}