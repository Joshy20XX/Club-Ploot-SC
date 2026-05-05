Project: Club Ploot
Authors: Nicholas Melchiore, Edgar Zayas, Samarth Muthyala, Josh Ottey
Topic: Internet chat room
Project Timeline: February 6 - May 4, 2026
Language: C++
Resources: Qt Creator, CPPcheck, CMake
GitHub repository: https://github.com/Joshy20XX/Club-Ploot-SC

Club Ploot is an Club Penguin-inspired chat room based on an original video game developed by our group member Nick. The application is a work-in-progress and current features are set to change in the future. 

The main executable of Club Ploot is located within this folder:
/build/Desktop_Qt_6_11_0_MinGW_64_bit-Release/ClubPloot.exe

All dependences are deployed within this folder so that no extra compilation steps are needed. We recommend viewing our source code in Qt Creator as it was our IDE for the project. It's easy to install. Otherwise, you can look at the source files directly through other means.

If installed, open Qt Creator and click on the "Open Project..." button at the top right corner of the window. Then, locate CMakeLists.txt in the project folder you extracted. It will open the source files. Leave the CMake build configuration options as is in the Build Settings window.

To get started, pass the login window for now by clicking the "Continue" button. It currently doesn't work but it will be fixed later on. It should take you to the start menu. Click the "Open" button to open the Ploot Select Menu and click on "Select Ploot". Find the .ploot file saved on your disk. It should be "Tara.ploot" for you Professor Ali. The variables within the file should be properly formatted to be validated. Make sure to check the timestamp as it's the most important value. Beware of real world time. Have it be under 11 days as of now and not in the future. If it's valid, the name of your Ploot will appear at the top and the "Confirm" button will become available. It should log you into the Moon River play space.

In Moon River, you can click anywhere in the backdrop using your mouse. The Ploot will walk to the mouse click's position. You can also view your Ploot's stats by clicking on "About your Ploot" at the top right corner of the window. You can input any message in the text box and click Send to display it on the server. Before it's sent to the server, the chat room filter will be check for malicious alphanumeric characters and capital letters. If enough is found, the "Rudeness" level increases by 1. A bad words list is parsed upon login and your text message is also checked against it. If any is found in your message, your rudeness level increases by 10. Please be respectful to other users.

FUTURE features: Online UDP socket, Ploot file exported on log out, bug fixes and more polish.
