#include <math.h>
#include "waveform.h"

double compute_rms(waveformSample *samples, int n) {
    double sum_sq = 0.0;

    for (int i = 0; i < n; i++) {
        sum_sq += (samples[i].phaseVoltageA * samples[i].phaseVoltageA);
    }
    return sqrt(sum_sq / n);

}