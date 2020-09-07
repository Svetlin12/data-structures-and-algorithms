#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef vector<pair<int, pair<int, int>>> vpp;

int find(int v, vector<int>& parents) {
	if (v == parents[v])
		return v;
	else return parents[v] = find(parents[v], parents);
}

bool Union(pair<int, int> p, vector<int>& parents, unordered_map<int, bool>& machines) {
	int parent1 = find(p.first, parents);
	int parent2 = find(p.second, parents);

	if (machines[parent1] && machines[parent2])
		return false;

	if (parent1 != parent2) {
		if (machines[parent2])
			swap(parent2, parent1);

		parents[parent2] = parent1;
		return true;
	}

	return false;
}

int minTime(vpp& roads, unordered_map<int, bool>& machines) {
	sort(roads.begin(), roads.end(), greater<pair<int, pair<int, int>>>());
	vector<int> parents(roads.size() + 1);
	
	for (int i = 0; i < parents.size(); i++)
		parents[i] = i;

	int time = 0;
	for (auto& road : roads)
		if (!Union({ road.second.first, road.second.second }, parents, machines))
			time += road.first;

	return time;
}

int main() {
	int n, k;
	cin >> n >> k;

	vpp roads;
	roads.reserve(n);
	int city1, city2, time;
	for (int i = 0; i < n - 1; i++) {
		cin >> city1 >> city2 >> time;
		roads.push_back({ time, {city1, city2} });
	}

	unordered_map<int, bool> machines;
	int machine;
	for (int i = 0; i < k; i++) {
		cin >> machine;
		machines[machine] = true;
	}

	cout << minTime(roads, machines);

	return 0;
}
