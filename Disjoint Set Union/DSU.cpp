#include <iostream>
#include <vector>
using namespace std;

// complexity is O(1) amortised

int findSet(int v, vector<int>& parent) {
	if (v == parent[v])
		return v;
	return parent[v] = findSet(parent[v], parent);
}

// union by size
void makeSet(int v, vector<int>& parent, vector<int>& size) {
	parent[v] = v;
	size[v] = 1;
}

void unionSet(int set1, int set2, vector<int>& parent, vector<int>& size) {
	set1 = findSet(set1, parent);
	set2 = findSet(set2, parent);

	if (set1 != set2) {
		if (size[set1] < size[set2])
			swap(set1, set2);
		parent[set2] = set1;
		size[set1] += size[set2];
	}
}

// union by rank(depth)
void makeSet(int v, vector<int>& parent, vector<int>& rank) {
	parent[v] = v;
	rank[v] = 0;
}

void unionSet(int set1, int set2, vector<int>& parent, vector<int>& rank) {
	set1 = findSet(set1, parent);
	set2 = findSet(set2, parent);

	if (set1 != set2) {
		if (rank[set1] < rank[set2])
			swap(set1, set2);

		parent[set2] = set1;
		if (rank[set1] == rank[set2])
			rank[set1]++;
	}
}

int main() {
	return 0;
}
