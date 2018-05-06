#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	vector<vector<int>> mtrx;

	default_random_engine generator;
	uniform_int_distribution<int> distribution(-999, 999);

	for (int i = 0; i < n; ++i) {
		vector<int> line;
		for (int j = 0; j < m; ++j) {
			int num = distribution(generator);
			line.push_back(num);
		}
		mtrx.push_back(line);
	}

	// Сортировка первой строки.
	bool flag = true;
	while (flag) {
		flag = false;
		for (int j = 0; j < m - 1; ++j) {
			if (mtrx[0][j] > mtrx[0][j + 1]) {
				flag = true;
				// Здесь меняем местами j и j + 1 столбцы.
				// Для этого во всех строках матрицы меняем местами j и j + 1 элементы.
				for (int i = 0; i < n; ++i) {
					int temp = mtrx[i][j];
					mtrx[i][j] = mtrx[i][j + 1];
					mtrx[i][j + 1] = temp;
				}
			}
		}
	}

	// Сортировка первой сттолбца.
	flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n - 1; ++i) {
			if (mtrx[i][0] > mtrx[i + 1][0]) {
				flag = true;
				// Здесь меняем местами i и i + 1 строки.
				vector<int> temp = mtrx[i];
				mtrx[i] = mtrx[i + 1];
				mtrx[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << mtrx[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}