#include <iostream>
#include <vector>
using namespace std;

bool isUsedInRow(vector<vector<char>>& board, int row, char num) {
    int cnt = 0;
    for (int col = 0; col < 9; col++) {
        if (board[row][col] == num) {
            cnt++;
            if (cnt > 1)
                return true;
        }
    }
    return false;
}

bool isUsedInCol(vector<vector<char>>& board, int col, char num) {
    int cnt = 0;
    for (int row = 0; row < 9; row++) {
        if (board[row][col] == num) {
            cnt++;
            if (cnt > 1)
                return true;
        }
    }
    return false;
}

vector<int> getBoxRowCol(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return {0, 0, 2, 2};
    }
    else if (row >= 3 && row < 6 && col >= 0 && col < 3) {
        return {3, 0, 5, 2};
    }
    else if (row >= 6 && row < 9 && col >= 0 && col < 3) {
        return {6, 0, 8, 2};
    }
    else if (row >= 0 && row < 3 && col >= 3 && col < 6) {
        return {0, 3, 2, 5};
    }
    else if (row >= 3 && row < 6 && col >= 3 && col < 6) {
        return {3, 3, 5, 5};
    }
    else if (row >= 6 && row < 9 && col >= 3 && col < 6) {
        return {6, 3, 8, 5};
    }
    else if (row >= 0 && row < 3 && col >= 6 && col < 9) {
        return {0, 6, 2, 8};
    }
    else if (row >= 3 && row < 6 && col >= 6 && col < 9) {
        return {3, 6, 5, 8};
    }
    else if (row >= 6 && row < 9 && col >= 6 && col < 9) {
        return {6, 6, 8, 8};
    }
    else {
        return vector<int>();
    }
}

bool isAlreadyInBox(vector<vector<char>>& board, int row, int col, char num) {
    vector<int> pos = getBoxRowCol(row, col);

    if (pos.empty())
        return false;

    int startRow = pos[0], endRow = pos[2];
    int startCol = pos[1], endCol = pos[3];

    int cnt = 0;
    for (int r = startRow; r <= endRow; r++) {
        for (int c = startCol; c <= endCol; c++) {
            if (board[r][c] == num) {
               cnt++;
               if (cnt > 1)
                   return true;
            }
        }
    }

    return false;
}

bool isValidNum(vector<vector<char>>& board, int row, int col, char num) {
    return !isUsedInCol(board, col, num) && !isUsedInRow(board, row, num) && !isAlreadyInBox(board, row, col, num);
}

bool isValidSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.' && !isValidNum(board, row, col, board[row][col]))
                return false;
        }
    }
    return true;
}

void printSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << board[row][col] << " ";
            if (col == 2 || col == 5)
                cout << "  ";
        }
        cout << endl;
        if (row == 2 || row == 5)
            cout << endl;
    }
}

int main() {

    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

//    vector<vector<char>> board = {
//            {'.','.','.','.','5','.','.','1','.'},
//            {'.','4','.','3','.','.','.','.','.'},
//            {'.','.','.','.','.','3','.','.','1'},
//            {'8','.','.','.','.','.','.','2','.'},
//            {'.','.','2','.','7','.','.','.','.'},
//            {'.','1','5','.','.','.','.','.','.'},
//            {'.','.','.','.','.','2','.','.','.'},
//            {'.','2','.','9','.','.','.','.','.'},
//            {'.','.','4','.','.','.','.','.','.'}
//    };


    printSudoku(board);
    if (isValidSudoku(board))
        cout << endl << endl << "valid: true";
    else
        cout << endl << endl << "valid: false";

    return 0;
}
