// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s)
    {
        int len = s.length();
        int maxlen = 0;

        int lencounter = 0;
        int level = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                level++;
            }
            else if (s[i] == ')') {
                level--;
            }

            lencounter++;

            if (level < 0) {
                level = 0;
                lencounter = 0;
            }
            if (maxlen < lencounter and level == 0)
                maxlen = lencounter;
        }

        lencounter = 0;
        level = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '(') {
                level++;
            }
            else if (s[i] == ')') {
                level--;
            }

            lencounter++;

            if (level > 0) {
                level = 0;
                lencounter = 0;
            }
            if (maxlen < lencounter and level == 0)
                maxlen = lencounter;
        }

        return maxlen;
    }
};
