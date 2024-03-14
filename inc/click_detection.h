#ifndef CLICK_DETECTION_H
#define CLICK_DETECTION_H

#include <stdbool.h>

#define LOWER_NOISE 100
#define UPPER_NOISE 3000
#define SHORT_LONG_CLICK_TRESHOLD 800
#define SHORT_CLICK_TIME_OUT 50


typedef enum{
    NOISE,
    CLICK,
    STAGE,
} ClickStates;

typedef enum{
    INITIAL,
    ONE_CLICK,
    DOUBLE_CLICK,
    LONG_CLICK
} ClickTypes;

typedef struct{
    unsigned int time_pressed;
    unsigned int time_released;
    unsigned char click_counter;
    ClickStates state;
} ClickData;

/**
 * @brief Function used to init the  click detection module.
 * 
 * @return ClickData 
 */
ClickData initClickDetection(void);

void risingEdge(ClickData *click_data);
void fallingEdge(ClickData *click_data);
void incrementPressedTime(ClickData *click_data);
void incrementReleasedTime(ClickData *click_data);
ClickTypes proccesClickData(ClickData *click_data, bool curr_pin_state);


#endif // CLICK_DETECTION_H