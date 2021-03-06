EESchema Schematic File Version 4
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Crystal Y1
U 1 1 5CBE94E2
P 3350 2350
F 0 "Y1" H 3350 2618 50  0000 C CNN
F 1 "Crystal" H 3350 2527 50  0000 C CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 3350 2350 50  0001 C CNN
F 3 "~" H 3350 2350 50  0001 C CNN
	1    3350 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CBE97C9
P 3100 2850
F 0 "C1" H 3215 2896 50  0000 L CNN
F 1 "22p" H 3215 2805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3138 2700 50  0001 C CNN
F 3 "~" H 3100 2850 50  0001 C CNN
	1    3100 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5CBE9CBC
P 3600 2850
F 0 "C2" H 3715 2896 50  0000 L CNN
F 1 "22p" H 3715 2805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3638 2700 50  0001 C CNN
F 3 "~" H 3600 2850 50  0001 C CNN
	1    3600 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CBEAE25
P 3350 2550
F 0 "R1" V 3350 2550 50  0000 C CNN
F 1 "1M" V 3450 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3280 2550 50  0001 C CNN
F 3 "~" H 3350 2550 50  0001 C CNN
	1    3350 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 3050 3600 3000
$Comp
L power:GND #PWR0101
U 1 1 5CBEC6E7
P 3100 3050
F 0 "#PWR0101" H 3100 2800 50  0001 C CNN
F 1 "GND" H 3105 2877 50  0000 C CNN
F 2 "" H 3100 3050 50  0001 C CNN
F 3 "" H 3100 3050 50  0001 C CNN
	1    3100 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3050 3100 3000
$Comp
L power:GND #PWR0102
U 1 1 5CBECF01
P 3600 3050
F 0 "#PWR0102" H 3600 2800 50  0001 C CNN
F 1 "GND" H 3605 2877 50  0000 C CNN
F 2 "" H 3600 3050 50  0001 C CNN
F 3 "" H 3600 3050 50  0001 C CNN
	1    3600 3050
	1    0    0    -1  
$EndComp
Text GLabel 3600 2350 1    50   Input ~ 0
XTAL1
Text GLabel 3100 2350 1    50   Input ~ 0
XTAL2
Text GLabel 3200 3850 0    50   Input ~ 0
PG4
Text GLabel 3700 3850 2    50   Input ~ 0
~RST
$Comp
L power:VCC #PWR0103
U 1 1 5CBF2C3B
P 3200 3950
F 0 "#PWR0103" H 3200 3800 50  0001 C CNN
F 1 "VCC" V 3218 4077 50  0000 L CNN
F 2 "" H 3200 3950 50  0001 C CNN
F 3 "" H 3200 3950 50  0001 C CNN
	1    3200 3950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5CBF3B5E
P 3700 3950
F 0 "#PWR0104" H 3700 3700 50  0001 C CNN
F 1 "GND" V 3705 3822 50  0000 R CNN
F 2 "" H 3700 3950 50  0001 C CNN
F 3 "" H 3700 3950 50  0001 C CNN
	1    3700 3950
	0    -1   -1   0   
$EndComp
Text GLabel 3200 4050 0    50   Input ~ 0
XTAL2
Text GLabel 3700 4050 2    50   Input ~ 0
XTAL1
Wire Wire Line
	3100 2700 3100 2550
Wire Wire Line
	3200 2350 3100 2350
Wire Wire Line
	3500 2350 3600 2350
Wire Wire Line
	3600 2350 3600 2550
Wire Wire Line
	3500 2550 3600 2550
Connection ~ 3600 2550
Wire Wire Line
	3600 2550 3600 2700
Wire Wire Line
	3200 2550 3100 2550
Connection ~ 3100 2550
Wire Wire Line
	3100 2550 3100 2350
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J1
U 1 1 5CBF7DAD
P 3400 3950
F 0 "J1" H 3450 4267 50  0000 C CNN
F 1 "Conn_02x04_Odd_Even" H 3450 4176 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x04_P2.54mm_Vertical" H 3400 3950 50  0001 C CNN
F 3 "~" H 3400 3950 50  0001 C CNN
	1    3400 3950
	1    0    0    -1  
$EndComp
Text GLabel 3200 4150 0    50   Input ~ 0
SCL
Text GLabel 3700 4150 2    50   Input ~ 0
SDA
$Comp
L Connector:Conn_01x01_Female J3
U 1 1 5CBF9A13
P 4700 3350
F 0 "J3" H 4728 3376 50  0000 L CNN
F 1 "SDA" H 4728 3285 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 4700 3350 50  0001 C CNN
F 3 "~" H 4700 3350 50  0001 C CNN
	1    4700 3350
	1    0    0    -1  
$EndComp
Text GLabel 4500 3350 0    50   Input ~ 0
SDA
$Comp
L Connector:Conn_01x01_Female J2
U 1 1 5CBF9F42
P 4700 3250
F 0 "J2" H 4728 3276 50  0000 L CNN
F 1 "SCL" H 4728 3185 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 4700 3250 50  0001 C CNN
F 3 "~" H 4700 3250 50  0001 C CNN
	1    4700 3250
	1    0    0    -1  
$EndComp
Text GLabel 4500 3250 0    50   Input ~ 0
SCL
Text GLabel 4500 2750 0    50   Input ~ 0
SCL
Text GLabel 4500 2850 0    50   Input ~ 0
SDA
$Comp
L Device:R R2
U 1 1 5CBFA32C
P 4650 2750
F 0 "R2" V 4650 2750 50  0000 C CNN
F 1 "10K" V 4550 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4580 2750 50  0001 C CNN
F 3 "~" H 4650 2750 50  0001 C CNN
	1    4650 2750
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5CBFAC86
P 4650 2850
F 0 "R3" V 4650 2850 50  0000 C CNN
F 1 "10K" V 4750 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4580 2850 50  0001 C CNN
F 3 "~" H 4650 2850 50  0001 C CNN
	1    4650 2850
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0105
U 1 1 5CBFB381
P 4850 2750
F 0 "#PWR0105" H 4850 2600 50  0001 C CNN
F 1 "VCC" V 4867 2878 50  0000 L CNN
F 2 "" H 4850 2750 50  0001 C CNN
F 3 "" H 4850 2750 50  0001 C CNN
	1    4850 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 2750 4800 2750
Wire Wire Line
	4800 2850 4800 2750
Connection ~ 4800 2750
$Comp
L Connector:Conn_01x01_Female J4
U 1 1 5CBFD6F6
P 4700 3500
F 0 "J4" H 4728 3526 50  0000 L CNN
F 1 "~RST" H 4728 3435 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 4700 3500 50  0001 C CNN
F 3 "~" H 4700 3500 50  0001 C CNN
	1    4700 3500
	1    0    0    -1  
$EndComp
Text GLabel 4500 3500 0    50   Input ~ 0
~RST
Text GLabel 4500 3600 0    50   Input ~ 0
PG4
$Comp
L Connector:Conn_01x01_Female J5
U 1 1 5CBFDD1D
P 4700 3600
F 0 "J5" H 4728 3626 50  0000 L CNN
F 1 "PG4" H 4728 3535 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 4700 3600 50  0001 C CNN
F 3 "~" H 4700 3600 50  0001 C CNN
	1    4700 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J6
U 1 1 5CC01834
P 4700 3850
F 0 "J6" H 4728 3876 50  0000 L CNN
F 1 "VCC" H 4728 3785 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 4700 3850 50  0001 C CNN
F 3 "~" H 4700 3850 50  0001 C CNN
	1    4700 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J7
U 1 1 5CC01AD8
P 4700 4000
F 0 "J7" H 4728 4026 50  0000 L CNN
F 1 "GND" H 4728 3935 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 4700 4000 50  0001 C CNN
F 3 "~" H 4700 4000 50  0001 C CNN
	1    4700 4000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 5CC01FB1
P 4500 3850
F 0 "#PWR0106" H 4500 3700 50  0001 C CNN
F 1 "VCC" V 4518 3977 50  0000 L CNN
F 2 "" H 4500 3850 50  0001 C CNN
F 3 "" H 4500 3850 50  0001 C CNN
	1    4500 3850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5CC026DB
P 4500 4000
F 0 "#PWR0107" H 4500 3750 50  0001 C CNN
F 1 "GND" V 4505 3872 50  0000 R CNN
F 2 "" H 4500 4000 50  0001 C CNN
F 3 "" H 4500 4000 50  0001 C CNN
	1    4500 4000
	0    1    1    0   
$EndComp
$Comp
L Device:C C3
U 1 1 5CC096F5
P 2650 2850
F 0 "C3" H 2765 2896 50  0000 L CNN
F 1 "100n" H 2765 2805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2688 2700 50  0001 C CNN
F 3 "~" H 2650 2850 50  0001 C CNN
	1    2650 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5CC09B48
P 2650 3000
F 0 "#PWR0108" H 2650 2750 50  0001 C CNN
F 1 "GND" H 2655 2827 50  0000 C CNN
F 2 "" H 2650 3000 50  0001 C CNN
F 3 "" H 2650 3000 50  0001 C CNN
	1    2650 3000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 5CC09ED0
P 2650 2700
F 0 "#PWR0109" H 2650 2550 50  0001 C CNN
F 1 "VCC" H 2667 2873 50  0000 C CNN
F 2 "" H 2650 2700 50  0001 C CNN
F 3 "" H 2650 2700 50  0001 C CNN
	1    2650 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5CC141EC
P 2150 2750
F 0 "D1" V 2189 2633 50  0000 R CNN
F 1 "LED" V 2098 2633 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2150 2750 50  0001 C CNN
F 3 "~" H 2150 2750 50  0001 C CNN
	1    2150 2750
	0    -1   -1   0   
$EndComp
Text GLabel 2150 3000 3    50   Input ~ 0
PG4
$Comp
L Device:R R5
U 1 1 5CC17C7D
P 2150 2450
F 0 "R5" V 2150 2450 50  0000 C CNN
F 1 "1K" V 2250 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2080 2450 50  0001 C CNN
F 3 "~" H 2150 2450 50  0001 C CNN
	1    2150 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 2250 2150 2300
$Comp
L Device:C C4
U 1 1 5CC1A304
P 1750 3000
F 0 "C4" H 1865 3046 50  0000 L CNN
F 1 "100n" H 1865 2955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1788 2850 50  0001 C CNN
F 3 "~" H 1750 3000 50  0001 C CNN
	1    1750 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5CC1A59B
P 1750 3150
F 0 "#PWR0110" H 1750 2900 50  0001 C CNN
F 1 "GND" H 1755 2977 50  0000 C CNN
F 2 "" H 1750 3150 50  0001 C CNN
F 3 "" H 1750 3150 50  0001 C CNN
	1    1750 3150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0111
U 1 1 5CC1B891
P 2150 2250
F 0 "#PWR0111" H 2150 2100 50  0001 C CNN
F 1 "VCC" H 2167 2423 50  0000 C CNN
F 2 "" H 2150 2250 50  0001 C CNN
F 3 "" H 2150 2250 50  0001 C CNN
	1    2150 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 2900 2150 3000
$Comp
L Device:R R4
U 1 1 5CC1D2A1
P 1750 2400
F 0 "R4" V 1750 2400 50  0000 C CNN
F 1 "1K" V 1850 2400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1680 2400 50  0001 C CNN
F 3 "~" H 1750 2400 50  0001 C CNN
	1    1750 2400
	-1   0    0    1   
$EndComp
Text GLabel 1550 2700 0    50   Input ~ 0
~RST
Wire Wire Line
	1550 2700 1750 2700
Wire Wire Line
	1750 2700 1750 2550
Wire Wire Line
	1750 2850 1750 2700
Connection ~ 1750 2700
$Comp
L power:VCC #PWR0112
U 1 1 5CC209C4
P 1750 2250
F 0 "#PWR0112" H 1750 2100 50  0001 C CNN
F 1 "VCC" H 1767 2423 50  0000 C CNN
F 2 "" H 1750 2250 50  0001 C CNN
F 3 "" H 1750 2250 50  0001 C CNN
	1    1750 2250
	1    0    0    -1  
$EndComp
Text GLabel 4350 4450 0    50   Input ~ 0
~RST
$Comp
L Device:C C5
U 1 1 5CC25E7D
P 4500 4450
F 0 "C5" H 4615 4496 50  0000 L CNN
F 1 "100n" H 4615 4405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4538 4300 50  0001 C CNN
F 3 "~" H 4500 4450 50  0001 C CNN
	1    4500 4450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J8
U 1 1 5CC2698C
P 4850 4450
F 0 "J8" H 4878 4476 50  0000 L CNN
F 1 "DTR" H 4878 4385 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 4850 4450 50  0001 C CNN
F 3 "~" H 4850 4450 50  0001 C CNN
	1    4850 4450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
