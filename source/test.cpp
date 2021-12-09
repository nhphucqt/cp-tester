#include <bits/stdc++.h>
#include "modules.h"

using namespace std;

void genTest() {
    ofstream inp(test::name+test::ex_in);
    //
    // Make test here
    int n = test::rg[0].ra();
    inp << 1 << ' ' << n << '\n';
    for (int i = 1; i <= n; ++i) {
        inp << test::rg[1].ra() << ' ';
    }
    //
    inp.close();
}

bool checker() {
    ifstream inp(test::name+test::ex_in);
    ifstream out(test::name+test::ex_out);
    ifstream ans(test::name+test::ex_ans);
    bool checkValue = false;
    // Correct output -> checkValue = true
    // Incorrect output -> checkValue = false
    //
    // Make checker here
    //
    inp.close();
    out.close();
    ans.close();
    return checkValue;
}

#include "bottom.h"