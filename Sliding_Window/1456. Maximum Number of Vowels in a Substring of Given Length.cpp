class Solution {
public:
    bool isVowel(char c) {
        const string vowels = "aeiou";
        for(char x : vowels)
            if(c == x)
                return true;
        
        return false;
    }
    int maxVowels(string s, int k) {
        int leftWindowPointer = 0;
        int mxVowels = 0;
        for(int x = 0 ; x < k ; x++){
            mxVowels += isVowel(s[x]);
        }
        int mxWindow = mxVowels;
        while(k < s.size())
        {
            mxWindow -= isVowel(s[leftWindowPointer++]);
            mxWindow += isVowel(s[k++]);
            mxVowels = max(mxVowels , mxWindow);
        }
        return mxVowels;
    }
};
