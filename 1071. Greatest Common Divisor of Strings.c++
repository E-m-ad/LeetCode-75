#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
// Brute Force sloution
bool check(string &target , string &str) {
    if( str.size() % target.size())
        return false;
    int len = target.size();
    bool divisble = true;
    int i = 0;
    int count = 0;
    while(divisble && count < str.size()){
        i %= len;
        if(str[count] != target[i])
             return false;
        i++;
        count += 1;
    }
    return divisble;
}
void divisorString(string s , vector<string> & gcds , int d){
  
    if(s.size() % d )
        return;
    string partOne = s.substr(0 , s.size() / d); 
    string partTwo  = s.substr(s.size() / d);
    if(check(partOne , partTwo)) {
        gcds.push_back(partOne);
    }
}
string gcdString(string s1 ,string s2 , vector<string> &gcds)
{
    string minString = s1;
    string maxString = s2;
    if (s1.size() != s2.size())
    {
        minString = s1.size() < s2.size() ? s1 : s2;
        maxString = s1.size() > s2.size() ? s1 : s2;
    }
    gcds.push_back(minString);
    for(int i = 2 ; i <= sqrt(minString.size());i++ ) {
        divisorString(minString , gcds , i ); 
        if(i != (int)minString.size() / i)
             divisorString(minString , gcds , (int)(minString.size() / i) ); 
        
    }
    sort(gcds.rbegin() , gcds.rend());
    for(int i = 0 ; i < gcds.size() ; i++) {
        if(check(gcds[i] , maxString))
            return gcds[i];  
        }
    return "";
}
// Math sloution 
   string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
            return "";
        const int _gcd = gcd(str1.size() , str2.size());
        return str1.substr(0,_gcd);
    }
int main()
{
    IO();
    string s1 ,s2;
    cin >> s1 >> s2;
    vector<string> gcds;
   cout <<  gcdString(s1,s2,gcds);
   for(int i = 0 ; i < gcds.size() ; i++)
    cout << gcds[i] << "\n";

}
