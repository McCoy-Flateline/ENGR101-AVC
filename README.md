# ENGR101_2020 AVC Project (Team 4)

### Team Members & Contact Info:
- Deepkrsna Arora (aroradeep-DK) ~ aroradeep@myvuw.ac.nz
- Selby Dasent (McCoy-Flateline) ~ dasentselb@myvuw.ac.nz
- Elliot Rose (jesusonweels) ~ roseelli@myvuw.ac.nz
- Ella Tait (ellatait07) ~ taitella@myvuw.ac.nz

### Roles:
- Deepkrsna Arora & Selby Dasent: Programming the image processor
- Elliot Rose & Ella Tait: Programming the robot's movement

## Project Description:
The purpose of this project is to write software which guides a robot
through a maze. The robot is equipped with a video camera and two
wheels. The camera image is an input for the program. The program
controls the speeds of left and right motors.

## Communication tool:
- Facebook Messenger

### GitHub:
- [GitHub Pages](https://github.com/McCoy-Flateline/ENGR101)

## Project Plan:
**Start Date:** Tuesday 26/05/2020  
**Due Date:** Tuesday 02/06/2020   
**Objective:** Start Project   
**Conflicts:** N/A   
**Tasks:**
- [x] Selby – Setup GitHub Repository
- [x] Deepkrsna – Setup Facebook group chat
- [x] Selby & Deepkrsna – Complete plan for ImageProcessor class
- [x] Ella & Elliot – Complete plan for RobotMovement class
- [x] All – Merge both plans to form the AVC project plan
- [x] All – Test all installations/help install SFML on all team
member’s computers
- [x] Selby – Create Trello board and invite everyone

***

**Start Date:** 01/06/2020   
**Due Date:** 07/06/2020   
**Objective:** Image Processor Core   
**Conflicts:** COMP102 Assignment, CYBR171 Assignment, ENGR121
Assignment   
**Tasks:**
- [x] Deepkrsna – Create a development branch for Image Processor Core  
- [x] Deepkrsna – Implement line recognition  
- [x] Deepkrsna – Implement obstacle recognition
- [x] Deepkrsna – Submit code for testing
- [x] Selby – Test code and provide feedback  
- [x] Deepkrsna – Improve based on the feedback (if any)  
- [x] Deepkrsna – Commit to branch  
- [x] Deepkrsna– Create pull request

***

**Start Date:** 02/06/2020   
**Due Date:** 07/06/2020   
**Objective:** Movement Class Core   
**Conflicts:** N/A   
**Tasks:**
- [x] Ella - Create a development branch for Movement Core
- [x] Elliott - Assign variables and fields for basic movement
- [x] Elliott & Ella - Calculate the speeds of the left and right motors
- [x] Elliott & Ella - Submit code for testing
- [x] Elliott & Ella - Test code and provide feedback
- [x] Elliott & Ella - Improve based on the feedback (if any)
- [x] Elliott - Commit to branch
- [x] Elliott - Create pull request  

***

**Start Date:** 02/06/2020   
**Due Date:** 13/06/2020   
**Objective:** Image Processor Completion   
**Conflicts:** N/A   
**Tasks:**
- [x] Selby - Create a development branch for Image Processor Completion
- [x] Selby - Implement line recognition
- [x] Selby - Implement obstacle recognition
- [x] Selby - Implement intersection recognition
- [x] Selby - Submit code for testing
- [x] Deepkrsna – Test code and provide feedback
- [x] Selby - Improve based on the feedback (if any)
- [x] Selby - Commit to branch

***

**Start Date:** 02/06/2020   
**Due Date:** 13/06/2020   
**Objective:** Movement Class Completion     
**Conflicts:** N/A   
**Tasks:**
- [x] Elliott - Create a development branch for Movement Completion
- [x] Elliott & Ella - Use intersection recognition to make a decision
about which path to follow (turning left when possible)
- [x] Ella - Determine movement when faced with obstacle
- [x] Elliott - Submit code for testing
- [x] Elliott - Test code and provide feedback
- [x] Elliott & Ella - Improve based on the feedback (if any)
- [x] Ella - Commit to branch  
- [x] Ella - Create pull request  

***

**Start Date:** 07/06/2020   
**Due Date:** 15/06/2020   
**Objective:** Image Processor Challenge     
**Conflicts:** CYBR171 Assignment, COMP102 Assignment, ENGR121
Assignment, ENGR121 Lab 3   
**Tasks:**
- [x] Deepkrsna – Create a development branch for Image Processor
Challenge
- [x] Deepkrsna  – Implement maze navigation
- [x] Deepkrsna – Implement obstacle recognition
- [x] Selby – Test code and provide feedback  
- [x] Deepkrsna – Improve based on the feedback (if any)  
- [x] Deepkrsna – Commit to branch  
- [x] Deepkrsna – Create pull request  

***

**Start Date:** 02/06/2020   
**Due Date:** 19/06/2020   
**Objective:** Movement Class Challenge   
**Conflicts:** N/A   
**Tasks:**
- [x] Elliott - Create a development branch for Movement Challenge
- [x] Elliott & Ella - create system for navigating through maze without
a guide
- [x] Ella - Submit code for testing
- [x] Ella - Test code and provide feedback
- [x] Elliott & Ella - Improve based on the feedback (if any)
- [x] Elliott - Commit to branch  
- [x] Elliott - Create pull request  

## Installation Instructions
Note: The following instructions are only for a Linux based operating system.
### Install SFML
1. Go to https://www.sfml-dev.org/download/sfml/2.5.1/
2. Install the SFML version for Linux (GCC -64-bit)
3. Extract the downloaded folder into your “Downloads” folder
4. Rename the folder to “SFML”

### Install Geany
1. Open the terminal by pressing Ctrl + Alt + T
2. Enter the following command in the terminal: sudo apt-get install geany
3. When or if prompted, enter your password to grant permission to start the download
4. When or if prompted, enter “Y” to confirm the installation
5. Once installed, try running Geany by either entering “geany” in the terminal or searching for it in the start menu

## Install Project
1. Click on the “Clone or download” button in the repository
2. Click the “Download ZIP” button on the popup that appears
3. Extract the downloaded folder and open it
4. Navigate into the “AVC_server” folder
5. Open the file named “makefile” in a text editor
6. On the first line, “SFML = /home/INSERT_USERNAME_HERE/Downloads/SFML/SFML-2.5.1”, replace “INSERT_USERNAME_HERE” with your computer’s username, save it, and close the file.
7. Open the file named server3.cpp in Geany
8. Use the “Make” option from the Geany menu (Build > Make) or press Shift + F9
    - If you get a missing operator error, make sure that there is a tab (not whitespaces) on the lines before “g++” in the makefile (line 6 & 8)
    - Else, if everything goes well, you should see “Compilation finished successfully.”
9. Run the server3 program by pressing the “Execute” option from the Geany menu (Build > Execute) or press F5
10. Navigate into the “AVC_robot” folder
11. Open the file named “makefile” in a text editor
12. On the first line, “SFML = /home/INSERT_USERNAME_HERE/Downloads/SFML/SFML-2.5.1”, replace “INSERT_USERNAME_HERE” with your computer’s username, save it, and close the file.
13. Open the file named robot.cpp in Geany
14. Use the “Make” option from the Geany menu (Build > Make) or press Shift + F9
    -If you get a missing operator error, make sure that there is a tab (not whitespaces) on the lines before “g++” in the makefile (line 6 & 8)
    - Else, if everything goes well, you should see “Compilation finished successfully.”
15. Run the server3 program by pressing the “Execute” option from the Geany menu (Build > Execute) or press F5
16. A terminal should open asking you for the maze being used. Enter “Core”, “Completion” or “Challenge” depending on the maze being used
    - If a terminal does not open, try pressing Alt + Tab until you find the terminal
17. Switch to the Global View by pressing Alt + Tab to view to simulation
18. To stop/close the program, press Alt + Tab to switch to each terminal open and press Ctrl + C

Note: Once the program has been executed once, you do not need to Make the files again. Simply executing the server3 and robot files in that respective order will start the simulation.
Also, you can change the maze being used by editing the first line of the file named config.txt in the AVC_server folder, replacing filename, for example “core.txt” with “completion.txt”, and saving it before execution.
