# 🎮 Arduino Joystick Combo Controller

An **Arduino Uno** project that demonstrates **analog input handling**, **output control**, and **multi-directional logic** using a **joystick module**, **LEDs**, **a passive buzzer**, and a **laser module**.

This small project combines electronics, programming, and logic design — ideal for portfolios and interviews with embedded systems or IoT companies.

---

## 🚀 Features

- Reads joystick position from **two analog axes (VRx & VRy)**.
- Detects **four main directions** and **four diagonal combinations**.
- Controls multiple outputs based on joystick direction:
  - **Left** → 🔴 Red LED  
  - **Right** → 🟢 Green LED  
  - **Up** → 🔊 Passive buzzer (tone)  
  - **Down** → 🔦 Laser module  
  - **Diagonals** → combination of the two corresponding outputs  
- Includes a **deadzone filter** to prevent random activations near center.
- Clean and modular Arduino code.

---

## 🧰 Components Used

| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno | 1 | Microcontroller board |
| Joystick Module | 1 | Dual-axis analog joystick (VRx, VRy) |
| Passive Buzzer (KY-006) | 1 | Emits tone using Arduino `tone()` |
| Laser Module (KY-008 or similar) | 1 | Controlled via digital output |
| Red LED | 1 | With 220Ω resistor |
| Green LED | 1 | With 220Ω resistor |
| Breadboard & Jumper Wires | — | For connections |

---

## ⚙️ Circuit Diagram / Wiring

| Component | Arduino Pin | Notes |
|------------|--------------|-------|
| **Joystick VRx** | `A0` | Horizontal axis (left/right) |
| **Joystick VRy** | `A1` | Vertical axis (up/down) |
| **Joystick VCC** | `5V` | Power |
| **Joystick GND** | `GND` | Ground |
| **Red LED (+)** | `D8` | 220Ω resistor → GND |
| **Green LED (+)** | `D9` | 220Ω resistor → GND |
| **Buzzer (SIG)** | `D6` | Passive buzzer |
| **Laser (S)** | `D7` | Active HIGH |
| **Laser GND / Joystick GND / LEDs GND** | `GND` | Common ground |

📝 *If you want to include the joystick button (SW), connect it to any digital pin with a pull-up resistor.*

---

🧪 Usage

Open joystick_combos.ino in the Arduino IDE.

Select Board → Arduino Uno.

Upload the sketch.

Move the joystick:

Left → Red LED lights

Right → Green LED lights

Up → Buzzer plays tone

Down → Laser activates

Diagonals trigger combinations (e.g., Up+Left = Buzzer + Red LED)
