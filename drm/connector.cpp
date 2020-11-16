#include "connector.hpp"

Connector::Connector(int device_file_descriptor, drmModeRes *resources,
    drmModeConnector *conn) {

    if (!conn->count_modes)
        return; // No modes available

    if (conn->connection != DRM_MODE_CONNECTED) {
        std::cout << "Unused connector found" << std::endl;
    } else {
        std::cout << "Used connector found" << std::endl;
    }

    this->id = conn->connector_id;
    unsigned int index, sub_index = 0;

    for (; index < conn->count_modes; index++)
        this->modes.push_back(conn->modes[index]);

    drmModeEncoder *encoder = NULL;

    if (conn->encoder_id) {
        encoder = drmModeGetEncoder(device_file_descriptor, conn->encoder_id);

        if (encoder->crtc_id) {
            this->crtc_id = encoder->crtc_id;

            // this should eventually check to make sure the CRTC isn't taken
        }

        drmModeFreeEncoder(encoder);
    } else {

        for (index = 0; index < conn->count_encoders; ++index) {
            encoder = drmModeGetEncoder(device_file_descriptor,
                conn->encoders[index]);
            if (!encoder)
                continue;

            for (; sub_index < resources->count_crtcs; ++sub_index) {
                if (!(encoder->possible_crtcs & (1 << sub_index)))
                    continue;

                this->crtc_id = resources->crtcs[sub_index];
                // this should eventually check to make sure the CRTC isn't
                // taken
                drmModeFreeEncoder(encoder);
            }
        }

        drmModeFreeEncoder(encoder);

    }

    std::cout << "Framebuffers here" << std::endl;


    // create framebuffer here
}
