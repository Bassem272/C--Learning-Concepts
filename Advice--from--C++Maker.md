Certainly! Below are examples for each of the given recommendations:

### 1. Use Constructors to Establish Invariants:
```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor to initialize the object's state
    Person(const std::string& n, int a) : name(n), age(a) {
        // Additional setup or validation can be done here
        if (age < 0) {
            // Handle invalid age
            std::cerr << "Error: Invalid age specified." << std::endl;
            // You might choose to throw an exception or take other appropriate actions
            age = 0; // Set a default value for age
        }
    }

    // Other member functions and methods can follow
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Using the constructor to create a Person object
    Person person1("John Doe", 30);
    person1.displayInfo();

    // Creating another Person object with potential for invalid data
    Person person2("Alice", -5); // Constructor handles validation and sets a default age
    person2.displayInfo();

    return 0;
}
```

### 2. Use Constructor/Destructor Pairs to Simplify Resource Management (RAII):
```cpp
#include <iostream>
#include <fstream>

class FileHandler {
private:
    std::ofstream file;

public:
    // Constructor opens the file
    FileHandler(const std::string& filename) : file(filename) {
        if (!file.is_open()) {
            throw std::runtime_error("Error: Unable to open file.");
        }
        std::cout << "File opened successfully." << std::endl;
    }

    // Destructor closes the file automatically
    ~FileHandler() {
        file.close();
        std::cout << "File closed." << std::endl;
    }

    // Other member functions for file operations can follow
};

int main() {
    try {
        // Using constructor/destructor to manage file resources
        FileHandler fileHandler("example.txt");
        // Perform file operations here
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
```

### 3. Avoid ‘‘Naked’’ `new` and `delete`:
```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructed." << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructed." << std::endl;
    }
};

int main() {
    // Using smart pointers to manage memory
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();

    // No need for explicit 'delete'; memory is managed automatically

    return 0;
}
```

### 4. Use Containers and Algorithms Rather Than Built-in Arrays and Ad Hoc Code:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Using standard containers and algorithms
    std::vector<int> numbers = {5, 2, 8, 3, 1, 7};

    // Sorting the vector
    std::sort(numbers.begin(), numbers.end());

    // Displaying the sorted vector
    std::cout << "Sorted numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 5. Prefer Standard-Library Facilities to Locally Developed Code:
```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Using standard-library facilities for accumulating values
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Calculating the sum using standard accumulate function
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum of numbers: " << sum << std::endl;

    return 0;
}
```

### 6. Use Exceptions, Rather Than Error Codes, to Report Errors That Cannot Be Handled Locally:
```cpp
#include <iostream>
#include <stdexcept>

double divide(double numerator, double denominator) {
    if (denominator == 0.0) {
        // Using exceptions to report division by zero
        throw std::runtime_error("Error: Division by zero");
    }
    return numerator / denominator;
}

int main() {
    try {
        double result = divide(10.0, 0.0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
```

### 7. Use Move Semantics to Avoid Copying Large Objects:
```cpp
#include <iostream>
#include <vector>

class LargeObject {
public:
    LargeObject() {
        std::cout << "LargeObject constructed." << std::endl;
    }

    // Move constructor for efficient transfer of resources
    LargeObject(LargeObject&& other) noexcept {
        std::cout << "LargeObject moved." << std::endl;
    }
};

int main() {
    // Using move semantics to avoid unnecessary copying
    std::vector<LargeObject> sourceObjects(5);

    // Move the objects to a new vector
    std::vector<LargeObject> destinationObjects = std::move(sourceObjects);

    return 0;
}
```

### 8. Use `unique_ptr` to Reference Objects of Polymorphic Type:
```cpp
#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a shape." << std::endl;
    }

    virtual ~Shape() {
        std::cout << "Shape destructed." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }

    ~Circle() override {
        std::cout << "Circle destructed." << std::endl;
    }
};

int main() {
    // Using unique_ptr for polymorphic type
    std::unique_ptr<Shape> shapePtr = std::make_unique<Circle>();
    shapePtr->draw();

    return 0;
}
```

### 9. Use `shared_ptr` to Reference Shared Objects, That Is, Objects Without a Single Owner That Is Responsible for Their Destruction:
```cpp
#include <iostream>
#include <memory>

class SharedResource {
public:
    SharedResource() {
        std::cout << "SharedResource constructed." << std::endl;
    }

    ~SharedResource() {
        std::cout << "SharedResource destructed." << std::endl;
    }
};

int main() {
    // Using shared_ptr for shared ownership
    std::shared_ptr<SharedResource> sharedResource1 = std::make_shared<SharedResource>();
    std

::shared_ptr<SharedResource> sharedResource2 = sharedResource1;

    // Both shared pointers share ownership of the resource

    return 0;
}
```

### 10. Use Templates to Maintain Static Type Safety (Eliminate Casts) and Avoid Unnecessary Use of Class Hierarchies:
```cpp
#include <iostream>
#include <vector>

template <typename T>
void printElements(const std::vector<T>& elements) {
    for (const auto& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Using templates to maintain static type safety
    std::vector<int> intVector = {1, 2, 3, 4, 5};
    std::vector<double> doubleVector = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Print elements without the need for explicit casting
    printElements(intVector);
    printElements(doubleVector);

    return 0;
}
```

These examples demonstrate the practical implementation of each recommendation, showcasing modern C++ techniques.