#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y) {
    cout<<"? "<<x<<" "<<y<<endl;

    int ans;
    cin>>ans;

    return ans;
}

void tell(int x, int y) {
    cout<<"! "<<x<<" "<<y<<endl;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, m;
        cin>>n>>m;

        int a = ask(1, 1); 
        //! atleast one of the mines lie on the diagonal given by the equation x + y = a + 2

        //* now finding the two endpoints of the diagonal
        //* perform casework on pen-paper to understand why this works

        int xd1 = max(1, a + 2 - m), yd1 = a + 2 - xd1;
        int yd2 = max(1, a + 2 - n), xd2 = a + 2 - yd2;

        //* query from both the endpoints
        int ad1 = ask(xd1, yd1);
        int ad2 = ask(xd2, yd2);


        //* check if either of them is equal to 0, in which case that point is a mine
        if(ad1 == 0) {
            tell(xd1, yd1);
            continue;
        }

        if(ad2 == 0) {
            tell(xd2, yd2);
            continue;
        }

        //* calculate the coordinates of the points based on their distance from the given endpoints of diagonal

        int xp1 = xd1 + (ad1 / 2), yp1 = yd1 - (ad1 / 2);
        int xp2 = xd2 - (ad2 / 2), yp2 = yd2 + (ad2 / 2);

        //* atleast one of them should return 0 distance when queried
        if(ask(xp1, yp1) == 0) {
            tell(xp1, yp1);
        }
        else {
            tell(xp2, yp2);
        }
    }

    return 0;
}