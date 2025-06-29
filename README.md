## CS210 Project Reflection

### Project Summary

This project solves the problem of quantifying and reporting on inventory data from a simple text file. The core task was to read a list of purchased items, count the occurrences of each unique item, and present this data to a user in multiple formats through a console menu. The program effectively transforms raw data into a structured frequency map and allows a user to perform queries on it, such as searching for a specific item's count or visualizing the data as a list or a histogram.

### What did you do particularly well?

The project excels in its modularity and adherence to object-oriented best practices. By splitting the logic into three distinct classes (`FileReader`, `Inventory`, `Menu`), the codebase is clean, and each component has a clear, single responsibility. For example, the `FileReader`'s sole purpose is file I/O, and the `Menu` class is only used to print options to the user. The use of an `std::map` to store the item frequencies was also a strong choice, as it is a highly efficient data structure for this purpose.

### Where could you enhance your code?

While the program is functional, there are several areas for enhancement:

* **Error Handling**: The `FileReader.cpp` file includes a check to see if the input file opened successfully, but the error handling could be more robust for different types of file-related issues, such as permissions. Similarly, the backup file creation could fail and only prints an error message without halting or retrying.
* **Input Flexibility**: The item search is case-sensitive, as noted in the documentation. An improvement would be to make the search case-insensitive by converting both the user's input and the inventory keys to a common case before comparison. Additionally, the `std::cin >> itemToSearch;` command in `main.cpp` only reads single words. To search for items with spaces, `std::getline(std::cin, itemToSearch);` would be a better choice after handling the newline character left in the buffer.
* **Code Structure**: In `main.cpp`, the `if-else if` chain for menu options is functional but could be replaced with a `switch` statement for improved readability.

### Which pieces of the code did you find most challenging?

The most challenging part of this project was likely implementing the user input validation in `main.cpp`. Ensuring the program can gracefully handle non-integer inputs without crashing requires a solid understanding of C++ stream states (`std::cin.fail()`). It's necessary to not only detect the failure but also to clear the error state (`std::cin.clear()`) and discard the invalid input from the buffer (`std::cin.ignore()`) before prompting the user again. This sequence is crucial for creating a robust interactive application, as shown in the documentation's screenshots. As a support network, online resources like Stack Overflow for specific coding problems and official C++ documentation for understanding standard library features are invaluable additions.

### What skills from this project will be particularly transferable?

Many skills from this project are highly transferable:

* **Object-Oriented Design**: Structuring a program into logical classes is a fundamental skill in modern software development.
* **C++ STL Usage**: Proficiency with standard containers like `std::map` and `std::string` is essential for any C++ project.
* **File I/O**: Reading from and writing to files using `fstream` is a common requirement for applications that need to persist data.
* **User Input Validation**: Building robust applications that don't crash on unexpected user input is a critical skill for creating professional software.
* **CLI Development**: Creating a clear and interactive Command-Line Interface (CLI) is a valuable skill, especially for developing backend services and developer tools.

### How did you make this program maintainable, readable, and adaptable?

The program's design choices directly contribute to its quality attributes:

* **Maintainability**: Because the code is separated into logical classes, a developer can modify one part of the system (e.g., change the file output format in `FileReader`) with minimal impact on the others (`Inventory` or `Menu`). This single-responsibility approach reduces the risk of introducing bugs.
* **Readability**: Using clear and consistent naming for classes (`FileReader`, `Inventory`), functions (`ConvertFileToFrequencyMap`, `PrintHistogram`), and variables makes the code easier to understand and follow. The clean menu formatting also enhances the user-facing readability.
* **Adaptability**: The modular design makes the program highly adaptable. If the business requirement changed from reading a local file to fetching data from a database, only the `FileReader` class would need to be rewritten. The `Inventory` class and the main application logic would remain unchanged, demonstrating a flexible and scalable architecture.
