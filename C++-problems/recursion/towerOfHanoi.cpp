#include <bits/stdc++.h>
using namespace std;

/*
src  dest  helper
1
2
3

src  dest  helper
2           1
3

src  dest  helper
3     2     1

src  dest  helper
3     1
      2

src  dest  helper
      1     3
      2

src  dest  helper
 1          2
            3

src  dest  helper
            1
            2
            3 

*/

void towerOfHanoi(int n, string src, string dest, string helper){
    if(n == 0)
        return;

// move n-1 plates to helper rod
    towerOfHanoi(n - 1, src, helper, dest);
// now move n-1 plates to destn
    cout << "Move from " << src << " to " << dest << endl;

    towerOfHanoi(n - 1, helper, dest, src);

    return;
}
int main(){
    towerOfHanoi(3, "SRC", "DEST", "HELP");

    return 0;
}