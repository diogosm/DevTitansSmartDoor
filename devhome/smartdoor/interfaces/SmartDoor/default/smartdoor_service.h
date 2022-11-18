#pragma once

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <android/binder_manager.h>

#include <aidl/devtitans/smartdoor/BnSmarDoor.h>            // Criado pelo AIDL automaticamente

#include "smardoor_lib.h"                                   // Classe Smartlamp (biblioteca)

using namespace devHome::smartdoor;

namespace aidl::devHome::smartdoor {

class SmartdoorService : public BnSmartdoor {
    public:
        ndk::ScopedAStatus connect(int32_t* _aidl_return) override;
        ndk::ScopedAStatus getDoor(int32_t* _aidl_return) override;
        ndk::ScopedAStatus setDoor(int32_t in_ValorPorta, bool* _aidl_return) override;
        ndk::ScopedAStatus getValorPorta(int32_t* _aidl_return) override;

    private:
        SmartDoor smartdoor;                                 // Biblioteca
};

}
