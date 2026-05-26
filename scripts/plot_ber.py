
import matplotlib.pyplot as plt

snr = [0, 5, 10, 15, 20]
ber = [0.25, 0.10, 0.02, 0.005, 0.0001]

plt.plot(snr, ber, marker='o')
plt.xlabel("SNR (dB)")
plt.ylabel("BER")
plt.title("BER vs SNR")
plt.grid(True)
plt.savefig("ber_curve.png")
print("BER curve saved")
