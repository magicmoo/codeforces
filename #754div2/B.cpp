#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
char str[maxn];
vector<int> ans;
int main(){
    // IOS;
    int n;
    CAS {
        cin>>n;
        scanf("%s",str+1);
        int cnt = 0;
        ans.clear();
        Rep(i,1,n) if(str[i]=='1') cnt++;
        int r = n;
        Rep(i,1,n){
            if(cnt==0 || i>=r) break;
            if(str[i]=='0') continue;
            while(r>i && str[r]=='1'){
                cnt--;
                r--;
            }
            if(r==i) break;
            ans.push_back(i);
            ans.push_back(r);
            r--;
        }
        if(ans.size()==0) cout<<"0\n";
        else{
            sort(ans.begin(),ans.end());
            cout<<"1\n";
            cout<<ans.size()<<" ";
            for(int val : ans) cout<<val<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
