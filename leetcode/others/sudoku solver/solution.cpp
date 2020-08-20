#include <iostream>
#include <vector>
using namespace std;

bool isUsedInRow(vector<vector<char>>& board, int row, char num) {
    for (int col = 0; col < 9; col++) {
        if (board[row][col] == num)
            return true;
    }
    return false;
}

bool isUsedInCol(vector<vector<char>>& board, int col, char num) {
    for (int row = 0; row < 9; row++) {
        if (board[row][col] == num)
            return true;
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

    if (pos.size() == 0)
        return false;

    int startRow = pos[0], endRow = pos[2];
    int startCol = pos[1], endCol = pos[3];

    for (int r = startRow; r <= endRow; r++) {
        for (int c = startCol; c <= endCol; c++) {
            if (board[r][c] == num) {
                return true;
            }
        }
    }

    return false;
}

bool canBeAssignedNum(vector<vector<char>>& board, int row, int col, char num) {
    return !isUsedInCol(board, col, num) && !isUsedInRow(board, row, num) && !isAlreadyInBox(board, row, col, num);
}

pair<int, int> getUnassignedSpace(vector<vector<char>>& board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                return {r, c};
            }
        }
    }

    return {-1, -1};
}

void solveSudoku(vector<vector<char>>& board) {

    // first - row, second - col
    pair<int, int> unassigned = getUnassignedSpace(board);
    if (unassigned.first == -1) {
        return;
    }
    int row = unassigned.first, col = unassigned.second;

    for (char num = '1'; num <= '9'; num++) {
        if (canBeAssignedNum(board, row, col, num)) {
            board[row][col] = num;
            solveSudoku(board);

            unassigned = getUnassignedSpace(board);
            if (unassigned.first == -1)
                return;

            board[row][col] = '.';
        }
    }

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

    printSudoku(board);
    solveSudoku(board);
    cout << endl;
    cout << "Solved:" << endl << endl;
    printSudoku(board);

    return 0;
}
