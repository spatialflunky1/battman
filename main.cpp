#include <iostream>
#include <fstream>
#include <string>

void get_percent() {
    std::ifstream capacity_file("/sys/class/power_supply/BAT0/capacity");
    std::string percent;
    if (capacity_file.is_open()) capacity_file >> percent;
    capacity_file.close();
    std::cout << percent << "%\n";
}

void is_charging() {
    std::ifstream charge_file("/sys/class/power_supply/ADP0/online");
    std::string charge_status;
    if (charge_file.is_open()) charge_file >> charge_status;
    charge_file.close();
    if (charge_status == "1") std::cout << "Charging\n";
    if (charge_status == "0") std::cout << "Not Charging\n";
    else std::cout << "Illegal status detected\n";
}

void disp_help() {
    std::cout << "Battman (Battery Manager) v1.0\n";
    std::cout << "---------------------------------\n";
    std::cout << "usage: battman [option]\n\n";
    std::cout << "Options:\n";
    std::cout << "  --help         Prints this list\n";
    std::cout << "  percent        Prints the current battery percentage\n";
    std::cout << "  charging       Prints if the battery is currently charging\n";
}

int main(int argc, char* argv[]) {
    if (argc > 2) std::cout << "Too many arguments!\n";
    else if (argc < 2) std::cout << "No arguments!\n";
    else {
        std::string argument = argv[1];
        if (argument == "--help") disp_help();
        else if (argument == "percent") get_percent();
        else if (argument == "charging") is_charging();
        else std::cout << "Invalid argument\n";
    }
}
