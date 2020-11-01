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
#line 3 "/home/defineprogram/Desktop/Library/math/modint.cpp"

template<int MOD>
struct mint{
	int32_t n;
	mint():n(0){}
	mint(ll x):n(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}

	mint &operator+=(const mint &p){
		if((n+=p.n)>=MOD)n-=MOD;
		return *this;
	}
	mint &operator-=(const mint &p){
		if((n+=MOD-p.n)>=MOD)n-=MOD;
		return *this;
	}
	mint &operator*=(const mint &p){
		n=1ll*n*p.n%MOD;
		return *this;
	}
	mint &operator/=(const mint &p){
		*this*=p.inverse();
		return *this;
	}
	mint operator-()const{return mint(-n);}
	mint operator+(const mint &p)const{return mint(*this)+=p;}
	mint operator-(const mint &p)const{return mint(*this)-=p;}
	mint operator*(const mint &p)const{return mint(*this)*=p;}
	mint operator/(const mint &p)const{return mint(*this)/=p;}
	bool operator==(const mint &p)const{return n==p.n;}
	bool operator!=(const mint &p)const{return n!=p.n;}

	friend ostream &operator<<(ostream &os,const mint &p){
		return os<<p.n;
	}
	friend istream &operator>>(istream &is,mint &p){
		int x;is>>x;
		p=mint(x);
		return is;
	}
	mint pow(int64_t x)const{
		mint res(1),mul(n);
		while(x>0){
			if(x&1)res*=mul;
			mul*=mul;
			x>>=1;
		}
		return res;
	}
	mint inverse()const{
		return pow(MOD-2);
	}
};
/*
@brief mod int
@docs docs/modint.md
*/
#line 3 "main.cpp"

using modint=mint<(int)(1e9+7)>;
int N,K;
modint dp[500][500*500];
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>N>>K;
    dp[0][0]=1;dp[0][1]=-1;
    rep(i,N+1){
        rep(j,K+1){
            dp[i][j+1]+=dp[i][j];
            dp[i+1][j]+=dp[i][j];
            if(j+i+1<=K)dp[i+1][j+i+1]-=dp[i][j];
        }
    }
    cout<<dp[N][K]<<endl;
}
