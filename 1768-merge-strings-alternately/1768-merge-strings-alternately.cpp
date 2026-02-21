class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0 ;
        int j = 0 ;
        string mergedString = ""; 
        // abc   pqr
        while(i < word1.size() && j < word2.size()){ 
            mergedString += word1[i];
            mergedString += word2[j];
            i += 1;
            j += 1;
        }
        while( i < word1.size())
        {
            mergedString += word1[i];
            i+=1;
        }

        while(j < word2.size()){
            mergedString+= word2[j];
            j+=1;
        }


        return mergedString;
    }
};
