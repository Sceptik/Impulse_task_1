#pragma once
#include <vector>
#include <complex>
#include <random>
#include "config.hpp"

std::vector<std::complex<double>> generate_constellation_table(size_t constellation_size);

std::vector<std::complex<double>> set_QPSK_table();
std::vector<std::complex<double>> set_QAM16_table();
std::vector<std::complex<double>> set_QAM64_table();


std::vector<bool> generate_bits(size_t total_bits);

const double qpsk_level = 1.0 / std::sqrt(2);

const double qam16_level_1 = 1.0 / std::sqrt(10);
const double qam16_level_2 = 3.0 / std::sqrt(10);

const double qam64_level_1 = 1.0 / std::sqrt(42);
const double qam64_level_2 = 3.0 / std::sqrt(42);
const double qam64_level_3 = 5.0 / std::sqrt(42);
const double qam64_level_4 = 7.0 / std::sqrt(42);