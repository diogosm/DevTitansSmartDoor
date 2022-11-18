package devhome.smartdoor;

@VintfStability
interface ISmartdoor {
        int connect();

        int getDoor();
        boolean setDoor(in int ValueDoor);

        int getValorPorta();
}
