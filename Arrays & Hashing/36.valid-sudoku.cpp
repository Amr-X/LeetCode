/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<cctype>
using namespace std;
class Solution {
public:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false

    bool isValidSudoku(vector<vector<char>>& board) {
        // A HashMap - Storing Unique digits (as char)
        unordered_map<char,bool> map;
        // Verify Each Row
        for (const auto &row : board)
        {
            for (const auto &ch : row)
            {
                if(isdigit(ch)){
                    if(map.count(ch) != 0){ // It's Already There
                        return false;
                    }
                    map[ch] = true;
                    
                }
            }
            map.clear();
        }
        
        // Verify Each Column
        for(size_t i = 0; i < board.front().size();i++){
             for (size_t j = 0; j < board.size(); j++)
             {
                char ch = board[j][i];
                if(isdigit(ch)){
                    if(map.count(ch)){ // It's Already There
                        return false;
                    }
                    map[ch] = true;
                }
             }
            map.clear(); 
        }

        // Verify Each Box of 3x3 - This is gonna be messy i think
        const int size{3};
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                // For Every Box
                // I Get The Problem Now:
                    // k = 50;
                    // size = 3 
                    // From 50 to 3 ??????????????????????????????????
                    // No-> from 50 to 50 +3
                for(size_t k = i*3;k < i*3+size;k++){
                    for(size_t p = j*3;p < j*3+size;p++){
                        char ch = board[k][p];
                        if(isdigit(ch)){
                            if(map.count(ch)){ // It's Already There
                                return false;
                            }
                            map[ch] = true;
                        }
                    }
                }
                map.clear();
            }
        }
        // Hell ton of verifications
        return true;
    }
};
// @lc code=end

