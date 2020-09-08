#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findParent(int v, vector<int>& parent) {
	if (v == parent[v])
		return v;
	return parent[v] = findParent(parent[v], parent);
}

bool Union(pair<int, int> road, vector<int>& parent, vector<int>& depth) {
	int set1 = findParent(road.first, parent);
	int set2 = findParent(road.second, parent);

	if (set1 != set2) {
		if (depth[set1] < depth[set2])
			swap(set1, set2);

		parent[set2] = set1;

		if (depth[set1] == depth[set2])
			depth[set1]++;

		return true;
	}

	return false;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> roads(n - 1);
	pair<int, int> p;
	for (int i = 0; i < n - 1; i++) {
		cin >> p.first >> p.second;
		roads[i] = { p.first, p.second };
	}

	vector<int> parent(n + 1);
	for (int i = 0; i < n + 1; i++)
		parent[i] = i;

	vector<int> depth(n + 1, 0);
	vector<pair<int, int>> removedRoads;
	vector<pair<int, int>> addedRoads;
	for (int i = 0; i < n - 1; i++) {
		if (!Union({ roads[i].first, roads[i].second }, parent, depth))
			removedRoads.push_back({ roads[i].first, roads[i].second });
	}

	for (int i = 2; i <= n; i++) {
		if (Union({ i, i - 1 }, parent, depth))
			addedRoads.push_back({ i, i - 1 });
	}

	cout << addedRoads.size() << endl;
	for (int i = 0; i < addedRoads.size(); i++) {
		cout << removedRoads[i].first << " " << removedRoads[i].second << " " << addedRoads[i].first << " " << addedRoads[i].second << endl;
	}

	return 0;
}
