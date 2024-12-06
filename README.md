# 2048 🎮

### Description of Game!
The game aims to slide numbered tiles on a grid to combine them to create a tile with the number 2048. However, one can continue to play the game after reaching the goal, creating tiles with larger numbers. - [Source](https://healthybrains.org/2048-game/)

### Prerequisites ✅
1. **Have access to an Ubuntu distribution or use VirtualBox**
   - Use the following resource as a guide if you need to set this up: [Tutorial on Ubuntu for VirtualBox](https://www.geeksforgeeks.org/how-to-install-ubuntu-on-virtualbox/)

2. **Ensure the GCC Compiler is installed**
   - To install GCC for compiling via the command line, run:
   ```bash
   sudo apt update
   sudo apt install build-essential
   ```
   - **If on VirtualBox**, use:
   ```bash
   su -
   sudo apt update
   sudo apt install build-essential
   ```

---

### Quick Install ⚡
1. Navigate to the **Actions** tab at the top of the screen.
2. Go to the **2048 App Workflow**, and under **Artifacts**, download and unzip the `GUI Executable`.
3. Within the unzipped directory, run the following via the command line:
   ```bash
   ./the-matrix
   ```
   - OR, simply double-click on the executable.

---

### Command-Line Install 💻

1. **Clone the repository**
   Run this command:
   ```bash
   git clone https://github.com/Sam-Scott-McMaster/the-team-assignment-team-2-the-matrix.git
   ```

2. **Change directory (CD)** into the repository:
   ```bash
   cd the-team-assignment-team-2-the-matrix
   ```

3. **Download the necessary packages and compile the program**:
   ```bash
   sudo apt install libglfw3-dev libopenal-dev libxxf86vm-dev libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev; git clone --depth 1 https://github.com/raysan5/raylib.git raylib; cd raylib/src/; make PLATFORM=PLATFORM_DESKTOP; sudo make install; cd ../../; make;
   ```
4. **Understand how to play the game:**
   ```bash
   ./the-matrix --help
   ```

5. **Run the executable and aim for a new high score! 🏆**
   ```bash
   ./the-matrix
   ```

It is pretty fun :)
