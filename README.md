# Knapsack Problem Test Framework
---

## 📌 Project Overview

This project is a **Knapsack Problem Test Framework** built in C++. It automates the creation of test datasets and benchmarks different implementations of the classic **0/1 Knapsack Problem** using dynamic programming. It consists of three parts:

1. **Sample Generator** – creates random test files with item values, weights, and knapsack capacity.
2. **Test Runner** – reads each test file, runs the knapsack algorithm, and logs results and execution time.
3. **Knapsack Algorithms** – includes two variations of the dynamic programming solution:

   * Top-down 2D DP
   * Space-optimized 1D DP

---

## ✅ Project Features

* 📂 **Automatic Dataset Generator**:
  Generates random `.txt` files with customizable item count, max value, and number of samples.

* ⚙️ **Two DP Implementations**:
  Includes standard 2D and optimized 1D DP approaches for solving the 0/1 knapsack problem.

* ⏱️ **Performance Benchmarking**:
  Measures execution time for each test case using `chrono` and logs detailed results in `log.txt`.

* 📁 **File-based Input/Output**:
  Uses the filesystem to process all samples in a directory automatically.

* 🧪 **Scalable Testing**:
  Supports testing multiple instances efficiently, useful for performance evaluation or algorithm comparisons.

---
Here’s a suitable **folder structure** and **usage section** you can add to your `README.md`:

---

## 📁 Folder Structure

```
knapsack-project/
├── samples/                # Auto-generated sample input files
│   ├── sample_1.txt
│   ├── sample_2.txt
│   └── ...
├── algorithm1.cpp          # Knapsack implementation (2D or 1D DP)
├── generator.cpp           # Sample input generator
├── tester.cpp              # Test runner and logger
├── log.txt                 # Output log with results and timings
├── README.md               # Project documentation
└── Makefile / build.sh     # (Optional) For compiling all components
```

---

## 🛠️ Usage

### 🔹 1. Compile the Files

You can compile the files using `g++`:

```bash
g++ -std=c++17 Randomizer.cpp -o generator
g++ -std=c++17 tester.cpp -o tester
```

> Ensure that `algorithm1.cpp` is correctly included in `tester.cpp`.

---

### 🔹 2. Generate Samples

Run the generator to create test cases:

```bash
./Randomizer
```

You'll be prompted to enter:

* `n`: number of items per test
* `m`: number of test files to generate
* `k`: max value/weight range

Example:

```
Enter number of elements per sample (n): 5
Enter number of samples to generate (m): 3
Enter maximum range value (k): 50
```

---

### 🔹 3. Run the Tester

After generating samples, execute:

```bash
./tester
```

It will:

* Read all `.txt` files in `./samples/`
* Apply the knapsack algorithm specified in the header files.
* Log results and time in `log.txt`

---

