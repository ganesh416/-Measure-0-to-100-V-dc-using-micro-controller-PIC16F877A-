/*
 * File:   main.c
 * Name : Ganesh Pyndla
 * Date : 25-07-2024
 * Description :  Measure 0 to 100V dc using micro controller
 */

#include <xc.h>
#include "main.h"
#include "adc.h"
#include "clcd.h"


#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)



static void init_config(void) {
    //configure ADC for volatge source as input
    init_adc();
    //configure as CLCD for displaying voltage range from 0 to 100 volts
    init_clcd();
}

void main(void) {
    /*variable for storing ADC value*/
    unsigned short voltage; //0 to 1023
    init_config();
    /*Display the static message in line1 on CLCD*/
    clcd_print("Digital Voltmeter", LINE1(0)); 
    /*super loop*/
    while (1) {
        
        //read voltage from the adc
        voltage = read_adc();
        //after read voltage it will like 1023 then we convert 5 volts and after multiplying with 20 = 100 volts 
        voltage = (((float)voltage/1000) * 4.88 * 20);
        //display voltage in CLCD 
        clcd_print("Voltage = ", LINE2(0));
        clcd_print("Volts", LINE2(12));
        clcd_putch(voltage / 10 + '0',LINE2(10));
        clcd_putch(voltage % 10 + '0',LINE2(11));
        
        
    }
    return;
}
