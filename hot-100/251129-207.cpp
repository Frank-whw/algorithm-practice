// 207. 课程表

// 中等

// 相关企业
// 提示
// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，
// 其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

#include<bits/stdc++.h>
using namespace std;

class Solution {
private :
    vector<vector<int>> edges;
    vector<int> visited; // 0=未访问 1=访问中 2=已访问
    bool valid = true; // 标记图是否无环
public:
    void dfs(int u){
        visited[u] = 1;
        for(int v: edges[u]){
            if(visited[v] == 0){
                dfs(v);
                if(!valid)  return; // 已经发现有环 避免无用遍历
            }
            else if(visited[v] == 1){ // v处于访问中，说明绕回去了
                valid = false;
                return;
            }
        }
        visited[u] = 2; // 遍历完毕 无环
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. 初始化邻接表和访问状态数组的大小（节点数 = 课程数）
        edges.resize(numCourses);
        visited.resize(numCourses);  // 初始值默认是 0（未访问）

        // 2. 构建有向图的邻接表
        for (const auto& info : prerequisites) {
            // info[1] 是前置课程（先修课），info[0] 是后续课程（需先修 info[1]）
            // 因此添加边：info[1] → info[0]（表示 info[1] 是 info[0] 的前置依赖）
            edges[info[1]].push_back(info[0]);
        }

        // 3. 遍历所有未访问的节点（处理非连通图：可能存在多个独立的课程依赖链）
        // 若已发现环（valid 为 false），直接终止循环，提高效率
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {  // 只遍历未访问的节点，避免重复处理
                dfs(i);
            }
        }

        // 4. 返回结果：valid 为 true 表示无环，可完成所有课程；false 表示有环，不可完成
        return valid;
    }
};


class Solution {
private:
    vector<vector<int>> edges; // 邻接举证
    vector<int> indeg; // 入度

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // 初始化队列
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};