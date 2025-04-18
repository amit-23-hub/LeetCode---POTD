class Solution {
public:

    string encode(const string &res) {
        string ans = "";
        int cnt = 1;

        for (int i = 1; i < res.size(); i++) {
            if (res[i] == res[i - 1]) {
                cnt++;
            } else {
                ans += to_string(cnt) + res[i - 1];
                cnt = 1;
            }
        }
// Jab hum last character tak pahuch jaate hain, tab loop khatam ho jaata hai aur last group of characters ko ans mein add nahi karte — isliye explicitly last wale group ko manually add karna padta hai.
       char lastChar = res[res.size() - 1];
ans += to_string(cnt) + lastChar;

return ans;
    }

    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string str = "1";
        for (int i = 2; i <= n; i++) {
            str = encode(str);
        }

        return str;
    }
};
