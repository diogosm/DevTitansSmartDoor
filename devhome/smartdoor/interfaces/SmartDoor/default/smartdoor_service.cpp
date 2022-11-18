#include "smartdoor_service.h"

namespace aidl::devHome::smartdoor {
    ndk::ScopedAStatus SmartdoorService::connect(int32_t* _aidl_return) {
        *_aidl_return = this->smartdoor.connect();
        LOG(INFO) << "connect(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus SmartdoorService::getDoor(int32_t* _aidl_return) {
        *_aidl_return = this->smartdoor.getDoor();
        LOG(INFO) << "getDoor(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus SmartdoorService::setDoor(int32_t in_ledValue, bool* _aidl_return) {
        *_aidl_return = this->smartlamp.setDoor(in_ValorPorta);
        LOG(INFO) << "setDoor( " << in_ValorPorta << "): " << (*_aidl_return ? "true" : "false");
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus SmartdoorService::getValorPorta(int32_t* _aidl_return) {
        *_aidl_return = this->smartdoor.getValorPorta();
        LOG(INFO) << "getValorPorta(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }
}
