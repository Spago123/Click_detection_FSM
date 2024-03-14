#include <stdbool.h>
#include <stdio.h>
#include "inc/click_detection.h"

void printClick(ClickTypes click_types){
    switch (click_types){
        case INITIAL:
            printf("NO CLICK\n");
            break;
        case ONE_CLICK:
            printf("ONE CLICK\n");
            break;
        case DOUBLE_CLICK:
            printf("DOUBLE CLICK\n");
            break;
        case LONG_CLICK:
            printf("LONG CLICK\n");
            break;
    }
}
void prinClickData(ClickData *click_data){
    printf(" Time pressed: %d, \n time released: %d, \n click counter: %d, \n", click_data->time_pressed, 
    click_data->time_released, click_data->click_counter);
    switch (click_data->state){
        case NOISE:
            printf(" state: NOISE\n");
            break;
        case CLICK:
            printf(" state: CLICK\n");
            break;
        case STAGE:
            printf(" state: STAGE\n");
            break;
    }
}

ClickTypes scenario1(void);
ClickTypes scenario2(void);
ClickTypes scenario3(void);
ClickTypes scenario4(void);
ClickTypes scenario5(void);
int main(){
    // scenario1();
    // scenario2();
    // scenario3();
    scenario4();
    return 0;
}
ClickTypes scenario1(void){
    ClickData click_data = initClickDetection();
    risingEdge(&click_data);
    click_data.time_pressed = LOWER_NOISE;
    printClick(proccesClickData(&click_data, false));
    prinClickData(&click_data);
}
ClickTypes scenario2(void){
    ClickData click_data = initClickDetection();
    risingEdge(&click_data);
    click_data.time_pressed = LOWER_NOISE + 1;
    printClick(proccesClickData(&click_data, true));
    prinClickData(&click_data);
    click_data.time_pressed = UPPER_NOISE;
    printClick(proccesClickData(&click_data, false)); // SHOULD BE LONG CLICK
    prinClickData(&click_data);
}
ClickTypes scenario3(void){
    ClickData click_data = initClickDetection();
    risingEdge(&click_data);
    click_data.time_pressed = LOWER_NOISE + 1;
    printClick(proccesClickData(&click_data, true));
    prinClickData(&click_data);
    click_data.time_pressed = SHORT_LONG_CLICK_TRESHOLD;
    printClick(proccesClickData(&click_data, false)); //
    prinClickData(&click_data);
    click_data.time_released = SHORT_CLICK_TIME_OUT + 1;
    printClick(proccesClickData(&click_data, false)); // ONE CLICK
    prinClickData(&click_data);
}

ClickTypes scenario4(void){
    ClickData click_data = initClickDetection();
    risingEdge(&click_data);
    click_data.time_pressed = LOWER_NOISE + 1;
    printClick(proccesClickData(&click_data, true));
    prinClickData(&click_data);
    click_data.time_pressed = SHORT_LONG_CLICK_TRESHOLD;
    printClick(proccesClickData(&click_data, false)); //
    prinClickData(&click_data);
    click_data.time_released = SHORT_CLICK_TIME_OUT;
    printClick(proccesClickData(&click_data, true)); // 
    prinClickData(&click_data);
    printClick(proccesClickData(&click_data, false)); // 
    prinClickData(&click_data);
    click_data.time_released = SHORT_CLICK_TIME_OUT + 1;
    printClick(proccesClickData(&click_data, false)); // 
    prinClickData(&click_data);
}