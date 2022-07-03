#include <Windows.h>
#include <iostream>
#include "Snarl.h"

void start() {
    new Snarl();
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if(fdwReason == DLL_PROCESS_ATTACH) {
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)start, nullptr, 0, nullptr);
    }
	return true;
}