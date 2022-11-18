package devHome.smartdoormanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devHome.smardoor.ISmartDoor;                      // Criado pelo AIDL

public class SmartdoorManager {
    private static final String TAG = "DevHOME.SmartdoorManager";
    private IBinder binder;
    private ISmardoor service;

    private static SmartdoorManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada.
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro desse arquivo.
    private SmartdoorManager() {
        Log.d(TAG, "Nova (única) instância do SmartlampManager ...");

        binder = ServiceManager.getService("devHome.smartdoor.ISmartdoor/default");
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
    public static SmartDoor getInstance() {
        if (instance == null)
            instance = new SmartdoorManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    public int getDoor() throws RemoteException {
        Log.d(TAG, "Executando método getDoor() ...");
        return service.getDoor();
    }

    public boolean setDoor(int valorPorta) throws RemoteException {
        Log.d(TAG, "Executando método setDoor(" + valorPorta + ") ...");
        return service.setDoor(valorPorta);
    }

    public int getValorPorta() throws RemoteException {
        Log.d(TAG, "Executando método getValorPorta() ...");
        return service.getValorPorta();
    }
}
