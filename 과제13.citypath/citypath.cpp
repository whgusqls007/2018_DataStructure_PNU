#include<bits/stdc++.h>

using namespace std;

void distance(int start, int n, priority_queue<int, vector<int>,
	less<int>>&max, vector<vector<int>> graph);

int main() {
	ifstream in("1.inp");
	int n, counter = 0;
	in >> n;
	priority_queue<int, vector<int>, less<int>> max;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < n; i++) {
		int a, b;
		in >> a >> b;
		while (b != 0) {
			graph[a].push_back(b);
			in >> b;
		}
	}
	in.close();
	for (int start_node = 1; start_node <= n; start_node++) {
		distance(start_node, n, max, graph);
	}
	ofstream out("citypath.out");
	out << max.top() << endl;
	out.close();
}
void distance(int start, int n, priority_queue<int, vector<int>,
	less<int>>&max, vector<vector<int>> graph) {
	int counter = 0;
	deque<int> q1, q2;
	vector<vector<int>> map(n + 1);
	int* visit;
	visit = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		visit[i] = -1;
	}
	visit[0] = 0;
	visit[start] = 0;
	q1.push_back(start);
	while (!q1.empty()) {
		int node = q1.front();
		q1.pop_front();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (visit[next] == -1) {
				if (counter > 0) {
					visit[next] = visit[node] + graph[node].size();
				}
				else if (counter == 0)
					visit[next] = visit[node] + 1;
				q2.push_back(next);
				if (node != graph[node][i]) {
					map[node].push_back(next);
				}
			}
			else {
				if (visit[node] + graph[node].size() < visit[next]) {
					visit[next] = visit[node] + graph[node].size();
				}
			}
		}
		if (q1.empty()) {
			q1 = q2;
			q2.clear();
			counter++;
		}
	}
	int maximum = 0;
	for (int i = 1; i < n + 1; i++) {
		if (visit[i] > maximum) {
			maximum = visit[i];
		}
	}
	max.push(maximum);
}