#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"

int load_csv(const char *file_name, waveformSample *samples, int n);

int main() {
    int num_rows = 1000;

    waveformSample *samples = malloc(num_rows * sizeof(waveformSample));

    if (samples == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    if (load_csv("power_quality_log.csv", samples, num_rows)) {
        printf("Successfully loaded %d samples\n", num_rows);

        printf("First sample - time: %.4f, Phase A: %.2fV\n", samples[0].tStamp, samples[0].phaseVoltageA);
        printf("Second sample - time: %.4f, Phase A: %.2fV\n", samples[1].tStamp, samples[1].phaseVoltageA);

    } else {
        printf("Failed to load file\n");
    }
    free(samples);

    return 0;
}
