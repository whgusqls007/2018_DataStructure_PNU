#include <bits/stdc++.h>

using namespace std;

void calculate(int i, int j);
int N, M, K;
deque<int> q1, q2;
vector<vector<int>> virus;
vector<vector<bool>> visit;
int main() {
	ifstream in("virus.inp");
	int counter = 0;
	in >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		vector<int> int_temp;
		vector<bool> bool_temp;
		for (int j = 0; j < N; j++) {
			char ctemp;
			in >> ctemp;
			if (ctemp == '#') { int_temp.push_back(1); }
			else { int_temp.push_back(0); }
			bool_temp.push_back(0);
		}
		virus.push_back(int_temp);
		visit.push_back(bool_temp);
	}
	in.close();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (virus[i][j] == 1 && visit[i][j] == 0) {
				calculate(i, j);
			}
			if (q1.size() >= K) {
				counter++;
			}
			if (q1.size() < K) {
				q1.clear();
			}
			if (q1.size() > q2.size()) {
				q2 = q1;
			}
			q1.clear();
		}
	}
	ofstream out("virus.out");
	out << counter << " " << q2.size() << endl;
	out.close();
}
void calculate(int i, int j) {
	q1.push_back(1);
	visit[i][j] = 1;
	if (i == 0 && j == 0) {
		if (virus[i][j + 1] == 1 && visit[i][j + 1] == 0) {
			calculate(i, j + 1);
		}
		if (virus[i + 1][j] == 1 && visit[i + 1][j] == 0) {
			calculate(i + 1, j);
		}
	}
	else if (i == 0 && j > 0 && j < N - 1) {
		if (virus[i][j + 1] == 1 && visit[i][j + 1] == 0) {
			calculate(i, j + 1);
		}
		if (virus[i][j - 1] == 1 && visit[i][j - 1] == 0) {
			calculate(i, j - 1);
		}
		if (virus[i + 1][j] == 1 && visit[i + 1][j] == 0) {
			calculate(i + 1, j);
		}
	}
	else if (i < M - 1 && i > 0 && j == 0) {
		if (virus[i][j + 1] == 1 && visit[i][j + 1] == 0) {
			calculate(i, j + 1);
		}
		if (virus[i - 1][j] == 1 && visit[i - 1][j] == 0) {
			calculate(i - 1, j);
		}
		if (virus[i + 1][j] == 1 && visit[i + 1][j] == 0) {
			calculate(i + 1, j);
		}
	}
	else if (i == M - 1 && j == N - 1) {
		if (virus[i][j - 1] == 1 && visit[i][j - 1] == 0) {
			calculate(i, j - 1);
		}
		if (virus[i - 1][j] == 1 && visit[i - 1][j] == 0) {
			calculate(i - 1, j);
		}
	}
	else if (i == M - 1 && j >= 0 && j < N - 1) {
		if (j != 0) {
			if (virus[i][j + 1] == 1 && visit[i][j + 1] == 0) {
				calculate(i, j + 1);
			}
			if (virus[i][j - 1] == 1 && visit[i][j - 1] == 0) {
				calculate(i, j - 1);
			}
			if (virus[i - 1][j] == 1 && visit[i - 1][j] == 0) {
				calculate(i - 1, j);
			}
		}
		else {
			if (virus[i][j + 1] == 1 && visit[i][j + 1] == 0) {
				calculate(i, j + 1);
			}
			if (virus[i - 1][j] == 1 && visit[i - 1][j] == 0) {
				calculate(i - 1, j);
			}
		}
	}
	else if (i >= 0 && i < M - 1 && j == N - 1) {
		if (i != 0) {
			if (virus[i - 1][j] == 1 && visit[i - 1][j] == 0) {
				calculate(i - 1, j);
			}
			if (virus[i + 1][j] == 1 && visit[i + 1][j] == 0) {
				calculate(i + 1, j);
			}
			if (virus[i][j - 1] == 1 && visit[i][j - 1] == 0) {
				calculate(i, j - 1);
			}
		}
		else {
			if (virus[i + 1][j] == 1 && visit[i + 1][j] == 0) {
				calculate(i + 1, j);
			}
			if (virus[i][j - 1] == 1 && visit[i][j - 1] == 0) {
				calculate(i, j - 1);
			}
		}
	}
	else if (i > 0 && i < M - 1 && j > 0 && j < N - 1) {
		if (virus[i][j + 1] == 1 && visit[i][j + 1] == 0) {
			calculate(i, j + 1);
		}
		if (virus[i][j - 1] == 1 && visit[i][j - 1] == 0) {
			calculate(i, j - 1);
		}
		if (virus[i + 1][j] == 1 && visit[i + 1][j] == 0) {
			calculate(i + 1, j);
		}
		if (virus[i - 1][j] == 1 && visit[i - 1][j] == 0) {
			calculate(i - 1, j);
		}
	}
}