
#pragma once
#include <vector>
#include <complex>

using Complex = std::complex<double>;

class QPSK {
public:
    static std::vector<Complex> modulate(const std::vector<int>& bits);
    static std::vector<int> demodulate(const std::vector<Complex>& symbols);
};
