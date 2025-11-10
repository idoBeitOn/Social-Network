# Social Media Console Application 🖥️

This is a console-based social media application implemented in **C++**, emphasizing **Object-Oriented Programming (OOP)**.  
The system allows registered users to interact with their friends, follow fan pages, post statuses, and manage social interactions. All data is saved to a text file, allowing persistence between runs.

---

## ✨ Features

### 👤 User and Page Management
- Add a new member  
- Create fan pages  
- Maintain a friends list and social connections  
- Maintain fan lists for fan pages  

### 📝 Status Updates
- Add a status for a member  
- Add a status for a fan page  
- Display all statuses of a member or a fan page  
- Display the 10 most recent statuses from a member's friends  

### 🤝 Social Interactions
- Establish friendship between two members  
- Remove friendship between members  
- Add a fan to a page  
- Remove a fan from a page  

### 📊 Data Overview
- Display all entities in the system  
- Display friends of a specific member  
- Display fans of a specific fan page  

### 💡 Additional Functionalities 
- Support for operator overloading (`+=`, `<`, `==`, `!=`)  
- Use of STL containers instead of raw arrays and strings  
- Exception handling for invalid input  
- Inheritance and polymorphism  
- Persistent storage using file I/O  

---

## ⚙️ Usage

- The interface is menu-driven, repeating until exit.  
- Enter the corresponding number to perform an action.  

### Example Menu Options
1. Add a new member  
2. Add a fan page  
3. Add a status  
4. Display all statuses of a member/fan page  
5. Display 10 most recent statuses of a member's friends  
6. Establish friendship between two members  
7. Remove friendship between members  
8. Add a fan to a page  
9. Remove a fan from a page  
10. Display all entities in the system  
11. Display friends/fans  
12. Exit and save data  

---

## ⚡ Setup

1. Compile and run the project:
```bash
g++ -std=c++17 main.cpp -o social_network
./social_network
