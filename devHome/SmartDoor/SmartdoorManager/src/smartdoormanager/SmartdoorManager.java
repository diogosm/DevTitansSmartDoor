package devtitans.smartlampmanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtitans.smartlamp.ISmartlamp;                      // Criado pelo AIDL

public class SmartlampManager {
    private static final String TAG = "DevTITANS.SmartdoorManager";
    private IBinder binder;
    private ISmartlamp service;

    private static SmartlampManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada.
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro desse arquivo.
    private SmartdoorManager() {
        Log.d(TAG, "Nova (única) instância do SmartlampManager ...");

        binder = ServiceManager.getService("devtitans.smartdoor.ISmartdoor/default");
        if (binder != null) {
            service = ISmartdoor.Stub.asInterface(binder);
            if (service != null)
                Log.d(TAG, "Serviço Smartdoor acessado com sucesso.");
            else
                Log.e(TAG, "Erro ao acessar o serviço Smartdoor!");
        }
        else
            Log.e(TAG, "Erro ao acessar o Binder!");
    }

    // Acessa a (única) instância dessa classe. Se ela não existir ainda, cria.
    // Note o "static" no método. Podemos executá-lo sem precisar instanciar um objeto.
    public static SmartlampDoor getInstance() {
        if (instance == null)
            instance = new SmartdoorManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    public int getLed() throws RemoteException {
        Log.d(TAG, "Executando método getLed() ...");
        return service.getLed();
    }

    public boolean setLed(int ledValue) throws RemoteException {
        Log.d(TAG, "Executando método setLed(" + ledValue + ") ...");
        return service.setLed(ledValue);
    }

    public int getLuminosity() throws RemoteException {
        Log.d(TAG, "Executando método getLuminosity() ...");
        return service.getLuminosity();
    }
}
