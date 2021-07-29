//Source : https://leetcode.com/problems/decode-string/
//Author : Ayan Agrawal
//Date   : 29-07-2021

class Solution {
public:
    string decodeString(string s) {
        int n = s.size(),i=0;
        string ans = "";
        //Maintain two stack one for count with which string should be appended
        //Other for the string that should be appended
        stack<int> nums;
        stack<string> strs;
        while(i<n)
        {
            if(s[i]=='[')
            {
                strs.push(ans);//Push in strings stack if opening bracket
                ans = "";
                i++;
            }
            else if(s[i]==']')
            {
                int x = nums.top();
                string st = strs.top();
                while(x--)
                {
                    st.append(ans);
                }
                nums.pop();
                strs.pop();
                ans = st; //update string x number of times if closing bracket
                i++;
            }
            else if(s[i]-'0'<=9 && s[i]-'0'>=0)
            {
                int c=0;
                while(i<n && s[i]-'0'<=9 && s[i]-'0'>=0)//Number can have more than 1 digit
                {
                    c = c*10 + s[i]-'0';
                    i++;
                }
                nums.push(c);
            }
            else
            {
                ans += s[i]; //if alphabet then just add to ans
                i++;
            }
        }
        return ans;
    }
};