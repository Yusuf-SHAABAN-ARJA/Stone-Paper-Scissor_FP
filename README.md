# 🪨 📄 ✂️ Stone, Paper, Scissors Game (C++)

A modern, interactive command-line implementation of the classic **Stone, Paper, Scissors** game built in C++. This project demonstrates structural programming concepts, object-like structures, dynamic console styling, and randomized AI logic.

---

## 📸 Screenshots

### 1. Game Setup & Round Selection
![Round Selection](Images/You%20Choose%20Number%20Of%20Rounds.png)

### 2. User Won Round With Color-coded Round Result (Green)
![Gameplay](Images/I%20Won.png)

### 3. Computer Won Round With Color-Coded Round Result (Red)
![Round Result](Images/I%20Lost.png)

### 4. Game Over Screen
![Game Over](Images/No%20Winner.png)



---

## ✨ Features

* **Customizable Game Length:** Choose between 1 and 10 rounds per game match.
* **Randomized Computer AI:** The computer generates unpredictable choices using C++ pseudo-random logic.
* **Dynamic Visual Feedback (Color Coding):**
  * 🟢 **Green Screen:** Player wins the round.
  * 🔴 **Red Screen:** Computer wins the round.
  * 🟡 **Yellow Screen:** Draw / Tie.
* **Comprehensive Match Summary:** Displays detailed statistics including total rounds, player wins, computer wins, draws, and the ultimate match winner.
* **Replay Functionality:** Option to play another match seamlessly without restarting the executable.

---

## 🛠️ Technical Highlights

* **Language:** C++
* **IDE:** Microsoft Visual Studio
* **Core Concepts Used:**
  * Enums (`enum`) for game choices and round winners.
  * Structures (`struct`) for managing round and game state data cleanly.
  * Modular programming with functions and clear separation of concerns.
  * Windows Console API (`system("color")`) for dynamic UI feedback.

---

## 🚀 How to Run

### Option 1: Using Visual Studio (Recommended)
1. Clone or download this repository.
2. Open the `Stone Paper Scissor FP Course 5.sln` file in Visual Studio.
3. Press `Ctrl + F5` to compile and run the project.

### Option 2: Using GCC / MinGW Terminal
1. Open your terminal in the project directory.
2. Compile the source code:
   ```bash
   g++ "Stone Paper Scissor FP Course 5.cpp" -o StonePaperScissors.exe
