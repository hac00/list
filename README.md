# 🔗 Singly Linked List Library in C

A lightweight, modular, and fully custom implementation of a Singly Linked List in C. Built from scratch to master pointers, dynamic memory allocation (`malloc`/`free`), and modular project structuring (`.h` and `.c` separation).

---

## 📁 Project Structure

```text
├── list.h      # Header file (struct definition and function prototypes)
├── list.c      # Library implementation (all linked list operations)
├── main.c      # Comprehensive test suite and usage examples
└── README.md   # Documentation
```

---

## ⚙️ Features

### 1. Insertion
- **Insert at Start:** Prepends a new node to the beginning of the list.
- **Insert at End:** Appends a new node to the tail of the list.

### 2. Removal & Deletion
- **Remove Start:** Deletes the head node and shifts the list.
- **Remove End:** Deletes the tail node.
- **Remove by Position:** Deletes a node at a specific index/position.
- **Remove by Value:** Deletes the first node matching a specific integer value.

### 3. Data Processing & Queries
- **Count Nodes:** Returns the total number of elements.
- **Sum Values:** Computes the total sum of all node values.
- **Average Value:** Calculates the mathematical average of the list data.
- **Highest Value:** Finds the maximum value in the list (first occurrence).
- **Lowest Value:** Finds the minimum value in the list (first occurrence).
- **Find Node:** Searches for a value and returns its position.

### 4. Advanced Operations & Utilities
- **List to Array:** Converts the linked list into a dynamically allocated array on the heap.
- **Copy List:** Creates a full, deep-copy clone of an existing list.
- **Random Allocation:** Generates a list with a random number of nodes.
- **Random Values:** Populates nodes with random integers.
- **Printing Utilities:** Custom pretty-printers for lists, heap arrays, and raw memory addresses.

---

## 🚀 How to Compile and Run

If you are using `gcc` in your terminal, compile all source files together with the following command:

```bash
gcc main.c list.c -o test
```

Then, run the executable:

```bash
# On Linux/macOS
./test

# On Windows (PowerShell/CMD)
.\test.exe
```