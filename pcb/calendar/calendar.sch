EESchema Schematic File Version 4
LIBS:calendar-cache
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
L Timer_RTC:PCF8563T U1
U 1 1 5CA9BE92
P 3600 2000
F 0 "U1" H 3400 2000 50  0000 C CNN
F 1 "PCF8563T" H 3900 1600 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3600 2000 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PCF8563.pdf" H 3600 2000 50  0001 C CNN
	1    3600 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5CA9CC2B
P 2900 1800
F 0 "Y1" V 2950 1550 50  0000 L CNN
F 1 "32 768" V 2750 1500 50  0000 L CNN
F 2 "Crystal:Crystal_DS15_D1.5mm_L5.0mm_Horizontal" H 2900 1800 50  0001 C CNN
F 3 "~" H 2900 1800 50  0001 C CNN
	1    2900 1800
	-1   0    0    1   
$EndComp
Wire Wire Line
	3050 1800 3200 1800
Wire Wire Line
	3200 2200 3050 2200
$Comp
L power:GND #PWR0101
U 1 1 5CA9E497
P 3600 2400
F 0 "#PWR0101" H 3600 2150 50  0001 C CNN
F 1 "GND" H 3605 2227 50  0000 C CNN
F 2 "" H 3600 2400 50  0001 C CNN
F 3 "" H 3600 2400 50  0001 C CNN
	1    3600 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CAA303F
P 5100 1950
F 0 "#PWR0102" H 5100 1700 50  0001 C CNN
F 1 "GND" V 5105 1822 50  0000 R CNN
F 2 "" H 5100 1950 50  0001 C CNN
F 3 "" H 5100 1950 50  0001 C CNN
	1    5100 1950
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5CAA42EB
P 2900 2200
F 0 "C1" V 2648 2200 50  0000 C CNN
F 1 "C" V 2739 2200 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 2938 2050 50  0001 C CNN
F 3 "~" H 2900 2200 50  0001 C CNN
	1    2900 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	2750 1800 2750 2200
$Comp
L sdd:MAX7219_7221 U2
U 1 1 5CAA8A71
P 3700 2750
F 0 "U2" H 3300 1500 50  0000 C CNN
F 1 "MAX7219" H 3400 1250 50  0000 C CNN
F 2 "Package_SO:SOIC-24W_7.5x15.4mm_P1.27mm" H 3550 2550 50  0001 C CNN
F 3 "" H 3550 2550 50  0001 C CNN
	1    3700 2750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5CAB2BBF
P 3450 2850
F 0 "#PWR0103" H 3450 2700 50  0001 C CNN
F 1 "+5V" H 3465 3023 50  0000 C CNN
F 2 "" H 3450 2850 50  0001 C CNN
F 3 "" H 3450 2850 50  0001 C CNN
	1    3450 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2850 3450 3050
$Comp
L Device:R R1
U 1 1 5CAB342B
P 3750 3000
F 0 "R1" V 3543 3000 50  0000 C CNN
F 1 "9K53" V 3634 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3680 3000 50  0001 C CNN
F 3 "~" H 3750 3000 50  0001 C CNN
	1    3750 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 3000 3600 3050
$Comp
L power:+5V #PWR0104
U 1 1 5CAB41BA
P 3950 2850
F 0 "#PWR0104" H 3950 2700 50  0001 C CNN
F 1 "+5V" H 3965 3023 50  0000 C CNN
F 2 "" H 3950 2850 50  0001 C CNN
F 3 "" H 3950 2850 50  0001 C CNN
	1    3950 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3000 3950 3000
Wire Wire Line
	3950 2850 3950 3000
$Comp
L power:GND #PWR0105
U 1 1 5CAB4F2E
P 3450 5050
F 0 "#PWR0105" H 3450 4800 50  0001 C CNN
F 1 "GND" H 3455 4877 50  0000 C CNN
F 2 "" H 3450 5050 50  0001 C CNN
F 3 "" H 3450 5050 50  0001 C CNN
	1    3450 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5CAB55DC
P 3550 5050
F 0 "#PWR0106" H 3550 4800 50  0001 C CNN
F 1 "GND" H 3555 4877 50  0000 C CNN
F 2 "" H 3550 5050 50  0001 C CNN
F 3 "" H 3550 5050 50  0001 C CNN
	1    3550 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5CAB57B4
P 3600 1600
F 0 "#PWR0107" H 3600 1450 50  0001 C CNN
F 1 "+5V" H 3615 1773 50  0000 C CNN
F 2 "" H 3600 1600 50  0001 C CNN
F 3 "" H 3600 1600 50  0001 C CNN
	1    3600 1600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 5CAB5CA1
P 5750 1850
F 0 "#PWR0108" H 5750 1700 50  0001 C CNN
F 1 "+5V" V 5765 1978 50  0000 L CNN
F 2 "" H 5750 1850 50  0001 C CNN
F 3 "" H 5750 1850 50  0001 C CNN
	1    5750 1850
	0    1    1    0   
$EndComp
Text GLabel 4000 2200 2    50   Input ~ 0
T~INT
Text GLabel 4000 2100 2    50   Input ~ 0
TCLK
Text GLabel 4000 1900 2    50   Input ~ 0
SDA
Text GLabel 4000 1800 2    50   Input ~ 0
SCL
Text GLabel 5750 2050 2    50   Input ~ 0
T~INT
Text GLabel 5100 2050 0    50   Input ~ 0
TCLK
Text GLabel 5100 2250 0    50   Input ~ 0
SDA
Text GLabel 5100 2150 0    50   Input ~ 0
SCL
Text GLabel 3100 3550 0    50   Input ~ 0
DIN
Text GLabel 3100 3650 0    50   Input ~ 0
SCLK
Text GLabel 3100 4550 0    50   Input ~ 0
LOAD
Text GLabel 5750 2250 2    50   Input ~ 0
LOAD
Text GLabel 5100 1850 0    50   Input ~ 0
SCLK
Text GLabel 5750 1950 2    50   Input ~ 0
DIN
Text GLabel 4050 3250 2    50   Input ~ 0
DOUT
Text GLabel 4050 3350 2    50   Input ~ 0
D0
Text GLabel 4050 3450 2    50   Input ~ 0
D1
Text GLabel 4050 3550 2    50   Input ~ 0
D2
Text GLabel 4050 3650 2    50   Input ~ 0
D3
Text GLabel 4050 3750 2    50   Input ~ 0
D4
Text GLabel 4050 3850 2    50   Input ~ 0
D5
Text GLabel 4050 3950 2    50   Input ~ 0
D6
Text GLabel 4050 4050 2    50   Input ~ 0
D7
Text GLabel 4050 4150 2    50   Input ~ 0
A
Text GLabel 4050 4250 2    50   Input ~ 0
B
Text GLabel 4050 4350 2    50   Input ~ 0
C
Text GLabel 4050 4450 2    50   Input ~ 0
D
Text GLabel 4050 4550 2    50   Input ~ 0
E
Text GLabel 4050 4650 2    50   Input ~ 0
F
Text GLabel 4050 4750 2    50   Input ~ 0
G
Text GLabel 4050 4850 2    50   Input ~ 0
DP
Text GLabel 5100 3500 0    50   Input ~ 0
D0
Text GLabel 5100 3100 0    50   Input ~ 0
D1
Text GLabel 5100 3300 0    50   Input ~ 0
D2
Text GLabel 5750 3300 2    50   Input ~ 0
D3
Text GLabel 5100 3400 0    50   Input ~ 0
D4
Text GLabel 5750 3200 2    50   Input ~ 0
D5
Text GLabel 5750 3400 2    50   Input ~ 0
D6
Text GLabel 5100 3200 0    50   Input ~ 0
D7
Text GLabel 5750 3500 2    50   Input ~ 0
DOUT
Text GLabel 5100 4550 0    50   Input ~ 0
A
Text GLabel 5100 4650 0    50   Input ~ 0
B
Text GLabel 5100 4750 0    50   Input ~ 0
C
Text GLabel 5100 4850 0    50   Input ~ 0
D
Text GLabel 5800 4850 2    50   Input ~ 0
E
Text GLabel 5800 4650 2    50   Input ~ 0
F
Text GLabel 5800 4750 2    50   Input ~ 0
G
Text GLabel 5100 4450 0    50   Input ~ 0
DP
Text GLabel 5100 3000 0    50   Input ~ 0
LOAD
Text GLabel 5750 3000 2    50   Input ~ 0
SCLK
$Comp
L power:+5V #PWR0109
U 1 1 5CADF666
P 5800 4550
F 0 "#PWR0109" H 5800 4400 50  0001 C CNN
F 1 "+5V" V 5815 4678 50  0000 L CNN
F 2 "" H 5800 4550 50  0001 C CNN
F 3 "" H 5800 4550 50  0001 C CNN
	1    5800 4550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5CAE018A
P 5800 4450
F 0 "#PWR0110" H 5800 4200 50  0001 C CNN
F 1 "GND" V 5805 4322 50  0000 R CNN
F 2 "" H 5800 4450 50  0001 C CNN
F 3 "" H 5800 4450 50  0001 C CNN
	1    5800 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C2
U 1 1 5CAFE1C4
P 1850 2850
F 0 "C2" H 1735 2804 50  0000 R CNN
F 1 "100n" H 1735 2895 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1888 2700 50  0001 C CNN
F 3 "~" H 1850 2850 50  0001 C CNN
	1    1850 2850
	-1   0    0    1   
$EndComp
$Comp
L Device:C C3
U 1 1 5CAFF373
P 2250 2850
F 0 "C3" H 2135 2804 50  0000 R CNN
F 1 "100n" H 2135 2895 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2288 2700 50  0001 C CNN
F 3 "~" H 2250 2850 50  0001 C CNN
	1    2250 2850
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5CAFF68C
P 1850 3000
F 0 "#PWR0111" H 1850 2750 50  0001 C CNN
F 1 "GND" H 1855 2827 50  0000 C CNN
F 2 "" H 1850 3000 50  0001 C CNN
F 3 "" H 1850 3000 50  0001 C CNN
	1    1850 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5CAFFAB6
P 2250 3000
F 0 "#PWR0112" H 2250 2750 50  0001 C CNN
F 1 "GND" H 2255 2827 50  0000 C CNN
F 2 "" H 2250 3000 50  0001 C CNN
F 3 "" H 2250 3000 50  0001 C CNN
	1    2250 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0113
U 1 1 5CAFFD42
P 2250 2700
F 0 "#PWR0113" H 2250 2550 50  0001 C CNN
F 1 "+5V" H 2265 2873 50  0000 C CNN
F 2 "" H 2250 2700 50  0001 C CNN
F 3 "" H 2250 2700 50  0001 C CNN
	1    2250 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0114
U 1 1 5CB0036D
P 1850 2700
F 0 "#PWR0114" H 1850 2550 50  0001 C CNN
F 1 "+5V" H 1865 2873 50  0000 C CNN
F 2 "" H 1850 2700 50  0001 C CNN
F 3 "" H 1850 2700 50  0001 C CNN
	1    1850 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J1
U 1 1 5CB9CED1
P 5300 1850
F 0 "J1" H 5272 1782 50  0000 R CNN
F 1 "J" H 5272 1873 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 1850 50  0001 C CNN
F 3 "~" H 5300 1850 50  0001 C CNN
	1    5300 1850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J2
U 1 1 5CBA4584
P 5300 1950
F 0 "J2" H 5272 1882 50  0000 R CNN
F 1 "J" H 5272 1973 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 1950 50  0001 C CNN
F 3 "~" H 5300 1950 50  0001 C CNN
	1    5300 1950
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J3
U 1 1 5CBA46EE
P 5300 2050
F 0 "J3" H 5272 1982 50  0000 R CNN
F 1 "J" H 5272 2073 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 2050 50  0001 C CNN
F 3 "~" H 5300 2050 50  0001 C CNN
	1    5300 2050
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J4
U 1 1 5CBA47A6
P 5300 2150
F 0 "J4" H 5272 2082 50  0000 R CNN
F 1 "J" H 5272 2173 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 2150 50  0001 C CNN
F 3 "~" H 5300 2150 50  0001 C CNN
	1    5300 2150
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J5
U 1 1 5CBA4969
P 5300 2250
F 0 "J5" H 5272 2182 50  0000 R CNN
F 1 "J" H 5272 2273 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 2250 50  0001 C CNN
F 3 "~" H 5300 2250 50  0001 C CNN
	1    5300 2250
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J6
U 1 1 5CBA4AAE
P 5300 3000
F 0 "J6" H 5272 2932 50  0000 R CNN
F 1 "J" H 5272 3023 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 3000 50  0001 C CNN
F 3 "~" H 5300 3000 50  0001 C CNN
	1    5300 3000
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J7
U 1 1 5CBA4EED
P 5300 3100
F 0 "J7" H 5272 3032 50  0000 R CNN
F 1 "J" H 5272 3123 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 3100 50  0001 C CNN
F 3 "~" H 5300 3100 50  0001 C CNN
	1    5300 3100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J8
U 1 1 5CBA5080
P 5300 3200
F 0 "J8" H 5272 3132 50  0000 R CNN
F 1 "J" H 5272 3223 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 3200 50  0001 C CNN
F 3 "~" H 5300 3200 50  0001 C CNN
	1    5300 3200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J9
U 1 1 5CBA5249
P 5300 3300
F 0 "J9" H 5272 3232 50  0000 R CNN
F 1 "J" H 5272 3323 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 3300 50  0001 C CNN
F 3 "~" H 5300 3300 50  0001 C CNN
	1    5300 3300
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J10
U 1 1 5CBA54AA
P 5300 3400
F 0 "J10" H 5272 3332 50  0000 R CNN
F 1 "J" H 5272 3423 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 3400 50  0001 C CNN
F 3 "~" H 5300 3400 50  0001 C CNN
	1    5300 3400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J11
U 1 1 5CBA560F
P 5300 3500
F 0 "J11" H 5272 3432 50  0000 R CNN
F 1 "J" H 5272 3523 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 3500 50  0001 C CNN
F 3 "~" H 5300 3500 50  0001 C CNN
	1    5300 3500
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J12
U 1 1 5CBA57DD
P 5300 4450
F 0 "J12" H 5272 4382 50  0000 R CNN
F 1 "J" H 5272 4473 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 4450 50  0001 C CNN
F 3 "~" H 5300 4450 50  0001 C CNN
	1    5300 4450
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J13
U 1 1 5CBA5CD4
P 5300 4550
F 0 "J13" H 5272 4482 50  0000 R CNN
F 1 "J" H 5272 4573 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 4550 50  0001 C CNN
F 3 "~" H 5300 4550 50  0001 C CNN
	1    5300 4550
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J14
U 1 1 5CBA5E58
P 5300 4650
F 0 "J14" H 5272 4582 50  0000 R CNN
F 1 "J" H 5272 4673 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 4650 50  0001 C CNN
F 3 "~" H 5300 4650 50  0001 C CNN
	1    5300 4650
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J15
U 1 1 5CBA614D
P 5300 4750
F 0 "J15" H 5272 4682 50  0000 R CNN
F 1 "J" H 5272 4773 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 4750 50  0001 C CNN
F 3 "~" H 5300 4750 50  0001 C CNN
	1    5300 4750
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J16
U 1 1 5CBA62D6
P 5300 4850
F 0 "J16" H 5272 4782 50  0000 R CNN
F 1 "J" H 5272 4873 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5300 4850 50  0001 C CNN
F 3 "~" H 5300 4850 50  0001 C CNN
	1    5300 4850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J30
U 1 1 5CBA64F7
P 5600 4850
F 0 "J30" H 5708 5031 50  0000 C CNN
F 1 "J" H 5708 4940 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5600 4850 50  0001 C CNN
F 3 "~" H 5600 4850 50  0001 C CNN
	1    5600 4850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J29
U 1 1 5CBA694B
P 5600 4750
F 0 "J29" H 5708 4931 50  0000 C CNN
F 1 "J" H 5708 4840 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5600 4750 50  0001 C CNN
F 3 "~" H 5600 4750 50  0001 C CNN
	1    5600 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J28
U 1 1 5CBA6ADF
P 5600 4650
F 0 "J28" H 5708 4831 50  0000 C CNN
F 1 "J" H 5708 4740 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5600 4650 50  0001 C CNN
F 3 "~" H 5600 4650 50  0001 C CNN
	1    5600 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J27
U 1 1 5CBA6C53
P 5600 4550
F 0 "J27" H 5708 4731 50  0000 C CNN
F 1 "J" H 5708 4640 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5600 4550 50  0001 C CNN
F 3 "~" H 5600 4550 50  0001 C CNN
	1    5600 4550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J26
U 1 1 5CBA6DCD
P 5600 4450
F 0 "J26" H 5708 4631 50  0000 C CNN
F 1 "J" H 5708 4540 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5600 4450 50  0001 C CNN
F 3 "~" H 5600 4450 50  0001 C CNN
	1    5600 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J25
U 1 1 5CBA6F6D
P 5550 3500
F 0 "J25" H 5658 3681 50  0000 C CNN
F 1 "J" H 5658 3590 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 3500 50  0001 C CNN
F 3 "~" H 5550 3500 50  0001 C CNN
	1    5550 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J24
U 1 1 5CBA7443
P 5550 3400
F 0 "J24" H 5658 3581 50  0000 C CNN
F 1 "J" H 5658 3490 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 3400 50  0001 C CNN
F 3 "~" H 5550 3400 50  0001 C CNN
	1    5550 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J23
U 1 1 5CBA7578
P 5550 3300
F 0 "J23" H 5658 3481 50  0000 C CNN
F 1 "J" H 5658 3390 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 3300 50  0001 C CNN
F 3 "~" H 5550 3300 50  0001 C CNN
	1    5550 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J22
U 1 1 5CBA76CC
P 5550 3200
F 0 "J22" H 5658 3381 50  0000 C CNN
F 1 "J" H 5658 3290 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 3200 50  0001 C CNN
F 3 "~" H 5550 3200 50  0001 C CNN
	1    5550 3200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J21
U 1 1 5CBA7855
P 5550 3000
F 0 "J21" H 5658 3181 50  0000 C CNN
F 1 "J" H 5658 3090 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 3000 50  0001 C CNN
F 3 "~" H 5550 3000 50  0001 C CNN
	1    5550 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J17
U 1 1 5CBA7C65
P 5550 1850
F 0 "J17" H 5658 2031 50  0000 C CNN
F 1 "J" H 5658 1940 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 1850 50  0001 C CNN
F 3 "~" H 5550 1850 50  0001 C CNN
	1    5550 1850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J18
U 1 1 5CBA8233
P 5550 1950
F 0 "J18" H 5658 2131 50  0000 C CNN
F 1 "J" H 5658 2040 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 1950 50  0001 C CNN
F 3 "~" H 5550 1950 50  0001 C CNN
	1    5550 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J19
U 1 1 5CBA8519
P 5550 2050
F 0 "J19" H 5658 2231 50  0000 C CNN
F 1 "J" H 5658 2140 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 2050 50  0001 C CNN
F 3 "~" H 5550 2050 50  0001 C CNN
	1    5550 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J20
U 1 1 5CBA8796
P 5550 2250
F 0 "J20" H 5658 2431 50  0000 C CNN
F 1 "J" H 5658 2340 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 5550 2250 50  0001 C CNN
F 3 "~" H 5550 2250 50  0001 C CNN
	1    5550 2250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
