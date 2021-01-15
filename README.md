# Bear_Robotics_ATM
Welcome to the Kartik's Bear Robotics ATM

### How to Clone

Method 1: Using Git Clone
  - Click on the "Code" button present above the repository
  - Under "Clone" header, select HTTPS, and then copy the Link from the text box
  - On your system terminal, go to the folder where you want to import the project
  - In the terminal enter: git clone <copied text>
 
 Method 2: Download Zip
  - Click on the "Code" button present above the repository
  - Click on "Download ZIP". Repository should start downloading now.
  - Unzip the file where you want to keep the project
 
 
### Build and Run the Project
(Instructions for Linux Ubnutu using Command Line)

 1) cd <project_folder> 
 2) cd build
 3) cmake ..
 4) make
 5) ./main
 
 ### Testing the project
 
 Once the project is running, follow the command prompts to navigate and test the functionalities.
 
 Look at the valid card numbers and pin in the data files in the data/ folder.
 New Data can be added as new rows in the user_data.csv and account_balance.csv files in the data/ folder
 
 
 ### Notes and Future Improvement
 - At each step, only enter numeric inputs
 - Considering that an atm has only numeric keys, no check is performed on the numerical validity of the input
 - When the ATM starts, all the data is loaded into the memory and modifications are performed on this only
 - Future functionality may include modifying and updating the account balance in the csv files
 - In the system, a card number has a corresponding user id
 - Each card number can have multiple accounts associated with it 
 
### Note : The user and account data is read using relative paths. In case of error in reading file, provide the absolute path to the project directory in main.cpp
