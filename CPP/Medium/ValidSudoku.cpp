#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

// Time Complexity: O(9^2), O(n)
// Space Complexity: O(n)
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> boxes;
        const int n = board.size();

        for (int i = 0; i < n; i++) // rows
        {
            for (int j = 0; j < board[i].size(); j++) // cols
            {
                const char c = board[i][j];

                if (c == '.')
                    continue;

                const pair<int, int> p(i / 3, j / 3);

                if (rows[i].find(c) != rows[i].end() || cols[j].find(c) != cols[j].end() || boxes[p].find(c) != boxes[p].end())
                    return false;

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[p].insert(c);
            }
        }

        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    s->isValidSudoku(board);
    return 0;
}