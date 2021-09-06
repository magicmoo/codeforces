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
// #include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1000+5;

char map[maxn][maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>map[i][j];
        bool flag = false;
        if(m%2 == 1){
            cout<<"YES\n";
            for(int i=0;i<m;i+=2){
                cout<<"1 2 ";
            }
            cout<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(map[i][j] == map[j][i]){
                    flag = true;
                    cout<<"YES\n";
                    for(int k=0;k<m;k+=2){
                        cout<<i<<" "<<j<<" ";
                    }
                    cout<<i<<"\n";
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) continue;
        for(int i=1;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(i == j) continue;
                if(map[i][i==1?2:1] != map[i][j]){
                    flag = true;
                    cout<<"YES\n";
                    if(m%4 == 0){
                        for(int k=0;k<m/4;k++){
                            cout<<i<<" "<<(i==1?2:1)<<" ";
                        }
                        cout<<i<<" ";
                        for(int k=0;k<m/4;k++){
                            cout<<j<<" "<<i<<" ";
                        }
                        cout<<"\n";
                    }else{
                        for(int k=0;k<m/4+1;k++){
                            cout<<(i==1?2:1)<<" "<<i<<" ";
                        }
                        for(int k=0;k<m/4;k++){
                            cout<<j<<" "<<i<<" ";
                        }
                        cout<<j<<"\n";
                    }
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"NO\n";
    }
    return 0;
}
