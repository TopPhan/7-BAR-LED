📟 Displaying Numbers on 7-Segment LED Using AVR

    This is a small project I made to practice controlling a 7-segment LED using an AVR (ATmega16/32). 
    I used Proteus for simulation and wrote the code in C.
    The program displays the number 07 on two 7-segment LEDs using multiplexing.

⚙️ Features

    Displays a two-digit number on 2x 7-segment LEDs.
    Uses multiplexing to control both LEDs with a shared data port.
    Written in C using basic AVR libraries.
    Simulated entirely in Proteus — no real hardware needed.
    
🛠 Tools Used

    Microcontroller: ATmega16/32
    Language: C
    Libraries:
    <avr/io.h> for I/O control
    <util/delay.h> for delays
    Simulation Software: Proteus
    
⚡ Code Explanation

    Clock Configuration:
    #define F_CPU 8000000UL
    Sets the system clock to 8 MHz to ensure accurate delays.

    I/O Pin Configuration:
    #define LED_Direction DDRD
    #define LED_PORT PORTD
    #define LED_chuc 0  // Controls tens digit LED
    #define LED_dvi  1  // Controls units digit LED
    PORTD is used to control the segments a-g of the LEDs.
    PORTC.0 and PORTC.1 are used to switch between the tens and units digits.
    
    Segment Code Array:
    char array[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
    This array holds the hex codes to display digits 0–9 on a common anode 7-segment LED.

    Display Function:
    void display(int a)
    This function takes a number from 00–99, splits it into tens and units digits, 
    Displays them using multiplexing. 
    Each LED is switched on and off alternately with delays, so they appear to be lit simultaneously.

    Main Loop:
    while (1) {
        display(07);
    }
    The loop constantly displays the number 07.

🔌 Simulating in Proteus

    Preparation:
    Microcontroller: ATmega16 or ATmega32
    2x Common Anode 7-Segment LEDs
    Current-limiting resistors (~330Ω)
    Proteus for simulation
    
    Wiring:
    PORTD connects to segments a-g of both LEDs.
    PORTC.0 → Controls tens digit LED (LED_chuc)
    PORTC.1 → Controls units digit LED (LED_dvi)
    Use resistors between PORTD and the LED segments to limit current.
    
    Running the Simulation:
    Compile the code and generate a HEX file.
    Load the HEX file into the ATmega16/32 in Proteus.
    Click Run — the number 07 should display on the LEDs.
    
📂 How to Compile and Run

  
📖 What I Learned

    How to control a 7-segment LED with an AVR microcontroller.
    Implementing multiplexing to control multiple LEDs using fewer I/O pins.
    Using Proteus for circuit simulation.
    Working with AVR libraries and writing embedded C code.

🚀 Ideas for Future Improvements

    Add push buttons to increment or decrement the displayed number (00–99).
    Create a countdown timer or stopwatch.
    Expand to 4x 7-segment LEDs.
    Integrate sensors (e.g., temperature, light) and display their readings.
    📸 Simulation Screenshot

📧 Contact

    Phan Hoàng Đỉnh – Fresher Embedded Developer
    📍 Ho Chi Minh City, Vietnam
    ✉️ topphanst@gmail.com
