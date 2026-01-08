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
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxKidCandy = -1;
        for(int i = 0 ; i < candies.size() ; i++)
            if(candies[i] > maxKidCandy)
                maxKidCandy = candies[i];
        vector<bool> result(candies.size());
        for(int i = 0 ; i < candies.size() ; i++) {
            if(candies[i] + extraCandies >= maxKidCandy)
                result[i] = true;
            else 
                result[i] = false;
        }
        return result;        
    }
};
int main()
{
    IO();
}