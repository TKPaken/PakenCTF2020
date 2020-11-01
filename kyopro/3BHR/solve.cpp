#line 2 "/home/defineprogram/Desktop/Library/template/template.cpp"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,n) for(ll i=1;i<n;i++)
#define rev(i,n) for(ll i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<ll,ll>
#define len(s) (ll)s.size()
 
template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr ll inf = 3e18;
#line 2 "main.cpp"

int H,W,N,X[100005],Y[100005],p[100005];
vector<int>G[200005];
bool yoko[100005],tate[100005];
int nyuji[200005];
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>H>>W>>N;
    vector<int>xx,yy;
    rep(i,N){
        cin>>X[i]>>Y[i]>>p[i];
        xx.push_back(X[i]);yy.push_back(Y[i]);
    }
    sort(all(xx));xx.erase(unique(all(xx)),xx.end());
    sort(all(yy));yy.erase(unique(all(yy)),yy.end());
    rep(i,N){
        X[i]=lower_bound(all(xx),X[i])-xx.begin();
        Y[i]=lower_bound(all(yy),Y[i])-yy.begin();
        if(!p[i])tate[Y[i]]=true;
        else yoko[X[i]]=true;
    }
    rep(i,N){
        if(!p[i]&&yoko[X[i]]){
            G[X[i]].push_back(Y[i]+100000);
            nyuji[Y[i]+100000]++;
        }
        if(p[i]&&tate[Y[i]]){
            G[Y[i]+100000].push_back(X[i]);
            nyuji[X[i]]++;
        }
    }
    queue<int>que;
    rep(i,200000)if(!nyuji[i])que.push(i);
    while(!que.empty()){
        int p=que.front();que.pop();
        for(int i:G[p]){
            nyuji[i]--;
            if(!nyuji[i])que.push(i);
        }
    }
    int ans=0;
    rep(i,N)if(!nyuji[X[i]]||!nyuji[100000+Y[i]])ans++;
    cout<<ans<<endl;
}
