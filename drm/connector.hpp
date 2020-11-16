#include <vector>
#include <xf86drmMode.h>

class Connector {
public:
    Connector(drmModeConnector*);
private:
    unsigned int id;
    std::vector<drmModeModeInfo> modes;
};
