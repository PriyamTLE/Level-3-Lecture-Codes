#include <bits/stdc++.h>
using namespace std;

double maxSumChecker(vector<double> &arr, int n)
{
    vector<double> d(n);
    d[0] = arr[0];
    d[1] = arr[1] + max(d[0], double(0));
    for (int i = 2; i < n; i++)
    {
        d[i] = arr[i] + max(d[i - 1], d[i - 2]);
    }
    return max(d[n - 1], d[n - 2]);
}

double bestAverage(vector<long long> arr, int n)
{
    double left = 0, right = 1e12;
    double error = 1e-5;
    double avg;
    // SS - log2(10^17)
    for (int iterations = 0; iterations <= 100; iterations++)
    {
        double mid = (left + right) / 2;
        vector<double> transformed_array(n);
        for (int i = 0; i < n; i++)
            transformed_array[i] = arr[i] - mid;
        
        if (maxSumChecker(transformed_array, n) >= 0)
        {
            avg = mid;
            left = mid + error;
        }
        else
        {
            right = mid - error;
        }
    }
    return avg;
}

long long bestMedian(vector<long long> arr, int n)
{
    long long left = 0, right = 1e12;
    long long median;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        vector<double> temp(n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= mid)
            {
                temp[i] = 1;
            }
            else
            {
                temp[i] = -1;
            }
        }
        if (maxSumChecker(temp, n) > 0)
        {
            median = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return median;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << setprecision(7) << bestAverage(arr, n) << endl;
    cout << bestMedian(arr, n) << endl;

    return 0;
}