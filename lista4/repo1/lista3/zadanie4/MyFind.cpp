#include "MyFind.h"

#include <algorithm>
#include <cmath>

extern int FUNCTION_NUMBER;
using namespace std;
static constexpr double EPS = 1e-9;


// ======================================================
// FUNCTIONS
// ======================================================

static inline double f1(int i) {
    return std::pow(
        std::log2(i + 1.0),
        3.0
    );
}

static inline double f2(int i) {
    return std::sqrt((double)i)
           + std::log2(i + 1.0);
}

static double (*f)(int) = nullptr;


// ======================================================
// FIRST INDEX:
// f(i) >= y
// ======================================================

static int lower_inverse_f(
    double y,
    int n
) {

    int l = 0;
    int r = n - 1;

    int ans = n;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (f(mid) >= y) {

            ans = mid;
            r = mid - 1;
        }
        else {

            l = mid + 1;
        }
    }

    return ans;
}


// ======================================================
// LAST INDEX:
// f(i) <= y
// ======================================================

static int upper_inverse_f(
    double y,
    int n
) {

    int l = 0;
    int r = n - 1;

    int ans = -1;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (f(mid) <= y) {

            ans = mid;
            l = mid + 1;
        }
        else {

            r = mid - 1;
        }
    }

    return ans;
}


// ======================================================
// BINARY SEARCH ON RANGE
// ======================================================

static int BinarySearchRange(
    const double A[],
    int l,
    int r,
    double k,
    int &comparisons
) {

    while (l <= r) {

        int mid =
            l + (r - l) / 2;

        comparisons++;

        if (std::abs(A[mid] - k) <= EPS) {
            return mid;
        }

        comparisons++;

        if (A[mid] < k) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return -1;
}


// ======================================================
// MAIN ALGORITHM
// ======================================================

int MyFind(
    const double A[],
    int n,
    double k,
    int &fallback_used,
    int &comparisons
) {

    fallback_used = 0;

    if (n == 0) {
        return -1;
    }


    // ======================================================
    // FUNCTION SELECTION
    // ======================================================

    double delta;

    if (FUNCTION_NUMBER == 1) {

        f = f1;
        delta = 10.0;
    }
    else {

        f = f2;
        delta = 50.0;
    }


    // ======================================================
    // QUICK REJECTION
    // ======================================================

    comparisons++;

    if (k < A[0]) {
        return -1;
    }

    comparisons++;

    if (k > A[n - 1]) {
        return -1;
    }


    // ======================================================
    // RANGE REDUCTION
    //
    // f(i) <= A[i] < f(i) + delta
    //
    // if A[i] = k:
    //
    // k - delta < f(i) <= k
    // ======================================================

    int left =
        lower_inverse_f(
            k - delta,
            n
        );

    int right =
        upper_inverse_f(
            k,
            n
        );


    left =
        max(0, left);

    right =
        min(n - 1, right);


    // ======================================================
    // FALLBACK
    // ======================================================

    if (left > right) {

        fallback_used = 1;

        return BinarySearchRange(
            A,
            0,
            n - 1,
            k,
            comparisons
        );
    }


    // ======================================================
    // SEARCH ONLY INSIDE SMALL RANGE
    // ======================================================

    return BinarySearchRange(
        A,
        left,
        right,
        k,
        comparisons
    );
}