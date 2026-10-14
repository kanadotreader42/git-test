# ==========================================
# Tarot Card Picker
# A beginner-friendly Python project
# ==========================================

# Import required modules
from pathlib import Path
import random
import tkinter as tk
from PIL import Image, ImageTk


# STEP 1: Locate the tarot card folder

PROJECT_FOLDER = Path(__file__).parent
CARD_FOLDER = PROJECT_FOLDER / "tarot card"


# STEP 2: Find all JPG and JPEG images

if not CARD_FOLDER.is_dir():
    raise SystemExit(
        f"Error: The tarot card folder was not found: {CARD_FOLDER}"
    )

cards = sorted(
    file
    for file in CARD_FOLDER.iterdir()
    if file.is_file() and file.suffix.lower() in {".jpg", ".jpeg"}
)


# STEP 3: Check whether enough cards exist

if len(cards) < 3:
    raise SystemExit(
        "Error: Please add at least 3 JPG or JPEG images "
        "to the 'tarot card' folder."
    )


# STEP 4: Create the application window

root = tk.Tk()
root.title("Tarot Card Picker")
root.geometry("1050x650")
root.configure(bg="#171326")


# STEP 5: Add the heading

title = tk.Label(
    root,
    text="YOUR THREE TAROT CARDS",
    font=("Georgia", 22, "bold"),
    fg="#E8CF8A",
    bg="#171326"
)

title.pack(pady=20)


# STEP 6: Create a frame for the cards

card_frame = tk.Frame(root, bg="#171326")
card_frame.pack(expand=True)

# Show a message if fewer than three readable images are available.
status_label = tk.Label(
    root,
    text="",
    font=("Arial", 11),
    fg="#E8CF8A",
    bg="#171326"
)
status_label.pack()


# STEP 7: Keep image references alive

photo_images = []


# STEP 8: Function to draw three random cards

def draw_cards():

    # Remove the previously displayed cards
    for widget in card_frame.winfo_children():
        widget.destroy()

    # Clear previous image references
    photo_images.clear()

    # Check cards in a random order so unreadable files can be skipped.
    selected_cards = random.sample(cards, len(cards))
    displayed_cards = 0

    # Display the first three cards that can be opened.
    for card in selected_cards:

        try:
            with Image.open(card) as image:
                image = image.convert("RGB")
                image.thumbnail((260, 390))

                photo = ImageTk.PhotoImage(image, master=root)

        except (OSError, ValueError, Image.DecompressionBombError) as error:
            print(f"Could not load {card.name}: {error}")
            continue

        # Keep a reference to the image so Tkinter can display it.
        photo_images.append(photo)

        # Create a container for this card
        column = tk.Frame(card_frame, bg="#171326")
        column.pack(side="left", padx=18)

        # Display the image
        image_label = tk.Label(
            column,
            image=photo,
            bg="#171326"
        )
        image_label.pack()

        # Display the card's filename
        name_label = tk.Label(
            column,
            text=card.stem,
            font=("Georgia", 13, "bold"),
            fg="#E8CF8A",
            bg="#171326",
            wraplength=260
        )
        name_label.pack(pady=12)

        displayed_cards += 1
        if displayed_cards == 3:
            break

    if displayed_cards < 3:
        status_label.config(
            text=(
                f"Only {displayed_cards} readable card(s) found. "
                "Check the image files in the 'tarot card' folder."
            )
        )
    else:
        status_label.config(text="")


# STEP 9: Create the draw button

draw_button = tk.Button(
    root,
    text="Draw Three Cards",
    command=draw_cards,
    font=("Arial", 12, "bold"),
    bg="#574477",
    fg="white",
    activebackground="#765B9D",
    padx=18,
    pady=10
)

draw_button.pack(pady=20)


# STEP 10: Display three cards when the program starts

draw_cards()


# STEP 11: Keep the application running

root.mainloop()