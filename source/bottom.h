void readConfig() {
    ifstream config("source/config.conf");
    string tmp;
    config >> tmp >> test::name;
    config >> tmp >> test::numTest;
    config >> tmp >> test::option;
    config >> tmp >> test::checker;
    config >> tmp >> test::numRange;
    test::rg.resize(test::numRange);
    for (int i = 0; i < test::numRange; ++i) {
        config >> tmp >> test::rg[i].l >> test::rg[i].r;
    }
    config.close();
}

void strTest() {
    for (int it = 0; it < test::numTest; ++it) {
        cerr << "Test " << it << ":\n";
        genTest();
        test::runtime("./"+test::name); // Linux
        test::runtime("./"+test::name+"_"); // Linux
        // test::run(test::name+".exe"); // Windows
        // test::run(test::name+"_.exe"); // Windows
        if (test::checker) {
            if (checker()) {
                cerr << "OK\n";
            }
            else {
                cerr << "Diff!!\n";
                return;
            }
        }
        else {
            if (test::compare(test::name+test::ex_out, test::name+test::ex_ans)) {
                cerr << "Diff!!\n";
                return;
            }
            else {
                cerr << "OK\n";
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    readConfig();
    if (test::option == "make") {
        cerr << "Making test... ";
        genTest();
        cerr << "Done\n";
    }
    else if (test::option == "test") {
        cerr << "Stressing Test...\n";
        strTest();
        cerr << "Done!\n";
    }
    return 0;
}