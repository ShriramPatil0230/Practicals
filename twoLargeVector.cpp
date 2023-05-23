#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void parallelVectorAddition(const vector<int>& a, const vector<int>& b, vector<int>& result) {
    int size = a.size();
    result.resize(size);

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        result[i] = a[i] + b[i];
    }
}

int main() {
    // Example large vectors
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> b = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    int size = a.size();
    vector<int> result(size);

    cout << "Parallel Vector Addition:" << endl;
    parallelVectorAddition(a, b, result);

    cout << "Result: ";
    for (int i = 0; i < size; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
