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
string s,t;

struct Node{
    int l,r;
    bool flag;
    bool operator>(const Node n)const{
        return this->r > n.r;
    }
    bool operator<(const Node n)const{
        return this->r < n.r;
    }
};
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>s>>t;
        bool flag = false;
        priority_queue<Node> q;
        rep(i,0,s.length()){
            if(s[i] == t[0]) q.push({i,1,false});
        }
        while(!flag && !q.empty()){
            Node temp = q.top(); q.pop();
            if(temp.r == t.length()){
                flag = true;
                break;
            }
            if(!temp.flag && temp.l+1<s.length() && s[temp.l+1]==t[temp.r])
                q.push({temp.l+1,temp.r+1,false});
            if(temp.l-1>=0 && s[temp.l-1]==t[temp.r])
                q.push({temp.l-1,temp.r+1,true});
        }
        YON;
    }
    return 0;
}
