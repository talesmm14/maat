#include "maat.h"


float standardDeviation(sarcophagus_t *data, uint32_t *data_len)
{
    sarcophagus_t *current = data;
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
    return sqrt(deviations / &data_len - 1);
}

float movingAverage(sarcophagus_t **data, float new_value)
{
    sarcophagus_t *new;
    sarcophagus_t *aux;
    uint32_t len = 0;
    float sum;

    if (*data != NULL)
    {
        new->next = data;
        new->val = new_value;

        while (new != NULL)
        {
            len+=1;
            if (len == SAMPLE_QUANTITY){
                aux = new->next;
                aux = NULL;
                new->next = NULL;
            }
            sum += new->val;
            new = new->next;
        }

        return sum / len;
    }

    return 0;
}

float weightedMovingAverage(sarcophagus_t **data, float new_value, float coef)
{
    sarcophagus_t *new;
    sarcophagus_t *aux;
    uint32_t len = 0, devisor = 0;
    float sum;

    if (*data != NULL)
    {
        new->next = data;
        new->val = new_value;

        while (new != NULL)
        {
            len+=1;
            if (len == SAMPLE_QUANTITY){
                aux = new->next;
                aux = NULL;
                new->next = NULL;
            }
            sum += len * new->val;
            new = new->next;
        }

        devisor = ((1 + SAMPLE_QUANTITY) * SAMPLE_QUANTITY) / 2;

        return sum / devisor;
    }

    return 0;
}
