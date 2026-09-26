class Solution {
public:
    bool palindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
            while (i < j)
            {
                if (s[i] != s[j])
                {

                    bool path_1 = (s[i] == s[j - 1]);
                    bool path_2 = (s[i + 1] == s[j]);
                    if (path_1 == false && path_2 == false)
                        return false;
                    bool checkPath_1 = palindrome(s, i, j - 1);
                    bool checkPath_2 = palindrome(s, i + 1, j);
                    if (checkPath_1 == false && checkPath_2 == false)
                        return false;
                    return true;
                }
                i++;
                j--;
            }
            return true;
            }
};