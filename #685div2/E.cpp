#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1<<18+5;
int val[maxn],book[maxn],ans[maxn];
void opr(string str,int i,int j){
    cout<<str<<" "<<i<<" "<<j<<"\n";
    cout.flush();
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int l = -1,r = -1;
    book[0] = 1;
    Rep(i,2,n){
        opr("XOR",1,i);
        cin>>val[i];
        if(book[val[i]]){
            l = book[val[i]];
            r = i;
        }
        book[val[i]] = i;
    }
    if(l!=-1){
        opr("AND",l,r);
        cin>>ans[l];
        ans[1] = ans[l]^val[l];
        Rep(i,2,n){
            ans[i] = ans[1]^val[i];
        }
    }else{
        Rep(i,2,n){
            if(val[i]==1) l = i;
            else if(val[i]==2) r = i;
        }
        int temp1,temp2;
        opr("AND",1,l);
        cin>>temp1;
        opr("AND",1,r);
        cin>>temp2;
        ans[1] = (temp1/2*2)+temp2%2;
        Rep(i,2,n){
            ans[i] = ans[1]^val[i];
        }
    }
    cout<<"!";
    Rep(i,1,n) cout<<" "<<ans[i];
    cout<<"\n";
    return 0;
}
