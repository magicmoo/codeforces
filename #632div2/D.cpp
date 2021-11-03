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
const int maxn = 3e3+5;
char a[maxn];
int n,k;
vector<int> vec[maxn];
int calc(){
    int ans = 0,cnt = 1;
    Rep(i,1,n){
        if(a[i]=='L') ans += i-cnt++;
    }
    return ans;
}
void out(){
    int cnt = 1;
    Rep(i,1,n){
        if(a[i]=='L'){
            Dep(j,i-1,cnt){
                cout<<"1 "<<j<<"\n";
            }
            cnt++;
        }
    }
}
int main(){
    IOS;
    cin>>n>>k;
    Rep(i,1,n) cin>>a[i];
    bool flag = 0;
    int kk = k,tol = 0;
    if(calc() < k){
        cout<<"-1\n";
        return 0;
    }
    while(kk){
        int tmp = calc();
        if(tmp<=kk){
            flag = 1;
            rep(i,0,tol-1){
                cout<<vec[i].size()<<" ";
                rep(j,0,vec[i].size()){
                    cout<<vec[i][j]<<" ";
                }
                cout<<"\n";
            }
            if(tol>=1){
                Rep(i,0,kk-tmp-1){
                    cout<<"1 "<<vec[tol-1][i]<<"\n";
                }
            }
            if(tol>=1 && vec[tol-1].size()-kk+tmp > 0){
                cout<<(vec[tol-1].size()-kk+tmp)<<" ";
                rep(i,kk-tmp,vec[tol-1].size()){
                    cout<<vec[tol-1][i]<<" ";
                }
                cout<<"\n";
            }
            out();
            break;
        }
        Rep(i,1,n-1){
            if(a[i]=='R' && a[i+1]=='L'){
                vec[tol].push_back(i);
                a[i] = 'L';
                a[++i] = 'R';
            }
        }
        kk--;
        tol++;
    }
    if(!flag) cout<<"-1\n";
    return 0;
}
