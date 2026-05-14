#include "utils.hpp"

std::vector<bool> generate_bits(size_t total_bits) {

    std::vector<bool> bits(total_bits);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (size_t i = 0; i < bits.size(); ++i) {
        bits[i] = static_cast<bool>(dis(gen));
    }

    return bits;
}

std::vector<std::complex<double>> generate_constellation_table(size_t constellation_size) {
    switch (constellation_size) {
        case 4:  return set_QPSK_table();
        case 16: return set_QAM16_table();
        case 64: return set_QAM64_table();
    }
}

std::vector<std::complex<double>> set_QPSK_table()
{
    std::vector<std::complex<double>> qpsk_constellation_table(4);

    qpsk_constellation_table[0] = std::complex(qpsk_level, qpsk_level);
    qpsk_constellation_table[1] = std::complex(qpsk_level, -qpsk_level);
    qpsk_constellation_table[2] = std::complex(-qpsk_level, qpsk_level);
    qpsk_constellation_table[3] = std::complex(-qpsk_level, -qpsk_level);

    return qpsk_constellation_table;
}

std::vector<std::complex<double>> set_QAM16_table()
{
    std::vector<std::complex<double>> qam_constellation_table(16);

    qam_constellation_table[0]  = std::complex(qam16_level_1, qam16_level_1);
    qam_constellation_table[1]  = std::complex(qam16_level_1, qam16_level_2);
    qam_constellation_table[2]  = std::complex(qam16_level_2, qam16_level_1);
    qam_constellation_table[3]  = std::complex(qam16_level_2, qam16_level_2);
    qam_constellation_table[4]  = std::complex(qam16_level_1, - qam16_level_1);
    qam_constellation_table[5]  = std::complex(qam16_level_1, - qam16_level_2);
    qam_constellation_table[6]  = std::complex(qam16_level_2, - qam16_level_1);
    qam_constellation_table[7]  = std::complex(qam16_level_2, - qam16_level_2);
    qam_constellation_table[8]  = std::complex(-qam16_level_1, qam16_level_1);
    qam_constellation_table[9]  = std::complex(-qam16_level_1, qam16_level_2);
    qam_constellation_table[10] = std::complex(-qam16_level_2, qam16_level_1);
    qam_constellation_table[11] = std::complex(-qam16_level_2, qam16_level_2);
    qam_constellation_table[12] = std::complex(-qam16_level_1, - qam16_level_1);
    qam_constellation_table[13] = std::complex(-qam16_level_1, - qam16_level_2);
    qam_constellation_table[14] = std::complex(-qam16_level_2, - qam16_level_1);
    qam_constellation_table[15] = std::complex(-qam16_level_2, - qam16_level_2);

    return qam_constellation_table;
}

std::vector<std::complex<double>> set_QAM64_table()
{
    std::vector<std::complex<double>> qam64_constellation_table(64);

    qam64_constellation_table[0]  = std::complex(qam64_level_2,  qam64_level_2);
    qam64_constellation_table[1]  = std::complex(qam64_level_2,  qam64_level_1);
    qam64_constellation_table[2]  = std::complex(qam64_level_1,  qam64_level_2);
    qam64_constellation_table[3]  = std::complex(qam64_level_1,  qam64_level_1);
    qam64_constellation_table[4]  = std::complex(qam64_level_2,  qam64_level_3);
    qam64_constellation_table[5]  = std::complex(qam64_level_2,  qam64_level_4);
    qam64_constellation_table[6]  = std::complex(qam64_level_1,  qam64_level_3);
    qam64_constellation_table[7]  = std::complex(qam64_level_1,  qam64_level_4);
    qam64_constellation_table[8]  = std::complex(qam64_level_3,  qam64_level_2);
    qam64_constellation_table[9]  = std::complex(qam64_level_3,  qam64_level_1);
    qam64_constellation_table[10] = std::complex(qam64_level_4,  qam64_level_2);
    qam64_constellation_table[11] = std::complex(qam64_level_4,  qam64_level_1);
    qam64_constellation_table[12] = std::complex(qam64_level_3,  qam64_level_3);
    qam64_constellation_table[13] = std::complex(qam64_level_3,  qam64_level_4);
    qam64_constellation_table[14] = std::complex(qam64_level_4,  qam64_level_3);
    qam64_constellation_table[15] = std::complex(qam64_level_4,  qam64_level_4);

    qam64_constellation_table[16] = std::complex(qam64_level_2, -qam64_level_2);
    qam64_constellation_table[17] = std::complex(qam64_level_2, -qam64_level_1);
    qam64_constellation_table[18] = std::complex(qam64_level_1, -qam64_level_2);
    qam64_constellation_table[19] = std::complex(qam64_level_1, -qam64_level_1);
    qam64_constellation_table[20] = std::complex(qam64_level_2, -qam64_level_3);
    qam64_constellation_table[21] = std::complex(qam64_level_2, -qam64_level_4);
    qam64_constellation_table[22] = std::complex(qam64_level_1, -qam64_level_3);
    qam64_constellation_table[23] = std::complex(qam64_level_1, -qam64_level_4);
    qam64_constellation_table[24] = std::complex(qam64_level_3, -qam64_level_2);
    qam64_constellation_table[25] = std::complex(qam64_level_3, -qam64_level_1);
    qam64_constellation_table[26] = std::complex(qam64_level_4, -qam64_level_2);
    qam64_constellation_table[27] = std::complex(qam64_level_4, -qam64_level_1);
    qam64_constellation_table[28] = std::complex(qam64_level_3, -qam64_level_3);
    qam64_constellation_table[29] = std::complex(qam64_level_3, -qam64_level_4);
    qam64_constellation_table[30] = std::complex(qam64_level_4, -qam64_level_3);
    qam64_constellation_table[31] = std::complex(qam64_level_4, -qam64_level_4);

    qam64_constellation_table[32] = std::complex(-qam64_level_2,  qam64_level_2);
    qam64_constellation_table[33] = std::complex(-qam64_level_2,  qam64_level_1);
    qam64_constellation_table[34] = std::complex(-qam64_level_1,  qam64_level_2);
    qam64_constellation_table[35] = std::complex(-qam64_level_1,  qam64_level_1);
    qam64_constellation_table[36] = std::complex(-qam64_level_2,  qam64_level_3);
    qam64_constellation_table[37] = std::complex(-qam64_level_2,  qam64_level_4);
    qam64_constellation_table[38] = std::complex(-qam64_level_1,  qam64_level_3);
    qam64_constellation_table[39] = std::complex(-qam64_level_1,  qam64_level_4);
    qam64_constellation_table[40] = std::complex(-qam64_level_3,  qam64_level_2);
    qam64_constellation_table[41] = std::complex(-qam64_level_3,  qam64_level_1);
    qam64_constellation_table[42] = std::complex(-qam64_level_4,  qam64_level_2);
    qam64_constellation_table[43] = std::complex(-qam64_level_4,  qam64_level_1);
    qam64_constellation_table[44] = std::complex(-qam64_level_3,  qam64_level_3);
    qam64_constellation_table[45] = std::complex(-qam64_level_3,  qam64_level_4);
    qam64_constellation_table[46] = std::complex(-qam64_level_4,  qam64_level_3);
    qam64_constellation_table[47] = std::complex(-qam64_level_4,  qam64_level_4);

    qam64_constellation_table[48] = std::complex(-qam64_level_2, -qam64_level_2);
    qam64_constellation_table[49] = std::complex(-qam64_level_2, -qam64_level_1);
    qam64_constellation_table[50] = std::complex(-qam64_level_1, -qam64_level_2);
    qam64_constellation_table[51] = std::complex(-qam64_level_1, -qam64_level_1);
    qam64_constellation_table[52] = std::complex(-qam64_level_2, -qam64_level_3);
    qam64_constellation_table[53] = std::complex(-qam64_level_2, -qam64_level_4);
    qam64_constellation_table[54] = std::complex(-qam64_level_1, -qam64_level_3);
    qam64_constellation_table[55] = std::complex(-qam64_level_1, -qam64_level_4);
    qam64_constellation_table[56] = std::complex(-qam64_level_3, -qam64_level_2);
    qam64_constellation_table[57] = std::complex(-qam64_level_3, -qam64_level_1);
    qam64_constellation_table[58] = std::complex(-qam64_level_4, -qam64_level_2);
    qam64_constellation_table[59] = std::complex(-qam64_level_4, -qam64_level_1);
    qam64_constellation_table[60] = std::complex(-qam64_level_3, -qam64_level_3);
    qam64_constellation_table[61] = std::complex(-qam64_level_3, -qam64_level_4);
    qam64_constellation_table[62] = std::complex(-qam64_level_4, -qam64_level_3);
    qam64_constellation_table[63] = std::complex(-qam64_level_4, -qam64_level_4);

    return qam64_constellation_table;
}
