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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 3e5+5;
int a[maxn],b[maxn],c[maxn],n;
vector<int> ans;
void solve(int a[],int b[],int num){
    int nowa = 1,nowb = 1;
    while(nowa<=2*n || nowb<=2*n){
        while(nowa<=2*n && a[nowa] != num) ans.push_back(a[nowa++]);
        while(nowb<=2*n && b[nowb] != num) ans.push_back(b[nowb++]);
        if(nowa<=2*n || nowb<=2*n) ans.push_back(num);
        nowa++; nowb++;
    }
    while(ans.size() < 3*n) ans.push_back(0);
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS{
        cin>>n;
        ans.clear();
        for(int i=1;i<=2*n;i++) scanf("%1d",&a[i]);
        for(int i=1;i<=2*n;i++) scanf("%1d",&b[i]);
        for(int i=1;i<=2*n;i++) scanf("%1d",&c[i]);
        int cnt1 = 0,cnt2 = 0,cnt3 = 0;
        for(int i=1;i<=2*n;i++){
            cnt1 += a[i];
            cnt2 += b[i];
            cnt3 += c[i];
        }
        if(cnt1>=n&&cnt2>=n) solve(a,b,1);
        else if(cnt1>=n&&cnt3>=n) solve(a,c,1);
        else if(cnt2>=n&&cnt3>=n) solve(b,c,1);
        else if(cnt1<n&&cnt2<n) solve(a,b,0);
        else if(cnt1<n&&cnt3<n) solve(a,c,0);
        else solve(b,c,0);
        for(int i=0;i<ans.size();i++) cout<<ans[i];
        cout<<"\n";
    }
    return 0;
}
