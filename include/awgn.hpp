#pragma once
#include <vector>
#include <complex>
#include <random>

class AWGN {
public:
    static std::vector<std::complex<double>> add_noise(std::vector<std::complex<double>> symbol_sequence, 
                                                        double noise_variance);
};