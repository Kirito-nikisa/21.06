#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void create_random_matrix(int** matrix, int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int sum_pattern_a(int** matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int sum_pattern_b(int** matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int sum_pattern_v(int** matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j <= i; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the size of the matrix n: ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    create_random_matrix(matrix, n);

    cout << "Matrix " << n << "x" << n << ":" << endl;
    print_matrix(matrix, n);

    int sum_a = sum_pattern_a(matrix, n);
    int sum_b = sum_pattern_b(matrix, n);
    int sum_v = sum_pattern_v(matrix, n);

    cout << "Sum for pattern 'a': " << sum_a << endl;
    cout << "Sum for pattern 'b': " << sum_b << endl;
    cout << "Sum for pattern 'v': " << sum_v << endl;

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
