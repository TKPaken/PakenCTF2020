#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstdint>
using namespace std;

struct edge {
    long long to, cost;
};

int main(){
long long N, M, K,a,b,c,ans=1000000000000000;
    cin >> N >> M >> K;
    vector<vector<edge>>graph(N);//辺の追加にかかるコストを辺を通るcostと考える
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back({ b,0 });
    }
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({ b,c });
    }
    //全頂点ダイクストラ
    for (int i = 0; i < N; i++) {//始点
        vector<long long>dist(N, 1000000000000000);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pque;//{cost,to}
        for (int j = 0; j < (int)graph[i].size(); j++) {
            dist[graph[i][j].to] = graph[i][j].cost;
            pque.push({ graph[i][j].cost, graph[i][j].to });
        }
        while (!pque.empty()) {
            int fir = pque.top().first,sec=pque.top().second;
            pque.pop();
            if (dist[sec] < fir)continue;
            for (int j = 0; j < graph[sec].size(); j++) {
                if (dist[graph[sec][j].to] > dist[sec] + graph[sec][j].cost) {
                    dist[graph[sec][j].to] = dist[sec] + graph[sec][j].cost;
                    pque.push({ dist[graph[sec][j].to],graph[sec][j].to });
                }
            }
        }
        if (ans > dist[i]) ans = dist[i];
    }
    //cycleがないときの処理
    if(ans==1000000000000000){
        cout<<-1<<endl;
        return 0;
    }
    
    cout << ans << endl;
}