#include "BinarySearch.h"
#include <cmath>

static constexpr double EPS = 1e-9;

int BinarySearch(const double A[], int l, int r, double k, int &comparisons) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        double val = A[mid];

        comparisons++;
        if (std::abs(val - k) <= EPS)
            return mid;

        comparisons++;
        if (val < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}