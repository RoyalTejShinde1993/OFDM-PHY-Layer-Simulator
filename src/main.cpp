
#include <iostream>
#include <vector>
#include <complex>
#include <random>
#include <cmath>
#include <algorithm>

using Complex = std::complex<double>;

constexpr double PI = 3.14159265358979323846;

class QPSK {
public:
    static std::vector<Complex> modulate(const std::vector<int>& bits) {
        std::vector<Complex> symbols;

        for (size_t i = 0; i < bits.size(); i += 2) {
            double real = bits[i] ? 1.0 : -1.0;
            double imag = bits[i + 1] ? 1.0 : -1.0;

            symbols.emplace_back(real, imag);
        }

        return symbols;
    }

    static std::vector<int> demodulate(
        const std::vector<Complex>& symbols
    ) {
        std::vector<int> bits;

        for (const auto& s : symbols) {
            bits.push_back(s.real() > 0 ? 1 : 0);
            bits.push_back(s.imag() > 0 ? 1 : 0);
        }

        return bits;
    }
};

class OFDM {
public:
    OFDM(int fftSize, int cpLen)
        : fftSize_(fftSize), cpLen_(cpLen) {}

    std::vector<Complex> ifft(
        const std::vector<Complex>& freq
    ) {
        std::vector<Complex> time(fftSize_);

        for (int n = 0; n < fftSize_; ++n) {
            Complex sum = 0;

            for (int k = 0; k < fftSize_; ++k) {
                double angle = 2.0 * PI * k * n / fftSize_;
                sum += freq[k] * std::exp(Complex(0, angle));
            }

            time[n] = sum / static_cast<double>(fftSize_);
        }

        return time;
    }

    std::vector<Complex> fft(
        const std::vector<Complex>& time
    ) {
        std::vector<Complex> freq(fftSize_);

        for (int k = 0; k < fftSize_; ++k) {
            Complex sum = 0;

            for (int n = 0; n < fftSize_; ++n) {
                double angle = -2.0 * PI * k * n / fftSize_;
                sum += time[n] * std::exp(Complex(0, angle));
            }

            freq[k] = sum;
        }

        return freq;
    }

    std::vector<Complex> modulate(
        const std::vector<Complex>& symbols
    ) {
        auto timeSignal = ifft(symbols);

        std::vector<Complex> withCP;

        for (int i = fftSize_ - cpLen_; i < fftSize_; ++i) {
            withCP.push_back(timeSignal[i]);
        }

        withCP.insert(
            withCP.end(),
            timeSignal.begin(),
            timeSignal.end()
        );

        return withCP;
    }

    std::vector<Complex> demodulate(
        const std::vector<Complex>& signal
    ) {
        std::vector<Complex> noCP(
            signal.begin() + cpLen_,
            signal.end()
        );

        return fft(noCP);
    }

private:
    int fftSize_;
    int cpLen_;
};

class Channel {
public:
    static std::vector<Complex> addAWGN(
        const std::vector<Complex>& signal,
        double snrDb
    ) {
        std::default_random_engine gen;
        std::normal_distribution<double> dist(0.0, 1.0);

        double snr = std::pow(10.0, snrDb / 10.0);
        double noisePower = 1.0 / snr;

        std::vector<Complex> noisy;

        for (const auto& s : signal) {
            double nr = dist(gen) * std::sqrt(noisePower / 2.0);
            double ni = dist(gen) * std::sqrt(noisePower / 2.0);

            noisy.emplace_back(
                s.real() + nr,
                s.imag() + ni
            );
        }

        return noisy;
    }
};

int main() {
    constexpr int FFT_SIZE = 64;
    constexpr int CP_LEN = 16;
    constexpr int NUM_BITS = FFT_SIZE * 2;

    std::vector<int> bits(NUM_BITS);

    std::default_random_engine gen;
    std::uniform_int_distribution<int> bitDist(0, 1);

    for (auto& b : bits) {
        b = bitDist(gen);
    }

    auto qpskSymbols = QPSK::modulate(bits);

    OFDM ofdm(FFT_SIZE, CP_LEN);

    auto txSignal = ofdm.modulate(qpskSymbols);

    auto rxSignal = Channel::addAWGN(txSignal, 20.0);

    auto rxSymbols = ofdm.demodulate(rxSignal);

    auto recoveredBits = QPSK::demodulate(rxSymbols);

    int bitErrors = 0;

    for (size_t i = 0; i < bits.size(); ++i) {
        if (bits[i] != recoveredBits[i]) {
            bitErrors++;
        }
    }

    double ber = static_cast<double>(bitErrors)
                / static_cast<double>(bits.size());

    std::cout << "===== OFDM PHY Simulator =====" << std::endl;
    std::cout << "FFT Size: " << FFT_SIZE << std::endl;
    std::cout << "Cyclic Prefix: " << CP_LEN << std::endl;
    std::cout << "SNR(dB): 20" << std::endl;
    std::cout << "Bit Errors: " << bitErrors << std::endl;
    std::cout << "BER: " << ber << std::endl;

    return 0;
}
