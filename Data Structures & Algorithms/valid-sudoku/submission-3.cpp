class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> sqs(9,0);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int mask = 1 << (board[i][j] - '1');
                if((rows[i] & mask) || 
                    cols[j] & mask || 
                    sqs[(i/3)*3 + (j/3)] & mask){
                        return false;
                }

                rows[i] |= mask;
                cols[j] |= mask;
                sqs[(i/3)*3 + j/3] |= mask;
            }
        }

        return true;
    }
};
