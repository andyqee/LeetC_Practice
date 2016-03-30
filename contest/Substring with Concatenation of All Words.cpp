//
//  Substring with Concatenation of All Words.cpp
//  contest
//
//  Created by andy on 2/6/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter).

// 这道题的意思，我貌似没理解对
// 就是说 s 中包含的字串 是由 words 中构成的

// 容易忽略的case；
// 如果 words 中的 word相同 用set来区分 就会有问题。
//

// 这道题目和 LeetCode:Longest Substring Without Repeating Characters 和LeetCode:Minimum Window Substring 用到的解决方法很类似

#warning 这道题目 值得再研究几遍 

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> map;
        set<string> set;

        size_t len = words[0].size();
        size_t count = words.size();
        
        for (int i = 0; i < words.size(); i++) {
            map[words[i]] = 1;                  // 这里如果words 中有相同的单词，就会丢失
        }
        if(len * count > s.length()) return result;
        
        int j = 0;
        while (j < s.length() - len * count + 1) {
            int k = j;
            int i = 0;
            
            while (i < count) {
//                if (k + count * i + len >= s.length()) {
//                    break;
//                }
                if (map[ s.substr(k + len * i, len) ] != 1 && set.count( s.substr(k + len * i, len) )== 0 )
                {
                    j++;
                    set.clear();
                    break;
                    
                } else
                {
                    set.insert( s.substr(k + len * i, len));
                    
                    i++;
                    if (i == count) {
                        result.push_back(j);
                        j += count * len;
                    }
                }
            }
            
        }
        return result;
    }
    
    // 折腾了第二个版本 time limit exceeded
    
    vector<int> findSubstring02(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> map;
        unordered_map<string, int> clone_map;

        set<string> set;
        
        size_t len = words[0].size();
        size_t count = words.size();
        
        for (int i = 0; i < words.size(); i++) {
            if (map[words[i]] > 0) {
                map[words[i]]++;
            } else {
                map[words[i]] = 1;
            }
        }
        if(len * count > s.length()) return result;
        
        int j = 0;
        while (j < s.length() - len * count + 1) {
            int k = j;
            int i = 0;
            clone_map = map;
            
            while (i < count) {
                if (map[ s.substr(k + len * i, len) ] < 1 && clone_map[s.substr(k + len * i, len)] < 1)
                {
                    j++;
                    clone_map = map;
                    break;
                    
                } else
                {
                    if( clone_map[s.substr(k + len * i, len)] > 1) {
                        clone_map[s.substr(k + len * i, len)]--;
                    } else {
                        clone_map.erase(s.substr(k + len * i, len));
                    }
                    i++;
                    if (i == count) {
                        result.push_back(j);
                        j += count * len;
                    }
                }
            }
            
        }
        return result;
    }
    
    // http://www.jiuzhang.com/solutions/substring-with-concatenation-of-all-words/
    // 下面这行代码是来自 九章算法
    // This solution cost only O(n * m) time where n is length of the master string s. m is the length of each word.
    // This solution's algorithm is using sliding window to optimize the traverse of the string.
    // directly for every start index and then determine whether this start index is a legal result will cost O(n * m * k) time where k is the numbers of words.
    
    // sliding window 是个什么东东？？
    
    class JZSolution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
            if (words.size() == 0) {      //边界条件检查
                return result;
            }
            
            unordered_map<string, int> hash;
            for (int i = 0; i < words.size(); i++) {
                if (hash.find(words[i]) == hash.end()) {  // 首先是通过 这种方式，判断是否存在。
                    hash[words[i]] = 1;
                } else {
                    hash[words[i]]++;
                }
            }
            
            int wSize = words[0].length();
            for (int start = 0; start < wSize; start++) {
                int wCount = 0;
                unordered_map<string, int> slidingWindow;
                for (int i = start; i + wSize <= s.length(); i+=wSize) {
                    string word = s.substr(i, wSize);
                    if (hash.find(word) == hash.end()) {
                        slidingWindow.clear();
                        wCount = 0;
                    } else {
                        if (wCount == words.size()) {
                            string removedWord = s.substr(i - wCount * wSize, wSize);
                            slidingWindow[removedWord]--;
                            wCount--;
                        }
                        wCount++;
                        if (slidingWindow.find(word) == slidingWindow.end()) {
                            slidingWindow[word] = 1;
                        } else {
                            slidingWindow[word]++;
                        }
                        while (hash[word] < slidingWindow[word]) {
                            string removedWord = s.substr(i - (wCount-1) * wSize, wSize);
                            slidingWindow[removedWord]--;
                            wCount--;
                        }
                    }
                    
                    if (wCount == words.size()) {
                        result.push_back(i - (wCount - 1) * wSize);
                    }
                }
            }
            
            return result;
        }
    };
};

// http://www.cnblogs.com/TenosDoIt/p/3807055.html

class CNSolution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int>wordTimes;//L中单词出现的次数
        for(int i = 0; i < L.size(); i++)
            if(wordTimes.count(L[i]) == 0)
                wordTimes.insert(make_pair(L[i], 1));
            else wordTimes[L[i]]++;
        int wordLen = L[0].size();
        
        vector<int> res;
        for(int i = 0; i < wordLen; i++)
        {//为了不遗漏从s的每一个位置开始的子串，第一层循环为单词的长度
            unordered_map<string, int>wordTimes2;//当前窗口中单词出现的次数
            int winStart = i, cnt = 0;//winStart为窗口起始位置,cnt为当前窗口中的单词数目
            for(int winEnd = i; winEnd <= (int)S.size()-wordLen; winEnd+=wordLen)
            {//窗口为[winStart,winEnd)
                string word = S.substr(winEnd, wordLen);
                if(wordTimes.find(word) != wordTimes.end())
                {
                    if(wordTimes2.find(word) == wordTimes2.end())
                        wordTimes2[word] = 1;
                    else wordTimes2[word]++;
                    
                    if(wordTimes2[word] <= wordTimes[word])
                        cnt++;
                    else
                    {//当前的单词在L中，但是它已经在窗口中出现了相应的次数，不应该加入窗口
                        //此时，应该把窗口起始位置想左移动到，该单词第一次出现的位置的下一个单词位置
                        for(int k = winStart; ; k += wordLen)
                        {
                            string tmpstr = S.substr(k, wordLen);
                            wordTimes2[tmpstr]--;
                            if(tmpstr == word)
                            {
                                winStart = k + wordLen;
                                break;
                            }
                            cnt--;
                        }
                    }
                    
                    if(cnt == L.size())
                        res.push_back(winStart);
                }
                else
                {//发现不在L中的单词
                    winStart = winEnd + wordLen;
                    wordTimes2.clear();
                    cnt = 0;
                }
            }
        }
        return res;
    }
};


// Accepted recursive solution using Trie Tree

// Java 实现

//static class TrieNode {
//    int value = 0;
//    Map<Character, TrieNode> children = new HashMap<Character, TrieNode>();
//}
//
//TrieNode trie;
//
//// build a trie tree
//public List<Integer> findSubstring(String S, String[] L) {
//    trie = buildTrie(L);
//    int length = getTotalLength(L);
//    List<Integer> result = new LinkedList<Integer>();
//    for (int i = 0; i < S.length() - length + 1; i++) {
//        if (isSubString(S, i, i + length))
//            result.add(i);
//    }
//    return result;
//}
//
//private int getTotalLength(String[] L) {
//    int sum = 0;
//    for (String l : L)
//        sum += l.length();
//    return sum;
//}
//
//private TrieNode buildTrie(String[] L) {
//    TrieNode root = new TrieNode();
//    for (String l : L)
//        addWord(root, l);
//    return root;
//}
//
//private void addWord(TrieNode root, String s) {
//    TrieNode node = root;
//    for (int i = 0; i < s.length(); i++) {
//        char c = s.charAt(i);
//        TrieNode next = node.children.get(c);
//        if (next == null) {
//            next = new TrieNode();
//            node.children.put(c, next);
//        }
//        node = next;
//    }
//    node.value++;
//}
//
//private boolean isSubString(String S, int start, int end) {
//    if (start == end)
//        return true;
//    // search in the trie tree
//    TrieNode node = trie;
//    for (int i = start; i < end; i++) {
//        char c = S.charAt(i);
//        if (node.children.get(c) == null)
//            return false;
//        node = node.children.get(c);
//        if (node.value > 0) {  // leaf & can be used
//            node.value--; // mark as used
//            if (isSubString(S, i + 1, end)) {
//                node.value++; // mark as unused
//                return true;
//            }
//            node.value++; // mark as unused
//        }
//    }
//    return false;
//}