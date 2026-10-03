# Smart Code Auto-Completion Engine 🚀

A C++-based auto-completion engine that uses a Trie data structure for efficient prefix searching and a Priority Queue (Min-Heap) for frequency-based ranking.

The application loads words and their frequencies from an external dictionary.txt file and returns the top 5 most frequent suggestions for a given prefix.

## Features

- Fast prefix-based word searching using a Trie
- Frequency-based ranking of suggestions
- Returns the top 5 suggestions
- Loads word-frequency data from dictionary.txt
- Uses C++ STL containers for efficient implementation
- Simple command-line interface

## How It Works

1. Reads words and their frequencies from dictionary.txt.
2. Inserts each word into a Trie.
3. Stores the frequency at the corresponding word's ending node.
4. Accepts a prefix from the user.
5. Traverses the Trie to find words matching the prefix.
6. Uses a Priority Queue to maintain the top 5 suggestions.
7. Displays the suggestions to the user.

## Example

If the dictionary contains:

print 50
println 40
printf 35
priority 10
private 8

and the user enters:

pri

the engine returns matching words ranked according to their frequency.

## Project Structure

Smart-Code-Auto-completion-Engine/
│
├── main.cpp
├── dictionary.txt
├── readme.md
└── main.exe

## Tech Stack

- C++
- Trie Data Structure
- Priority Queue / Min-Heap
- STL unordered_map
- STL priority_queue
- File Handling using fstream

## How to Run

### 1. Clone the repository

git clone https://github.com/piyush-garg-code/Auto-Completion-Smart-Engine.git

### 2. Navigate to the project directory

cd Auto-Completion-Smart-Engine

### 3. Compile the program

g++ main.cpp -o autocomplete

### 4. Run the program

Windows:

.\autocomplete.exe

Linux / macOS:

./autocomplete

### 5. Enter a prefix

For example:

>> auto

The program will display matching suggestions based on their frequency.

## Dictionary Format

The dictionary.txt file contains words along with their frequency values:

auto 100
automatic 90
autocomplete 80
authority 60
author 50
autumn 40
autonomy 30

The frequency value is used to rank matching suggestions.

## Complexity

Let:

- L = length of the word or prefix
- N = number of words matching the prefix
- K = maximum number of suggestions (K = 5)

### Insertion

Each word is inserted into the Trie in approximately O(L).

### Prefix Search

Finding the prefix in the Trie takes O(L).

The matching subtree is then traversed to collect suggestions.

### Ranking

A Priority Queue maintains the top K suggestions efficiently instead of sorting all matching words.

## Future Improvements

- Dynamic frequency updates based on user searches
- Case-insensitive search
- Fuzzy matching for spelling mistakes
- User-specific search history
- Support for larger dictionaries
- Interactive GUI or web-based interface

## Author

Piyush Garg

GitHub: https://github.com/piyush-garg-code
