#include <bits/stdc++.h>

using namespace std;

array<int, 3> ask(int ind, int n)
{

    //* mid-1, mid, mid+1
    array<int, 3> ans;

    if (ind - 1 > 0)
    {
        cout << "? " << ind - 1 << endl; //! \n + cout.flush()
        cin >> ans[0];
    }
    else
    {
        ans[0] = INT_MAX;
    }

    cout << "? " << ind << endl;
    cin >> ans[1];

    if (ind + 1 <= n)
    {
        cout << "? " << ind + 1 << endl;
        cin >> ans[2];
    }
    else
    {
        ans[2] = INT_MAX;
    }

    return ans;
}

void tell(int ind)
{
    cout << "! " << ind << endl;
}

int main()
{
    int n;
    cin >> n;

    int low = 1, high = n;
    int ans;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        array<int, 3> val = ask(mid, n); //! mid-1, mid, mid+1

        if ((val[1] < val[2]) and (val[1] < val[0]))
        {
            ans = mid;
            break;
        }
        else if ((val[1] < val[2]) and (val[1] > val[0]))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    tell(ans);
}