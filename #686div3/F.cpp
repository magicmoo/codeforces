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
const int maxn = 2e5+5;
int a[maxn];
int maxsum[maxn][20],minsum[maxn][20];
void RMQ(int num){  //共num个数
    for(int i=1;i<=num;i++)
        maxsum[i][0] = minsum[i][0] = a[i];
    for(int j=1;j<20;j++){
        for(int i=1;i<=num;i++){
            if(i+(1<<j)-1 <= num){
                maxsum[i][j] = max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
                minsum[i][j] = min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
            }
        }
    }
}
int maxl,minl;
void Query(int l,int r){
    int k = (int)(log(r-l+1)/log(2.0));
    maxl = max(maxsum[l][k],maxsum[r-(1<<k)+1][k]);
    minl = min(minsum[l][k],minsum[r-(1<<k)+1][k]);
}
map<int,vector<int>> mp;
int b[maxn];
void out(int a,int b,int c){
    cout<<"YES\n";
    cout<<a<<" "<<b<<" "<<c<<"\n";
}
int main(){
    IOS;
    int n;
    CAS {
        mp.clear();
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        a[n+1] = 0;
        Rep(i,1,n){
            mp[a[i]].push_back(i);
            b[i] = a[i];
        }
        sort(b+1,b+1+n);
        RMQ(n);
        bool flag = 0;
        vector<int> v = mp[b[n]];
        if(v.size()>=3){
            out(v[1]-1,1,n-v[1]);
            continue;
        }
        int l = v[0],r = v.back();
        Dep(now,n-1,1){
            if(b[now]==b[now+1]) continue;
            v = mp[b[now]];
            Query(l,r);
            if(minl==b[now] && v[0]<l && v.back()>r){
                out(l-1,r-l+1,n-r);
                flag = 1;
                break;
            }else if(a[l-1]==b[now] && v[0]<l-1 && v.back()>r){
                l--;
                out(l-1,r-l+1,n-r);
                flag = 1;
                break;
            }else if(a[r+1]==b[now] && v[0]<l && v.back()>r+1){
                r++;
                out(l-1,r-l+1,n-r);
                flag = 1;
                break;
            }
            l = min(l,v[0]),r = max(r,v.back());
        }
        if(!flag) cout<<"NO\n";
    }
    return 0;
}
