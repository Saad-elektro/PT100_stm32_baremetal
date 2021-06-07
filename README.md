# PT100_stm32_baremetal
Temperature sensor using 24-bit ADC_ ADS1220 

It's a prototype for an industrial temperature sensor, based on 3-wire RTD PT100, which offers
the possibility to read the measurements in situ or from a remote terminal,
can be used to keep the traceability of temperature storage for foodstuffs.

it can operates from -30°C to 120°C temperature range,
Ensure accuracy measurements +/-0.5°C.

The sensor is supplied with 2 parallel batteries to increase the capacity, which can ensure 2 Days autonomy in case of main voltage failure
it contains a charging and battery protection circuit.

a P-channel MOSFET allows the power supply to switche to an external +5v DC source .

24-bit ADC from Texas Instruments is used to perform digital conversion.

Tne hardware is developed with Altium Designer.

Software Design:

The firmware is running on an stm32f103 microcontroller, based on ARM-Cortex M3 processor.
and developed under Keil Uvision IDE.

Various communication protocol was implemented in this project :
- SPI protocol for ADC (bare metal)
- UART protocol for serial communication with the computer (bare metal)
- I2C for LCD (HAL librarie)

the ADC driver was developped fully with bare metal programming, which allows a direct interaction with the hardware level.


The system provides a Wi-Fi connectivity to watch the temperature measurements from a remote terminal, the firmware is still in progress.

![Photo](https://user-images.githubusercontent.com/58118111/121067061-81c9c900-c7c2-11eb-8e8d-f9fbc34c4a85.jpg)
![Photo2](https://user-images.githubusercontent.com/58118111/121067191-aa51c300-c7c2-11eb-8193-002d495c1365.jpg)

