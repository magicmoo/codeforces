#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
map<string,ll> cnt;
map<string,string> pre,post;
ll cal(string& str){
    ll ans = 0;
    rep(i,3,str.size()){
        if(str.substr(i-3,4) == "haha") ans++;
    }
    return ans;
}
ll cal(string& str1,string& str2){
    ll ans = 0;
    rep(i,1,4){
        if(str1.size()<i || str2.size()<4-i) continue;
        string s1 = str1.substr(str1.size()-i,i);
        string s2 = str2.substr(0,4-i);
        if(s1+s2 == "haha") ans++;
    }
    return ans;
}
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        string s1,s2,s3,s4,s5;
        ll ans = 0;
        while(n--){
            cin>>s1>>s2;
            if(s2 == ":="){
                cin>>s3;
                pre[s1] = s3.substr(0,min(3LL,(ll)s3.size()));
                if(s3.size()>=3) post[s1] = s3.substr(s3.size()-3,3);
                else post[s1] = s3.substr(0LL,(ll)s3.size());
                ans = cnt[s1] = cal(s3);
            }else{
                cin>>s3>>s4>>s5;
                ans = cnt[s3]+cnt[s5];
                string str1 = pre[s3];
                string str2 = post[s5];
                ans += cal(post[s3],pre[s5]);
                cnt[s1] = ans;
                if(str1.size()>=3) pre[s1] = str1;
                else{
                    str1 += pre[s5];
                    pre[s1] = str1.substr(0,min(3LL,(ll)str1.size()));
                }
                if(str2.size()>=3) post[s1] = str2;
                else{
                    str2 = post[s3]+str2;
                    if(s3.size()>=3) post[s1] = str2.substr(str2.size()-3,3);
                    else post[s1] = str2.substr(0LL,(ll)str2.size());
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
