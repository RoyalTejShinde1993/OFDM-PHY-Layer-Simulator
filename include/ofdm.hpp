
#pragma once
#include <vector>
#include <complex>

using Complex = std::complex<double>;

class OFDM {
public:
    OFDM(int fftSize, int cpLen);

    std::vector<Complex> modulate(const std::vector<Complex>& symbols);
    std::vector<Complex> demodulate(const std::vector<Complex>& signal);

private:
    int fftSize_;
    int cpLen_;
};
