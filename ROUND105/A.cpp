    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    #include<iostream>
    #include<string>
    #include<vector>
    #include<stack>
    #include<bitset>
    #include<cstdlib>
    #include<cmath>
    #include<set>
    #include<list>
    #include<deque>
    #include<map>
    #include<queue>
    using namespace std;
    typedef long long ll;
    const double PI = acos(-1.0);
    const int INF = 0x3f3f3f3f;

    bool check(string str,int a,int b,int c){
        int num = 0;
        for(int i=0;i<str.length();i++){
            if(str[i] == 'A'){
                if(a == 0){
                    num++;  
                }else if(num == 0){
                    return false;
                }else{
                    num--;
                }
            }else if(str[i] == 'B'){
                if(b == 0) num++;
                else if(num == 0) return false;
                else num--;
            }else{
                if(c == 0) num++;
                else if(num == 0) return false;
                else num--;
            }
        }
        if(num == 0) return true;
        return false;
    }
    int main(){
        std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
        #endif
        int T;
        string str;
        cin>>T; while(T--){
            cin>>str;
            if(check(str,0,0,0)) cout<<"YES\n";
            else if(check(str,0,0,1)) cout<<"YES\n";
            else if(check(str,0,1,0)) cout<<"YES\n";
            else if(check(str,0,1,1)) cout<<"YES\n";
            else if(check(str,1,0,0)) cout<<"YES\n";
            else if(check(str,1,0,1)) cout<<"YES\n";
            else if(check(str,1,1,0)) cout<<"YES\n";
            else if(check(str,1,1,1)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        return 0;
    }
