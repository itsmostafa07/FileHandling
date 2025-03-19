---

# **Accounts Manager**  

A simple **C-based account manager** that securely stores, retrieves, updates, deletes, and renames account credentials using file handling.  

---

## **Features**  

✅ **Add Account** – Store a new service with an email/username and password.  
✅ **List Services** – View all saved service names.  
✅ **View Account** – Retrieve and display account details of a specific service.  
✅ **Update Account** – Modify the email/username or password of an existing service.  
✅ **Delete Account** – Remove an account permanently from the database.  
✅ **Rename Service** – Change the name of an existing service.  

---

## **How It Works**  

- Uses **binary file storage** (`accounts.dat`) to keep account data.  
- A **menu-driven interface** allows users to navigate through different operations.  
- Implements **C file handling** to ensure persistent data storage.  

---

## **Installation & Usage**  

### **1. Clone the Repository**  
```bash
git clone https://github.com/itsmostafa07/FileHandling.git
cd FileHandling
```  

### **2. Compile the Program**  
Use **GCC** to compile:  
```bash
gcc -o FileHandling main.c
```  

### **3. Run the Program**  
```bash
./FileHandling
```  

---

## **Menu Options**  

| Option | Functionality |
|--------|--------------|
| 1️⃣ **Add Account** | Store a new account |
| 2️⃣ **List Services** | Display saved services |
| 3️⃣ **View Account** | Search and view an account |
| 4️⃣ **Update Account** | Modify email/username or password |
| 5️⃣ **Delete Account** | Remove an account |
| 6️⃣ **Rename Service** | Change a service name |
| 7️⃣ **Exit** | Close the program |

---

## **Example Usage**  

### **Adding an Account:**  
```plaintext
Enter New Service: Gmail  
Enter Your Email or Username: example@gmail.com  
Enter Your Password: password123  
Account Added Successfully!  
```  

### **Viewing a Service:**  
```plaintext
Enter service name to view: Gmail  
Service: Gmail  
Email: example@gmail.com  
Password: password123  
```  

### **Updating an Account:**  
```plaintext
Enter service name to update: Gmail  
1. Update email  
2. Update password  
3. Both  
Enter choice: 1  
Enter new email: new_example@gmail.com  
Account updated successfully!  
```  

---

## **File Details**  

📂 `main.c` – The main source file containing all program logic.  
📂 `accounts.dat` – The binary file storing account details (auto-created when you add an account).  

---

## **Why Use This?**  

**Simple & Fast** – No database required, just a binary file.  
**Easy to Use** – Menu-driven interface for quick navigation.  
**Secure & Persistent** – Data is stored permanently unless deleted.  
**Open-Source** – Modify or improve as needed!  

---

**Try it out and manage your accounts easily!**

---
