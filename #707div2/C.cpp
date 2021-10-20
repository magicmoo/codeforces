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
const int maxn = 2e5+5;

int a[maxn];
pair<int,int> p[maxn];
map<int,pair<int,int>> mp;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i].first=a[i],p[i].second=i;
    sort(p+1,p+1+n);
    bool flag = 0;
    int l=0,r=0;
    Rep(i,2,n){
        if(l==0 && p[i].first==p[i-1].first){
            l = p[i-1].second;
            r = p[i].second;
            i++;
        }else if(l && p[i].first==p[i-1].first){
            flag = 1;
            cout<<"YES\n";
            cout<<l<<" "<<p[i].second<<" "<<r<<" "<<p[i-1].second<<"\n";
            break;
        }
    }
    if(flag) return 0;
    mp[a[l]+a[r]] = {l,r};
    sort(a+1,a+1+n);
    Rep(i,1,n){
        if(a[i] == a[i-1]) continue;
        Rep(j,i+1,n){
            if(a[j]==a[j-1]) continue;
            if(mp.count(a[i]+a[j])){
                flag = 1;
                cout<<"YES\n";
                cout<<mp[a[i]+a[j]].first<<" "<<mp[a[i]+a[j]].second<<" "<<p[i].second<<" "<<p[j].second<<"\n";
                break;
            }
            mp[a[i]+a[j]] = {p[i].second,p[j].second};
        }
        if(flag) break;
    }
    if(!flag) cout<<"NO\n";
    return 0;
}
