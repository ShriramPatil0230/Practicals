#include <iostream>
#include <vector>
#include <climits>
#include <omp.h>

using namespace std;

int main() {
    vector<int> arr = {5, 2, 9, 1, 7, 4, 6, 3, 8};

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int sum = 0;

    #pragma omp parallel for reduction(min:minVal) reduction(max:maxVal) reduction(+:sum)
    for (int i = 0; i < arr.size(); ++i) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
        sum += arr[i];
    }

    double avg = static_cast<double>(sum) / arr.size();

    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;

    return 0;
}