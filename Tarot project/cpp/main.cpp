#include <algorithm>
#include <array>
#include <cctype>
#include <filesystem>
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    // 1. Set the tarot card folder
    const fs::path folder =
        (argc > 1) ? fs::path(argv[1]) : fs::path("tarot card");

    // 2. Define the three reading positions
    const std::array<std::string, 3> positions = {
        "Past",
        "Present",
        "Future"
    };

    // 3. Store the image filenames
    std::vector<fs::path> cards;

    // 4. Check whether the folder exists
    try {
        if (!fs::is_directory(folder)) {
            std::cerr << "Error: Tarot card folder not found: "
                      << folder.string() << '\n';
            return 1;
        }

        // 5. Find all JPG and JPEG images
        for (const auto& entry : fs::directory_iterator(folder)) {

            if (!entry.is_regular_file()) {
                continue;
            }

            std::string extension = entry.path().extension().string();

            // Convert the extension to lowercase
            std::transform(
                extension.begin(),
                extension.end(),
                extension.begin(),
                [](unsigned char c) {
                    return static_cast<char>(std::tolower(c));
                }
            );

            if (extension == ".jpg" || extension == ".jpeg") {
                cards.push_back(entry.path());
            }
        }

    } catch (const fs::filesystem_error& error) {
        std::cerr << "Error reading folder: "
                  << error.what() << '\n';
        return 1;
    }

    // 6. Sort filenames for consistent input ordering
    std::sort(cards.begin(), cards.end());

    // 7. Make sure at least three cards exist
    if (cards.size() < positions.size()) {
        std::cerr << "Error: At least 3 JPG/JPEG cards are required.\n";
        std::cerr << "Cards found: " << cards.size() << '\n';
        return 1;
    }

    // 8. Initialize the random number generator
    std::random_device rd;
    std::mt19937 generator(rd());

    // 9. Shuffle the cards randomly
    std::shuffle(cards.begin(), cards.end(), generator);

    // 10. Display the reading
    std::cout << "\n";
    std::cout << "====================================\n";
    std::cout << "         YOUR TAROT READING\n";
    std::cout << "====================================\n\n";

    for (std::size_t i = 0; i < positions.size(); ++i) {
        std::cout << positions[i] << ": "
                  << cards[i].filename().string()
                  << '\n';
    }

    std::cout << "\n====================================\n";
    std::cout << "Cards selected: " << positions.size() << '\n';
    std::cout << "Total cards available: " << cards.size() << '\n';
    std::cout << "====================================\n";

    return 0;
}
