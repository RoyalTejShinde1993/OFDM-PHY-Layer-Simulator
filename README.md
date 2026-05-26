# 🚀 OFDM PHY Layer Simulator (C++17/20/23/26)

![C++](https://img.shields.io/badge/C%2B%2B-17%20%7C%2020%20%7C%2023%20%7C%2026-blue)
![Build](https://img.shields.io/badge/Build-CMake-success)
![DSP](https://img.shields.io/badge/Wireless-OFDM-orange)
![PHY](https://img.shields.io/badge/PHY-Layer-red)
![License](https://img.shields.io/badge/License-MIT-green)

LTE/5G-inspired OFDM PHY Layer Simulator implemented in Modern C++.

This project simulates the internal signal-processing pipeline of modern wireless communication systems including:

* LTE PHY
* 5G NR PHY
* OFDM-based broadband systems
* Fixed Wireless Access (FWA)
* Wireless DSP pipelines

---

# 📡 Overview

This simulator demonstrates a simplified but production-inspired wireless baseband processing architecture.

The project implements:

* ✅ QPSK modulation/demodulation
* ✅ OFDM FFT/IFFT processing
* ✅ Cyclic Prefix handling
* ✅ AWGN wireless channel simulation
* ✅ BER (Bit Error Rate) analysis
* ✅ BER vs SNR visualization
* ✅ Wireless signal recovery
* ✅ Modern CMake build system
* ✅ Linux-based DSP development workflow
* ✅ C++17/20/23/26 compatibility

---

# 🧠 Why This Project Matters

Modern wireless systems rely heavily on:

* OFDM communication
* FFT/IFFT processing
* PHY-layer DSP pipelines
* BER optimization
* Channel estimation
* Synchronization
* MIMO systems
* Beamforming

This project demonstrates these concepts in a simplified but engineering-oriented implementation.

It serves as a strong learning platform for:

* wireless PHY engineering
* DSP software development
* LTE/5G systems
* communication systems research
* modem software development
* embedded wireless systems
* Linux/C++ DSP development

---

# 🏗️ PHY Layer Architecture

## 📤 Transmitter Pipeline

```text
Random Bits
      │
      ▼
QPSK Modulation
      │
      ▼
OFDM Subcarrier Mapping
      │
      ▼
IFFT
      │
      ▼
Cyclic Prefix Addition
      │
      ▼
Wireless Channel
```

---

## 📥 Receiver Pipeline

```text
Wireless Channel
      │
      ▼
Cyclic Prefix Removal
      │
      ▼
FFT
      │
      ▼
QPSK Demodulation
      │
      ▼
BER Calculation
```

---

# 📊 BER vs SNR Analysis

The simulator demonstrates the fundamental wireless communication principle:

> As Signal-to-Noise Ratio (SNR) increases, Bit Error Rate (BER) decreases.

This behavior is fundamental to:

* LTE
* 5G NR
* WiFi
* OFDM broadband systems

## 📈 Generated BER Curve

```text
BER decreases as SNR increases
Higher SNR → Better signal quality → Lower BER
```

---

# ⚙️ Core Components

## 1️⃣ QPSK Modulator

Responsible for:

* bit mapping
* constellation generation
* symbol conversion

Example:

```text
Bits → Complex Symbols
00 → (-1,-1)
01 → (-1,+1)
10 → (+1,-1)
11 → (+1,+1)
```

---

## 2️⃣ OFDM Processor

Implements:

* FFT
* IFFT
* subcarrier mapping
* cyclic prefix insertion/removal

Files:

```text
include/ofdm.hpp
src/main.cpp
```

---

## 3️⃣ Wireless Channel Simulator

Simulates:

* AWGN channel noise
* wireless impairments
* noisy transmission medium

Example:

```text
TX Signal + Noise → RX Signal
```

---

## 4️⃣ BER Analyzer

Calculates:

* bit recovery accuracy
* BER statistics
* communication quality metrics

Example Output:

```text
Bit Errors: 5
BER: 0.0390625
```

---

## 5️⃣ BER Plot Generator

Uses:

* Python
* matplotlib

Purpose:

* BER visualization
* SNR analysis
* PHY performance plotting

---

# 📂 Project Structure

```text
OFDM-PHY-Layer-Simulator/
│
├── build/
│
├── docs/
│   └── architecture.md
│
├── include/
│   ├── channel.hpp
│   ├── ofdm.hpp
│   └── qpsk.hpp
│
├── scripts/
│   └── plot_ber.py
│
├── src/
│   └── main.cpp
│
├── tests/
│
├── CMakeLists.txt
├── LICENSE
├── README.md
└── ber_curve.png
```

---

# 🛠️ Build Instructions

## 📦 Requirements

Install:

* GCC 13+
* CMake 3.15+
* FFTW3
* Python3
* matplotlib

---

# 🔧 Install Dependencies

## Ubuntu / Debian

```bash
sudo apt update

sudo apt install -y \
    build-essential \
    cmake \
    g++ \
    fftw3-dev \
    python3 \
    python3-pip
```

---

# 📈 Install matplotlib

Example troubleshooting session:

```bash
python3 scripts/plot_ber.py
```

Expected Error:

```text
ModuleNotFoundError: No module named 'matplotlib'
```

Install:

```bash
python3 -m pip install matplotlib
```

Verify:

```bash
python3 -c "import matplotlib; print(matplotlib.__version__)"
```

Expected:

```text
3.10.9
```

---

# 🔨 Build Project

## Step 1 — Clone Repository

```bash
git clone <repository-url>

cd OFDM-PHY-Layer-Simulator
```

---

## Step 2 — Create Build Directory

```bash
mkdir build
cd build
```

---

## Step 3 — Generate Build Files

```bash
cmake ..
```

Expected Output:

```text
-- Configuring done
-- Generating done
-- Build files have been written to:
```

---

## Step 4 — Compile

```bash
make -j$(nproc)
```

Expected Output:

```text
[100%] Built target ofdm_phy_simulator
```

---

# ▶️ Run Simulator

```bash
./ofdm_phy_simulator
```

---

# 🖥️ Example Runtime Output

```text
===== OFDM PHY Simulator =====
FFT Size: 64
Cyclic Prefix: 16
SNR(dB): 20
Bit Errors: 5
BER: 0.0390625
```

---

# 📈 Generate BER Plot

From project root:

```bash
python3 scripts/plot_ber.py
```

Expected:

```text
BER curve saved
```

Generated file:

```text
ber_curve.png
```

---

# 🌐 View BER Plot in Browser

Codespaces/devcontainers may not support:

```bash
xdg-open
```

Alternative:

```bash
python3 -m http.server 8080
```

Open:

```text
http://localhost:8080/ber_curve.png
```

---

# 🧪 Communication Concepts Demonstrated

| Technology          | Simulated |
| ------------------- | --------- |
| OFDM                | ✅         |
| FFT/IFFT            | ✅         |
| QPSK                | ✅         |
| BER Analysis        | ✅         |
| AWGN Channel        | ✅         |
| Wireless PHY        | ✅         |
| DSP Pipelines       | ✅         |
| Linux Build Systems | ✅         |
| Modern C++          | ✅         |

---

# 🎯 Skills Demonstrated

* Modern C++17/20/23/26
* DSP fundamentals
* OFDM systems
* Wireless communications
* PHY-layer simulation
* FFT/IFFT processing
* BER analysis
* Linux systems programming
* Numerical computing
* CMake build systems
* Python plotting
* Wireless signal processing

---

# 🚀 Future Enhancements

## Planned Features

### ✅ Multipath Fading

Implement:

* Rayleigh fading
* delay spread
* multipath taps

---

### ✅ Channel Estimation

Implement:

* pilot insertion
* LS estimator
* MMSE equalizer

---

### ✅ Synchronization

Implement:

* timing synchronization
* CFO estimation
* Schmidl-Cox algorithm

---

### ✅ MIMO Support

Potential features:

* 2x2 MIMO
* Alamouti coding
* diversity gain

---

### ✅ SDR Integration

Potential integrations:

* GNU Radio
* USRP
* BladeRF
* LimeSDR

---

# 📊 Performance Characteristics

| Feature      | Current    |
| ------------ | ---------- |
| FFT Size     | 64         |
| CP Length    | 16         |
| Modulation   | QPSK       |
| Channel      | AWGN       |
| BER Analysis | ✅          |
| Plotting     | matplotlib |
| Build System | CMake      |
| Language     | C++17+     |

---

# 🧪 Testing Commands

## Rebuild From Scratch

```bash
cd /workspaces/OFDM-PHY-Layer-Simulator

rm -rf build

mkdir build
cd build

cmake ..
make -j$(nproc)
```

---

## Run Simulator

```bash
./ofdm_phy_simulator
```

---

## Verify Binary Exists

```bash
ls -l ./ofdm_phy_simulator
```

---

# 🏗️ Production-Level Concepts Demonstrated

| Concept           | Demonstrated |
| ----------------- | ------------ |
| Wireless PHY      | ✅            |
| OFDM Processing   | ✅            |
| BER Evaluation    | ✅            |
| FFT/IFFT DSP      | ✅            |
| Wireless Channels | ✅            |
| Signal Recovery   | ✅            |
| Linux Toolchain   | ✅            |
| Modern C++        | ✅            |

---

# 🔧 GitHub Actions CI

Create:

```text
.github/workflows/build.yml
```

Example:

```yaml
name: C++ Build

on:
  push:
  pull_request:

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v4

    - name: Install Dependencies
      run: |
        sudo apt-get update
        sudo apt-get install -y cmake g++ fftw3-dev

    - name: Build Project
      run: |
        mkdir build
        cd build
        cmake ..
        make -j4
```

---

# 👨‍💻 Author

Royal Tej Shinde

Built using:

* Modern C++
* DSP concepts
* Wireless communication principles
* Linux systems programming
* CMake
* PHY-layer engineering concepts

---

# 📜 License

MIT License

---

# ⭐ Star This Project

If you found this project useful for learning:

* OFDM
* LTE/5G PHY
* DSP
* wireless communications
* C++ systems programming
* BER analysis
* PHY simulation

consider giving it a ⭐ on GitHub.

---

# 📌 About

Production-style OFDM PHY Layer Simulator built using Modern C++17/20/23/26 implementing OFDM signal processing, QPSK modulation, FFT/IFFT pipelines, AWGN wireless channel simulation, and BER analysis for LTE/5G-inspired wireless communication systems.

---

# 🏷️ Topics

```text
cpp cpp17 cpp20 cpp23 cpp26
ofdm
lte
5g
phy-layer
wireless
wireless-communications
dsp
signal-processing
fft
ifft
ber
qpsk
awgn
linux
cmake
matplotlib
telecommunications
modem
baseband
```
