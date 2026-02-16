#pragma once
#include <cstdint>
#include <vector>
#include "df.h"

class DeepFilterNetProcessor {
public:
    DeepFilterNetProcessor(uint32_t sampleRate = 48000);
    ~DeepFilterNetProcessor();

    bool initialize(); 
    void setAttenLim(float limitDB);
    
    void processFrame(const float* input, float* output);
    bool isReady() const { return state != nullptr; }

private:
    DFState* state = nullptr;
    uint32_t sampleRate = 48000;
};