#include "qam_demodulator.hpp"
#include "utils.hpp"

qamDemodulator::qamDemodulator(qamMode mode){
    mode_ = static_cast<size_t>(mode);
    bits_per_symbol_ = static_cast<size_t>(std::log2(static_cast<size_t>(mode)));
    constellation_table_ = generate_constellation_table(static_cast<size_t>(mode));
}

std::vector<bool> qamDemodulator::demodulation(std::vector<std::complex<double>>& symbol_sequence) {
    
    switch (mode_) {
        case 4: return qpsk_demodulation(symbol_sequence);
        case 16: return qam16_demodulation(symbol_sequence);
        case 64: return qam64_demodulation(symbol_sequence);
    }
}

std::vector<bool> qamDemodulator::qpsk_demodulation(std::vector<std::complex<double>>& symbol_sequence){
    size_t sequence_size = symbol_sequence.size();

    std::vector<bool> demodulated;

    for(auto symbol : symbol_sequence){

        if(symbol.real() > 0){
            demodulated.push_back(0);
        } else {
            demodulated.push_back(1);
        }

        if(symbol.imag() > 0){
            demodulated.push_back(0);
        } else {
            demodulated.push_back(1);
        }
    }

    return demodulated;
}

std::vector<bool> qamDemodulator::qam16_demodulation(std::vector<std::complex<double>>& symbol_sequence){
    size_t sequence_size = symbol_sequence.size();

    std::vector<bool> demodulated;

    for(auto symbol : symbol_sequence){

        if(symbol.real() > 0){
            demodulated.push_back(0);
        } else {
            demodulated.push_back(1);
        }

        if(symbol.imag() > 0){
            demodulated.push_back(0);
        } else {
            demodulated.push_back(1);
        }

        if((symbol.real() > qam16_threshold) || (symbol.real() < -qam16_threshold)){
            demodulated.push_back(1);
        } else {
            demodulated.push_back(0);
        }

        if((symbol.imag() > qam16_threshold) || (symbol.imag() < -qam16_threshold)){
            demodulated.push_back(1);
        } else {
            demodulated.push_back(0);
        }
    }

    return demodulated;
}

std::vector<bool> qamDemodulator::qam64_demodulation(std::vector<std::complex<double>>& symbol_sequence) {
    std::vector<bool> demodulated;
    demodulated.reserve(symbol_sequence.size() * 6);

    for (const auto& symbol : symbol_sequence) {
        bool i_sign = (symbol.real() > 0) ? 0 : 1;
        
        bool i_amp1, i_amp2;
        if ((symbol.real() > qam64_threshold_3) || (symbol.real() < -qam64_threshold_3)) {
            i_amp1 = 1; i_amp2 = 1;
        } else if ((symbol.real() > qam64_threshold_2) || (symbol.real() < -qam64_threshold_2)) {
            i_amp1 = 1; i_amp2 = 0;
        } else if ((symbol.real() > qam64_threshold_1) || (symbol.real() < -qam64_threshold_1)) {
            i_amp1 = 0; i_amp2 = 0;
        } else {
            i_amp1 = 0; i_amp2 = 1;
        }

        bool q_sign = (symbol.imag() > 0) ? 0 : 1;
        
        bool q_amp1, q_amp2;
        if ((symbol.imag() > qam64_threshold_3) || (symbol.imag() < -qam64_threshold_3)) {
            q_amp1 = 1; q_amp2 = 1; 
        } else if ((symbol.imag() > qam64_threshold_2) || (symbol.imag() < -qam64_threshold_2)) {
            q_amp1 = 1; q_amp2 = 0; 
        } else if ((symbol.imag() > qam64_threshold_1) || (symbol.imag() < -qam64_threshold_1)) {
            q_amp1 = 0; q_amp2 = 0; 
        } else {
            q_amp1 = 0; q_amp2 = 1; 
        }

        demodulated.push_back(i_sign); 
        demodulated.push_back(q_sign); 
        demodulated.push_back(i_amp1); 
        demodulated.push_back(q_amp1); 
        demodulated.push_back(i_amp2); 
        demodulated.push_back(q_amp2); 
    }

    return demodulated;
}