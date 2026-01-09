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
class Solution
{
public:
    int possibleFills(int n)
    {
        return ((n - 1) / 2);
    }
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        flowerbed.insert(flowerbed.begin(), 0);
        int last_1Plot = 0;
        int i = 0;
        while (i < flowerbed.size() && n > 0)
        {
            int value = 0;
            if (flowerbed[i] == 1)
            {
                value = i - last_1Plot;
                if (flowerbed[last_1Plot] == 1)
                    value -= 1;
                value = (value > 0) ? value : 0;
                n -= possibleFills(value);
                last_1Plot = i;
            }
            i++;
        }
        return !(n > 0);
    }
};
int main()
{
    IO();
    vector<int> v = {0, 0, 1, 0, 1};
}