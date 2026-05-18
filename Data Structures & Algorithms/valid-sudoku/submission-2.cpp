class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            vector<int> check(9,1);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(num < 1 || num > 9){
                        return false;
                    }
                    if(check[num - 1] < 1){
                        return false;
                    }
                    check[num - 1]--;
                }
            }
        }

        for(int j = 0; j < 9; j++){
            vector<int> check(9,1);
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(num < 1 || num > 9){
                        return false;
                    }
                    if(check[num - 1] < 1){
                        return false;
                    }
                    check[num - 1]--;
                }
            }
        }

        for(int br = 0; br < 3; br++){
            for(int bc = 0; bc < 3; bc++){
                unordered_map<int,int> check;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[br*3 + i][bc*3 + j] != '.'){
                            int num = board[br*3 + i][bc*3 + j] - '0';
                            if(num < 1 || num > 9){
                                return false;
                            }
                            if(check[num] > 0){
                                return false;
                            }
                            check[num]++;
                        }
                    }
                }
            }
        }

        return true;
    }
};
