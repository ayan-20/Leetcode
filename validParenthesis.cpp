//Source : https://leetcode.com/problems/valid-parentheses/
//Author : Ayan Agrawal
//Date   : 27-06-2021

class Solution {
public:
    bool isValid(string s) {
        
        //push the opposite character when an opening character is found
        //if closing is found then compare with stack top(if present).
        
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='{') st.push('}');   
            else if(s[i]=='(') st.push(')');
            else if(s[i]=='[') st.push(']');
            else
            {
                if(st.empty()==true) return false;
                if(st.top()!=s[i]) return false;
                else st.pop();
            }
        }
        if(st.empty()==true) return true;
        else return false;
    }
};