//
//  Course Schedule.cpp
//  contest
//
//  Created by andy on 27/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>

//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
//For example:
//
//2, [[1,0]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
//
//2, [[1,0],[0,1]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
//
//Note:
//The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.


// 这个问题是不是转换成 对有向图中存在环的判断
// 这里涉及到的是BFS 和DFS

#warning 理解的不是很清楚


using namespace std;

class Solution {
public:
    //从这儿，发现list of edges 在c++ 中可以用 pair<int ,int>
    //BFS 拓扑排序  这玩意真容易忘记，拓扑排序忘记了。
    
    bool canFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites) {
       
        // 将edge list 转换成 adjacency matrices
        vector<unordered_set<int>> matrix(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            matrix[prerequisites[i].second].insert(prerequisites[i].first);   // 以入口来统计
        }
        
        vector<int> d(numCourses, 0); // in-degree
        for(int i = 0; i < numCourses; ++ i)
            for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
                ++ d[*it];
        
        for(int j = 0, i; j < numCourses; ++ j)
        {
            for(i = 0; i < numCourses && d[i] != 0; ++ i); // find a node whose in-degree is 0
            
            if(i == numCourses) // if not find
                return false;
            
            d[i] = -1;
            for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
                -- d[*it];
        }
        
        return true;
    }
    
    // DFS 找cycle 的方法。 这个比较好理解 directed graph search
    
    bool canFinishDFS(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<unordered_set<int>> matrix(numCourses); // save this directed graph
        for(int i = 0; i < prerequisites.size(); ++ i)
            matrix[prerequisites[i][1]].insert(prerequisites[i][0]);
        
        unordered_set<int> visited;
        vector<bool> flag(numCourses, false);
        for(int i = 0; i < numCourses; ++ i)
            if(!flag[i])
                if(DFS(matrix, visited, i, flag))
                    return false;
        return true;
    }
    
    bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
    {
        flag[b] = true;
        visited.insert(b);   // 这是用数据结构查找的办法，还有一种面向对象的方式。就是把 visted 定义在每个对象中。
        for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
            if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
                return true;
        visited.erase(b);
        return false;
    }
    
};


