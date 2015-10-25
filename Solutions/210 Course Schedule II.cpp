class Solution {
private:
    vector<vector<int>> graph;
    vector<int> count_in;

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph.resize(numCourses, vector<int>());
        count_in.resize(numCourses, 0);

        for (auto p : prerequisites){
            count_in[p.first]++; 
            graph[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int i = 0; i < numCourses; i++) 
            if (count_in[i] == 0) ans.push_back(i);

        for(int cur = 0; cur < ans.size(); cur++){
            for (auto it = graph[ans[cur]].begin(); it != graph[ans[cur]].end(); it++){
                count_in[*it]--;
                if (count_in[*it] == 0) ans.push_back(*it);
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};



// class Solution {
// private:
//     vector<vector<int>> graph;
//     vector<int> used, order;
//     vector<pair<int, int>> time_exit;
//     int time;
//     bool is_exist;

//     void dfs(int v){
//         used[v] = 1;
//         for (int i : graph[v]){
//             if (!used[i]) dfs(i);
//         }
//         time_exit[v].first = time++;
//     }


//     void dfs_check(int v){
//         used[v] = 2;
//         for (int i : graph[v]){
//             if (used[i] == 1) dfs_check(i);
//             if (time_exit[v].first < time_exit[i].first) is_exist = false;
//         }
//     }

// public:
//     vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
//         graph.resize(numCourses);
//         used.resize(numCourses);
//         time_exit.resize(numCourses);
//         order.resize(numCourses);
//         time = 0;
//         is_exist = true;

//         for (pair<int, int> p : prerequisites) graph[p.first].push_back(p.second);
//         for (int i = 0; i < numCourses; i++){
//             time_exit[i].second = i;
//             if (!used[i]) dfs(i);
//         }

        
//         for (pair<int, int> p : time_exit)
//         for (int q : graph[p.second])
//         if (p.first < time_exit[q].first) return vector<int>();

//         if (is_exist){
//             sort(time_exit.begin(), time_exit.end());
//             for (int i = 0; i < numCourses; i++) order[i] = time_exit[i].second;
//         }

//         return order;
//     }
// };