/*

 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 *
 * https://leetcode.com/problems/sliding-puzzle/description/
 *
 * algorithms
 * Hard (58.76%)
 * Likes:    706
 * Dislikes: 25
 * Total Accepted:    39.7K
 * Total Submissions: 67K
 * Testcase Example:  '[[1,2,3],[4,0,5]]'
 *
 * On a 2x3 board, there are 5 tiles represented by the integers 1 through 5,
 * and an empty square represented by 0.
 *
 * A move consists of choosing 0 and a 4-directionally adjacent number and
 * swapping it.
 *  * The state of the board is solved if and only if the board is
 * [[1,2,3],[4,5,0]].
 *  * Given a puzzle board, return the least number of moves required so that the
 * state of the board is solved. If it is impossible for the state of the board
 * to be solved, return -1.
 *  * Examples:
 *  *  * Input: board = [[1,2,3],[4,0,5]]
 * Output: 1
 * Explanation: Swap the 0 and the 5 in one move.
 *  *  *  * Input: board = [[1,2,3],[5,4,0]]
 * Output: -1
 * Explanation: No number of moves will make the board solved.
 *  *  *  * Input: board = [[4,1,2],[5,0,3]]
 * Output: 5
 * Explanation: 5 is the smallest number of moves that solves the board.
 * An example path:
 * After move 0: [[4,1,2],[5,0,3]]
 * After move 1: [[4,1,2],[0,5,3]]
 * After move 2: [[0,1,2],[4,5,3]]
 * After move 3: [[1,0,2],[4,5,3]]
 * After move 4: [[1,2,0],[4,5,3]]
 * After move 5: [[1,2,3],[4,5,0]]
 *  *  *  * Input: board = [[3,2,4],[1,5,0]]
 * Output: 14
 *  *  * Note:
 *  *  * board will be a 2 x 3 array as described above.
 * board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
 *  *   */


// @lc code=start



class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> ind(6);
        ind[0] = {1,3};
        ind[1] = {0,2,4};
        ind[2] = {1,5};
        ind[3] = {0,4};
        ind[4] = {1,3,5};
        ind[5] = {2,4};
        string end = "123450";

        string state;
        unordered_map<string, int> prev;
        queue<string> q;
        int moves = 1;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                state += board[i][j] + '0';
            }
        }

        if(state == end)
            return 0;

        int i = 0;
        for( ; i < state.size(); i++) {
            if(state[i] == '0')
                break;
        }

        for(int j : ind[i]) {
            swap(state[i], state[j]);
            if(prev.find(state) == prev.end()) {
                prev[state] = 1;
                q.push(state);
                
            }   
            swap(state[i], state[j]);
        }

        bool found = false;

        while(!q.empty() && !found) {
            
            int k = q.size();

            while(k--) {
                string curr = q.front();
                q.pop();
                if(curr == end) {
                    found = true;
                    break;
                }
                int indZ = 0;
                for(; indZ < curr.size(); indZ++) {
                    if(curr[indZ] == '0')
                        break;
                }

                for(int j : ind[indZ]) {
                    swap(curr[j], curr[indZ]);
                    if(prev.find(curr) == prev.end()) {
                        prev[curr] = 1;
                        q.push(curr);
                    }
                    swap(curr[indZ], curr[j]);
                }
            }

            if(!found)
                moves++;

        }

        if(!found)
            return -1;
        return moves;
    }
};
// @lc code=end

