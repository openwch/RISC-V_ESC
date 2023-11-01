# RISC-V ESC Base on CH32V203F8U6

* [Introduction](https://github.com/openwch/RISC-V_ESC#Introduction)<br>
* [Hardware](https://github.com/openwch/RISC-V_ESC#Hardware)<br>
* [Config](https://github.com/openwch/RISC-V_ESC#Config)<br>
* [Test](https://github.com/openwch/RISC-V_ESC#Test)<br>


## Introduction
The AM32 firmware has been ported to the RISC-V platform, and the main controller has chosen CH32V203F8U6, which is highly cost-effective. It can be compiled directly on MRS. At the same time, the bootloader program has been ported, and tool of Esc_Config_Tool_1_82_WIN can be used to configure and upgrade firmware for ESC.


## Hardware

### MCU
The resources of MCU are shown in the following figure,You can see that it has many peripheral resources.For more information, you can refer to the [wch](https://www.wch-ic.com/products/CH32V203.html?).<br>

<img src="docs/image/mcu.jpg" alt="mcu" style="zoom:70%;" />

But for ESC design, it cannot use all the peripherals. Therefore, I choose a QFN20(3mm*3mm) packaged chip CH32V203F8U6. The size is very small and the price is cheap.<br>

<img src="docs/image/mcu_packge.jpg" alt="mcu_packge" style="zoom:70%;" />


### System Block Diagram
<img src="docs/image/System_block.jpg" alt="System_block" style="zoom:70%;" />

Using TIM1 to output 3 sets of complementary PWM for driving MOSFEET, Using TIM2 for capturing external throttle signals, Using ADC to sample voltage, current, and temperature for low voltage protection, over current protection, and over temperature protection. Using internal OPA and BEMF to estimate rotor position. TIM3 and TIM4 is used to calculate commutation time and motor timing. Systick is used to complete some periodic tasks.

### PINS
<img src="docs/image/PINS.jpg" alt="PINS" style="zoom:80%;" />

AH AL BH BL CH CL:  TIM1 PWM outputs;<br>
INPUT: TIM2 Channel1  used to capture external throttle signals;<br>
A_BEMF: A-Phase BEMF, connect to the negative end-1 of OPA2(PA5);<br>
B_BEMF: B-Phase BEMF, connect to the negative end-0 of OPA2(PB10);<br>
C_BEMF: C-Phase BEMF, connect to the negative end-0 of OPA1(PB11);<br>
CC_BEMF: Neutral point BEMF, connect to the positive end-0 of OPA2(PB14) and positive end-0 of OPA1(PB15);<br>
ADC_V: Voltage sampling channel;<br>
ADC_I: Current sampling channel;<br>
 
In order to unify the interrupt entry of OPA, the outputs of OPA1(PA3) and OPA2(PA4) are merged into PA2, Using external interrupts of PA2 for zero crossing comparison processing. <font color=red>**Individual external interrupts can also be used to save one GPIO(PA2)**</font><br>

PA13 and PA14 are used to download bootloader  via WCH-LINKE. If necessary, the program can also reuse these two ports.<br>

For detailed information, please refer to the [schematic diagram](https://github.com/openwch/RISC-V_ESC/blob/main/docs/SCH_AM32_V203F8U6.pdf), <font color=red>**NOTE: The current schematic does not enable current sampling. If desired, simply amplify the current and connect the signal to PA6.**</font><br>


## Config

### Flashing BootLoader
1. For empty chips, BootLoader needs to be flashed via WCH-LINKE, Connect according to the diagram below.


   <img src="docs/image/bootloader.jpg" alt="bootloader" style="zoom:55%;" />
   <img src="docs/image/ESC_PCB.jpg" alt="ESC_PCB" style="zoom:80%;" />


2. Open the [Bootloader project](https://github.com/TianpeiLee/CH32V203_AM32_Bootloader) using MRS and download it directly after compilation.


    <img src="docs/image/mrs.jpg" alt="mrs" style="zoom:80%;" />

3. Use a [one-wire serial port](https://github.com/TianpeiLee/OneWireUSART) to connect to ESC and use tools to configure and update firmware. I used CH32V003 to perform a software conversion, and the wiring is shown in the following figure.

    <img src="docs/image/config.jpg" alt="config" style="zoom:55%;" />


    If the Bootloader is burned correctly, Open the configuration tool ***Esc_Config_Tool_1_82_WIN.exe*** and power on the ESC. Follow the steps in the following figure to click. When connecting for the first time, <font color=red>*'No EEprom'*</font> will be displayed!
    
    <img src="docs/image/first_power_on.jpg" alt="first_power_on" style="zoom:65%;" />

    Directly click on ***Send Default Settings*** below to burn the default values. After successful burning, power on again. Connect again and click ***M1***. The default parameters we just burned will be displayed.

    <img src="docs/image/default_para.jpg" alt="default_para" style="zoom:65%;" />


4. Flashing firmware and configurations
   
   Returning to the FLASH interface of the tool, we click on ***Load Firmware***, select the firmware we compiled in MRS, and the ***FLash Firmware*** button will pop up. Click to start updating the program. 


    <img src="docs/image/updata.jpg" alt="updata" style="zoom:100%;" />


    After the update is completed, power on again and connect ESC again to configure ESC. The specific meaning of configuration values can be found in the following [links](https://github.com/AlkaMotors/AM32-MultiRotor-ESC-firmware/wiki/ESC-Settings-Explained).

    <img src="docs/image/v203_para.jpg" alt="v203_para" style="zoom:100%;" />


## Test

The version I ported is V1.95, which supports signals such as dshot300, dshot600, and PWM. To test ESC, I used CH32V003 to create a [servo testing tool](https://github.com/TianpeiLee/ServoTestTool). You can connect it directly to the ESC to test.


<img src="docs/image/test.jpg" alt="test" style="zoom:55%;" /> <br>


### ESC Test
This video demonstrates the running of ESC under different signal input conditions.<br>
[<img src="docs/image/vedio1.jpg" alt="vedio1" style="zoom:72%;" />](https://youtu.be/h0iekUh7lSY)



### Output signal of servo testing tool
This video demonstrates three different output signals of a servo testing tool.<br>
[<img src="docs/image/vedio2.jpg" alt="vedio2" style="zoom:54%;" />](https://youtu.be/FwIuJzSEXmE)












