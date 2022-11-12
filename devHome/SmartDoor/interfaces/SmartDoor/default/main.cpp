#include "smartdoor_service.h"

using namespace aidl::devHome::SmartDoor;                // SmartdoorService (smartdoor_service.cpp)
using namespace std;                                       // std::shared_ptr
using namespace ndk;                                       // ndk::SharedRefBase

int main() {
    LOG(INFO) << "Iniciando SmartDoor AIDL Service ...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    shared_ptr<SmartdoorService> smartdoor_service = SharedRefBase::make<SmartdoorService>();

    const string instance = std::string() + ISmartDoor::descriptor + "/default";   // devHome.smartdoor.ISmartDoor/default
    binder_status_t status = AServiceManager_addService(smartdoor_service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    LOG(INFO) << "SmartDoor AIDL Service iniciado com nome: " << instance;
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;                                   // Não deve chegar nunca aqui
}
