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

double computePtP(waveformSample *samples, int n);
double computeDCoffset(waveformSample *samples, int n);
void countClipped(waveformSample *samples, int n, int *a_out, int *b_out, int *c_out);
#endif
