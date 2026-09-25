class Solution {
public:
    string normalizePhrase(string phrase)
    {
        string normalizePhrase = "";
        for (int i = 0; i < phrase.size(); i++)
        {
            if (phrase[i] >= 65 && phrase[i] <= 90)
                phrase[i] = (phrase[i] - 65) + 97;

            if ((phrase[i] >= 48 && phrase[i] <= 57) || (phrase[i] >= 97 && phrase[i] <= 122))
                normalizePhrase += phrase[i];
        }
        return normalizePhrase;
    }

    bool isPalindrome(string s) {
        s = normalizePhrase(s);
         if (s.size() == 0)
        return true;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};