# 🔥 Unix Signal Chat System | Unix Sinyal Tabanlı İletişim Sistemi

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Unix%2FLinux-orange.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

**English:** A real-time inter-process communication system using Unix signals. This project demonstrates advanced system programming concepts by implementing a client-server chat system where messages are transmitted bit by bit using only `SIGUSR1` and `SIGUSR2` signals.

**Türkçe:** Unix sinyallerini kullanarak gerçek zamanlı prosesler arası iletişim sistemi. Bu proje, sadece `SIGUSR1` ve `SIGUSR2` sinyallerini kullanarak mesajları bit bit ileten client-server chat sistemi ile gelişmiş sistem programlama kavramlarını göstermektedir.

## 📋 İçindekiler | Table of Contents

- [Genel Bakış | Overview](#genel-bakış--overview)
- [Önemli Özellikler | Key Features](#önemli-özellikler--key-features)
- [Teknik Kavramlar | Technical Concepts](#teknik-kavramlar--technical-concepts)
- [Proje Yapısı | Project Structure](#proje-yapısı--project-structure)
- [Kurulum | Installation](#kurulum--installation)
- [Kullanım | Usage](#kullanım--usage)
- [Nasıl Çalışır | How It Works](#nasıl-çalışır--how-it-works)
- [Örnekler | Examples](#örnekler--examples)
- [Teknik Uygulama | Technical Implementation](#teknik-uygulama--technical-implementation)
- [Katkıda Bulunma | Contributing](#katkıda-bulunma--contributing)

## 🎯 Genel Bakış | Overview

**Türkçe:** Bu proje, prosesler arasında metin mesajları iletmek için Unix sinyallerini kullanan gelişmiş bir iletişim protokolü uygular. Sistem her karakteri binary temsiline dönüştürür ve iki farklı sinyal kullanarak bit bit gönderir. Düşük seviye sistem programlama ve sinyal işleme konularını göstermektedir.

**English:** This project implements a sophisticated communication protocol using Unix signals to transmit text messages between processes. The system converts each character into its binary representation and sends it bit by bit using two different signals, showcasing low-level system programming and signal handling.

## ⚡ Önemli Özellikler | Key Features

- **Gerçek Zamanlı İletişim | Real-time Communication**: Client ve server arasında anlık mesaj iletimi
- **Binary Kodlama | Binary Encoding**: Karakter-to-binary dönüşümü ve bit seviyesinde iletim
- **Sinyal Tabanlı Protokol | Signal-based Protocol**: Sadece SIGUSR1 ve SIGUSR2 kullanır
- **Onay Sistemi | Acknowledgment System**: Server mesaj alımını onaylar (bonus versiyon)
- **Hata Yönetimi | Error Handling**: Sağlam PID doğrulama ve sinyal hata yönetimi
- **Bellek Verimli | Memory Efficient**: Bit manipülasyonu ile minimal bellek kullanımı
- **Proses Güvenliği | Process Safety**: Uygun maskeleme ile güvenli sinyal işleme

## 🧠 Teknik Kavramlar | Technical Concepts

### Sinyal İşleme | Signal Processing
- **SIGUSR1**: Binary `1` temsil eder
- **SIGUSR2**: Binary `0` temsil eder  
- **sigaction()**: Bağlam bilgisi ile gelişmiş sinyal işleme
- **Signal masking**: İşleme sırasında sinyal karışmasını önler

### Bit Manipülasyonu | Bit Manipulation
- **Karakter kodlama | Character encoding**: 8-bit ASCII temsili
- **Bit kaydırma | Bit shifting**: Bit çıkarma için sağa kaydırma işlemleri
- **Binary yeniden yapılandırma | Binary reconstruction**: Bitleri karakterlere geri dönüştürme

### Prosesler Arası İletişim | Inter-Process Communication (IPC)
- **Proses tanımlama | Process identification**: Hedefli iletişim için PID kullanımı
- **Asenkron mesajlaşma | Asynchronous messaging**: Engellenmeyen sinyal iletimi
- **Durum yönetimi | State management**: Sinyaller arasında iletişim durumunu koruma

## 📁 Proje Yapısı | Project Structure

```
unix-signal-chat/
├── 📁 include/
│   ├── minitalk.h          # Ana header dosyası | Main header file
│   └── minitalk_bonus.h    # Bonus özellikler header | Bonus features header
├── 📁 src/
│   ├── server.c            # Server uygulaması | Server implementation
│   ├── client.c            # Client uygulaması | Client implementation
│   ├── server_bonus.c      # Onaylamalı server | Server with acknowledgment
│   ├── client_bonus.c      # Onaylamalı client | Client with acknowledgment
│   └── utils.c             # Yardımcı fonksiyonlar | Utility functions
├── Makefile                # Derleme yapılandırması | Build configuration
└── README.md              # Proje dokümantasyonu | Project documentation
```

## 🚀 Kurulum | Installation

### Gereksinimler | Prerequisites
- GCC derleyici | GCC compiler
- Unix/Linux işletim sistemi | Unix/Linux operating system
- Make yardımcı programı | Make utility

### Derleme Komutları | Build Commands

```bash
# Depoyu klonla | Clone the repository
git clone https://github.com/yalives7/unix-signal-chat.git
cd unix-signal-chat

# Standart sürümü derle | Build standard version
make

# Onaylamalı bonus sürümü derle | Build bonus version with acknowledgment
make bonus

# Object dosyalarını temizle | Clean object files
make clean

# Her şeyi temizle | Clean everything
make fclean

# Her şeyi yeniden derle | Rebuild everything
make re
```

## 🎮 Kullanım | Usage

### Standart Versiyon | Standard Version

#### 1. Server'ı Başlat | Start the Server
```bash
./server
```
Server PID'ini (Process ID) görüntüleyecek | The server will display its PID (Process ID).

#### 2. Mesaj Gönder | Send Messages
```bash
./client [SERVER_PID] "Mesajınız buraya | Your message here"
```

### Bonus Versiyon (Onaylamalı) | Bonus Version (with Acknowledgment)

#### 1. Bonus Server'ı Başlat | Start the Bonus Server
```bash
./server_bonus
```

#### 2. Onaylamalı Mesaj Gönder | Send Messages with Confirmation
```bash
./client_bonus [SERVER_PID] "Mesajınız buraya | Your message here"
```

## 🔬 Nasıl Çalışır | How It Works

### Mesaj İletim Süreci | Message Transmission Process

1. **Karakter Kodlama | Character Encoding**: Her karakter 8-bit binary'ye dönüştürülür
2. **Bit İletimi | Bit Transmission**: Her bit sinyal olarak gönderilir (SIGUSR1=1, SIGUSR2=0)
3. **Server Alımı | Server Reception**: Server sinyalleri alır ve karakterleri yeniden oluşturur
4. **Görüntüleme | Display**: Yeniden oluşturulan mesaj server terminalinde gösterilir

### Sinyal Akış Diyagramı | Signal Flow Diagram

```
Client Process          Server Process
     |                       |
     |---[SIGUSR1/2]-------->|  (Bit iletimi | Bit transmission)
     |---[SIGUSR1/2]-------->|  (Karakter başına 8 sinyal | 8 signals per char)
     |---[SIGUSR1/2]-------->|  (Sıralı işleme | Sequential processing)
     |                       |
     |<--[SIGUSR2]-----------| (Onay - bonus | Acknowledgment - bonus)
```

## 📚 Örnekler | Examples

### Örnek 1: Temel İletişim | Example 1: Basic Communication
```bash
# Terminal 1 - Server başlat | Start server
./server
Server PID: 12345

# Terminal 2 - Mesaj gönder | Send message
./client 12345 "Merhaba Dünya! | Hello World!"
```

Server çıktısı | Server output:
```
Server PID: 12345
Merhaba Dünya! | Hello World!
```

### Örnek 2: Onaylamalı Bonus | Example 2: Bonus with Acknowledgment
```bash
# Terminal 1 - Bonus server başlat | Start bonus server
./server_bonus
Server PID: 12345

# Terminal 2 - Onaylamalı mesaj gönder | Send message with confirmation
./client_bonus 12345 "Sistem programlama harika! | System programming rocks!"
Mesaj İletildi | Message Delivered
```

Server çıktısı | Server output:
```
Server PID: 12345
Sistem programlama harika! | System programming rocks!
```

## 🔧 Teknik Uygulama | Technical Implementation

### Temel Fonksiyonlar | Core Functions

#### `send_character(char c, int pid)`
- Karakteri 8-bit temsiline dönüştürür | Converts character to 8-bit representation
- Her biti SIGUSR1 (1) veya SIGUSR2 (0) olarak gönderir | Sends each bit as SIGUSR1 (1) or SIGUSR2 (0)
- Güvenilir iletim için zamanlama gecikmeleri içerir | Includes timing delays for reliable transmission

#### `handler(int sig, siginfo_t *info, void *ucontext)`
- Gelen sinyalleri alır ve işler | Receives and processes incoming signals
- Alınan bitlerden karakterleri yeniden oluşturur | Reconstructs characters from received bits
- Bonus versiyonda onaylama işler | Handles acknowledgment in bonus version

#### `ft_safe_atoi(char *str)`
- String'i güvenli şekilde integer'a dönüştürür | Safely converts string to integer
- PID formatını ve aralığını doğrular | Validates PID format and range
- Buffer overflow saldırılarını önler | Prevents buffer overflow attacks

### Önemli Teknik Detaylar | Key Technical Details

- **Zamanlama | Timing**: Stabilite için sinyaller arası 700 mikrosaniye gecikme
- **Bit Sırası | Bit Order**: MSB (En Önemli Bit) önce iletim
- **Signal Masking**: İşleme sırasında sinyal kaybını önler
- **Hata Yönetimi | Error Handling**: Geçersiz PID'lerde veya sinyal hatalarında zarif başarısızlık

## 🎓 Öğrenme Çıktıları | Learning Outcomes

Bu proje şunları göstermektedir | This project demonstrates:

- **Sistem Programlama | System Programming**: Düşük seviye Unix sistem çağrıları ve sinyal işleme
- **Bit Manipülasyonu | Bit Manipulation**: Binary işlemler ve karakter kodlama
- **Proses İletişimi | Process Communication**: Prosesler arası iletişim protokolleri
- **Hata Yönetimi | Error Handling**: Sistem programlamada sağlam hata yönetimi
- **Bellek Yönetimi | Memory Management**: Verimli kaynak kullanımı
- **Protokol Tasarımı | Protocol Design**: Özel iletişim protokolü uygulaması

## 🤝 Katkıda Bulunma | Contributing

Katkılar memnuniyetle karşılanır! Pull Request göndermekten çekinmeyin. Büyük değişiklikler için önce ne değiştirmek istediğinizi tartışmak üzere bir issue açın.

**English:** Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

## 📄 Lisans | License

Bu proje MIT Lisansı altında lisanslanmıştır - detaylar için LICENSE dosyasına bakın.

**English:** This project is licensed under the MIT License - see the LICENSE file for details.

## 👨‍💻 Yazar | Author

SEVİLAY ÜNGÖR- Bilgisayar Mühendisliği Öğrencisi | Computer Engineering Student
- 42 School Projesi (Minitalk) | 42 School Project (Minitalk)  
- Eğitim amaçlı geliştirildi ve dokümante edildi | Enhanced and documented for educational purposes

---

⭐ Bu projeyi faydalı bulduysanız, yıldız vermeyi unutmayın! | If you found this project helpful, please give it a star!

🔗 **İlgili Kavramlar | Related Concepts**: Unix Signals, IPC, System Programming, Bit Manipulation, Client-Server Architecture
