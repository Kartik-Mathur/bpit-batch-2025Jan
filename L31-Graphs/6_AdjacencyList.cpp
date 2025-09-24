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

	void bfs(T src) {
		unordered_map<T, bool> visited;
		queue<T> q;
		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			cout << x << " ";
			for (auto ch : h[x]) {
				// count returns 0 or 1, if present in hashmap then 1 else 0
				if (visited.count(ch) == 0) {
					q.push(ch);
					visited[ch] = true;
				}
			}
		}
	}

	void singleSourceShortestPath(char src, char des) {
		unordered_map<T, int> dist;
		unordered_map<T, T> par;

		queue<T> q;
		q.push(src);
		par[src] = src;
		dist[src] = 0;

		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			for (auto ch : h[x]) {
				// count returns 0 or 1, if present in hashmap then 1 else 0
				if (dist.count(ch) == 0) {
					q.push(ch);
					dist[ch] = dist[x] + 1;
					par[ch] = x;
				}
			}
		}

		cout << "Distance of every node from " << src << " is: " << endl;
		for (auto p : dist) {
			cout << "Dist of " << src << " from " << p.first << "  : " << p.second << endl;
		}


		// Print the path
		while (des != par[des]) {
			cout << des << "<--";
			des = par[des];
		}
		cout << des << endl;
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

	// g.print();
	g.singleSourceShortestPath('A', 'F');

	return 0;
}
















