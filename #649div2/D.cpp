#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
vector<int> vec[maxn];
int book[maxn];
int pre[maxn],Min,s,e;
int n,m,k;
vector<int> v;
void dfs(int now,int last,int sign){
    if(book[now] != 0) return;
    book[now] = sign;
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last) continue;
        dfs(nxt,now,-sign);
    }
}
void dfs2(int now,int last){
    if(book[now]){
        if(abs(book[last]-book[now])+1 < Min){
            Min = abs(book[last]-book[now])+1;
            s = last; e = now;
        }
        return;
    }
    pre[now] = last;
    book[now] = book[last]+1;
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last) continue;
        dfs2(nxt,now);
    }
}
int main(){
    IOS;
    int l,r;
    cin>>n>>m>>k;
    Rep(i,1,m){
        cin>>l>>r;
        vec[l].push_back(r);
        vec[r].push_back(l);
    }
    if(m==n-1){
        dfs(1,-1,1);
        int cnt = 0;
        Rep(i,1,n){
            if(book[i]==1) cnt++;
        }
        cout<<"1\n";
        int num = (k+1)/2;
        if(cnt>=num){
            Rep(i,1,n){
                if(num==0) break;
                if(book[i]==1){
                    cout<<i<<" ";
                    num--;
                }
            }
        }else{
            Rep(i,1,n){
                if(num==0) break;
                if(book[i]==-1){
                    cout<<i<<" ";
                    num--;
                }
            }
        }
    }else{
        Min = INF;
        dfs2(1,0);
        int now = s;
        while(now != e){
            v.push_back(now);
            now = pre[now];
        }
        v.push_back(e);
        if(v.size() <= k){
            cout<<"2\n";
            cout<<v.size()<<"\n";
            for(int val : v){
                cout<<val<<" ";
            }
            cout<<"\n";
        }else{
            int num = (k+1)/2;
            cout<<"1\n";
            for(int i=0;i<v.size();i+=2){
                if(num<=0) break;
                cout<<v[i]<<" ";
                num--;
            }
            cout<<"\n";
        }
    }
    return 0;
}