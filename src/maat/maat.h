#ifdef MAAT_H
#define MAAT_H

#include <stdint.h>
#include <math.h>

#define SAMPLE_QUANTITY 10

typedef struct sarcophagus
{
    float val;
    struct sarcophagus *next;

} sarcophagus_t;

float movingAverage(sarcophagus_t **data, float new_value);

float weightedMovingAverage(sarcophagus_t **data, float new_value, float coef);

#endif // MAAT_H_
