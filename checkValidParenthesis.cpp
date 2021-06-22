//Source : https://leetcode.com/problems/valid-parenthesis-string/
//Author : Ayan Agrawal
//Date   : 22-06-2021

class Solution {
public:
    bool checkValidString(string s) {
        
        //low : take '*' as ')', if there are some '(' not matched
        //high : take '*' as '('
        //if high < 0 means too much ')'
        //if low > 0 , after the count finished, means too much '('
        
        int n = s.size();
        int low=0,high=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                low++;
                high++;
            }
            else if(s[i]==')')
            {
                if(low>0)low--;
                high--;
            }
            else
            {
                if(low>0)low--;
                high++;
            }
            if(high<0) return false;
        }
        if(low!=0) return false;
        else return true;
    }
};