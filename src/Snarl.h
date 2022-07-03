#include <jvmti.h>
#include <jni.h>
#include <iostream>
#include <Windows.h>
#include <debugapi.h>

#include <iostream>

#include "Clients/Lunar/Lunar.h"
#include "Clients/Forge/Forge.h"
#include "Clients/Vanilla/Vanilla.h"

using namespace std;

class Snarl {
    public:
        Snarl();

        void checkClient();
        
        void dev();
    private:
        JavaVM *jvm;
        JNIEnv *env;
};