#include <stdint.h>
#include <math.h>

typedef  struct sarcophagus
{
    float val;
    struct sarcophagus * next;
    
} sarcophagus_t;


float standardDeviation(sarcophagus_t * data, uint32_t * data_len) {
    sarcophagus_t * current = data;
    float sum, mean, deviations = 0.0;
    // Mean of the data
    while (current != NULL)
    {
        sum += current->val;
        current = current->next;
    }
    mean = sum / &data_len;

    // Square deviations
    while (current != NULL)
    {
        deviations += pow((current->val - mean), 2);
        current = current->next;
    }
    
    // Return Standard Deviation
    return sqrt(deviations / &data_len);
}