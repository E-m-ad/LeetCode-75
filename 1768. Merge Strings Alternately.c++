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
string mergeAlternately(string word1, string word2)
{
    int i = 0;
    string appendedString = "";
    for (i; i < min(word1.size(), word2.size()); i++)
    {
        appendedString += word1[i];
        appendedString += word2[i];
    }
    vector<string> v = {word1, word2};
    bool which = (word2.size() > i);
    return (word1.size() == word2.size() ? appendedString : appendedString += v[which].substr(i));
}
int main()
{
    IO();
    string s1, s2;
    cin >> s1 >> s2;
    cout << mergeAlternately(s1, s2);
}