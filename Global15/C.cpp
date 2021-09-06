#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 500;
pair<int,int> a[maxn];
int book[maxn];
vector<pair<int,int>> v;
bool cal(int xx1,int xx2,int yy1,int yy2){
    int x1 = max(xx1,xx2);
    int x2 = min(xx1,xx2);
    int y1 = max(yy1,yy2);
    int y2 = min(yy1,yy2);
    if(y2<x1 && y2<x2){
        if(y1>x2 && y1<x1) return 1;
    }else if(x2<y1 && x2<y2){
        if(x1>y2 && x1<y1) return 1;
    }
    return 0;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,k;
    CAS {
        cin>>n>>k;
        memset(book,0,sizeof(book));
        Rep(i,1,k) cin>>a[i].first>>a[i].second,book[a[i].first] = book[a[i].second] = 1;
        Rep(i,1,k){
            if(a[i].first < a[i].second) swap(a[i].first,a[i].second);
        }
        int ans = 0;
        Rep(i,1,k){
            Rep(j,i+1,k){
                ans += cal(a[i].first,a[i].second,a[j].first,a[j].second);
            }
        }
        int last = 2*n-2*k;
        Rep(i,1,k){
            int temp = 0;
            Rep(j,a[i].second+1,a[i].first-1){
                if(!book[j]) temp++;
            }
            ans += min(temp,last-temp);
        }
        ans += (last/2)*(last/2-1)/2;
        cout<<ans<<"\n";
    }
    return 0;
}
