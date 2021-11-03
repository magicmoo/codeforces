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
const int maxn = 3e5+5;
int a[maxn],b[maxn];
namespace ST{
int a[maxn];
pair<int,int> maxsum[maxn][20],minsum[maxn][20];
void RMQ(int num){  //共num个数
    for(int i=1;i<=num;i++){
        maxsum[i][0].first = minsum[i][0].first = a[i];
        maxsum[i][0].second = minsum[i][0].second = i;
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=num;i++){
            if(i+(1<<j)-1 <= num){
                maxsum[i][j] = max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
                minsum[i][j] = min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
            }
        }
    }
}
pair<int,int> maxl,minl;
void Query(int l,int r){
    int k = (int)(log(r-l+1)/log(2.0));
    maxl = max(maxsum[l][k],maxsum[r-(1<<k)+1][k]);
    minl = min(minsum[l][k],minsum[r-(1<<k)+1][k]);
}
}
vector<int> anss;
int main(){
    IOS;
    int n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,n) cin>>b[i];
    Rep(i,1,n) ST::a[i] = a[i+b[i]]-b[i]-i;
    ST::RMQ(n);
    int ans = 0,now = n;
    while(now>0){
        if(a[now] >= now){
            ans++;
            anss.push_back(0);
            break;
        }
        ST::Query(now-a[now],now);
        if(ST::maxl.second+b[ST::maxl.second] == now){
            ans = -1;
            break;
        }
        now = ST::maxl.second+b[ST::maxl.second];
        anss.push_back(ST::maxl.second);
        ans++;
    }
    cout<<ans<<"\n";
    if(ans>0){
        rep(i,0,ans){
            cout<<anss[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
