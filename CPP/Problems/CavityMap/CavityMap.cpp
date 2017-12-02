#include <iostream>
#include <string>
#include <vector>

// Problem https://www.hackerrank.com/challenges/cavity-map/problem
// Courtsey: HackerRank

using namespace std;

int charToInt(char c) {
	return c - '0';
}

char **findCavities(const vector<string> &grid) {
	size_t grid_size = grid.size();
	char **grid_with_cavities = new char*[grid_size];
	for (size_t i = 0; i < grid_size; i++) {
		grid_with_cavities[i] = new char[grid_size];
	}

	for (unsigned int row = 0; row < grid_size; row++) {
		for (unsigned int col = 0; col < grid_size; col++) {
			if (row == 0 || col == 0 || row == grid_size - 1 || col == grid_size - 1) {
				grid_with_cavities[row][col] = grid[row][col];
			}
		}
	}
	for (unsigned int row = 1; row < grid_size - 1; row++) {

		for (unsigned int col = 1; col < grid_size - 1; col++) {
			unsigned int cell_val = charToInt(grid[row][col]);
			unsigned int north = charToInt(grid[row - 1].at(col));
			unsigned int east = charToInt(grid[row].at(col + 1));
			unsigned int south = charToInt(grid[row + 1].at(col));
			unsigned int west = charToInt(grid[row].at(col - 1));
			if (cell_val > north && cell_val > east && cell_val > south && cell_val > west) {
				grid_with_cavities[row][col] = 'X';
			}
			else {
				grid_with_cavities[row][col] = grid[row][col];
			}

		}
	}
	return grid_with_cavities;
}

void print_grid(const vector<string> &input) {
	size_t length = input.size();
	for (size_t i = 0; i < length; i++) {
		cout << input[i] << endl;
	}
}

int main(){
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int grid_i = 0; grid_i < n; grid_i++){
		cin >> grid[grid_i];
	}
	char **grid_with_cavities_marked = findCavities(grid);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cout << grid_with_cavities_marked[i][j];
		}
		cout << endl;
	}
	return 0;
}