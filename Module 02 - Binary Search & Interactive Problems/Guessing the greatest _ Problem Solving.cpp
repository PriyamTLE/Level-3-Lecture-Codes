#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    cout<<"? "<<l<<" "<<r<<endl;

    int ans;
    cin>>ans;

    return ans;
}

void tell(int ind) {
    cout<<"! "<<ind<<endl;
}

int main() {
    int n;
    cin>>n;

    int secondMax = ask(1, n);

    if(n == 2) {
        if(secondMax == 1) {
            tell(2);
        }
        else {
            tell(1);
        }

        return 0;
    }

    
    int tmp = -1;

    if(secondMax != 1) {
        tmp = ask(1, secondMax);
    }

    //! if secondMax = 1, that means the maximum is to the right

    if(tmp == secondMax) {
        //* this means maximum value lies to the left of second maximum value in the array

        int low = 1, high = secondMax - 1;
        int ans;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(ask(mid, secondMax) == secondMax) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        tell(ans);        
    }
    else {
        //* this means maximum value lies to the right of the second maximum value in the array

        int low = secondMax + 1, high = n;
        int ans;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(ask(secondMax, mid) == secondMax) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        tell(ans);
    }

    return 0;
}