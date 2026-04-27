//
// Created by e2-benyehuda on 27/04/2026.
//

#ifndef UNTITLED2_WAVEFORM_H
#define UNTITLED2_WAVEFORM_H


#include <stdint.h>

typedef struct {
    double tStamp;
    double phaseVoltageA;
    double phaseVoltageB;
    double phaseVoltageC;
    double lineCurrent;
    double freq;
    double powerFactor;
    double thdPercent;

} waveformSample;
#endif //UNTITLED2_WAVEFORM_H
