
# OFDM PHY Architecture

TX:
Bits -> QPSK -> OFDM Mapper -> IFFT -> CP Addition -> Channel

RX:
Channel -> Synchronization -> CP Removal -> FFT
-> Equalization -> QPSK Demod -> BER

Future Enhancements:
- LS/MMSE estimation
- CFO correction
- MIMO
- Beamforming
- SDR integration
