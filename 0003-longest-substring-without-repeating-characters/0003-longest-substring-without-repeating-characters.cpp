class Solution {
public:
     int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> windowDublication;
    int left = 0, right = 0;
    int maxLength = 0;
    int window = 0;
    while (right < s.size())
    {
        if (left == right)
            window = 0;
        if ((windowDublication.find(s[right]) != windowDublication.end() && left > windowDublication[s[right]]) ||
            (windowDublication.find(s[right]) == windowDublication.end()))
            window += 1;
        else
        {
            left = windowDublication[s[right]] + 1;
            window = right - left + 1;
        }

        windowDublication[s[right]] = right;
        right += 1;
        maxLength = max(maxLength, window);
    }
    return maxLength; 
    }
};