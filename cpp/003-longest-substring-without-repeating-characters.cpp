class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        string sub= string(1,s[0]) ;
        string dummy="";
       for (int i = 1; i < s.length(); i++) {
    bool falgerror = false;
    for (int j = 0; j < sub.length(); j++) {
        if (sub[j] == s[i] ) {
            falgerror = true;
            if (dummy.length() < sub.length()) {
                dummy = sub;
            }
            // Cắt chuỗi sub từ vị trí trùng trở về trước và thêm s[i]
            sub = sub.substr(j + 1) + s[i];
            break;
        }

    }
    if (!falgerror) {
        sub += s[i];
    }
   
}
if (dummy.length() < sub.length()) {
    dummy = sub;
}

return dummy.length();
    } 
};