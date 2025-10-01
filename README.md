# 🔥 Unix Signal Chat System

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Unix%2FLinux-orange.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A real-time inter-process communication system using Unix signals. This project demonstrates advanced system programming concepts by implementing a client-server chat system where messages are transmitted bit by bit using only `SIGUSR1` and `SIGUSR2` signals.

## 📋 Table of Contents

- [Overview](#overview)
- [Key Features](#key-features)
- [Technical Concepts](#technical-concepts)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Examples](#examples)
- [Technical Implementation](#technical-implementation)
- [Contributing](#contributing)

## 🎯 Overview

This project implements a sophisticated communication protocol using Unix signals to transmit text messages between processes. The system converts each character into its binary representation and sends it bit by bit using two different signals, showcasing low-level system programming and signal handling.

## ⚡ Key Features

- **Real-time Communication**: Instant message transmission between client and server
- **Binary Encoding**: Character-to-binary conversion and bit-level transmission
- **Signal-based Protocol**: Uses only SIGUSR1 and SIGUSR2 for communication
- **Acknowledgment System**: Server confirms message receipt (bonus version)
- **Error Handling**: Robust PID validation and signal error management
- **Memory Efficient**: Minimal memory footprint with bit manipulation
- **Process Safety**: Safe signal handling with proper masking

## 🧠 Technical Concepts

### Signal Processing
- **SIGUSR1**: Represents binary `1`
- **SIGUSR2**: Represents binary `0`
- **sigaction()**: Advanced signal handling with context information
- **Signal masking**: Prevents signal interference during processing

### Bit Manipulation
- **Character encoding**: 8-bit ASCII representation
- **Bit shifting**: Right shift operations for bit extraction
- **Binary reconstruction**: Assembling bits back to characters

### Inter-Process Communication (IPC)
- **Process identification**: Using PID for targeted communication
- **Asynchronous messaging**: Non-blocking signal transmission
- **State management**: Maintaining communication state across signals

## 📁 Project Structure

```
unix-signal-chat/
├── 📁 include/
│   ├── minitalk.h          # Main header file
│   └── minitalk_bonus.h    # Bonus features header
├── 📁 src/
│   ├── server.c            # Server implementation
│   ├── client.c            # Client implementation
│   ├── server_bonus.c      # Server with acknowledgment
│   ├── client_bonus.c      # Client with acknowledgment
│   └── utils.c             # Utility functions
├── Makefile                # Build configuration
└── README.md              # Project documentation
```

## 🚀 Installation

### Prerequisites
- GCC compiler
- Unix/Linux operating system
- Make utility

### Build Commands

```bash
# Clone the repository
git clone https://github.com/yalives7/unix-signal-chat.git
cd unix-signal-chat

# Build standard version
make

# Build bonus version with acknowledgment
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Rebuild everything
make re
```

## 🎮 Usage

### Standard Version

#### 1. Start the Server
```bash
./server
```
The server will display its PID (Process ID).

#### 2. Send Messages
```bash
./client [SERVER_PID] "Your message here"
```

### Bonus Version (with Acknowledgment)

#### 1. Start the Bonus Server
```bash
./server_bonus
```

#### 2. Send Messages with Confirmation
```bash
./client_bonus [SERVER_PID] "Your message here"
```

## 🔬 How It Works

### Message Transmission Process

1. **Character Encoding**: Each character is converted to 8-bit binary
2. **Bit Transmission**: Each bit is sent as a signal (SIGUSR1=1, SIGUSR2=0)
3. **Server Reception**: Server receives signals and reconstructs characters
4. **Display**: Reconstructed message is displayed on server terminal

### Signal Flow Diagram

```
Client Process          Server Process
     |                       |
     |---[SIGUSR1/2]-------->|  (Bit transmission)
     |---[SIGUSR1/2]-------->|  (8 signals per char)
     |---[SIGUSR1/2]-------->|  (Sequential processing)
     |                       |
     |<--[SIGUSR2]-----------| (Acknowledgment - bonus)
```

## 📚 Examples

### Example 1: Basic Communication
```bash
# Terminal 1 - Start server
./server
Server PID: 12345

# Terminal 2 - Send message
./client 12345 "Hello World!"
```

Server output:
```
Server PID: 12345
Hello World!
```

### Example 2: Bonus with Acknowledgment
```bash
# Terminal 1 - Start bonus server
./server_bonus
Server PID: 12345

# Terminal 2 - Send message with confirmation
./client_bonus 12345 "System programming rocks!"
Message Delivered
```

Server output:
```
Server PID: 12345
System programming rocks!
```

## 🔧 Technical Implementation

### Core Functions

#### `send_character(char c, int pid)`
- Converts character to 8-bit representation
- Sends each bit as SIGUSR1 (1) or SIGUSR2 (0)
- Includes timing delays for reliable transmission

#### `handler(int sig, siginfo_t *info, void *ucontext)`
- Receives and processes incoming signals
- Reconstructs characters from received bits
- Handles acknowledgment in bonus version

#### `ft_safe_atoi(char *str)`
- Safely converts string to integer
- Validates PID format and range
- Prevents buffer overflow attacks

### Key Technical Details

- **Timing**: 700 microseconds delay between signals for stability
- **Bit Order**: MSB (Most Significant Bit) first transmission
- **Signal Masking**: Prevents signal loss during processing
- **Error Handling**: Graceful failure on invalid PIDs or signal errors

## 🎓 Learning Outcomes

This project demonstrates:

- **System Programming**: Low-level Unix system calls and signal handling
- **Bit Manipulation**: Binary operations and character encoding
- **Process Communication**: Inter-process communication protocols
- **Error Handling**: Robust error management in system programming
- **Memory Management**: Efficient resource utilization
- **Protocol Design**: Custom communication protocol implementation

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 👨‍💻 Author

**Sungor** - Computer Engineering Student
- 42 School Project (Minitalk)
- Enhanced and documented for educational purposes

---

⭐ If you found this project helpful, please give it a star!

🔗 **Related Concepts**: Unix Signals, IPC, System Programming, Bit Manipulation, Client-Server Architecture
