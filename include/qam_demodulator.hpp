#pragma once
#include <vector>
#include <complex>
#include "config.hpp"

class qamDemodulator {
public:
    explicit qamDemodulator(qamMode mode);
    

    std::vector<bool> qpsk_demodulation(std::vector<std::complex<double>>& symbol_sequence);
    std::vector<bool> qam16_demodulation(std::vector<std::complex<double>>& symbol_sequence);
    std::vector<bool> qam64_demodulation(std::vector<std::complex<double>>& symbol_sequence);

    std::vector<bool> demodulation(std::vector<std::complex<double>>& symbol_sequence);
    
private:
    size_t bits_per_symbol_;
    size_t mode_;
    std::vector<std::complex<double>> constellation_table_;

    double qam16_threshold = (2 / std::sqrt(10));

    double qam64_threshold_1 = (2 / std::sqrt(42));
    double qam64_threshold_2 = (4 / std::sqrt(42));
    double qam64_threshold_3 = (6 / std::sqrt(42));
};