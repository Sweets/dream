#include <vector>
#include <xf86drmMode.h>

class Connector {
public:
    Connector(int, drmModeRes*, drmModeConnector*);
private:
    unsigned int id;
    int ctrc_id;
    std::vector<drmModeModeInfo> modes;
};
