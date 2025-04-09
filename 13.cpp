// 13. Roman to Integer
class Solution {
    public:
        int romanToInt(string s) {
            ios_base::sync_with_stdio(0);
            unordered_map<char, int> dict;
    
            dict['I'] = 1;
            dict['V'] = 5;
            dict['X'] = 10;
            dict['L'] = 50;
            dict['C'] = 100;
            dict['D'] = 500;
            dict['M'] = 1000;
    
            int n = s.length();
            int res = dict[s[n - 1]];
    
            for (int i = n - 2; i >= 0; i--) {
                if (dict[s[i + 1]] <= dict[s[i]]) {
                    res += dict[s[i]];
    
                } else {
                    res -= dict[s[i]];
                }
            }
    
            return res;
        }
    };