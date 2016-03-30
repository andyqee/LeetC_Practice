//
//  main.cpp
//  contest
//
//  Created by andy on 5/4/15.
//  Copyright (c) 2015 andy. All rights reserved.//


#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>

//#include "Solution.cpp"
//#include "HappyNumber.cpp"

//#include "Reverse Linked List.cpp"

#include "Substring with Concatenation of All Words.cpp"

/** Problem 1: Funny String
using namespace std;

bool isFunny(const string &ch, long count)
{
    for (int i = 0; i != count / 2; ++i)
    {
        if (abs((ch[i+1] - ch[i])) != abs(ch[count- 1 - i] - ch[count - i - 2])) {
            return false;
        }
    }
    return true;
}

int main() {
    
    string str;
    int t;
    
    cin >> t;
    
    for (int i=0; i<t; i++) {
        cin >> str;
        cout << (isFunny(str, str.length()) ? "Funny" : "Not Funny") << endl;
    }
    
    return 0;
}
**/

/** Problem 2
using namespace std;

bool isPangrams(const string &ch, long count)
{
    set<char> set;
    for (int idx = 0; idx != count; idx++) {
        int gap = 'a' - 'A';
        char a = ch[idx];
        if (a == ' ') {
            continue;
        }
        if ( a <= 'Z') {
            a = a + gap;
        }
        if (set.count(a) != 0) {
            return false;
        } else {
            set.insert(a);
        }
    }
    return true;
}

int main() {
    
    string str;
    
    cout << (isPangrams(str, str.length()) ? "pangram" : "not pangram") << endl;
    
    return 0;
}
*/

using namespace std;
/**
string lexicographicallyGreaterString(string &text, long len)
{
    bool has_no_answer = !next_permutation(text.begin(), text.end());
    return has_no_answer ? "no answer" : text;
}

int main() {
    
    string str;
    int t;
    cin >> t;
    for (int idx = 0; idx != t; idx++) {
        cin >> str;
        cout << lexicographicallyGreaterString(str, str.length()) << endl;
    }
    
    return 0;
}
**/

/**
unsigned long  solution(string &s1, string &s2 )
{
    unsigned long count = 0;
    int ch1[26] = {0};
    int ch2[26] = {0};
    for(int i = 0; i != s1.length(); i++ ) {
        ch1[ s1[i]-97 ]++;
    }
    
    for(int i = 0; i != s2.length(); i++ ) {
        ch2[ s2[i]-97 ]++;
    }
    
    for (int i = 0; i < 26; i++) {
        count += abs(ch1[i] - ch2[i]);
    }
    return count;
}

int main() {
    
//    string s1, s2;
//    cin >> s1 >> s2;
        string s1 = "cde", s2 = "abc";
    cout << solution(s1, s2)<< endl;
    
    return 0;
}
**/

/**
 Gem Stones
 **/

//int main() {
//    
//    int t;
//    cin >>t;
//    
//    string fs;
//    cin >> fs;
//    
//    int set1[26] = {0};
//    for (int i = 0; i != fs.length(); i++) {
//        set1[fs[i]- 97] = 1;
//    }
//    
//    string s2;
//    for (int i = 0; i != t-1; i++) {
//        int set2[26] = {0};
//        cin >> s2;
//        for (int i = 0; i != s2.length() ; i++) {
//            set2[s2[i] - 97] = 1;
//        }
//        
//        for (int j = 0; j != 26; j++) {
//            set1[j] = set1[j] & set2[j];
//        }
//    }
//    
//    int count = 0;
//    for (int i; i != 26; i++) {
//        if (set1[i] == 1) {
//            count++;
//        }
//    }
//    
//    cout << count << endl;
//
//    return 0;
//}

/**
 Palindrome Index 40/50
 */

//unsigned long findIndex(const string &txt)
//{
//    unsigned long i = 0, j = txt.length() - 1;
//    while (i < j) {
//        if (txt[i] == txt[j]) {
//            i++;
//            j--;
//        } else {
//            if (txt[i] == txt[j-1]) {
//                return j;
//            }
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main() {
//    int t;
//    cin >> t;
//    string txt;
//    for (int idx = 0; idx != t; idx++) {
//        cin >> txt;
//        cout << findIndex(txt) << endl;
//    }
//    
//    return 0;
//}

/**
 two string commen substring
 */

//string findIndex(const string &t1, const string &t2)
//{
//    int set1[26] = {0};
//    for (int i = 0; i != t1.length(); i++) {
//        set1[t1[i]- 97] = 1;
//    }
//    
//    int j = 0;
//    while (j < t2.length()) {
//        if (set1[ t2[j++] - 97] == 1) {
//            return "YES";
//        }
//    }
//    return "NO";
//}
//
//int main() {
//    int t;
//    cin >> t;
//    string t1;
//    string t2;
//    for (int idx = 0; idx != t; idx++) {
//        cin >> t1;
//        cin >> t2;
//        cout << findIndex(t1, t2) << endl;
//    }
//    
//    return 0;
//}

int main() {
    Solution s;
//    string str = "abababab";
    string str = "a";
    vector<string> v;
    v.push_back("a");
//    v.push_back("b");
//    v.push_back("a");

    s.findSubstring02(str, v);
    
    return 0;
}


