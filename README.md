# Automated Dino Game

Hardware automation for the Chrome dinosaur game: **light-dependent resistors (LDRs)** watch the screen brightness, and a **servo** physically presses the spacebar (or touch target) when an obstacle is detected.

---

## How it works

1. **LDRs** are placed so their readings change when the playfield darkens (e.g. cactus or bird entering the detection zone). The sketch reads two analog channels (`A0` and `A1`) so you can use two sensing spots or distinguish different brightness conditions.
2. The **servo** toggles between an “unpressed” and “pressed” angle to tap the keyboard key that makes the dino jump.
3. **Thresholds** in firmware decide when the reading counts as “obstacle seen” and whether to fire a press. Tune `threshold`, `threshold2`, and the servo angles for your setup.

Logic summary (see the sketch for exact conditions):

- The servo rests at **unpress** most of the loop.
- Depending on whether `A1` is above `threshold2`, the sketch uses **either** “jump when `A0` is below `threshold`” **or** “jump when `A0` is above `threshold`” so you can match different lighting or sensor placement.

---

## Hardware

| Item        | Notes |
|------------|--------|
| Arduino    | Uno or compatible (analog `A0` / `A1`, digital pin `9` for servo) |
| 2× LDR     | Each in a **voltage divider** (e.g. LDR to GND, fixed resistor to 5 V, tap to `A0` or `A1`) |
| Servo      | Signal on **pin 9**; power per servo datasheet (often separate 5 V supply for larger servos; common ground with Arduino) |
| Mechanical | Servo horn or linkage aligned to press spacebar / on-screen jump control |

Pins used in code:

- **Pin 9** — servo signal  
- **A0**, **A1** — LDR divider outputs  

Constants in `sketch_aug13a.ino`:

- `threshold` (440) — primary obstacle sensitivity on `A0`  
- `threshold2` (600) — chooses which comparison branch to use based on `A1`  
- `unpress_angle` (60), `press_angle` (0) — servo positions for released vs pressed  

Adjust these after mounting the LDRs and servo; use **Serial Monitor at 9600 baud** to watch `A0` and `A1` while the game runs.

---

## Software

- **Arduino IDE** (or PlatformIO) with the **Servo** library (included with the IDE).
- Open `Dino game/sketch_aug13a.ino`, select your board and port, upload.

---

## Project structure

```
Automated-Dino-Game/
└── Dino game/
    └── sketch_aug13a.ino   # Main firmware (LDR + servo control)
```

---

## Usage tips

1. Open the dino game (`chrome://dino` or offline Chrome dinosaur).  
2. Position LDRs so obstacle appearance reliably moves analog readings past your thresholds.  
3. Calibrate with Serial Monitor; tweak `#define` values and re-upload.  
4. Ensure the servo does not damage the keyboard or screen; add a soft fingertip on the horn if needed.

---

## Disclaimer

This is an educational hardware demo. Be careful with servo torque, wiring, and what the mechanism contacts. You are responsible for safe mounting and power supply choice.
