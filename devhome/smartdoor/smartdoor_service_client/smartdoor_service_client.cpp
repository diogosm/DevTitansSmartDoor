#include <android/binder_manager.h>
#include <aidl/devtitans/smartdoor/ISmartdoor.h>
#include <iostream>                             // std::cout e std::endl (end-line)

using namespace aidl::devtitans::smartdoor;     // ISmartlamp
using namespace std;                            // std::shared_ptr
using namespace ndk;                            // ndk::SpAIBinder

int main() {
    shared_ptr<ISmartlamp> service;
    service = ISmartlamp::fromBinder(SpAIBinder(AServiceManager_getService("devtitans.smartdoor.ISmartdoor/default")));

    if (!service) {
        cout << "Erro acessando o serviço!" << endl;
        return 1;
    }

    int32_t _aidl_return;
    ScopedAStatus status = service->getValorPorta(&_aidl_return);
    int luminosity = static_cast<int32_t>(_aidl_return);
    cout << "ValorPorta: " << luminosity << endl;

    return 0;
}
