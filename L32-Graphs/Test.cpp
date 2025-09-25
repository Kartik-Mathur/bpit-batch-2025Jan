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

	void dfs(T src) {
		// We will call dfs function and visited map iske andar bana denge
		unordered_map<T, bool> visited;
		// ab dfsHelper ko call krdo aur usse dono cheezein mill jaengi aaram se
		dfsHelper(src, visited);
	}

	void componentCountHelper(T src, unordered_map<T, bool> &visited) {
		visited[src] = true;

		for (auto ch : h[src]) {
			if (!visited[ch]) {
				componentCountHelper(ch, visited);
			}
		}
	}

	void componentCount() {
		unordered_map<T, bool> visited;
		int components = 0;
		// Graph par iterate karo and dekhlo har key visited hai ya nahi
		// kyunki components jitne honge graph ke andar toh present honge hi
		// Use them to check, agar koi bhi key hashmap h mei visited nhi hai
		// toh ek new component mill gaya, ask dfs to mark that entire component
		// as visited and keep checking the remaining graph..
		for (auto p : h) {
			if (!visited[p.first]) {
				componentCountHelper(p.first, visited);
				components++;
			}
		}

		cout << "Total components: " << components << endl;
	}
};

int main() {

	Graph<char> g;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char u, v;
		cin >> u >> v;

		g.addEdge(u, v);
	}

	g.componentCount();
	// g.dfs('A');
	// g.print();
	return 0;
}
















