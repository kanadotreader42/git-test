# 🃏 Tarot Card Picker

A simple Python project that randomly selects three tarot cards from a folder of images and displays them in a graphical window.

This project is designed for beginners who are learning Python and want to build a small, practical application.

## ✨ Features

* Randomly selects three tarot cards.
* Ensures that the same card is not selected twice in one draw.
* Displays the actual tarot card images.
* Shows the name of each selected card.
* Provides a button to draw three new cards.
* Uses a simple graphical interface.

## 🛠️ Technologies Used

* **Python** — handles the program's logic.
* **Tkinter** — creates the graphical user interface.
* **Pillow** — loads and resizes images.
* **Random module** — selects cards randomly.
* **Pathlib** — locates image files and folders.

## 📁 Project Structure

```text
TarotProject/
│
├── main.py
├── requirements.txt
├── README.md
│
└── tarot card/
    ├── The Fool.jpg
    ├── The Magician.jpg
    ├── The Moon.jpg
    └── ... other tarot cards
```

**Note:** Place your tarot card images inside the `tarot card` folder. The program supports `.jpg` and `.jpeg` images.

## 📋 Requirements

Before running the project, make sure you have:

* Python 3 installed.
* Visual Studio Code (VS Code).
* The Python extension for VS Code.
* Pillow installed.

## 🚀 Installation and Setup

### Step 1: Clone the repository

Open a terminal and run:

```bash
git clone YOUR_REPOSITORY_URL
```

Replace `YOUR_REPOSITORY_URL` with your GitHub repository's URL.

Alternatively, download the repository as a ZIP file and extract it.

### Step 2: Open the project

Open VS Code and select:

**File → Open Folder → TarotProject**

### Step 3: Install the required library

Open the VS Code terminal and run:

```powershell
py -m pip install -r requirements.txt
```

This installs Pillow, which the program uses to process images.

### Step 4: Add your tarot cards

Place your JPG or JPEG images inside the `tarot card` folder.

### Step 5: Run the program

In the VS Code terminal, execute:

```powershell
py main.py
```

A window should appear displaying three randomly selected tarot cards.

Click **Draw Three Cards** to generate another selection.

The program skips image files that cannot be opened. If fewer than three readable
images are available, it displays a message; check that the files are valid JPG
or JPEG images.

## 📦 Dependencies

The project uses Pillow for image processing.

The `requirements.txt` file contains:

```text
Pillow
```

Other modules used by the program, such as `random`, `pathlib`, and `tkinter`, are part of Python's standard library in typical Windows installations.

## 🎯 What I Learned

This project helps beginners practise:

* Variables and data types.
* Lists and list comprehensions.
* Conditional statements.
* `for` loops.
* Functions.
* Importing Python modules.
* Working with files and folders.
* Random selection.
* Basic image processing.
* Creating graphical interfaces with Tkinter.

## 🔮 Future Improvements

Possible improvements include:

* Adding tarot card meanings.
* Displaying past, present, and future positions.
* Adding reversed card readings.
* Improving the application's design.
* Adding a shuffle animation.
* Saving previous card selections.

## 📄 License

This project is available for learning and personal use. Add a license file if you want to specify the permissions others have to use, modify, or distribute your code.
