class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<int> output;

        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});

        int i = 0;
        long long time = tasks[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> availableTasks;

        while (i < n || !availableTasks.empty()) {
            while (i < n && tasks[i][0] <= time) {
                availableTasks.emplace(tasks[i][1], tasks[i][2]);
                i++;
            }
            if(availableTasks.empty()) {
                time = tasks[i][0];
            } else {
                auto [processingTime, idx] = availableTasks.top(); availableTasks.pop(); 
                time += processingTime;
                output.push_back(idx);
            }
        }
        return output;
    }
};