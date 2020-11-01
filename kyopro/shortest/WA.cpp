#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

vector<int>solve(int n,int m,vector<pair<int,int>>E) {
	vector<vector<int>>G(n);
	for (auto& p : E) {
		G[p.first].push_back(p.second);
		G[p.second].push_back(p.first);
	}
	vector<int>d(n, -1);
	stack<int>st;
	d[0] = 0; st.push(0);
	while (!st.empty()) {
		int v = st.top(); st.pop();
		for (int u : G[v]) {
			if (d[u] == -1) {
				d[u] = d[v] + 1;
				st.push(u);
			}
		}
	}
	return d;
}

int main() {
	int n, m;
    cin >> n >> m;

	vector<pair<int, int>>E(m);
    for(auto &e : E){
        cin >> e.first >> e.second;
    }
	auto a = solve(n, m, E);
	for (int i : a)cout << i << ' ';
	cout << endl;
}