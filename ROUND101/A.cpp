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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    string str,str1;
    int T; cin>>T;
    while(T--){
        stack<int> s;
        cin>>str;
        str1 = "";
        int len = str.length();
        if(len%2){
            cout<<"NO\n"; continue;
        }
        int pre = 0;
        for(int i=0;i<len;i++){
            if(str[i] == '('){
                s.push(i);
            }else if(s.size() && str[i] == ')'){
                str[i] = ' ';
                str[s.top()] = ' ';
                s.pop();
            }
        }
        for(int i=0;i<len;i++){
            if(str[i] != ' ') str1 += str[i];
        }
        pre = 0;
        int num = 0;
        bool flag = true;
        for(int i=0;i<str1.length();i++){
            if(str1[i] == ')'){
                flag = false;
                break;
            }else if(str1[i] == '(' || str1[i] == '?'){
                flag = false;
                for(int j=i+1;j<str1.length();j++){
                    if(str1[j] == ')'){
                        flag = true;
                        str1[j] = ' ';
                        break;
                    }
                }
                if(!flag){
                    for(int j=i+1;j<str1.length();j++){
                        if(str1[j] == '?'){
                            flag = true;
                            str1[j] = ' ';
                            break;
                        }
                    }
                }
            }
            if(!flag) break;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
