#include <fstream>

class Device {
public:
    Device(const char*);
private:
    int file_descriptor;
};
