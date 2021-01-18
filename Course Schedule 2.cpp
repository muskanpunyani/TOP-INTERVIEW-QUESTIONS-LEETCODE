There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= numCourses * (numCourses - 1)
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    ai != bi
    All the pairs [ai, bi] are distinct.


****************
class Solution {
public:
    // TIME=0(V+E)
   // if cycle not possible
    bool dfs(vector<vector<int>> &graph,int start,vector<int> &ans,vector<bool> &visited,vector<bool>& helper)
    {
        visited[start]=true;
        helper[start]=true;
         for(auto it:graph[start])
        {
             if(helper[it]==true)
                 return true;
             if(!visited[it])
             {
              bool res=  dfs(graph,it,ans,visited,helper);
                if(res==true)
                {
                    return true;
                }
             }
        }
         ans.push_back(start);   // same as course schedule,just push the elements before backtrack(topological)
        helper[start]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            graph[v].push_back(u);
        }
        vector<bool> visited(numCourses+1,false);
        vector<bool> helper(numCourses+1,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i] && dfs(graph,i,ans,visited,helper)==true) // if cycle
                // then not possible
            {
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
