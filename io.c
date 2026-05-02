#include <stdio.h>
#include "waveform.h"
#include "io.h"

int load_csv(const char *filename, waveformSample *samples, int n) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return 0;
    }

    char header[1024];
    fgets(header, sizeof(header), file);

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &samples[i].tStamp,
            &samples[i].phaseVoltageA,
            &samples[i].phaseVoltageB,
            &samples[i].phaseVoltageC,
            &samples[i].lineCurrent,
            &samples[i].freq,
            &samples[i].powerFactor,
            &samples[i].thdPercent) !=8) {
        break;
        }
    }
    fclose(file);
    return 1;
}

void writeResults(const char *filename, double rmsA, double rmsB, double rmsC,  double vppA, double dcA, int clipsA) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) return;

    fprintf(f, "Phase A RMS voltage: %.2f V\n", rmsA);
    fprintf(f, "Phase B RMS voltage: %.2f V\n", rmsB);
    fprintf(f, "Phase C RMS voltage: %.2f V\n", rmsC);
    fprintf(f, "Phase A Peak to peak voltage: %.2f V\n", vppA);
    fprintf(f, "Phase A DC offset: %.4f V\n", dcA);
    fprintf(f, "Total clipped samples: %d\n", clipsA);

    if (rmsA >= 207.0 && rmsA <= 253.0) {
        fprintf(f, "Status: Compliant\n");
    } else {
        fprintf(f, "Status: Non-Compliant\n");
    }

    fclose(f);

}