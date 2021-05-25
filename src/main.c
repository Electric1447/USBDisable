#include <vitasdk.h>

/*    sceShellUtilInitEvents(0);
    sceShellUtilLock(SCE_SHELL_UTIL_LOCK_TYPE_QUICK_MENU |
                    SCE_SHELL_UTIL_LOCK_TYPE_POWEROFF_MENU |
                    SCE_SHELL_UTIL_LOCK_TYPE_USB_CONNECTION |
                    SCE_SHELL_UTIL_LOCK_TYPE_MC_INSERTED |
                    SCE_SHELL_UTIL_LOCK_TYPE_MC_REMOVED |
                    SCE_SHELL_UTIL_LOCK_TYPE_MUSIC_PLAYER |
                    SCE_SHELL_UTIL_LOCK_TYPE_PS_BTN_2);*/

void _start() __attribute__((weak, alias("module_start")));
int module_start(SceSize argc, const void *args)
{
    sceShellUtilInitEvents(0);
    sceShellUtilLock(SCE_SHELL_UTIL_LOCK_TYPE_USB_CONNECTION);

    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args)
{
    sceShellUtilUnlock(SCE_SHELL_UTIL_LOCK_TYPE_USB_CONNECTION);
    return SCE_KERNEL_STOP_SUCCESS;
}