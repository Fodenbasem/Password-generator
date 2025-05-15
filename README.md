# 🔐 Password Generator in C++ 

Welcome to **Fady's Password Generator** — a secure, flexible, and easy-to-use console application for generating strong passwords tailored to your needs!

---

## 🚀 Features

- 🔢 **Visa PIN**: Generate simple 4-digit numeric passwords for Visa.
- 📱 **Lock Screen Passwords**:
  - iPhone: 6-digit numeric PIN.
  - Android: Choose between 4 or 6 digits numeric PIN or a **custom complex password**.
- 🛡️ **Custom Passwords** for Social Media & Android:
  - Include **numbers**, **symbols**, **lowercase**, and **uppercase** letters.
  - Enforce selection of **at least 3 character types** for strong security.
  - Customize password **length** (minimum 8 characters).
- ✅ Input validation with friendly error messages.
- ⏳ Random seed based on current time for unique passwords every run.

---

## 💡 How to Use

### 1. Compile

Make sure you have a C++ compiler (g++, clang++, or MSVC):

```bash
g++ -o password_generator password_generator.cpp


/**********************************************************************************\


2. Run
./password_generator

/--------------------------------------------------------------------------------------\


3. Follow prompts
* Choose the category of password you want (Lock Screen, Visa, Social Media).

* For Lock Screen, select device and password type.

* For custom passwords, select character types and length.

* Receive a strong and random password instantly.
######Ex:-
Fady, welcome to the Password Generator!

Please select what you need:
1. Lock screen
2. Visa
3. Social Media
Enter your choice: 3

Please choose character types for your Social Media password:
Include numbers? (1: Yes, 0: No): 1
Include symbols? (1: Yes, 0: No): 1
Include lowercase letters? (1: Yes, 0: No): 1
Include uppercase letters? (1: Yes, 0: No): 0
Enter the desired length of your password (minimum 8): 12

Generated Social Media Password: a9$k3!d0#lzq

