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
const int maxn = 2025;
int a[maxn],mp[maxn];
int n;
vector<int> ans;
void change(int num){
    Rep(i,1,num/2) swap(a[i],a[num-i+1]);
    Rep(i,1,num) mp[a[i]] = i;
    ans.push_back(num);
}
int main(){
    IOS;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n) mp[a[i]] = i;
        ans.clear();
        bool flag = 1;
        for(int i=n;i>1;i-=2){
            if(mp[i]==i && mp[i-1]==i-1) continue;
            else if(mp[i]%2==0 || mp[i-1]%2==1){
                flag = 0; break; 
            }
            change(mp[i]);
            change(mp[i-1]-1);
            change(mp[i-1]+1);
            change(3);
            change(i);
        }
        if(flag){
            cout<<ans.size()<<"\n";
            rep(i,0,ans.size()) cout<<ans[i]<<" ";
            cout<<"\n";
        }else cout<<"-1\n";
    }
    return 0;
}
