#include <android/binder_manager.h>
#include <aidl/devhome/smartdoor/ISmartdoor.h>
#include <iostream>                             // std::cout e std::endl (end-line)

using namespace aidl::devhome::smartdoor;     // ISmartdoor
using namespace std;                            // std::shared_ptr
using namespace ndk;                            // ndk::SpAIBinder

int main() {
    shared_ptr<ISmartdoor> service;
    service = ISmartdoor::fromBinder(SpAIBinder(AServiceManager_getService("devhome.smartdoor.ISmartdoor/default")));

    if (!service) {
        cout << "Erro acessando o serviço!" << endl;
        return 1;
    }

    int32_t _aidl_return;
    ScopedAStatus status = service->getDoor(&_aidl_return);
    int valorPorta = static_cast<int32_t>(_aidl_return);
    cout << "ValorPorta: " << valorPorta << endl;

    return 0;
}
