import numpy as np
import matplotlib.pyplot as plt
qpsk_ber, qpsk_gamma = np.loadtxt("results/QPSK.csv", delimiter=",", unpack=True)

qam16_ber, qam16_gamma = np.loadtxt("results/QAM16.csv", delimiter=",", unpack=True)

qam64_ber, qam64_gamma = np.loadtxt("results/QAM64.csv", delimiter=",", unpack=True)


plt.figure(figsize=(10, 6))
plt.plot(qpsk_gamma, qpsk_ber, 'ro-',label='QPSK симуляция')
plt.plot(qam16_gamma, qam16_ber, 'bo-',label='QAM16 симуляция')
plt.plot(qam64_gamma, qam64_ber, 'go-',label='QAM64 симуляция')
plt.xlabel("Значение дисперсии шума")
plt.ylabel("BER")
plt.title("Зависимость вероятности ошибки на бит от дисперсии шума")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()