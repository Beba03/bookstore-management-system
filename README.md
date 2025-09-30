# 📚 Bookstore Management System (C)

A simple **Bookstore Management System** written in **C**, providing functionality to manage book records with features such as adding, deleting, modifying, searching, and sorting books. The system also includes basic **user authentication** and file persistence using `books.txt` and `credentials.txt`.

---

## ✨ Features
- 🔐 User login with credentials stored in `credentials.txt`
- ➕ Add new books with ISBN validation
- ✏️ Modify existing book records
- ❌ Delete books by ISBN
- 🔎 Basic and advanced search (by ISBN or keyword)
- 📑 Sorting by:
  - Title
  - Publication Date
  - Price
- 💾 Save and load books from `books.txt`

---

## 🛠️ Technologies
- **Language:** C
- **File Handling:** Standard I/O in C
- **Data Structures:** Structs and arrays

---

## 📂 File Structure
```
.
├── main.c            # Source code
├── books.txt         # Stores persisted book records
├── credentials.txt   # Stores username/password
└── README.md         # Documentation
```
## 🖥️ Program in Action

Here’s an example of the program running:

[![Program Demo](assets/demo.png)](https://raw.githubusercontent.com/Beba03/bookstore-management-system/refs/heads/main/Bookstore%20management%20system%20in%20C/assets/demo.png?raw=true)
---

## 🚀 Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/Beba03/bookstore-management-system-c.git
cd bookstore-management-system-c
```

### 2. Compile the Program
```bash
gcc main.c -o bookstore
```

### 3. Run the Program
```bash
./bookstore
```

### ⚠️ Setup Credentials
Make sure you have a `credentials.txt` file with a username and password before running.  
Example:

```
u123
p123
```

---

## 📌 Notes
- Data persists in `books.txt` with each book entry saved as:
  ```
  ISBN,Title,Author,Quantity,Price,MM-YYYY
  ```
- Authentication is handled via `credentials.txt`.
- Input validation is implemented for ISBN, quantity, price, and publication date.

---

## 👨‍💻 Author
([@Beba03](https://github.com/Beba03))
