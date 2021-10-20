#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
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
const int maxn = 5005;
int pre[maxn],book[maxn],dis[maxn];
set<int> s[maxn];
int main(){
    IOS;
    int n,d;
    CAS {
        cin>>n>>d;
        Rep(i,2,n) pre[i] = i-1;
        Rep(i,1,n-1) book[i] = 1;
        Rep(i,1,n) dis[i] = i-1;
        book[n] = 0;
        Rep(i,1,n) s[i].clear();
        Rep(i,1,n) s[i-1].insert(i);
        int now = n;
        int D = n*(n-1)/2;
        Dep(i,n,1){
            if(book[i] || D<=d) break;
            while(D>d && dis[i]>1){
                if(s[dis[i]-2].empty()) break;
                s[dis[i]].erase(i);
                if(--book[pre[i]]==1) s[dis[i]-1].insert(pre[i]);
                pre[i] = *(s[dis[i]-2].begin());
                if(++book[pre[i]]==2) s[dis[i]-2].erase(pre[i]);
                s[--dis[i]].insert(i);
                D--;
            }
        }
        if(D==d){
            cout<<"YES\n";
            Rep(i,2,n) cout<<pre[i]<<" ";
            cout<<"\n";
        }else cout<<"NO\n";
    }
    return 0;
}
