# Design-and-Implementation-of-PWM-Using-RISC-V-Processor-
Design and implementation of a Pulse Width Modulation (PWM) system using a RISC-V processor. Includes design, simulation, and testing for applications like motor control and embedded systems, with FPGA-based verification.


Pulse Width Modulation(PWM) is widely used in 
various applications, including embedded systems, VLSI, and 
power management circuits, for precise control of signals such as 
motor speed regulation and power efficiency optimization. This 
work focuses on integrating a PWM module with a RISC-V SoC 
using GPIO-based communication, enabling efficient hardware- 
level control without requiring complex software processing. The 
PWM module receives external control signals to modify the 
duty cycle, allowing real-time speed control. This implementation 
ensures a simple yet effective design, eliminating the need for 
complex interfacing mechanisms. Hardware validation confirms 
the system’s reliability and responsiveness, making it suitable 
for VLSI and embedded applications that require precise and 
efficient power management. This work demonstrates the feasibility of direct PWM integration with RISC-V processors, 
providing a foundation for further enhancements in real-time 
control applications.


## Methodology

This project implements a **PWM-based DC Motor Control System** using the **VEGA ET1035 RISC-V processor** on the **Arty A7 FPGA** platform. The workflow integrates hardware-level PWM generation with real-time software control for precise duty cycle modulation.
![Simulation Result](slide_sim.png)

### 1. Hardware Design (Verilog)
- Designed a Verilog module to generate PWM signals for motor speed and LED brightness control.  
- Implemented **counter-based logic** to define ON/OFF durations based on the duty cycle.  
- Ensured modularity for easy integration with other SoC components.

### 2. FPGA Configuration (Vivado)
- Synthesized and implemented the Verilog module using **Xilinx Vivado**.  
- Performed **port mapping** to memory-mapped registers for direct processor access.  
- Generated FPGA configuration files:
  - `.bit` — Bitstream for FPGA programming.  
  - `.bin` — Binary file stored in non-volatile memory for persistent configuration.

### 3. Software Development (C Programming)
- Developed **C source code** to interface with the PWM registers via the RISC-V core.  
- Integrated **real-time duty cycle control** to dynamically regulate motor speed and LED brightness.  
- Compiled the code with the **RISC-V GCC toolchain** to generate the processor executable.

### 4. System Integration
- Uploaded the compiled binary to the processor using **Tera Term** for serial communication and debugging.  
- Validated GPIO pin mapping for accurate hardware interfacing with the motor and LED.  

### 5. Testing and Validation
- Monitored PWM output waveforms using an **oscilloscope** to ensure accurate duty cycle modulation.  
- Performed real-time validation for:
  - **LED brightness control** under varying duty cycles.  
  - **Motor speed control** with smooth, stable response.  
- Confirmed the system’s robustness and responsiveness for real-time applications.

This methodology establishes an efficient, integrated hardware-software platform capable of precise, low-latency control suitable for embedded and VLSI applications.

