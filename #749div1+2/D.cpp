#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int a[maxn],arr[maxn];
int nxt[maxn],pre[maxn];
int n;
int query(){
    int ans;
    cout<<"?";
    Rep(i,1,n) cout<<" "<<arr[i];
    cout<<"\n";
    cin>>ans;
    cout.flush();
    return ans;
}
void dfs(int now){
    if(a[now]) return;
    if(nxt[now]){
        dfs(nxt[now]);
        a[now] = a[nxt[now]]-1;
    }else if(pre[now]){
        dfs(pre[now]);
        a[now] = a[pre[now]]+1;
    }
}
int main(){
    // IOS;
    cin>>n;
    Rep(i,1,n-1) arr[i] = 1;
    arr[n] = 2;
    int now = n;
    while(arr[n]<=n){
        nxt[now] = query();
        if(nxt[now] == 0){
            a[now] = n;
            break;
        }
        now = nxt[now];
        arr[n]++;
        if(arr[n]>n) a[now] = n;
    }
    Rep(i,1,n-1) arr[i] = n;
    arr[n] = n-1;
    now = n;
    while(arr[n]>0){
        pre[now] = query();
        if(pre[now] == 0){
            a[now] = 1;
            break;
        }
        now = pre[now];
        arr[n]--;
        if(arr[n]<=0) a[now] = 1;
    }
    Rep(i,1,n){
        if(!a[i]) dfs(i);
    }
    cout<<"!";
    Rep(i,1,n) cout<<" "<<a[i];
    cout<<"\n";
    cout.flush();
    return 0;
}
