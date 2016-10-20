//: [Previous](@previous)

import Foundation

//344. Reverse String   QuestionEditorial Solution  My Submissions
//Contributors: Admin
//Write a function that takes a string as input and returns the string reversed.
//
//Example:
//Given s = "hello", return "olleh".

func reverseString(_ s: String) -> String {
    if s.characters.count <= 1 {
        return s
    }
    
    var sA = Array(s.characters)
    var reversed =  [Character]()
    let len = s.characters.count
    
    for i in (0..<len).reversed() {
        reversed.append(sA[i])
    }
    return String(reversed)
}

//13. Roman to Integer   QuestionEditorial Solution  My Submissions

//Difficulty: Easy
//Contributors: Admin
//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999

// 这道题目我完全理解错了, 这里是把罗马数字 转成 int

//func romanToInt(_ s: String) -> Int {
//    let map = [Character : Int] = ["M": 1000, "D": 500, "C": 100, "L": 50, "X": 10, "V": 5, "I": 1]
//    
//}

//8. String to Integer (atoi)

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

//这里需要注意的就是
// string 是否为 nil, 这决定了 接口参数到底设计成 string 还是 String？
// string 的长度 是否超过Int
// 非法字符串情况，要过滤掉，如果0 开头的字符串，这个是代码容错 能力的体现
// 还有就是负数情况，就是说开头是 - 而不是数字，这些都需要考虑清楚啊
// 这里面只有numberic character 嘛？
// 要把这些思维过程想清楚，并传达给面试官
// 没有处理好的 int 越界，返回最大值

func myAtoi(_ str: String) -> Int {
    let map : [Character : Int] = ["0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9" : 9]
    
    var isFirstValidCha = false
    var isNagtive = false
    var value : Int = 0
    var index = 1
    
    for (_, c) in str.characters.enumerated() {
        if c == " " || c == "+" {
            continue
        }
        if c == "-" {
            isNagtive = true
        } else if map[c] != nil {
            if c == "0" && (isFirstValidCha == false) {
                continue
            } else { // 这里为什么是7 因为 二进制 最后 111 = 7，if > 7, it will overflow
                if value > Int.max / 10 || value == Int.max / 10 && map[c]! > 7 {
                    return isNagtive ? Int.min : Int.max
                }
                isFirstValidCha = true
                value = value * index + map[c]!
                index = 10
            }
        }
    }
    return isNagtive ? (0 - value) : value
}

//30. Substring with Concatenation of All Words

//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]
//
//You should return the indices: [0,9].

//func findSubstring(_ s: String, _ words: [String]) -> [Int] {
    
//}

//345. Reverse Vowels of a String
//Write a function that takes a string as input and reverse only the vowels of a string.
//
//Example 1:
//Given s = "hello", return "holle".
//
//Example 2:
//Given s = "leetcode", return "leotcede".
//
//Note:
//The vowels does not include the letter "y".

func reverseVowels(_ s: String) -> String {
    var j = s.characters.count - 1
    if j < 1 {
        return s
    }
    
//    let lowerS = s.lowercased() // 这里不能调用这个方法 比如aA 交换之后 Aa，
    let vowels : Set<Character> = ["a", "e", "i", "u", "o", "A", "E", "I", "O", "U"]
    
    var chs = Array(s.characters)
    var i = 0
    //swift 的set 功能比较强大，但是这里不能用
    while i < j { // 循环条件判断，容易出错, 注意数组越界检查
        while ( i < j && (!vowels.contains(chs[i]))) ) {
            i += 1
        }
        while ( i < j && !vowels.contains(chs[j])) {
            j -= 1
        }
        swap(&chs[i], &chs[j]) // 交换的方法
        i += 1
        j -= 1
    }
    return String(chs)
}

let a = reverseVowels("aA")

//38. Count and Say   QuestionEditorial Solution  My Submissions
//Total Accepted: 103094
//Total Submissions: 326709
//Difficulty: Easy
//Contributors: Admin
//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.

//func countAndSay(_ n: Int) -> String {
 //
//}
