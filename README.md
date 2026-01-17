# 🎓 School Management System (C)

A console-based **Student Record Management System** written in **C**, featuring authentication, role-based access control, file handling, and comprehensive logging capabilities. This project demonstrates core **C programming concepts** through a real-world application structure.

---

## ✨ Features

- 🔐 **Secure Authentication System**
  - Login system with masked password input
  - Session management

- 👥 **Role-Based Access Control**
  - **ADMIN**: Full CRUD operations (Create, Read, Update, Delete)
  - **VIEWER**: Read-only access (View and Search)

- 📁 **Persistent Data Storage**
  - File-based database system
  - Automatic data saving and loading

- 📝 **Activity Logging**
  - Comprehensive logging of all user actions
  - Timestamped entries for audit trails

- 🧩 **Clean Architecture**
  - Modular and maintainable codebase
  - Well-structured functions and modules

- ✅ **Robust Input Handling**
  - Input validation and sanitization
  - Error handling and user-friendly messages

---

## 🗂 Project Structure

```
school-management-system/
├── src/
│   ├── main.c              # Entry point
│   ├── auth.c              # Authentication module
│   ├── student.c           # Student operations (CRUD)
│   ├── file_handler.c      # File I/O operations
│   └── logger.c            # Logging system
├── include/
│   ├── auth.h
│   ├── student.h
│   ├── file_handler.h
│   └── logger.h
├── data/
│   ├── students.dat        # Student records
│   ├── users.dat           # User credentials
│   └── logs.txt            # Activity logs
├── Makefile                # Build configuration
└── README.md
```

---

## 🛠 Installation & Setup

### Prerequisites

- GCC compiler (MinGW for Windows, GCC for Linux/Mac)
- Make utility (optional, for easier building)

### Clone the Repository

```bash
git clone https://github.com/yourusername/school-management-system.git
cd school-management-system
```

### Compile the Project

**Using Make:**
```bash
make
```

**Manual Compilation:**
```bash
gcc src/*.c -I include -o school_management
```

---

## 🚀 Usage

### Run the Application

```bash
./school_management
```

### Default Credentials

| Username | Password | Role    |
|----------|----------|---------|
| admin    | admin123 | ADMIN   |
| viewer   | view123  | VIEWER  |

⚠️ **Security Note**: Change default passwords immediately in production use!

---

## 📋 Menu Options

### Admin Menu
1. ➕ Add New Student
2. 👁️ View All Students
3. 🔍 Search Student
4. ✏️ Update Student Record
5. ❌ Delete Student Record
6. 🚪 Logout

### Viewer Menu
1. 👁️ View All Students
2. 🔍 Search Student
3. 🚪 Logout

---

## 🎯 Key Functionalities

### Student Record Management
- **Add Student**: Register new students with ID, name, age, and grade
- **View Students**: Display all student records in a formatted table
- **Search**: Find students by ID or name
- **Update**: Modify existing student information
- **Delete**: Remove student records from the system

### Authentication & Authorization
- Secure login with password masking
- Role verification before operation execution
- Session-based access control

### Data Persistence
- Automatic saving of all changes
- File-based storage for portability
- Data integrity checks

### Logging
- All operations are logged with timestamps
- User activity tracking
- System event monitoring

---

## 💻 Technical Details

### Technologies Used
- **Language**: C (C99 standard)
- **Storage**: Binary file I/O
- **Authentication**: Simple credential verification
- **Logging**: Text-based append logging

### Core Concepts Demonstrated
- File handling (fopen, fread, fwrite, fclose)
- Structures and typedef
- Function pointers
- Dynamic memory allocation
- String manipulation
- Input/output operations
- Error handling
- Modular programming

---

## 🔒 Security Features

- Password input masking using `getch()`
- Role-based operation restrictions
- Input validation to prevent buffer overflows
- Secure file access controls

---

## 🐛 Known Limitations

- Single-user session (no concurrent access)
- Plain-text password storage (for educational purposes)
- Limited to console interface
- No encryption for data files

---

## 🚧 Future Enhancements

- [ ] Database integration (SQLite)
- [ ] Password hashing (SHA-256)
- [ ] Multi-user concurrent access
- [ ] GUI implementation
- [ ] Export records to CSV/PDF
- [ ] Advanced search filters
- [ ] Backup and restore functionality
- [ ] Email notification system

---

## 🤝 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

**Your Name**
- GitHub: [@hitdepani](https://github.com/hitdepani)
- Email: depanihit090@gmail.com

---

## 🙏 Acknowledgments

- Inspired by real-world school management systems
- Built as a learning project for C programming
- Thanks to the open-source community for guidance

---

## 📸 Screenshots

### Login Screen
```
===========================================
    SCHOOL MANAGEMENT SYSTEM - LOGIN
===========================================
Username: admin
Password: ********
Login Successful! Welcome, Admin.
```

### Admin Menu
```
===========================================
         ADMIN DASHBOARD
===========================================
1. Add New Student
2. View All Students
3. Search Student
4. Update Student Record
5. Delete Student Record
6. Logout
===========================================
Enter your choice: _
```

---

## 📞 Support

If you encounter any issues or have questions:
- Open an issue on GitHub
- Contact via email
- Check existing documentation

---

<div align="center">

**⭐ If you found this project helpful, please give it a star! ⭐**

Made with ❤️ and C

</div>
