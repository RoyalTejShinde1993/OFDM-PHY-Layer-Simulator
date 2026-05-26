
#pragma once
#include <vector>
#include <complex>

using Complex = std::complex<double>;

class Channel {
public:
    static std::vector<Complex> addAWGN(
        const std::vector<Complex>& signal,
        double snrDb
    );
};
