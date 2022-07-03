#include <jvmti.h>
#include <jni.h>
#include <iostream>
#include <debugapi.h>

#include "Lunar.h"

using namespace std;

class Snarl {
    public:
        Snarl();
        string checkClient();
        JavaVM *getJVM();
        JNIEnv *getENV();
        
        void devDebug(string);
    private:
        JavaVM *JVM;
        JNIEnv *ENV;
};