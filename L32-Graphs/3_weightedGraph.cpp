#include <iostream>
#include <set>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

template<typename T>
class Graph {
public:
	map < T, list < pair<T, int> > > h;

	void addEdge(T u, T v, int d, bool bidir = true) {
		h[u].push_back({v, d});
		if (bidir) {
			h[v].push_back({u, d});
		}
	}

	void print() {
		for (auto hp : h) {
			cout << hp.first << " : ";
			for (auto chp : hp.second) {
				cout << "(" << chp.first << ", " << chp.second << ") ";
			}
			cout << endl;
		}
	}

	// src node se har node ka shortest distance find karna
	void dijkstras(T src, T des) {
		unordered_map<T, T> parent;
		unordered_map<T, int> dist;

		for (auto hp : h) {
			dist[hp.first] = INT_MAX;
		}
		dist[src] = 0; // src ka distance khud se toh 0 hi hoga....
		parent[src] = src;

		// Set mei we will insert reverse pair: We want data sorted as per dist
		set<pair<int, T> > s;
		// src node khud se 0 distance par hai
		s.insert({0, src});

		while (!s.empty()) {
			auto rsp = *(s.begin());
			s.erase(s.begin());

			int cd = rsp.first;
			T n = rsp.second;

			for (auto chp : h[n]) {
				T ch = chp.first;
				int ed = chp.second;
				if (dist[ch] > cd + ed) {
					auto fp_address = s.find({dist[ch], ch});
					if (fp_address != s.end()) {
						s.erase(fp_address);
					}

					s.insert({cd + ed, ch});
					parent[ch] = n;
					dist[ch] = cd + ed;
				}
			}
		}


		for (auto p : dist) {
			cout << "Distance of " << p.first << " from " << src << " : " << p.second << endl;
		}

		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;

	}
};

int main() {

	Graph<string> g;

	int n, d;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string u, v;
		cin >> u >> v >> d;

		g.addEdge(u, v, d);
	}

	g.print();
	g.dijkstras("Amritsar", "Mumbai");

	return 0;
}
















