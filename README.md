# 🪙 Multi-Currency Coin Change Calculator

<div align="center">

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A modular, file-driven C application that calculates optimal coin change across multiple currencies.*

</div>

---

## 📌 Overview

This project contains **two versions** of a coin change calculator written in C. Both versions use a **greedy algorithm** to calculate the minimum number of coins needed for a given amount, and support **USD, AUD, and EUR** currencies.

| Version | Description |
|---|---|
| 🟠 Basic Version | Console-based, single-session calculator |
| 🟢 Advanced Version | File-driven, multi-record system with search and CSV export |

---

## 💰 Coin Denominations

| Currency | Coins (cents) |
|---|---|
| US$ | 50, 25, 10, 1 |
| AU$ | 50, 20, 10, 5 |
| EUR | 20, 10, 5, 1 |

---

## 🗂️ Project Structure

```
coin-change-calculator/
│
├── basic-version/
│   ├── main.c              # Entry point and main loop
│   ├── Coinfunctions.c     # Coin logic, validation, calculation, display
│   ├── coin_functions.h    # Function declarations
│   └── README.md           # Basic version documentation
│
├── advanced-version/
│   ├── main.c              # Entry point — loads data, starts menu loop
│   ├── types.c / .h        # Shared data structures and denomination tables
│   ├── file_handler.c / .h # File reading, parsing, validation, CSV export
│   ├── calculator.c / .h   # Greedy coin calculation logic
│   ├── search.c / .h       # Name-based record lookup
│   ├── display.c / .h      # Console output and user input
│   ├── menu.c / .h         # Menu loop and user interaction
│   ├── validation.c / .h   # Command-line argument validation
│   ├── coins.txt           # Sample input file
│   └── README.md           # Advanced version documentation
│
└── README.md
```

---

## 🟠 Basic Version

A simple interactive calculator where the user selects a currency, enters an amount, and gets the coin breakdown instantly.

### Compile & Run
```bash
cd basic-version
gcc -o calculator main.c Coinfunctions.c
```
```bash
# Windows
.\calculator.exe

# macOS / Linux
./calculator
```

### Sample Session
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

Do you want to continue? (Y/N): N
Program exited successfully.
```

---

## 🟢 Advanced Version

A file-driven system that reads multiple customer records, aggregates amounts per person, allows name-based search, and exports results to CSV.

### Compile & Run
```bash
cd advanced-version
gcc -o coin_program main.c menu.c search.c types.c validation.c calculator.c display.c file_handler.c
```
```bash
# Windows
.\coin_program.exe coins.txt

# macOS / Linux
./coin_program coins.txt
```

### Input File Format
```
10
Jane 30 cents in AU$
Joe 85 cents in EUR
Jane 25 cents in AU$
Bob 50 cents in US$
```

### Menu Options
```
1. Enter name   → Search for a customer and view their coin breakdown
2. Exit         → Save all results to change.csv and quit
```

---

## ✅ Validation Rules

| Rule | Details |
|---|---|
| Currency | Must be a supported type — USD, AUD, or EUR |
| Amount range | Must be between 1 and 95 cents inclusive |
| AUD rule | Amount must be divisible by 5 |

---

## 🧠 Key Concepts Demonstrated

| Concept | How It's Applied |
|---|---|
| Greedy Algorithm | Largest denomination selected first, working downward |
| Structs & Arrays | `PersonRecord` struct stores per-currency amounts and coin counts |
| File I/O | Reading from `.txt` input files, writing to `.csv` output |
| Modular Design | Each module has a single, well-defined responsibility |
| Input Validation | Invalid inputs are rejected with descriptive error messages |
| String Handling | Case-insensitive name search using `strcasecmp` |

---

## 🚀 Future Improvements

- [ ] Support for additional currencies (GBP, INR, JPY)
- [ ] Dynamic denomination config via external config file
- [ ] Sort output alphabetically by customer name
- [ ] Unit tests for calculator and validation modules
- [ ] Cross-platform `Makefile` for easier compilation

---

## 👤 Author

**Bibek Chaudhary**
📧 bibekchaudhary6362@gmail.com
🐙 [github.com/bibekchaudhary6362-hash](https://github.com/bibekchaudhary6362-hash)

---

<div align="center">
<sub>Built in C · Shared for portfolio and educational purposes</sub>
</div>
