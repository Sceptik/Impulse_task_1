#pragma once
#include <vector>
#include <complex>
#include "config.hpp"

class qamModulator {
public:
    explicit qamModulator(qamMode mode);

    std::vector<std::complex<double>> modulation(std::vector<bool>& bit_sequence);
    
private:
    size_t bits_per_symbol_;
    std::vector<std::complex<double>> constellation_table_;

};