//
//  392_Is_Subsequence.cpp
//  contest
//
//  Created by ethon_qi on 23/9/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

//Given a string s and a string t, check if s is subsequence of t.
//
//You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//
//Example 1:
//s = "abc", t = "ahbgdc"
//
//Return true.
//
//Example 2:
//s = "axc", t = "ahbgdc"
//
//Return false.
//
//Follow up:
//If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

#warning 忽略边界case
//第一次做的时候，忽略了 s 和t 都是 “” 空字符串的情况。
//

#warning 实现的性能比较靠后，也就是程序比别人写的慢

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if ((s.length() == 0) && (t.length() == 0)) // 补充完这个后就可以了。
            return true;
        
        size_t sIndex = 0;
        for (size_t idx = 0; idx != t.length(); idx++) {
            if(s[sIndex] == t[idx]) {
                sIndex++;
            }
            if (sIndex == s.length()) {
                return true;
            }
        }
        return false;
    }
    
    // 想到的第二个办法就是查表，遍历t建立表。但是这样不太行，因为要自字符会重复
    //下面这种写法稍微快了些
//    int si= 0;
//    for(int ti = 0; ti < t.size() && si < s.size(); ti++) {
//        if(t[ti] == s[si]) si++;
//    }
//    return si == s.size();
 
//  这个方法很牛逼啊
    
    bool NextisSubsequence(string s, string t) {
        //build a record to store the index of each char in t
        vector<vector<int>> record(26);
        //add indexs
        for(int i = 0; i < t.size(); i++) {
            record[t[i]-'a'].push_back(i);
        }
        //check if each char in s is in the legal place
        int index = -1;
        for(int i = 0; i < s.size(); i++) {
            auto iter = upper_bound(record[s[i]-'a'].begin(), record[s[i]-'a'].end(), index);
            if(iter == record[s[i]-'a'].end()) return false;
            index = *iter;
        }
        return true;
    }
};

