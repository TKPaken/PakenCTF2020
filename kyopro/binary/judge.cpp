#include<bits/stdc++.h>
using namespace std;
int main(){
    srand((unsigned)time(NULL));
    vector<int>v(10000),rem(9998);
    set<int>st;st.insert(0);st.insert(9999);
    iota(rem.begin(),rem.end(),1);
    v[0]=1;v[9999]=1000;
    bool flag=false;
    while(rem.size()){
        int index=rand()%rem.size();
        int l=*(--st.lower_bound(rem[index]));
        int r=*st.lower_bound(rem[index]);
        int lower=max({1,v[l]-(rem[index]-l),v[r]-(r-rem[index])});
        int upper=min({1000,v[l]+(rem[index]-l),v[r]+(r-rem[index])});
        if(flag&&lower!=upper){
            do{
                v[rem[index]]=lower+rand()%(upper-lower+1);
            }while(v[rem[index]]==500);
        }else {
            v[rem[index]]=lower+rand()%(upper-lower+1);
            if(v[rem[index]]==500)flag=true;
        }
        st.insert(rem[index]);
        rem.erase(rem.begin()+index);
    }

    int cnt=0;
    while(1){
        char c;cin>>c;
        if(c!='?'&&c!='!'){
            cerr<<"Invalid input"<<endl;return 0;
        }
        int n;cin>>n;
        if(n<=0||n>10000){
            cerr<<"Invalid input"<<endl;return 0;
        }
        if(c=='?'){
            if(cnt==10){
                cout<<"Too many queries"<<endl;return 0;
            }
            cout<<v[n-1]<<endl;
            cnt++;
        }else {
            if(v[n-1]==500){
                cout<<"Congratulations!"<<endl;
                system("/bin/cat flag.txt");return 0;
            }else {
                cout<<"Wrong Answer!"<<endl;return 0;
            }
        }
    }
}