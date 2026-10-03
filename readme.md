# Smart Code Auto-completion Engine 🚀

A C++ implementation of an intelligent auto-completion engine using **Trie** and **Min-Heap**, capable of suggesting the top `k` most frequent words matching a given prefix.

## 🧠 Features

- Designed using **Trie** + **Min-Heap** for fast and accurate auto-complete suggestions.
- Uses **C++ STL** (`unordered_map`, `priority_queue`) for optimized prefix lookup and frequency-based ranking.
- Accepts input prefix and displays top `k` completions based on word frequency.
- Loads word-frequency data from an external `dictionary.txt` file to simulate a real-world suggestion engine.

## 📁 Project Structure

'''├── main.cpp # Main application code
├── trie.h / trie.cpp # (If split) Trie implementation
├── dictionary.txt # Word-frequency data file
'''

## 🛠️ Tech Stack

- C++
- STL (unordered_map, priority_queue)
- DSA (Trie, Min-Heap)

## ▶️ How to Run

1. Clone the repository
2. Ensure `dictionary.txt` is in the same folder
3. Compile the code: `g++ main.cpp -o autocomplete`
4. Run: `./autocomplete`
5. Enter a prefix and view suggestions

## 🙋 Author

Made by Khushal Saini
