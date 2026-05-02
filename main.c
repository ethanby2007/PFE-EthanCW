#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"

int load_csv(const char *file_name, waveformSample *samples, int n);
double compute_rms(waveformSample *samples, int n);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Error: Missing input filename\n");
        printf("Usage: %s <filename.csv>\n", argv[0]);
        return 1;
    }

    int num_rows = 1000;

    waveformSample *samples = malloc(num_rows * sizeof(waveformSample));

    if (samples == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    if (load_csv("power_quality_log.csv", samples, num_rows)) {
        printf("Successfully loaded %d samples\n", num_rows);

        double v_rms_a = compute_rms(samples, num_rows);
        printf("Phase A RMS Voltage: %.2f V\n", v_rms_a);

        printf("First sample - time: %.4f, Phase A: %.2fV\n", samples[0].tStamp, samples[0].phaseVoltageA);
        printf("Second sample - time: %.4f, Phase A: %.2fV\n", samples[1].tStamp, samples[1].phaseVoltageA);

        double v_pp_a = computePtP(samples, num_rows);
        double v_dc_a = computeDCoffset(samples, num_rows);

        printf("Phase A peak to peak: %.2f V\n", v_pp_a);
        printf("Phase A DC offset: %.4f V\n", v_dc_a);

    } else {
        printf("Failed to load file\n");
    }
    free(samples);

    return 0;
}
