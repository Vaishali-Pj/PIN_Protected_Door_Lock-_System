# 🔐 PIN Protected Door Lock System

A simulation of a PIN-based door locking system using an ESP32, 4x4 Keypad, LCD, Servo Motor, and Buzzer.  
This project is built and tested on [Wokwi Simulator](https://wokwi.com/projects/440609363104521217).

---

## 📌 Features
- Enter a secure **4-digit PIN** via a 4x4 Keypad.
- **LCD Display** prompts the user and shows input in real time.
- **Buzzer feedback** for keypresses, successful authentication, or errors.
- **Access Control**:
  - ✅ Correct PIN → Displays "Access Granted", unlocks the servo (90°) for 5 seconds, and gives a confirmation beep.  
  - ❌ Wrong PIN → Displays "Access Denied" and triggers three error beeps.
- Reset option using `*` to clear input.

---

## 🛠️ Hardware Components
- ESP32 (or Arduino-compatible MCU)  
- 4x4 Matrix Keypad  
- 16x2 I²C LCD Display  
- Servo Motor (lock mechanism)  
- Buzzer  

---

## ⚙️ How It Works
1. The LCD prompts: **"Enter PIN:"**  
2. User enters the digits on the keypad → input is shown on the LCD.  
3. On pressing `#`:  
   - The system checks the entered PIN against the stored PIN (`1234`).  
   - If correct → Unlocks for 5 seconds.  
   - If incorrect → Displays error and buzzer beeps three times.  
4. Pressing `*` clears the current input.  

---

## 📂 Project Structure
- `main.ino` → Core Arduino/ESP32 code.  
- `simulation` → [Wokwi Project Link](https://wokwi.com/projects/440609363104521217).  

---

## 🚀 Getting Started
1. Open the [Wokwi Project](https://wokwi.com/projects/440609363104521217).  
2. Click ▶ Run to start the simulation.  
3. Enter `1234#` to unlock, or any other sequence to test denial.  

---

## 🔧 Future Improvements
- Configurable PIN stored in EEPROM/Flash.  
- Multiple user PIN support.  
- Add a relay to control real door lock hardware.  
- Mobile app integration for remote unlocking.

---

## 👩‍💻 Author
**Vaishali Pujari**  
Electronics & Communication Engineering | IoT & Embedded Systems Enthusiast  
