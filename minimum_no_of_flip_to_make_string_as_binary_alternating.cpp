class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.length();
        s = s + s;
        string s1, s2;
        for (int i = 0; i < 2 * n; i++)
        {
            if (i % 2)
            {
                s2 += '0';
                s1 += '1';
            }
            else
            {
                s1 += '0';
                s2 += '1';
            }
        }

        int result = INT_MAX;
        int i = 0;
        int j = 0;

        int len1 = 0;
        int len2 = 0;

        while (j < 2 * n)
        {
            if (s1[j] != s[j])
            {
                len1++;
            }
            if (s2[j] != s[j])
            {
                len2++;
            }

            if (j - i + 1 > n)
            {
                if (s[i] != s1[i])
                    len1--;
                if (s[i] != s2[i])
                    len2--;
                i++;
            }

            if ((j - i + 1) == n)
            {
                result = min({result, len1, len2});
            }

            j++;
        }
        return result;
    }
};