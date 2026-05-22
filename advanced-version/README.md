# 🪙 Coin Change Calculator — Advanced Version

<div align="center">

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-Advanced-brightgreen?style=for-the-badge)

*A modular, file-driven C application that calculates optimal coin change across multiple currencies.*

</div>

---

## 📌 Overview

This is the **advanced version** of the Coin Change Calculator. It reads customer coin data from a structured text file, calculates the **minimum number of coins** required for each currency amount using a **greedy algorithm**, allows users to **search records by name**, and exports the final results to a **CSV file**.

Built with a clean modular architecture — every concern is separated into its own `.c` / `.h` file pair.

For the simpler console-based version, see the `basic-version` folder.

---

## ✨ Features

| Feature | Description |
|---|---|
| 🌍 Multi-Currency Support | Handles **USD**, **AUD**, and **EUR** coin denominations |
| 🧮 Greedy Coin Algorithm | Calculates the minimum coins needed for any valid amount |
| 📂 File-Based Input | Reads and aggregates multiple customer records from a `.txt` file |
| 🔍 Name Search | Search and display a specific customer's full coin breakdown |
| 📊 CSV Export | Saves all processed results to `change.csv` on exit |
| ✅ Input Validation | Rejects invalid amounts, unsupported currencies, and malformed lines |
| 🧱 Modular Design | Clean separation across `.c` and `.h` files |

---

## 🗂️ Project Structure

```
advanced-version/
│
├── main.c              # Program entry point — loads data, starts menu loop
├── types.c / .h        # Shared data structures, currency & denomination tables
├── file_handler.c / .h # File reading, line parsing, validation, CSV export
├── calculator.c / .h   # Greedy coin calculation logic
├── search.c / .h       # Name-based record lookup
├── display.c / .h      # All console output and user input functions
├── menu.c / .h         # Menu loop and user interaction flow
├── validation.c / .h   # Command-line argument validation
│
├── coins.txt           # Sample input file
└── README.md
```

---

## 📥 Input File Format

The input file must begin with the **number of records**, followed by one entry per line:

```
10
Jane 30 cents in AU$
Joe 85 cents in EUR
Jane 25 cents in AU$
Bob 50 cents in US$
Alice 40 cents in AU$
```

> **Rules:**
> - Amounts must be between **1 and 95 cents**
> - AUD amounts must be **divisible by 5**
> - Supported currencies: `US$`, `AU$`, `EUR`
> - Multiple entries for the same person are **aggregated** automatically

---

## 💰 Coin Denominations

| Currency | Coins (cents) |
|---|---|
| US$ | 50, 25, 10, 1 |
| AU$ | 50, 20, 10, 5 |
| EUR | 20, 10, 5, 1 |

---

## ⚙️ How to Compile & Run

### Compile
```bash
gcc -o coin_program main.c menu.c search.c types.c validation.c calculator.c display.c file_handler.c
```

### Run
```bash
# Windows
.\coin_program.exe coins.txt

# macOS / Linux
./coin_program coins.txt
```

### Menu Options
```
1. Enter name   → Search for a customer and view their coin breakdown
2. Exit         → Save all results to change.csv and quit
```

---

## 📤 Sample Output

**Searching for "Jane":**
```
Customer:
Jane 55 cents in AU$
Change:
50 cents: 1
5 cents: 1

Customer:
Jane 15 cents in US$
Change:
10 cents: 1
1 cents: 5
```

**Exported CSV (`change.csv`):**
```
Jane, the change for 55 cents in AU$ is 1,0,1,0
Jane, the change for 15 cents in US$ is 0,0,1,5
Bob, the change for 50 cents in US$ is 1,0,0,0
```

---

## 🧠 Key Concepts Demonstrated

| Concept | How It's Applied |
|---|---|
| Greedy Algorithm | Selects the largest coin denomination first and works downward |
| Structs & Arrays | `PersonRecord` struct stores per-currency amounts and coin counts |
| File I/O | `fopen`, `fscanf`, `fprintf` for reading input and writing CSV |
| Modular Design | Each module has a single, well-defined responsibility |
| Input Validation | Invalid lines are skipped with descriptive error messages |
| String Handling | Case-insensitive name search using `strcasecmp` |

---

## 🚀 Future Improvements

- [ ] Support for additional currencies (GBP, INR, JPY)
- [ ] Dynamic denomination config via external JSON/config file
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
