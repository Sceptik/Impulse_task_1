#include "qam_modulator.hpp"
#include "utils.hpp"

qamModulator::qamModulator(qamMode mode){
    bits_per_symbol_ = static_cast<size_t>(std::log2(static_cast<size_t>(mode)));
    constellation_table_ = generate_constellation_table(static_cast<size_t>(mode));
}

std::vector<std::complex<double>> qamModulator::modulation(std::vector<bool>& bit_sequence){
    std::vector<std::complex<double>> modulated;

    for(int start = 0; start < bit_sequence.size(); start += bits_per_symbol_){
        size_t idx = 0;
        for(int bit = 0; bit < bits_per_symbol_; bit++){
            idx = (idx << 1) | (bit_sequence[start + bit] ? 1 : 0);
        }

        modulated.push_back(constellation_table_[idx]);

    }

    return modulated;
}
