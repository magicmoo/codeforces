#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
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
const int INF = 0x3f3f3f3f;
int cnt[30],mp[30];
char ch[30];
pair<int,int> book[30];
int main(){
    IOS;
    string s,t;
    CAS {
        cin>>t;
        rep(i,0,26) book[i] = {-1,i},cnt[i] = mp[i] = 0;
        rep(i,0,t.size()){
            book[t[i]-'a'].first = i;
            cnt[t[i]-'a']++;
        }
        int sum = 0;
        bool flag = 1;
        sort(book,book+26);
        int now = 0,tmp = 0;
        rep(i,0,26){
            if(book[i].first == -1) continue;
            tmp++;
            int num = book[i].second;
            ch[now++] = (char)('a'+num);
            if(cnt[num]%(tmp)!=0) flag = 0;
            cnt[num] /= tmp;
        }
        if(!flag){
            cout<<"-1\n"; continue;
        }
        rep(i,0,26) sum += cnt[i];
        s = t.substr(0,sum);
        int index = 0,nex;
        rep(i,0,now){
            int nex = index+sum;
            string tmp = "";
            rep(j,0,s.size()){
                if(!mp[s[j]-'a']) tmp.push_back(s[j]);
            }
            if(t.substr(index,sum) != tmp){
                flag = 0;
                break;
            }
            mp[ch[i]-'a'] = 1;
            index += sum;
            sum -= cnt[ch[i]-'a'];
        }
        if(flag){
            cout<<s<<" ";
            rep(i,0,now) cout<<ch[i];
            cout<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
