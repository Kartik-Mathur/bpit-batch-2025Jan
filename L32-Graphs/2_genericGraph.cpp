#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

template<typename T>
class Graph {
public:
	map<T, list<T> > h;

	void addEdge(T u, T v, bool bidir = true) {
		h[u].push_back(v);
		if (bidir) {
			h[v].push_back(u);
		}
	}

	void print() {
		for (auto p : h) {
			cout << p.first << " : ";
			for (auto no : p.second) {
				cout << no << " ";
			}
			cout << endl;
		}
	}

	void dfsHelper(T src, unordered_map<T, bool> &visited) {
		cout << src << " ";
		visited[src] = true;

		for (auto ch : h[src]) {
			if (!visited[ch]) {
				dfsHelper(ch, visited);
			}
		}
	}

	void dfs() {
		// We will call dfs function and visited map iske andar bana denge
		unordered_map<T, bool> visited;
		// ab dfsHelper ko call krdo aur usse dono cheezein mill jaengi aaram se
		for (auto p : h) {
			if (!visited[p.first]) {
				dfsHelper(p.first, visited);
			}
		}

	}

};

int main() {

	Graph<string> g;

	int n;
	bool directional;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string u, v;
		cin >> u >> v >> directional;

		g.addEdge(u, v, directional);
	}

	// g.print();
	g.dfs();
	return 0;
}
















