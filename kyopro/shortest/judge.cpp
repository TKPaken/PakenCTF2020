#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

vector<int>solve1(int n,int m,vector<pair<int,int>>E) {
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

vector<int>solve2(int n,int m,vector<pair<int,int>>E) {
	vector<vector<int>>G(n);
	for (auto& p : E) {
		G[p.first].push_back(p.second);
		G[p.second].push_back(p.first);
	}
	vector<int>d(n, -1);
	queue<int>que;
	d[0] = 0; que.push(0);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (int u : G[v]) {
			if (d[u] == -1) {
				d[u] = d[v] + 1;
				que.push(u);
			}
		}
	}
	return d;
}

int main() {
	int n, m;
    cin >> n >> m;
    
    if(n<=0||n>5||m<0||m>5){
        cout<<"Invalid input"<<endl;return 0;
    }
	vector<pair<int, int>>E(m);
    for(auto &e : E){
        cin >> e.first >> e.second;
        if(e.first<0||e.first>=n||e.second<0||e.second>=n){
            cout<<"Invalid input"<<endl;return 0;
        }
    }
	auto a = solve1(n, m, E);
    auto b = solve2(n, m, E);
    if(a!=b){
        cout<<"Congratulations!"<<endl;
        system("/bin/cat flag.txt");
    }else {
        cout<<"Unsuccess"<<endl;
    }
}