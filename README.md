# Traffic Light Simulator

An Arduino-controlled traffic light, built on a breadboard and then turned into a custom PCB in KiCad.

<img width="300"  alt="Screenshot 2026-09-09 234809" src="https://github.com/user-attachments/assets/5c4270d9-9b0b-4468-8f3f-f0c1b6e2b48b" />

## What it does

Three LEDs cycle through a standard traffic light sequence.

| Light  | Arduino Pin | Duration |
|--------|-------------|----------|
| Green  | D4          | 3 s      |
| Yellow | D3          | 1 s      |
| Red    | D2          | 3 s      |

## Hardware

- Arduino Uno R3
- 3x 5 mm THT LEDs (red, yellow, green)
- 3x 220 Ω current-limiting resistors
- 1x 4-pin male header (GND + 3 signals)

Each LED anode connects to its Arduino pin through a 220 Ω resistor; all cathodes share a common ground. That gives roughly 14 mA per LED, well under the Uno's 20 mA per-pin limit.

## PCB

Designed in KiCad 10. LEDs grouped at the top, resistors in a row below, 4-pin header at the bottom edge, and four M3 mounting holes at the corners.

<img width="300"  alt="IMG_3521" src="https://github.com/user-attachments/assets/db6ea260-05f7-4428-9b0e-84e4cefb1fec" />

<img width="300"  alt="Screenshot 2026-09-09 234824" src="https://github.com/user-attachments/assets/6a089e2b-b565-40b9-b878-12a83bc294b4" />

![3D render](images/pcb-3d.png)

Footprints:
- LEDs: `LED_THT:LED_D5.0mm`
- Resistors: `Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal`
- Header: `Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical`

## Running it

1. Flash `TrafficLights.ino` to an Arduino Uno
2. Connect the header to the Uno: GND to GND, signals to D2, D3, D4
3. Power over USB

Gerbers are in `/kicad` if you want to fabricate the board.

## Possible improvements

- Pedestrian crossing button with interrupt-driven state change
- Replace blocking `delay()` calls with `millis()` timing so the board can respond to input mid-cycle
- Second light head to simulate a full intersection
