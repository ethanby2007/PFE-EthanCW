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