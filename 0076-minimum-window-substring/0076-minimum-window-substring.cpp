class Solution {
public:
    bool containsMap(unordered_map<char, int>& have,
                     unordered_map<char, int>& need) {

        for (auto &p : need) {
            auto it = have.find(p.first);

            if (it == have.end() || it->second < p.second) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> mp1;

        for (char x : t) {
            mp1[x]++;
        }

        unordered_map<char, int> mp2;

        int left = 0;
        int left_i = 0;
        int right_i = 0;
        int ans = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            mp2[s[right]]++;

            while (containsMap(mp2, mp1)) {

                if (ans > right - left + 1) {
                    ans = right - left + 1;
                    left_i = left;
                    right_i = right;
                }

                mp2[s[left]]--;

                if (mp2[s[left]] == 0) {
                    mp2.erase(s[left]);
                }

                left++;
            }
        }

        if (ans == INT_MAX)
            return "";

        return s.substr(left_i, ans);
    }
};