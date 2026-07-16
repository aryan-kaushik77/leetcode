class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;

        for (char x : tasks) {
            mp[x]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        int time = 0;

        while (!pq.empty()) {

            int cycle = n + 1;
            int workdone = 0;
            vector<pair<int, char>> temp;

            while (!pq.empty() && cycle > 0) {

                int count = pq.top().first;
                char task = pq.top().second;
                pq.pop();

                count--;
                workdone++;
                cycle--;    // <-- Missing in your code

                if (count > 0) {
                    temp.push_back({count, task});
                }
            }

           
            for (auto x : temp) {
                pq.push(x);
            }

            if (!pq.empty())
                time += (n + 1);
            else
                time += workdone;
        }

        return time;
    }
};