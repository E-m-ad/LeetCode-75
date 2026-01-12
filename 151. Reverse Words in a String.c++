class Solution
{
public:
    bool isChar(char c)
    {
        return (char(c) >= 'A' && char(c) <= 'Z' || char(c) >= 'a' && char(c) <= 'z' || char(c) >= '0' && char(c) <= '9');
    }
    string reverseWords(string &s)
    {
        string c_s = " " + s + " ";
        vector<string> reversedWords;
        vector<int> startOfWords;
        for (int i = 1; i < c_s.size(); i++)
        {
            if (isChar(c_s[i]) && c_s[i - 1] == ' ')
                startOfWords.push_back(i);
        }
        s = "";
        for (int i = startOfWords.size() - 1; i >= 0; i--)
        {
            int j = 0;
            while (c_s[startOfWords[i] + j] != ' ' )
            {
               s+= c_s[startOfWords[i] + j++];
            }
            if (i)
                s += " ";
        }
        return s;
    }
};
// another solution.
class Solution
{
public:
    bool isChar(char c)
    {
        return (char(c) >= 'A' && char(c) <= 'Z' || char(c) >= 'a' && char(c) <= 'z' || char(c) >= '0' && char(c) <= '9');
    }
    string reverseWords(string &s)
    {
        string c_s = " " + s + " ";
        vector<int> startOfWords;
        stack<string> st;
        bool first = true;
        for (int i = 1; i < c_s.size(); i++)
        {
            if (isChar(c_s[i]) && c_s[i - 1] == ' ')
            {
                int j = i;
                s = "";
                while (c_s[j] != ' ' && j < c_s.size())
                {
                    s += c_s[j++];
                }
                if (!first)
                    st.push(s + " ");
                else
                {
                    st.push(s);
                    first = false;
                }
            }
        }

        s = "";
        while (st.empty() == false)
            s += st.top(), st.pop();

        return s;
    }
};
