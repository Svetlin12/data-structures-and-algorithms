#include <iostream>
#include <vector>
using namespace std;

int findParent(int v, vector<int>& parent) {
	if (v == parent[v])
		return v;
	return parent[v] = findParent(parent[v], parent);
}

void Union(pair<int, int> people, vector<int>& parent, vector<int>& size) {
	int set1 = findParent(people.first, parent);
	int set2 = findParent(people.second, parent);

	if (set1 != set2) {
		if (size[set1] < size[set2])
			swap(set1, set2);

		parent[set2] = set1;
		size[set1] += size[set2];
	}
}

int main() {
	int numPeople, numQueries;
	cin >> numPeople >> numQueries;

	vector<int> parent(numPeople + 1);
	for (int i = 0; i < numPeople; i++)
		parent[i] = i;

	vector<int> size(numPeople + 1, 1);

	char type;
	int person1, person2;
	for (int i = 0; i < numQueries; i++) {
		cin >> type;
		if (type == 'M') {
			cin >> person1 >> person2;
			Union({ person1, person2 }, parent, size);
		}
		else {
			cin >> person1;
			int p = findParent(person1, parent);
			cout << size[p] << endl;
		}
	}

	return 0;
}
