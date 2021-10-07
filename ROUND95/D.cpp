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
priority_queue<int> q;
map<int,int> mp;
set<int> s;
const int maxn = 1e5+5;
int a[maxn];
int main(){
    IOS;
    int n,Q;
    cin>>n>>Q;
    Rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    Rep(i,1,n) s.insert(a[i]);
    Rep(i,2,n){
        q.push(a[i]-a[i-1]);
    }
    if(s.size()>2){
        int cnt = *(--s.end())-*(s.begin());
        cout<<cnt-q.top()<<"\n";
    }else cout<<"0\n";
    while(Q--){
        int opr,x;
        cin>>opr>>x;
        if(opr==0){
            auto index = s.lower_bound(x);
            if(index != s.begin()){
                mp[(*(index)-*(--index))]++;
                index++; 
            }
            index++;
            if(index != s.end()){
                mp[(*index)-*(--index)]++;
                index++;
            }
            index = s.erase(--index);
            if(index!=s.end() && index != s.begin()) q.push((*index)-*(--index));
        }else{
            auto index = s.lower_bound(x);
            if(index!=s.end() && index!=s.begin()) mp[(*(index)-*(--index))]++;
            s.insert(x);
            index = s.lower_bound(x);
            if(index != s.begin()){
                q.push((*index)-*(--index));
                index++;
            }
            index++;
            if(index!=s.end() && index!=s.begin()) q.push((*index)-*(--index));
        }
        while(!q.empty() && mp[q.top()]){
            mp[q.top()]--;
            q.pop();
        }
        if(s.size()>2){
            int cnt = *(--s.end())-*(s.begin());
            cout<<cnt-q.top()<<"\n";
        }else cout<<"0\n";
    }
    return 0;
}
