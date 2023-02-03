class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        //Розв'язок заданого судоку
        for (int i = 0; i < board.size(); i++) { //Обхід заданого судоку
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') { //порожнє місце знайдено

                    for (char c = '1'; c <= '9'; c++) { //перебір усіх можливих чисел від 1-9
                        if (isValid(board, i, j, c)) { //перебір усіх можливих чисел від 1 до 9
                            board[i][j] = c;

                            if (solve(board) == true) //перебір наступного пропуску 
                                return true;
                            else
                                board[i][j] = '.'; //якщо після перевірки не вдається заповнити пропуск, то відмінити зміни
                        }
                    }
                    return false;
                }
            }
        }
        return true; //якщо все заповнено, то повернути true
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) //перевірка рядка на наявність значення
                return false;
            if (board[i][col] == c) //перевірка стовпця, якщо значення вже є
                return false;
            //перевірка підблоку 3X3, де присутнє пусте значення, на наявність елементу
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};

