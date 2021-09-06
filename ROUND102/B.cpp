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

string div(string s){
    int len = s.length();
    for(int i=1;i<=len/2;i++){
        if(len%i != 0) continue;
        string s1 = s.substr(0,i);
        bool flag = true;
        for(int j=i;i+j<=len;j+=i){
            string s2 = s.substr(j,i);
            if(s1 != s2){ flag = false; break;}
        }
        if(flag) return s1;
    }
    return s;
}
int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int T;
    string s1,s2;
    cin>>T;
    while(T--){
        cin>>s1>>s2;
        string ss1 = div(s1), ss2 = div(s2);
        if(ss1 != ss2){
            cout<<-1<<"\n";
            continue;
        }
        int a = s1.length()/ss1.length();
        int b = s2.length()/ss2.length();
        int num = LCM(min(a,b),max(a,b));
        for(int i=0;i<num;i++) cout<<ss1;
        cout<<"\n";
    }
    return 0;
}
