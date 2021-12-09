#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>

namespace test {
    std::string name;
    const std::string ex_in = ".inp";
    const std::string ex_out = ".out";
    const std::string ex_ans = ".ans";
    int numTest = 0;
    std::string option;
    bool checker = false;
    int numRange = 0;
    
    std::mt19937_64 ra(time(nullptr));
    inline long long rand(long long l, long long r) {
        assert(l <= r);
        return l + ra() % (r-l+1);
    }

    struct Range {
        long long l, r;
        long long ra() {
            return rand(l,r);
        }
    };

    std::vector<Range> rg;

    inline void run(const std::string &file) {
        assert(!system(file.c_str()));
    }
    inline void runtime(const std::string &file) {
        auto start = std::chrono::high_resolution_clock::now();
        run(file);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cerr << file << " run in: " << duration.count() / 1e6 << "s\n";
    }
    inline bool compare(const std::string &file1, const std::string &file2) {
        return system(("diff "+file1+" "+file2).c_str()); // Linux
        // return system(("fc "+file1+" "+file2).c_str()); // Windows
    }
}