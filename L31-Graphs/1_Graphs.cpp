#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Graph {
public:
	list< pair<T, T> > l;

	void addEdge(T u, T v) {
		l.push_back({u, v});
		// pair<T, T> p;
		// p.first = u;
		// p.second = v;
		// l.push_back(p);
	}

	void printGraph() {
		for (auto p : l) {
			cout << p.first << ", " << p.second << endl;
		}
	}
};

int main() {

	Graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('D', 'B');
	g.addEdge('D', 'C');
	g.addEdge('A', 'C');

	g.printGraph();
	return 0;
}
















