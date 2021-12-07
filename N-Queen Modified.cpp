#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> queen;
int ans=0;

vector<pair<int,int>>r;

bool check(int row,int col){
    for(auto i:r){
        if(i.first==row && i.second==col)return 0;
    }
    for(int prow=0;prow<row;prow++){
        int pcol=queen[prow];
        if(pcol==col || (abs(col-pcol)==abs(row-prow)))return 0;
    }return 1;
}

void rec(int level){
    if(level==n){
        ans++;
        return;
    }
    
    for(int col=0;col<n;col++){
        if(check(level,col)){
            queen.push_back(col);
            rec(level+1);
            queen.pop_back();
        }
    }
}

void solve(){
    n=8;
    for(int j=0;j<n;++j){
    for(int i=0;i<n;++i){
        char ch;
        cin>>ch;
        if(ch=='*'){
            r.push_back(make_pair(j,i));
        }
    }
  } rec(0);
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    solve();
}