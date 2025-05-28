#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <vector>

// Yay, fast clean!
void cinClear(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// To replace system pause and clear cuz am in windows lmao
void autodetect_pause() {
#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    system("read -n 1 -s -r -p \"Press any key to continue...\"");  // POSIX shells
    std::cout << std::endl;
#else
    std::cerr << "Unsupported OS, can't pause, sorry XD." << std::endl;
#endif
}

void autodetect_clear() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    system("clear");
#else
    // fallback – do nothing or print a warning
    std::cerr << "Unsupported OS, can't clean this mess 💀" << std::endl;
#endif
}