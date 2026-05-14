#include <iostream>
#include <fstream>

#include "config.hpp"
#include "qam_modulator.hpp"
#include "qam_demodulator.hpp"
#include "awgn.hpp"
#include "utils.hpp"

double BER_calculate(std::vector<bool>& original, std::vector<bool>& reqv){
    int total_num_bits = 0;
    int error_bit = 0;
    for(int i = 0; i < original.size(); i++){
        error_bit += original[i] ^ reqv[i];
        total_num_bits++;
    }
    double BER = static_cast<double>(error_bit) / total_num_bits;
    return BER;
}

int main(){
    std::string mod_type;
    printf("Aviable modulations: QPSK, QAM16, QAM64 \n");
    printf("Choose modulation:");
    std::cin >> mod_type;

    qamMode mode;
    if(mod_type == "QPSK" || mod_type == "qpsk"){
        mode = qamMode::QPSK;
    }
    else if(mod_type == "QAM16" || mod_type == "qam16"){
        mode = qamMode::QAM16;
    }
    else if(mod_type == "QAM64" || mod_type == "qam64"){
        mode = qamMode::QAM64;
    }
    else{
        printf("ERROR: No such modulation");
        return 1;
    }

    qamModulator modulator(mode);
    qamDemodulator demodulator(mode);

    int num_iterations = 1000;

    std::vector<double> noise_variance = {2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.01, 0.005, 0.0001, 0};
    std::vector<double> ber;
    for(double variance : noise_variance){
        double total_ber = 0;
        for(int i = 0; i < num_iterations; i++){
            auto bit_sequence = generate_bits(num_bits);

            auto modulated = modulator.modulation(bit_sequence);

            auto noise = AWGN::add_noise(modulated, variance);

            auto demodulated = demodulator.demodulation(noise);

            double ber = BER_calculate(bit_sequence, demodulated);

            total_ber+= ber;
        }

        ber.push_back(total_ber / num_iterations);
    }

    std::string filename = "results/" + mod_type + ".csv";
    FILE* f = fopen(filename.c_str(), "w");
    for (int i = 0; i < noise_variance.size(); i++) {
        fprintf(f, "%.6f, %.4f\n", ber[i], noise_variance[i]);
    }
    fclose(f);
}