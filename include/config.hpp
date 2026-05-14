#pragma once
#include <cstddef>

enum class qamMode{ 
    QPSK = 4, 
    QAM16 = 16, 
    QAM64 = 64 
};

constexpr size_t num_bits = 960;