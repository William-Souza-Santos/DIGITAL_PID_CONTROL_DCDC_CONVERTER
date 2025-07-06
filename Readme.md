# ⚡ FUZZY CONTROL APPLIED TO A BIDIRECTIONAL BUCK-BOOST DC-DC CONVERTER

This project presents the design and implementation of a four-switch bidirectional buck-boost DC-DC converter, featuring a fuzzy logic-based digital control system. The converter is designed for embedded and automotive power applications, ensuring stability, precision, and adaptability in bidirectional energy management.

---

## 🔍 Circuit Overview

<p align="center">
  <img src="09 - Pictures/Bidirectional_Circuit.png" width="700">
</p>

---

## 🔧 Project Highlights

- Implementation of a non-linear fuzzy logic controller to dynamically regulate the converter's duty cycle.
- Simulations conducted in **MATLAB/Simulink** and **Proteus**, covering both open-loop and closed-loop control strategies.
- Embedded firmware developed for the **ATmega328P** microcontroller to enable real-time control.
- Complete **PCB design**, including schematic capture, PCB layout, and 3D visualization.

---

## 🎯 Objective

To design and validate a high-efficiency bidirectional DC-DC converter capable of operating in buck, boost, and buck-boost modes, maintaining stable output voltage under varying load and input conditions.

---

## 🚗 Motivation: Automotive and Beyond

The primary motivation for this project lies in the growing demand for reliable DC-DC power converters in **automotive systems**, where multiple ECUs operate at different voltage levels. A bidirectional buck-boost converter ensures safe and efficient energy flow between these modules and energy storage systems such as batteries or supercapacitors.

Although tailored for automotive use, the converter is also applicable to:

- 🔋 Battery Management Systems (BMS)  
- ☀️ Renewable Energy Systems  
- 🏭 Industrial Automation  
- ✈️ Aerospace Power Electronics  

---

## 🧪 Simulation: Circuit in Proteus

<p align="center">
  <img src="09 - Pictures/Monitoring.png" width="400">
</p>

<p align="center">
  <img src="09 - Pictures/Proteus_Full_circuit.png" width="600">
</p> 

---

## 📝 Theoretical Foundations

<p align="center">
  <strong>Operating Modes</strong><br>
  <img src="09 - Pictures/Hysteresis_Between_Buck_and_Boost.png" width="500"><br>
</p>

<p align="center">
  <strong>BUCK</strong><br>
  <img src="09 - Pictures/Operational_Mode_BUCK.png" width="500"><br>
</p>

<p align="center">
  <strong>BOOST</strong><br>
  <img src="09 - Pictures/Operational_Mode_BOOST.png" width="500"><br>
</p>

---

## 🔁 Bidirectional Operation (Open-Loop Tests)

<p align="center">
  <strong>A → B (Boost Mode)</strong><br>
  <img src="09 - Pictures/A-B_BOOST.png" width="800"><br>
</p>

<p align="center">
  <strong>A → B (Buck Mode)</strong><br>
  <img src="09 - Pictures/A-B_BUCK (2).png" width="800"><br>
</p>

<p align="center">
  <strong>B → A (Boost Mode)</strong><br>
  <img src="09 - Pictures/B-A_BOOST.png" width="800"><br>
</p>

<p align="center">
  <strong>B → A (Buck Mode)</strong><br>
  <img src="09 - Pictures/B-A_BUCK.png" width="800"><br>
</p>

<!--
## 📉 Theorical Fundamentation and Transition Mode

<p align="center">
  <strong>Buck Waveform</strong><br>
  <img src="09 - Pictures/Curve_buck.bmp" width="800"><br>
</p>

<p align="center">
   <strong>Boost Waveform</strong><br>
  <img src="09 - Pictures/Curves_Boost.bmp" width="800">
</p>
-->

---

## 🤖 Fuzzy Control System (Closed-Loop in Simulink)

<p align="center">
  <strong>Closed-Loop Control Model</strong><br>
  <img src="09 - Pictures/Malha Fechada.png" width="800"><br>
</p>

---

## 🖥️ Choosing a Microcontroller

<p align="center">
  <img src="09 - Pictures/Microcontroller_Choice.png" width="700"><br>
</p>

---

## 🧩 Schematic

<p align="center">
  <img src="09 - Pictures/Schematic Final Version DC DC CONVERTER_page-0002.jpg" width="900"><br>
</p>

---

## 🧱 3D PCB View

<p align="center">
  <img src="09 - Pictures/DC_DC_CONVERTER_TOP.jpg" width="800"><br>
</p>

---

## 👨‍💻 Authors

- Marcelo Oliveira de Jesus Júnior  
- Victor Pereira dos Santos  
- William Souza Santos
