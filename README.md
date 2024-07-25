** Measure 0 to 100Vdc using micro controller **

**DC Voltmeter Introduction**
Digital DC voltmeter is designed to measure DC voltage using the PIC16F877A microcontroller. A voltage divider circuit is used to divide voltage into two parts. 
To prevent more than 5 volts appearing across the pic microcontroller. Because the microcontroller can not read voltage more than 5 volts directly.

In this function we CLCD to display the voltages from 0 to 100 v dc
**DC voltmeter with LCD display**
Liquid crystal display is interfaced with the microcontroller to display measured voltage value.  Built-in analog to digital converter of pic microcontroller is used to a measured analog voltage.

in this project i used MPLAB XDE for write the code and to compile the code i used XC8 compiler, i upload one file called Digital voltmeter.

**How to Measure Dc Voltage?**
Resistor R1=19k ohm and R2=1k ohm are used as voltage dividers. According to voltage division formula, voltage 5 volts appears across pic microcontroller in the case of maximum input voltage 10 volts.

Vout = (R2 / R1+R2 ) * Vinput
Vout = ( 2 / 18+2) * 100 = 5 volt

maximum 5 voltage appiled to mc to prevent damage, so we convert 100 volts to 5 volts by varying the potentiometer it vary from 0 to 5v volts in order get voltage from 0 to 100 volts
convert it again

**ADC Channel**
In this project, AN0/RA0 channel of the pic16F877A microcontroller is used. ADC module of pic microcontroller converts an analog signal into binary numbers. PIC16F877A microcontroller has a 10 bit ADC. 
So it converts an analog signal to a 10-bit digital number which can be back converted into voltage using the following calculation in the programming of digital voltmeter.

Resolution = (Vrer+ - Vref-) / (1024 -1 ) ;
ADC resolution is an important concept to discuss here. Resolution means minimum value of the analog signal for which ADC counter increment by one. For example, pic16f877A microcontroller has 10-bit ADC 
and it counts binary from 0-1023 for every minimum analog value of the input signal. This minimum analog value is called resolution ADC increment by one. For example, pic16f877A microcontroller has 10-bit ADC 
and it counts binary from 0-1023 for every minimum analog value of the input signal. This minimum analog value is called resolution.

In this project, we are taking Verf+= 5 volts and Vref- = 0 volt. Hence by using these values in the above formula, this minimum voltage will be:

resolution = (5 - 0 )/ (1023) = 4.8876 mV;
It means for every analog signal of 4.87mV, ADC value increments by one.

read adc value from potentiometer is 1023, so we convert into 5 volts by using below calculation.


voltage = (adc_value / 1000) * 4.88 volts * 20 ==> it will give 0 to 100 volts

we will print this voltage on CLCD.


Component used :
1) PIC16F877A
2) ADC
3) CLCD
4) XC8 compiler and MPLAB XDE

** Working **
1) first initialize the input and output peripherals like ADC and CLCD.
2) read the analog to digital convert value from ADC then convert into voltage between the range 0 to 100
3) then print volatge on CLCD.



