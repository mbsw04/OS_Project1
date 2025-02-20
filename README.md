# Air Traffic Control System Using Multi Threaded Programming (C++)

This project simulates an **Air Traffic Control System** using **multi-threading** in C++.  
The system handles aircraft landing and takeoff operations while demonstrating **thread synchronization, mutex locks, deadlock scenarios, and resolution techniques**.

## **1. Linux Setup Process**
Before running this project, you need to set up a Linux environment with the required tools.

### **1.1 Choosing a Linux Distribution**
I am going to be using a ubuntu. You can pick any distrubution that supports the required tools.

### **1.2 Installation Methods**
I am going to be using Docker to run a standard ubuntu container.  

### **1.3 Installing Essential Development Tools**
Run the following commands in the terminal:

```sh
# Update package lists
sudo apt update && sudo apt upgrade -y

# Install GCC compiler and necessary tools
sudo apt install g++ make build-essential -y

# Install Git for version control
sudo apt install git -y

# Install an IDE 
sudo apt install code -y   # VS Code