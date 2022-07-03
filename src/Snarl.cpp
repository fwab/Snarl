#include "Snarl.h"

Snarl::Snarl() {
    dev();

    cout << "Snarl Loaded" << endl;

	jvm = nullptr;
	env = nullptr;

    jsize count;
	if (JNI_GetCreatedJavaVMs(&jvm, 1, &count) != JNI_OK || count == 0)
		return;

	jint res = jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
	if (res == JNI_EDETACHED)
		res = jvm->AttachCurrentThread((void **)&env, nullptr);
	if (res != JNI_OK)
		return;

    Snarl::checkClient();
}

void Snarl::checkClient() {
    cout << "Checking client" << endl;

    jclass isLunar = env->FindClass("com/moonsworth/lunar/patcher/LunarMain");
	if (isLunar != nullptr) { new Lunar(); return; }

	// TODO - Fix OptiFine client flagging as Vanilla rather than Forge
	 
	jclass isForge = env->FindClass("net/minecraftforge/common/MinecraftForge");
	if (isForge != nullptr) { new Forge(); return; }
	
	new Vanilla();
	return;
}

void Snarl::dev() {
    AllocConsole();
	SetConsoleCtrlHandler(NULL, true);
	FILE *fIn;
	FILE* fOut;
	freopen_s(&fIn, "conin$", "r", stdin);
	freopen_s(&fOut, "conout$", "w", stdout);
	freopen_s(&fOut, "conout$", "w", stderr);
}