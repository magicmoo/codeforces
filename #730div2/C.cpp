#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double scale = 1e6;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
double c,m,p,vv;
int v;
double solve(int c,int m,int p,int now){
    double temp = now*p/scale;
    if(c>0 && c<=v){
        if(m > 0) temp += c/scale*solve(0,m+c/2,p+c/2,now+1);
        else temp += c/scale*solve(0,0,p+c,now+1);
    }else if(c>0 && c>v){
        if(m > 0) temp += c/scale*solve(c-v,m+v/2,p+v/2,now+1);
        else temp += c/scale*solve(c-v,0,p+v,now+1);
    }
    if(m>0 && m<=v){
        if(c > 0) temp += m/scale*solve(c+m/2,0,p+m/2,now+1);
        else temp += m/scale*solve(0,0,p+m,now+1);
    }else if(m>0 && m>v){
        if(c > 0) temp += m/scale*solve(c+v/2,m-v,p+v/2,now+1);
        else temp += m/scale*solve(0,m-v,p+v,now+1);
    }
    return temp;
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>c>>m>>p>>vv;
        int cc = round(c*scale);
        int mm = round(m*scale);
        int pp = round(p*scale);
        v = round(vv*scale);
        printf("%.12lf\n",solve(cc,mm,pp,1));
    }
    return 0;
}
