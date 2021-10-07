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
const int maxn = 60;
int a[maxn],book[maxn],n;
vector<vector<int>> vec;
void change(int x,int y){
    Rep(i,1,x-1){
        book[a[i]] = (n-x+1)+i;
    }
    Rep(i,y+1,n){
        book[a[i]] = i-y;
    }
    int now = x;
    while(a[now+1]>=a[x]) now++;
    Rep(i,now+1,y){
        book[a[i]] = (n-y)+(i-now);
    }
    Rep(i,x,now){
        book[a[i]] = (n-now)+(i-x)+1;
    }
    Rep(i,1,n) a[book[i]] = i;
    vector<int> ans;
    if(x-1) ans.push_back(x-1);
    ans.push_back(now-x+1);
    ans.push_back(y-now);
    if(n-y) ans.push_back(n-y);
    vec.push_back(ans);
}
int main(){
    IOS;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,n) book[a[i]] = i;
    int T = n;
    while(T--){
        Rep(i,1,n-1){
            if(book[i] > book[i+1]) change(book[i+1],book[i]);
        }
    }
    cout<<vec.size()<<"\n";
    rep(i,0,vec.size()){
        cout<<vec[i].size();
        rep(j,0,vec[i].size()){
            cout<<" "<<vec[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
