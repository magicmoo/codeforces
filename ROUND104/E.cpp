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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 150000+5;
const int maxn2 = 2e5+5;

struct Node{
    int d1,d2;
    int i;
};
vector<int> v[4][maxn2];
int a[5][maxn],dp[4][maxn];
int n[5],m,num1,num2;
void solve(){
    multiset<int> s;
    cin>>n[1]>>n[2]>>n[3]>>n[4];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=n[i];j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=3;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>num1>>num2;
            v[i][num2].push_back(num1);
        }
    }
    for(int i=1;i<=n[1];i++) dp[0][i] = a[1][i];
    for(int i=1;i<=3;i++){
        s.clear();
        for(int j=1;j<=n[i];j++){
            if(dp[i-1][j] != -1) s.insert(dp[i-1][j]);
        }
        for(int j=1;j<=n[i+1];j++){
            for(int k=0;k<v[i][j].size();k++){
                if(dp[i-1][v[i][j][k]] != -1) s.erase(s.find(dp[i-1][v[i][j][k]]));
            }
            if(s.size() == 0) dp[i][j] = -1;
            else dp[i][j] = *s.begin()+a[i+1][j];
            for(int k=0;k<v[i][j].size();k++){
                if(dp[i-1][v[i][j][k]] != -1) s.insert(dp[i-1][v[i][j][k]]);
            }
        }
    }
    int Min = INF;
    for(int i=1;i<=n[4];i++){
        if(dp[3][i] != -1)
            Min = min(Min,dp[3][i]);
    }
    if(Min == INF) cout<<"-1\n";
    else cout<<Min<<"\n";
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    solve();
    return 0;
}
