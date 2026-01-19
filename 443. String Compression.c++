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
// Key Aspects Optimization
// Space from O(N) to O(1)
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int read = 0;
        int write = 0;
        int n = chars.size();
        while (read < n)
        {
            int count = 0;
            char currentChar = chars[read];
            while (read < n && currentChar == chars[read])
            {
                count += 1;
                read += 1;
            }
            chars[write++] = currentChar;
            if (count > 1)
                for (char c : to_string(count))
                    chars[write++] = c;
        }
        return write;
    }
};
