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
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2005;
vector<int> v[maxn];
int temp[maxn],n,dis[maxn];
void query(int num){
    cout<<"? "<<num<<"\n\n";
    cout.flush();
    for(int i=1;i<=n;i++) cin>>temp[i];
}
void slove(int now,int len){
    query(now);
    for(int i=1;i<=n;i++){
        if(temp[i] == 1){
            if(dis[i] == len-1) v[i].push_back(now);
            else v[now].push_back(i);
        }
    }
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>n;
    query(1);
    for(int i=1;i<=n;i++) dis[i] = temp[i];
    int num1 = 0,num2 = 0;
    for(int i=2;i<=n;i++){
        if(dis[i]%2 == 0) num2++;
        else num1++;
    }
    if(num1 < num2){
        for(int i=1;i<=n;i++){
            if(dis[i]%2 == 1) slove(i,dis[i]);
        }
    }else{
        for(int i=2;i<=n;i++){
            if(dis[i] == 1){
                v[1].push_back(i);
            }
        }
        for(int i=2;i<=n;i++){
            if(dis[i]%2 == 0) slove(i,dis[i]);
        }
    }
    cout<<"!\n";
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<i<<" "<<v[i][j]<<"\n";
        }
    }
    return 0;
}
