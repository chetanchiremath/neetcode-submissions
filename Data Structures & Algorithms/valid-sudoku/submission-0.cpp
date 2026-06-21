class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (st.count(board[i][j]))
                    return false;
                st.insert(board[i][j]);
            }
        }

        for (int j = 0; j < 9; j++) {
            unordered_set<char> st;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                if (st.count(board[i][j]))
                    return false;
                st.insert(board[i][j]);
            }
        }

        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> st;

                for (int i = boxRow; i < boxRow + 3; i++) {
                    for (int j = boxCol; j < boxCol + 3; j++) {
                        if (board[i][j] == '.')
                            continue;
                        if (st.count(board[i][j]))
                            return false;
                        st.insert(board[i][j]);
                    }
                }
            }
        }
        
        return true;
    }
};
