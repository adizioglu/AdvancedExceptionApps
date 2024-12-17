#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

void DifferentMethod() {
    std::cout << "This is the different method working properly." << std::endl;
}

void ComplexMethod(const std::string& name) {
    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    if (lowerName == "tim") {
        throw std::runtime_error("Tim is too tall for this method.");
    }
    else {
        throw std::invalid_argument("This person isn't Tim.");
    }
}

void SimpleMethod() {
    throw std::invalid_argument("You should not be calling the SimpleMethod");
}

int main() {
    std::string name = "";

    try {
        DifferentMethod();

        std::cout << "What is your name: ";
        std::getline(std::cin, name);
        ComplexMethod(name);
        SimpleMethod();
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "You should not be calling these methods." << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (const std::logic_error& ex) {
        std::cout << "You forgot to finish your code!!!!" << std::endl;
    }
    catch (const std::exception& ex) {
        std::string lowerName = name;
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        if (lowerName == "tim") {
            std::cout << "You used Tim's name, didn't you?" << std::endl;
        }
        else {
            std::cout << ex.what() << std::endl;
        }
    }
    catch (...) {
        std::cout << "An unknown error occurred." << std::endl;
    }
 /*   finally {
        std::cout << "I always run" << std::endl;
    }*/

    std::cin.get();
    return 0;
}
