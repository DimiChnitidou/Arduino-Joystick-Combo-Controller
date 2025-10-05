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

## 🧠 How It Works

The joystick provides two analog signals:

- **VRx** → for horizontal motion (`A0`)
- **VRy** → for vertical motion (`A1`)

The Arduino reads both analog values (0–1023) and calculates their deviation from the center point (~512) to detect the joystick’s direction.  
A **deadzone** around the center prevents small jitters or noise from triggering unwanted outputs.

Depending on the direction(s), the Arduino activates:

- **LEDs** → digital outputs (left/right)
- **Laser** → digital output (down)
- **Buzzer** → analog sound via `tone()` (up)

---

## 🧪 Usage

1. Open `joystick_combos.ino` in the **Arduino IDE**.  
2. Select **Board → Arduino Uno**.  
3. Upload the sketch to your Arduino board.  
4. Move the joystick in different directions and observe the outputs:

- **Left** → 🔴 Red LED lights up  
- **Right** → 🟢 Green LED lights up  
- **Up** → 🔊 Buzzer plays tone  
- **Down** → 🔦 Laser activates  
- **Diagonals** → combinations (e.g., Up + Left → Buzzer + Red LED)

---

## 🧩 Example Scenarios

| Joystick Direction | Activated Output |
|--------------------|------------------|
| Left | 🔴 Red LED |
| Right | 🟢 Green LED |
| Up | 🔊 Buzzer |
| Down | 🔦 Laser |
| Up + Left | 🔊 Buzzer + 🔴 Red LED |
| Down + Right | 🔦 Laser + 🟢 Green LED |
| Up + Right | 🔊 Buzzer + 🟢 Green LED |
| Down + Left | 🔦 Laser + 🔴 Red LED |
