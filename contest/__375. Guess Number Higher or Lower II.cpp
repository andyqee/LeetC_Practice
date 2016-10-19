// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

// However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

// Example:

// n = 10, I pick 8.

// First round:  You guess 5, I tell you that it's higher. You pay $5.
// Second round: You guess 7, I tell you that it's higher. You pay $7.
// Third round:  You guess 9, I tell you that it's lower. You pay $9.

// Game over. 8 is the number I picked.

// You end up paying $5 + $7 + $9 = $21.
// Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

//https://leetcode.com/problems/guess-number-higher-or-lower-ii/

// DP result_when_pick_x = x + max{DP([i~x-1]), DP([x+1, j])}

// 当猜中一个数之后，其状态发生了怎样的变化
// 在设定状态方程的时候，首先思考地是，这个是由几个状态控制变化的
// 二维table 上搜索解空间
// 其对应的DAG是咋样的？
// 

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        
    }
};