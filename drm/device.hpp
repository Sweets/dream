#include <fstream>

class Device {
public:
    Device(std::string);
private:
    int file_descriptor;
};
