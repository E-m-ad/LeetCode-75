// with O(1) space using Two pointer + O(N) time
class Solution
{
public:
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};
    bool isVo(char c)
    {
        c = tolower(c);
        for (auto i : v)
            if (i == c)
                return true;
        return false;
    }
    string reverseVowels(string &s) //   c e C r e A m
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (!isVo(s[i]))
            {
                i++;
                continue;
            }
            if (!isVo(s[j]))
            {
                j--;
                continue;
            }

            if (isVo(s[i]) && isVo(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
// With O(N) space O(N) Time
