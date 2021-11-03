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
const int maxn = 505;
int a[maxn],b[maxn],n,tmp[maxn];
bool check(){
    Rep(i,1,n/2){
        if(a[i]==b[i] && a[n-i+1]==b[n-i+1]) continue;
        swap(a[i],a[n-i+1]);
        if(a[i]!=b[i] || a[n-i+1]!=b[n-i+1]){
            swap(a[i],a[n-i+1]);
            return 0;
        }
        swap(a[i],a[n-i+1]);
    }
    return 1;
}
void swap(int num){
    Rep(i,1,n) tmp[i] = a[i];
    Rep(i,1,num) a[i] = tmp[n-num+i];
    Rep(i,1,num) a[n-num+i] = tmp[i];
}
int main(){
    IOS;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n) cin>>b[i];
        if(n%2==1 && a[n/2+1]!=b[n/2+1]){
            cout<<"NO\n";
            continue;
        }
        bool flag = 0;
        Rep(i,0,n/2){
            swap(i);
            if(check()){
                flag = 1;
                break;
            }
            swap(i);
        }
        YON;
    }
    return 0;
}
