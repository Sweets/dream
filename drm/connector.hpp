#include <vector>
#include <xf86drmMode.h>

class Connector {
    Connector(drmModeConnector*);
public:
    unsigned int id;
    std::vector<drmModeModeInfo> modes;
};
