#include "Snarl.h"

Snarl::Snarl() {
    JavaVM *jvm = nullptr;
	JNIEnv *env = nullptr;

    	jsize count;
	if (JNI_GetCreatedJavaVMs(&jvm, 1, &count) != JNI_OK || count == 0)
		return;

	jint res = jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
	if (res == JNI_EDETACHED)
		res = jvm->AttachCurrentThread((void **)&env, nullptr);
	if (res != JNI_OK)
		return;

    switch(checkClient()) {
        case "Lunar":
            new Lunar();
    }
}

string Snarl::checkClient() {
    jclass isLunar = ENV->FindClass("com/moonsworth/lunar/patcher/LunarMain");
    if(isLunar != nullptr) return "Lunar"
}

void Snarl::devDebug(string message) {
    char buffer[100];
    sprintf_s(buffer, "[SNARL-DEV] %s\n", message);
    OutputDebugStringA(buffer);
}