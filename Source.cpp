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

	// ���������� ������ ������.
	bool flag = true;
	while (flag) {
		flag = false;
		for (int j = 0; j < m - 1; ++j) {
			if (mtrx[0][j] > mtrx[0][j + 1]) {
				flag = true;
				// ����� ������ ������� j � j + 1 �������.
				// ��� ����� �� ���� ������� ������� ������ ������� j � j + 1 ��������.
				for (int i = 0; i < n; ++i) {
					int temp = mtrx[i][j];
					mtrx[i][j] = mtrx[i][j + 1];
					mtrx[i][j + 1] = temp;
				}
			}
		}
	}

	// ���������� ������ ��������.
	flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n - 1; ++i) {
			if (mtrx[i][0] > mtrx[i + 1][0]) {
				flag = true;
				// ����� ������ ������� i � i + 1 ������.
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