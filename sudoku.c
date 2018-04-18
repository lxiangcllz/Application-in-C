//数独游戏

#include <stdio.h>
#include <stdbool.h>

#define For(i, a, b) for(int i = a; i < b; i++)

bool solve(int sudoku[9][9], int index);
bool check(int sudoku[9][9], int row, int col, int val);

int main() {
	int sudoku[9][9] = {0};
	For(i, 0, 9) {
		For(j, 0, 9) {
			scanf("%d", &sudoku[i][j]);
		}
	}

	solve(sudoku[9][9], 0);

	For(i, 0, 9) {
		For(j, 0, 9) {
			printf("%d ", sudoku[i][j]);
		}
		printf("\n");
	}
	return 0;
}

bool solve(int sudoku[9][9], int index) {
	int r = index / 9;
	int c = index % 9;//索引为index的元素所在的行和列
	if(index == 81) return true;
	else if(sudoku[r][c] != 0) return solve(sudoku[9][9], index+1);
	else {
		For(val, 1, 10) {
			//回溯：如果sudoku[r][c]可以置为val，还需要进一步检查是否
			//会对下一个位置的元素有影响，如果有则需还原为0，继续试下一个val值
			if(check(sudoku[9][9], r, c, val))
				sudoku[r][c] = val;
			if(solve(sudoku[9][9], index+1))
				return true;
			sudoku[r][c] = 0;
		}
	}
	return false;
}
bool check(int sudoku[9][9], int row, int col, int val) {
	For(i, 0, 9) {
		if(sudoku[row][i] == val) return false;
	}
	For(i, 0, 9) {
		if(sudoku[i][col] == val) return false;
	}
	For(i, row/3*3, (row/3+1)*3) {
		For(j, col/3*3, (col/3+1)*3) {
			if(sudoku[i][j] == val) return false;
		}
	}
	return true;
}
