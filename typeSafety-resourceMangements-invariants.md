# Learning Fundamental Concepts in C++

1. **Type Safety:**
   - **Concept:** Type safety ensures that variables and data are used in a manner consistent with their types. It helps catch errors at compile-time rather than runtime.
   - **Example:**
     ```cpp
     #include <iostream>
     #include <string>

     int main() {
         int number = 10;
         std::string text = "Hello, C++";

         // This will result in a compile-time error
         // text = number; // Error: cannot convert 'int' to 'std::string'

         std::cout << text << std::endl;

         return 0;
     }
     ```
   In this example, assigning an integer to a string variable results in a compile-time error, demonstrating type safety.

2. **Resource Management:**
   - **Concept:** C++ provides mechanisms for efficient and reliable resource management, especially memory allocation and deallocation, to prevent memory leaks and other resource-related issues.
   - **Example:**
     ```cpp
     #include <iostream>
     #include <memory>

     int main() {
         // Using smart pointers for automatic memory management
         std::unique_ptr<int> numberPtr = std::make_unique<int>(42);

         // No need to explicitly free memory; it's done automatically
         // and prevents memory leaks

         std::cout << *numberPtr << std::endl;

         return 0;
     }
     ```
   Here, `std::unique_ptr` is used for automatic memory management. When the `numberPtr` goes out of scope, the memory it owns is automatically freed.

3. **Invariants:**
   - **Concept:** Invariants are conditions or properties that are expected to be true at certain points during program execution. Maintaining invariants helps ensure the correctness of your program.
   - **Example:**
     ```cpp
     #include <iostream>
     #include <vector>

     class SafeVector {
     private:
         std::vector<int> data;

     public:
         // Ensuring the invariant that the vector should never be empty
         void addElement(int value) {
             data.push_back(value);
         }

         int getElement(size_t index) const {
             // Ensuring the invariant that the index should be within bounds
             if (index < data.size()) {
                 return data[index];
             } else {
                 // Handle the violation of the invariant (index out of bounds)
                 std::cerr << "Error: Index out of bounds." << std::endl;
                 return -1;
             }
         }
     };

     int main() {
         SafeVector safeVector;
         safeVector.addElement(10);
         safeVector.addElement(20);

         // Accessing an element safely, maintaining the invariants
         std::cout << safeVector.getElement(1) << std::endl; // Output: 20
         std::cout << safeVector.getElement(2) << std::endl; // Output: Error message

         return 0;
     }
     ```
   In this example, `SafeVector` is designed to maintain the invariant that the vector should never be empty, and the index used to access elements should be within bounds.

When learning C++, understanding and practicing these fundamental concepts will provide a solid foundation for writing robust and reliable code.
