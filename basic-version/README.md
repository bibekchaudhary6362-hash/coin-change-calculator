# 🪙 Coin Change Calculator — Basic Version

<div align="center">

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-Basic-orange?style=for-the-badge)

*A console-based C program that calculates optimal coin change for USD, AUD, and EUR.*

</div>

---

## 📌 Overview

This is the **basic version** of the Coin Change Calculator. The user selects a currency, enters an amount, and the program calculates the **minimum number of coins** required using a **greedy algorithm**. The session can repeat as many times as the user wants.

For the more advanced file-driven version, see the `advanced-version` folder.

---

## ✨ Features

| Feature | Description |
|---|---|
| 🌍 Multi-Currency Support | Handles **USD**, **AUD**, and **EUR** coin denominations |
| 🧮 Greedy Coin Algorithm | Calculates the minimum coins needed for any valid amount |
| ✅ Input Validation | Rejects invalid currency choices, out-of-range amounts, and AUD non-multiples of 5 |
| 🔁 Repeat Sessions | User can run multiple calculations without restarting the program |
| 🧱 Modular Design | Logic separated across `main.c`, `Coinfunctions.c`, and `coin_functions.h` |

---

## 💰 Coin Denominations

| Currency | Coins (cents) |
|---|---|
| USD | 50, 25, 10, 1 |
| AUD | 50, 20, 10, 5 |
| EUR | 20, 10, 5, 1 |

---

## 🗂️ File Structure

```
basic-version/
│
├── main.c            # Program entry point and main loop
├── Coinfunctions.c   # All coin logic — validation, calculation, display
└── coin_functions.h  # Function declarations
```

---

## ⚙️ How to Compile & Run

### Compile
```bash
gcc -o calculator main.c Coinfunctions.c
```

### Run
```bash
# Windows
.\calculator.exe

# macOS / Linux
./calculator
```

---

## 🖥️ Sample Session

```
Select a currency:
1 for USD
2 for AUD
3 for Euro
Enter your choice: 1

Enter an amount between 1 to 95: 85

You need 1 coin(s) of 50 cents.
You need 1 coin(s) of 25 cents.
You need 1 coin(s) of 10 cents.

Do you want to continue? (Y/N): Y

Select a currency:
1 for USD
2 for AUD
3 for Euro
Enter your choice: 2

Enter an amount between 1 to 95: 30

You need 1 coin(s) of 20 cents.
You need 1 coin(s) of 10 cents.

Do you want to continue? (Y/N): N
Program exited successfully.
```

---

## ✅ Validation Rules

| Rule | Details |
|---|---|
| Currency | Must be 1, 2, or 3 — anything else is rejected |
| Amount range | Must be between 1 and 95 cents inclusive |
| AUD rule | Amount must be divisible by 5 (no 1-cent coins in AUD) |

---

## 🧠 Key Concepts Demonstrated

| Concept | How It's Applied |
|---|---|
| Greedy Algorithm | Largest denomination selected first, working downward |
| Modular Design | Each function has a single, clear responsibility |
| Input Validation | Invalid inputs display error messages and re-prompt the user |
| Arrays | Coin denominations and counts stored in `int[4]` arrays |
| Loop Control | `do-while` loops for input, `while` loop for session repeat |

---

## 👤 Author

**Bibek Chaudhary**
📧 bibekchaudhary6362@gmail.com
🐙 [github.com/bibekchaudhary6362-hash](https://github.com/bibekchaudhary6362-hash)

---

<div align="center">
<sub>Built in C · Shared for portfolio and educational purposes</sub>
</div>
