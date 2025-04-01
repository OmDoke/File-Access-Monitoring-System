# File Access Monitoring System (Detect Unauthorized Access 🚨)

## 📌 Description  
The **File Access Monitoring System** is a C++-based security tool that monitors file access events in real-time. It detects unauthorized access, logs file activity, and can send **email alerts** when suspicious activity is detected. This tool is useful for protecting sensitive files from unauthorized modifications or deletions.

---

## 🚀 Features  
✅ **Real-time File Monitoring** – Detects when a file is opened, modified, or deleted.  
✅ **Unauthorized Access Detection** – Alerts when an unknown user accesses restricted files.  
✅ **Logging System** – Stores access history for review.  
✅ **Email Alerts** – Sends notifications for suspicious activity (using SMTP).  
✅ **Multi-threaded Monitoring** – Runs efficiently in the background.  
✅ **Customizable Watch Directory** – Specify which folders or files to monitor.  

---

## 🔧 How It Works  
1. **Monitors a directory** using `std::filesystem` to track file access.  
2. **Logs all access events** in a text file or database.  
3. **Detects unauthorized access attempts** by verifying user permissions.  
4. **Sends email alerts** using SMTP when suspicious access is detected.  

---

## 🔨 Technologies Used  
- **C++17** – Core programming language  
- **std::filesystem** – For file monitoring  
- **Boost.Asio** – For sending email alerts via SMTP  
- **Multithreading** – For efficient background monitoring  

---

## 🚀 Use Cases  
🔹 **Enterprise Security** – Protect confidential files from unauthorized access.  
🔹 **Personal Data Protection** – Monitor access to sensitive files.  
🔹 **Forensic Investigations** – Keep logs of file access for auditing.  
🔹 **Insider Threat Detection** – Detect suspicious employee activity.  

---

## 📜 Future Enhancements  
✨ **GUI Interface** – A user-friendly dashboard to visualize file access logs.  
✨ **Database Integration** – Store logs in MySQL or SQLite for better analysis.  
✨ **Machine Learning Anomaly Detection** – Detect unusual file access patterns.  
✨ **Remote Monitoring** – Admins can check access logs from a web interface.  

---

## ⚡ Getting Started  
### 1️⃣ Clone the Repository:  
```sh
git clone https://github.com/yourusername/FileAccessMonitor.git
cd FileAccessMonitor
```

### 2️⃣ Compile the Project:  
```sh
g++ -std=c++17 -Iinclude -o file_monitor src/main.cpp src/file_monitor.cpp src/email_alert.cpp src/logger.cpp -lboost_system
```

### 3️⃣ Run the Program:  
```sh
./file_monitor
```

---

## 💡 Conclusion  
This **File Access Monitoring System** is a powerful tool for detecting and preventing **unauthorized file access** in real-time. With **logging, alerts, and security monitoring**, it helps protect **sensitive data** from cyber threats.  

🚀 Contributions and suggestions for improvements are welcome!

