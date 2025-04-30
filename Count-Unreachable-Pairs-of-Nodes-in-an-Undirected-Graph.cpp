class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adj_matrix(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj_matrix[u].push_back(v);
            adj_matrix[v].push_back(u);
        }

        vector<bool> seen(n, false);
        vector<long long> components_size;
        for (int u = 0; u < n; ++u) {
            if (!seen[u]) {
                int size = 0;
                stack<int> st;
                st.push(u);
                seen[u] = true;
                while (!st.empty()){
                    int v = st.top();
                    st.pop();
                    size++;
                    for (auto& w : adj_matrix[v]) {
                        if (!seen[w]) {
                            seen[w] = true;
                            st.push(w);
                        }
                    }
                }
                components_size.push_back(size);
            }
        }

        long long total = 0;
        long long ans = 0;
        for (long long c : components_size) {
            ans += c * (n - total - c);
            total += c;
        }
        return ans;
    }
};