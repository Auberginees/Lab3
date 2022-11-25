#include <iostream>
#include <algorithm>
#include <vector>

//14

//0 1 4
//0 7 8
//1 2 8
//1 7 11
//2 3 7
//2 8 2
//2 5 4
//3 4 9
//3 5 14
//4 5 10
//5 6 2
//6 7 1
//6 8 6
//7 8 7

using namespace std;

int previous[100];

int set_find(int v) {

	if (previous[v] == v) {
		return v;
	}

	return set_find(previous[v]);
};


void set_unite(int v, int u) {
	int fv = set_find(v);
	int fu = set_find(u);
	previous[fv] = fu;
};

int main() {
	setlocale(LC_CTYPE, "ukr");
	for (int i = 0; i < 100; i++)
	{
		previous[i] = i;
	}

	int v, e;
	int first, sec, weight;
	vector < pair < int, pair < int, int > > > edges;
	cout << "Введiть к-сть вершин i ребер: " << endl;
	cin >> v >> e;

	cout << "Введiть : " << endl;

	for (int i = 0; i < e; i++)
	{
		cin >> first >> sec >> weight;
		edges.push_back(make_pair(weight, make_pair(first, sec)));
	}

	cout << endl;
	cout << "Пiсля Алгоритму Краскала: \n";
	int mst_weight = 0, mst_edges = 0, mst_n = 0;

	sort(edges.begin(), edges.end());
	while ((mst_edges < v - 2) || (mst_n < e))
	{
		first = edges[mst_n].second.first;
		sec = edges[mst_n].second.second;
		weight = edges[mst_n].first;

		if (set_find(first) != set_find(sec)) {
			set_unite(first, sec);
			mst_weight += weight;
			cout << first << "  " << sec
				<< " -> " << weight << endl;
			mst_edges++;
		}
		mst_n++;
	}
}
