#include <math.h>
#include "waveform.h"

double compute_rms(waveformSample *samples, int n) {
    double sum_sq = 0.0;

    for (int i = 0; i < n; i++) {
        sum_sq += (samples[i].phaseVoltageA * samples[i].phaseVoltageA);
    }
    return sqrt(sum_sq / n);

}

double computePtP(waveformSample *samples, int n) {
    double max_V = samples[0].phaseVoltageA;
    double min_V = samples[0].phaseVoltageA;

    for (int i = 1; i < n; i++) {
        if (samples[i].phaseVoltageA > max_V) max_V = samples[i].phaseVoltageA;
        if (samples[i].phaseVoltageA < min_V) min_V = samples[i].phaseVoltageA;
    }
    return max_V - min_V;
}

double computeDCoffset(waveformSample *samples, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (samples + i)->phaseVoltageA;
    }
    return sum / n;
}

void countClipped(waveformSample *samples, int n, int *a_out, int *b_out, int *c_out) {
    *a_out = 0;
    *b_out = 0;
    *c_out = 0;
    const double limit = 324.99;

    for (int i = 0; i < n; i++) {
        if (fabs(samples[i].phaseVoltageA) >= limit) {
            (*a_out)++;
        }
        if (fabs(samples[i].phaseVoltageB) >= limit) {
            (*b_out)++;
        }
        if (fabs(samples[i].phaseVoltageC) >= limit) {
            (*c_out)++;
        }
    }
}