class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size() || (s.size() == t.size() && s != t))
            return false;
        int i = 0 ;
        int j = 0 ;
        while( i < s.size()  && j < t.size()) { // abc - abc
            if(s[i] == t[j])
                i++;
            j++;
        }
        return (i == s.size());
    }
};
