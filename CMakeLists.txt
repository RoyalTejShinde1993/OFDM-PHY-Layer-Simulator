
cmake_minimum_required(VERSION 3.15)
project(ofdm_phy_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ofdm_phy_simulator
    src/main.cpp
)

find_library(FFTW_LIB fftw3)

if(FFTW_LIB)
    target_link_libraries(ofdm_phy_simulator PRIVATE ${FFTW_LIB})
endif()
