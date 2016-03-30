//
//  Letter Combinations of a Phone Number.cpp
//  contest
//
//  Created by andy on 16/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

#warning 这个问题还值得再次研究下

//Given a digit string, return all possible letter combinations that the number could represent.

//A mapping of digit to letters (just like on the telephone buttons) is given below.

//Although the above answer is in lexicographical order, your answer could be in any order you want


//Solution BFS

using namespace std;

class Solution {
public:
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if (digits.size() == 0) {
            ans.push_back("");
            return ans;
        }
        
        vector<string> temp = letterCombinations(digits.substr(1));
        for (int j = 0; j < dict[digits[0]].size(); j++) {
            for (int t = 0; t < temp.size(); t++) {
                ans.push_back(dict[digits[0]][j] + temp[t]);
            }
        }
        
        if(ans.empty()) ans = temp;

        return ans;
    }
};


//public class Solution {
//    private static final String[] LETTERS = {
//        "",       // 0
//        "",       // 1
//        "abc",    // 2
//        "def",    // 3
//        "ghi",    // 4
//        "jkl",    // 5
//        "mno",    // 6
//        "pqrs",   // 7
//        "tuv",    // 8
//        "wxyz"   // 9
//    };
//    public static List<String> letterCombinations(String digits) {
//        List<String> result = new ArrayList<String>();
//        result.add("");
//        for(char c : digits.toCharArray()) {
//            String letter = LETTERS[c - '0'];
//            if(letter.length() == 0)
//                continue;
//            List<String> newResult = new ArrayList<String>();
//            for(char l : letter.toCharArray())
//                for(String s : result)
//                    newResult.add(s + l);
//            result = newResult;
//        }
//        return result;
//    }
//}


class SolutionB {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> str;//str for final resut
        string save;//save for temporary answer
        int convert[10] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
        
        dfs(str, save, digits, 0, digits.size(), convert);
        
        return str;
    }
    
    void dfs(vector<string> &str, string save, string dig, int now, int size, int *convert){
        if(now == size){
            str.push_back(save);
            return;
        }
        
        int tmp = dig[now] - '0' - 2;//change '2' to 0, '3' to 1...
        for(int i = convert[tmp]; i < convert[tmp+1]; i++){
            save.push_back('a' + i);//ex: a,b,c | d,e,f         //  成对出现
            dfs(str, save, dig, now + 1, size, convert);
            save.pop_back();                                    // 成对出现
        }
    }
};


// 迭代的方式

vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    res.push_back("");
    
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}

// FIFO queue   BFS

//public List<String> letterCombinations(String digits) {
//    LinkedList<String> ans = new LinkedList<String>();
//    String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//    ans.add("");
//    for(int i =0; i<digits.length();i++){
//        int x = Character.getNumericValue(digits.charAt(i));
//        while(ans.peek().length()==i){
//            String t = ans.remove();
//            for(char s : mapping[x].toCharArray())
//                ans.add(t+s);
//        }
//    }
//    return ans;
//}

