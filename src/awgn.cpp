#include "awgn.hpp"


std::vector<std::complex<double>> AWGN::add_noise(std::vector<std::complex<double>> symbol_sequence, 
                                                    double noise_variance){


    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::normal_distribution<double> dist(0.0, std::sqrt(noise_variance));


    for (auto &symbol : symbol_sequence){
        symbol += std::complex<double>(dist(gen), dist(gen));
    }

    return symbol_sequence;
}