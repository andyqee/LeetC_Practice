//
//  Anagrams.cpp
//  contest
//
//  Created by andy on 2/6/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

//Given an array of strings, return all groups of strings that are anagrams.

// 问题的表述有问题

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        vector<string> sortedStrs = strs;  // copy strs
        unordered_map<string, vector<int>> map;
        //排序的方法
        
        for(int i = 0; i < strs.size(); i++){
            sort(sortedStrs[i].begin(), sortedStrs[i].end());
            map[sortedStrs[i]].push_back(i);
        }
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second.size() > 1){
                for(int i = 0; i < it->second.size(); i++){
                    result.push_back(strs[it->second[i]]);
                }
            }
        }
        return result;
    }
};