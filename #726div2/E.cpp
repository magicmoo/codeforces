#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;

int main(){
    IOS;
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    if(n == 1){
        for(int i=1;i<=k;i++) cout<<str[0];
        cout<<"\n";
    }else{
        int num = 0;
        string s = "";
        s += str[0];
        int last = 0;
        for(int i=1;i<n;i++){
            if(str[i]<str[0]){
                last = 0;
                s += str[i];
            }else if(str[i]==str[0]){
                int index = i; string temp = "";
                bool flag = 1,flag1 = 0;
                for(int j=i;j<n&&j-i<s.length();j++){
                    index = j;
                    if(str[j] == s[j-i]) temp+=str[j];
                    else if(str[j] < s[j-i]){
                        temp+=str[j];
                        flag1 = 1;
                        break;
                    }else{
                        flag = 0;
                        break;
                    }
                }
                if(!flag) break;
                i = index; s += temp;
                last = temp.size();
                if(flag1) last = 0;
            }else break;
        }
        for(int i=0;i<k;i++){
            cout<<s[i%(s.length()-last)];
        }
        cout<<"\n";
    }
    return 0;
}