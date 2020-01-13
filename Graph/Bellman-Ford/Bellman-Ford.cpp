#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef vector<pair<int, pair<int, int>>> vpp;

void belmond(vpp& gr, int num_vertices, int start)
{
	vector<int> paths((int)gr.size(), INT_MAX);
	paths[start] = 0;
	bool updated;

	int i;
	for (i = 0; i < num_vertices; i++)
	{
		updated = false;
		for (int j = 0; j < (int)gr.size(); j++)
		{
			if (paths[gr[j].first] != INT_MAX && paths[gr[j].first] + gr[j].second.second < paths[gr[j].second.first])
			{
				paths[gr[j].second.first] = paths[gr[j].first] + gr[j].second.second;
				updated = true;
			}
		}
		if (!updated)
			break;
	}

	if (updated && i == num_vertices)
		cout << "no min path\n";
	else
		for (int i = 1; i < num_vertices; i++)
		{
			if (i != start)
			{
				if (paths[i] == INT_MAX)
					cout << "-1\n";
				else
					cout << paths[i] << "\n";
			}
		}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vpp gr(m);

	int v1, v2, w;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> w;
		gr[i] = { v1, {v2, w} };
	}

	int start;
	cin >> start;

	belmond(gr, n, start);

	return 0;
}
