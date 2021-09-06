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
const int maxn = 105;
int mp[maxn][maxn];
int Set(int x,int y){
    rep(k,0,26){
        if(mp[x-1][y]==k || mp[x-1][y+1]==k || mp[x][y-1]==k || mp[x+1][y-1]==k) continue;
        return mp[x][y] = k;
    }
    return -1;
}
void Print(int n,int m){
    cout<<"YES\n";
    Rep(i,1,n){
        Rep(j,1,m){
            cout<<(char)('a'+mp[i][j]);
        }
        cout<<"\n";
    }
}
int main(){
    IOS;
    int n,m,k;
    CAS {
        memset(mp,0,sizeof(mp));
        cin>>n>>m>>k;
        if(n%2==0 && m%2==0){
            if(k%2==0){
                for(int i=1;i<=n;i+=2){
                    for(int j=1;j<=m;j+=2){
                        if(k>0){
                            mp[i][j+1] = Set(i,j);
                            mp[i+1][j+1] = Set(i+1,j);
                            k -= 2;
                        }else{
                            mp[i+1][j] = Set(i,j);
                            mp[i+1][j+1] = Set(i,j+1);
                        }
                    }
                }
                Print(n,m);
            }
            else cout<<"NO\n";
        }else if(n%2==1){
            int last = n*m/2-k;
            if(last%2==0){
                if(k >= m/2){
                    for(int j=1;j<=m;j+=2){
                        k--;
                        mp[1][j+1] = Set(1,j);
                    }
                    for(int i=2;i<=n;i+=2){
                        for(int j=1;j<=m;j+=2){
                            if(k>0){
                                mp[i][j+1] = Set(i,j);
                                mp[i+1][j+1] = Set(i+1,j);
                                k -= 2;
                            }else{
                                mp[i+1][j] = Set(i,j);
                                mp[i+1][j+1] = Set(i,j+1);
                            }
                        }
                    }
                    Print(n,m);
                }
                else cout<<"NO\n";
            }else cout<<"NO\n";
        }else{
            int last = n*m/2-k;
            if(k%2==0){
                if(last >= n/2){
                    for(int i=1;i<=n;i+=2){
                        mp[i+1][1] = Set(i,1);
                    }
                    for(int i=1;i<=n;i+=2){
                        for(int j=2;j<=m;j+=2){
                            if(k>0){
                                mp[i][j+1] = Set(i,j);
                                mp[i+1][j+1] = Set(i+1,j);
                                k -= 2;
                            }else{
                                mp[i+1][j] = Set(i,j);
                                mp[i+1][j+1] = Set(i,j+1);
                            }
                        }
                    }
                    Print(n,m);
                }
                else cout<<"NO\n";
            }else cout<<"NO\n";
        }
    }
    return 0;
}
