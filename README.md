# Gym Client Management System

## 🧾 Overview

This C program simulates a **gym management system** that handles:

- Client registration and updates
- Session attendance tracking
- Payment calculations based on gym plans
- Reports on client activity and usage
- Data persistence using CSV files
- Simple unit testing framework

The system uses a terminal menu interface to interact with users and store all data in editable `.csv` files.

---

## 📁 Project Structure

| File               | Purpose                                                                 |
|--------------------|-------------------------------------------------------------------------|
| `main.c`           | Main program loop and user interface.                                  |
| `clientes.c/h`     | Manage client data (add, edit, remove, search).                        |
| `registos.c/h`     | Manage session attendance for each client.                             |
| `pagamento.c/h`    | Calculate monthly payment including extra session fees.                |
| `relatorios.c/h`   | Generate activity reports (preferred plans, high attendance, etc.).    |
| `csv.c/h`          | Read and write client and attendance data from/to CSV files.           |
| `testes.c/h`       | Simple test cases to verify key functionalities.                       |
| `config.h`         | Data structures, constants, and file paths.                            |

---

## 🧰 Features

- ✅ Add, remove, edit and search clients
- ✅ Track attendance (session registration)
- ✅ Persistent data via CSV files (`clientes.csv`, `registos.csv`)
- ✅ Auto-calculate monthly payment with extra session fees
- ✅ Reports:
  - Most preferred plans
  - Top clients by attendance
  - Clients exceeding plan limits
- ✅ Basic testing suite (manual validation required)

---

## 🧪 Gym Plans & Pricing

| Plan  | Sessions Included | Monthly Fee | Extra Session Cost |
|-------|-------------------|-------------|---------------------|
| A     | 5                 | €10         | €2 per extra        |
| B     | 15                | €20         | €2 per extra        |
| C     | 30                | €30         | €2 per extra        |

---

## ▶️ How to Compile and Run

Using `gcc`:

```bash
gcc main.c clientes.c registos.c pagamento.c relatorios.c csv.c -o gym
./gym
