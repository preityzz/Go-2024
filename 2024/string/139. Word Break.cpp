class Solution
{
public:
    bool wordBreak(string word, vector<string> &wordList)
    {
        // an empty list of words
        if (word.empty())
            return true;

        int wordLen = word.length();

        // Check if the word can be broken down into
        // words from the wordList
        for (int i = 1; i <= wordLen; ++i)
        {
            string prefix = word.substr(0, i);

            if (find(wordList.begin(), wordList.end(), prefix) != wordList.end() && wordBreak(word.substr(i), wordList))
            {
                return true;
            }
        }

        return false;
    }
};
