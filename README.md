# 📁 Directory Manager - Filesystem Tool

A simple C++ program that allows users to manage directories and files using the C++17 `<filesystem>` library.

## ✅ Features

### ✔️ 1. Root Directory Initialization
- Automatically creates the `root` directory if it doesn't exist.
- All subdirectory operations occur within the root path.

### ✔️ 2. Subdirectory Operations
- **Create** subdirectories
- **Rename** subdirectories
- **Delete** subdirectories (with confirmation)
- **Navigate** into subdirectories
- **Return** to root

### ⏳ 3. File Operations (Coming Soon)
- **Create**, **Read**, **Update**, and **Delete** (CRUD) files within the current directory.

### ⏳ 4. Directory Statistics (Coming Soon)
- Count of:
  - All files
  - Files per extension/type
  - Subdirectories

---

## 📦 Setup

### Requirements
- C++17 or later
- A compiler that supports `<filesystem>` (e.g., g++ 9+, MSVC, Clang)

### Compile
```bash
g++ -std=c++17 main.cpp -o directoryManager
