class Solution {
public:
    long long atMost(string s, int k) {
        unordered_map<char,int> mp;

        int left = 0;
        long long ans = 0;

        for(int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while(mp.size() > k) {
                mp[s[left]]--;

                if(mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            ans += (long long)(right - left + 1);
        }

        return ans;
    }

    int numberOfSubstrings(string s) {

        long long n = s.size();
        long long total = n * (n + 1) / 2;

        return total - atMost(s, 2);
    }
};