#include "drv.h"

br_token brt_sdl_surface_h = BRT_NONE;

/*
 * Main entry point for device - this may get redefined by the build system.
 */
br_device *BR_EXPORT BrDrv1SDL2Begin(const char *arguments)
{
    br_device *device;
    (void)arguments;

    /*
     * Set up device
     */
    if((device = DeviceSDL2Allocate("SDL2")) == NULL)
        return NULL;

//    /*
//     * Create an output facility for each "screen mode".
//     */
//    if(OutputFacilitySDL2EnumerateModes(device) <= 0) {
//        /*
//         * If nothing is available, then don't admit to being a device
//         */
//        ObjectFree(device);
//        return NULL;
//    }

    brt_sdl_surface_h = BrTokenCreate("SDL_SURFACE_H", BR_NULL_TOKEN);

    if(OutputFacilitySDL2CreateGeneric(device) == NULL) {
        /*
         * If nothing is available, then don't admit to being a device
         */
        ObjectFree(device);
        return NULL;
    }

    return device;
}

#ifdef DEFINE_BR_ENTRY_POINT
br_device *BR_EXPORT BrDrv1Begin(const char *arguments)
{
    return BrDrv1SDL2Begin(arguments);
}
#endif

// br_device *BR_EXPORT BrDrv1MCGABegin(const char *arguments)
// {
//     /* TODO: implement */
//     return NULL;
// }

// br_device *BR_EXPORT BrDrv1VESABegin(const char *arguments)
// {
//     /* TODO: implement */
//     return NULL;
// }
