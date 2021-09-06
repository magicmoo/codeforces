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
const int maxn = 55;
char mp[maxn][maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        bool flag = true;
        int ni = -1,nj = -1;;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j] != '.'){
                    ni = i; nj = j;
                    break;
                }
            }
            if(ni != -1) break;
        }
        if(ni==-1){
            cout<<"YES\n";
            mp[1][1] = 'R';
            for(int i=1;i<=n;i++){
                if(i!=1){
                    if(mp[i-1][1] == 'R') mp[i][1] = 'W';
                    else mp[i][1] = 'R';
                }
                for(int j=2;j<=m;j++){
                    if(mp[i][j-1] == 'R') mp[i][j] = 'W';
                    else mp[i][j] = 'R';
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<mp[i][j];
                }
                cout<<"\n";
            }
            continue;
        }
        for(int j=nj-1;j>0;j--){
            if(mp[ni][j+1] == 'R'){
                if(mp[ni][j] == 'R'){
                    flag = false; break;
                }else mp[ni][j] = 'W';
            }else{
                if(mp[ni][j] == 'W'){
                    flag = false; break;
                }else mp[ni][j] = 'R';
            }
        }
        for(int j=nj+1;j<=m;j++){
            if(mp[ni][j-1] == 'R'){
                if(mp[ni][j] == 'R'){
                    flag = false; break;
                }else mp[ni][j] = 'W';
            }else{
                if(mp[ni][j] == 'W'){
                    flag = false; break;
                }else mp[ni][j] = 'R';
            }
        }
        if(!flag){
            cout<<"NO\n";
            continue;
        }
        for(int i=ni-1;i>0;i--){
            if(mp[i+1][1] == 'W') mp[i][1] = 'R';
            else mp[i][1] = 'W';
            for(int j=2;j<=m;j++){
                if(mp[i][j-1] == 'W') mp[i][j] = 'R';
                else mp[i][j] = 'W';
            }
        }
        for(int i=ni+1;i<=n;i++){
            if(mp[i-1][1] == 'W'){
                if(mp[i][1] == 'W'){
                    flag = false;
                    break;
                }else mp[i][1] = 'R';
            }else{
                if(mp[i][1] == 'R'){
                    flag = false;
                    break;
                }else mp[i][1] = 'W';
            }
            for(int j=2;j<=m;j++){
                if(mp[i][j-1] == 'W'){
                    if(mp[i][j] == 'W'){
                        flag = false; break;
                    }else mp[i][j] = 'R';
                }else{
                    if(mp[i][j] == 'R'){
                        flag = false; break;
                    }else mp[i][j] = 'W';
                }
            }
            if(!flag) break;
        }
        if(!flag){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<mp[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
