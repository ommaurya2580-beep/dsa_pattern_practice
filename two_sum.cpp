// Problem: Two Sum
// Given an array and a target, print the 0-based indices of two
// different elements whose sum equals the target.
// If no pair exists, print -1.
//
// Input:
//   n target
//   a1 a2 ... an
//
// Example:
//   5 9
//   2 7 11 15 1
// Output:
//   0 1
//
// Average time complexity: O(n)
// Auxiliary space complexity: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    long long target;

    if (!(cin >> n >> target) || n < 0) {
        return 0;
    }

    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> numbers[i])) {
            return 0;
        }
    }

    // Store values seen so far so the same element is never used twice.
    unordered_map<long long, int> indexByValue;

    for (int i = 0; i < n; ++i) {
        const long long needed = target - numbers[i];
        const auto match = indexByValue.find(needed);

        if (match != indexByValue.end()) {
            cout << match->second << " " << i << '\n';
            return 0;
        }

        // Insert after checking to correctly handle duplicate values.
        indexByValue.emplace(numbers[i], i);
    }

    cout << -1 << '\n';
    return 0;
}
