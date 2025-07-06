
## FUZZY CONTROL APPLIED TO A BIDIRECTIONAL BUCK-BOOST DC-DC CONVERTER

This project presents the development of a four-switch bidirectional buck-boost DC-DC converter with a digital control system based on fuzzy logic. It is intended for embedded and automotive power applications, ensuring stability, precision, and adaptability in managing energy flows in both directions.

## CIRCUIT OVERVIEW

<p align="center">
  <img src="09 - Pictures/Bidirectional_Circuit.png" width="800">
</p>

## 🔧 Project Overview

- Implementation of a non-linear fuzzy controller to dynamically regulate the converter's duty cycle.
- Simulations performed in MATLAB/Simulink and Proteus for both open- and closed-loop analysis.
- Firmware developed for an ATmega328P microcontroller to enable real-time control.
- Complete printed circuit board (PCB) design including schematic, layout, and 3D rendering.
  
## 🎯 Objective

To develop a high-efficiency, bidirectional DC-DC converter capable of operating in buck, boost, and buck-boost modes, while maintaining output voltage regulation under varying load and input conditions.

## 🚗 Motivation: Automotive and Beyond

The main motivation behind this project is the increasing need for reliable DC-DC power conversion in automotive electronics. Modern vehicles integrate numerous electronic control units (ECUs) operating at different voltage levels. A bidirectional buck-boost converter is essential to enable safe power flow between modules and energy storage systems (e.g., batteries, supercapacitors).

While tailored for **automotive applications**, this solution is also suitable for other domains requiring bidirectional power control, such as:

- Battery management systems (BMS)
- Renewable energy systems
- Industrial automation
- Aerospace power electronics


## CIRCUIT OVERVIEW PROTEUS

<p align="center">
  <img src="09 - Pictures/Monitoring.png" width="400">
</p>

<p align="center">
  <img src="09 - Pictures/Proteus_Full_circuit.png" width="600">
</p>

## DC DC CONVERTER PERFORMANCE WITHOUT CONTROL IMPLEMENTATION

# OPERATION MODES


# WAVE FORM
<p align="center">
  <img src="09 - Pictures/Curve_buck.bmp" width="800">
</p>

<p align="center">
  <img src="09 - Pictures/Curves_Boost.bmp" width="800">
</p>

## 👨‍💻 Authors

- Marcelo Oliveira de Jesus Júnior  
- Victor Pereira dos Santos  
- William Souza Santos



