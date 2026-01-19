class Solution
{
public:
    void sepearateCount(int count, vector<char> &chars)
    {
        if (count == 1)
            return;
        string cnt = to_string(count);
        for (char c : cnt)
            chars.push_back(c);
    }
    int compress(vector<char> &chars)
    {
        vector<char> compressed;
        int n = chars.size();
        char standard = chars[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (chars[i] == standard)
                count++;
            else
            {
                compressed.push_back(standard);
                sepearateCount(count, compressed);
                standard = chars[i];
                count = 1;
            }
        }
        compressed.push_back(standard);
        sepearateCount(count, compressed);
        chars = compressed;
        return chars.size();
    }
};
