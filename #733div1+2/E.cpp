#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
int mp[30];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS{
        string s;
        cin>>s;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
        }
        int num = 0,last;
        char ch;
        for(int i=0;i<26;i++){
            if(mp[i]){
                num = mp[i];
                ch = 'a'+i;
                break;
            }
        }
        bool flag = false;
        for(int i=0;i<26;i++){
            if(mp[i]==1){
                flag = true;
                ch = 'a'+i;
                break;
            }
        }
        last = s.length()-num;
        if(num==1){
            for(int i=0;i<26;i++){
                for(int j=0;j<mp[i];j++) cout<<(char)('a'+i);
            }
            cout<<"\n"; continue;
        }else if(last==0){
            cout<<s<<"\n"; continue;
        }else if(flag){
            cout<<ch;
            for(int i=0;i<26;i++){
                if('a'+i == ch) continue;
                for(int j=0;j<mp[i];j++) cout<<(char)('a'+i);
            }
            cout<<"\n"; continue;
        }
        int now = 2;
        while(now < num){
            if((num-now+last-1)/last<=(now-1)) break;
            now++;
        }
        if(now>2){
            int summ = 0;
            for(int i=0;i<26;i++) if(mp[i]) summ++;
            if(summ==2){
                cout<<ch;
                for(int i=ch-'a'+1;i<26;i++)
                    for(int j=0;j<mp[i];j++) cout<<(char)('a'+i);
                for(int i=1;i<mp[ch-'a'];i++) cout<<ch;
            }else{
                cout<<ch;
                for(int i=ch-'a'+1;i<26;i++)
                    if(mp[i]){
                        cout<<(char)('a'+i);
                        for(int j=1;j<mp[ch-'a'];j++) cout<<ch;
                        for(int j=i+1;j<26;j++)
                            if(mp[j]){
                                cout<<(char)('a'+j);
                                mp[j]--; break;
                            }
                        mp[i]--; break;
                    }
                for(int i=ch-'a'+1;i<26;i++)
                    for(int j=0;j<mp[i];j++) cout<<(char)('a'+i);
            }
            cout<<"\n"; continue;
        }
        for(int i=0;i<now;i++) cout<<ch;
        num -= now;
        vector<char> v;
        for(int i=ch-'a'+1;i<26;i++){
            for(int j=0;j<mp[i];j++) v.push_back('a'+i);
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            for(int j=0;j<now-1&&num;j++){
                cout<<ch; num--;
            }
        }
        cout<<"\n";
    }
    return 0;
}