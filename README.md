# 2048 🎮

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

3. **Download the necessary packages**:
```bash
sudo apt install libglfw3-dev libopenal-dev libxxf86vm-dev libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev; git clone --depth 1 https://github.com/raysan5/raylib.git raylib; cd raylib/src/; make PLATFORM=PLATFORM_DESKTOP; sudo make install; cd ../../; make;
```
   
4. **Compile the program**
   Paste the following command into the terminal:
   ```bash
   gcc -o the-matrix src/frontend/the-matrix.c src/frontend/gui.c include/gui.h src/backend/tile_generation.c include/tile_generation.h include/macros.h src/backend/slide.c include/slide.h src/backend/merge.c include/merge.h src/backend/scoring.c include/scoring.h -lraylib -lglfw -lGL -lopenal -lm -lpthread -ldl -lrt -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor; sudo ldconfig;
   ```

5. **Run the executable and aim for a new high score! 🏆**
   ```bash
   ./the-matrix
   ```
