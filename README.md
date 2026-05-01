
### 📄 README.md
## Overview
# LDLL and CDLL (Doubly Linked Lists)

This project implements two fundamental data structures in C++:
- **LDLL (Linear Doubly Linked List)**: A standard doubly linked list with head and tail pointers.
- **CDLL (Circular Doubly Linked List)**: A variation where the last node connects back to the first, forming a circular structure.
- **DNODE**: A reusable node structure used by both LDLL and CDLL.


## 📂 Folder Structure

```
LDLLandCDLL/
├── LDLLandCDLL/
│   ├── CDLL.h
│   ├── DNODE.h
│   ├── LDLL.h
│   ├── LDLLandCDLL.vcxproj
│   └── LDLLandCDLL.vcxproj.filters
├── main.cpp            # Driver file (entry point)
├── LDLLandCDLL.sln     # Visual Studio solution file
├── README.md
├── .gitignore
└── .gitattributes
```


## ⚙️ Build & Run Instructions

### 🔹 On Windows (Visual Studio)
1. Open `LDLLandCDLL.sln` in Visual Studio.
2. Add `main.cpp` at the root and include all `.h` files from `LDLLandCDLL/`.
3. Build the solution (`Ctrl+Shift+B`).
4. Run with **Ctrl+F5**.

### 🔹 On Linux/Mac (g++)
Compile `main.cpp` together with the headers:

``` bash
g++ main.cpp -o linkedlist_app
./linkedlist_app
```

## 🧩 Example Usage 

```
    // Linear Doubly Linked List
    LDLL ldll;
    ldll.insertAtHead(10);
    ldll.insertAtTail(20);
    ldll.display();   // Expected: 10 <-> 20

    // Circular Doubly Linked List
    CDLL cdll;
    cdll.insertAtHead(5);
    cdll.insertAtTail(15);
    cdll.display();   // Expected: 5 <-> 15 (circular)

```

**Expected Output:**
```
LDLL: 10  20
CDLL: 5  15 (circular)
```


## 🚀 Features Implemented
- LDLL:
  - Insert at head/tail
  - Delete from head/tail
  - Display forward/backward
- CDLL:
  - Insert at head/tail
  - Delete from head/tail
  - Circular traversal
- DNODE: shared node structure
- Modular design with `.h` separation
- Demonstrates pointer manipulation and dynamic memory


## 📌 Future Improvements
- Add search and insert‑at‑position functions.
- Implement reverse traversal for CDLL.
- Add unit tests for robustness.



## 👤 Author
Developed by **Shanzay Malik**  
