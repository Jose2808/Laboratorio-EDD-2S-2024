class Llave;
class Nodo;

class Nodo{
    private:
        bool hoja;
        Llave *primero;
        int numeroLlaves;

    public:
        Nodo();
        ~Nodo();

        void insertarLlave(Llave *llave);

        Llave* getPrimero();
        int getNumeroLlaves();
        bool esHoja();

        void setPrimero(Llave *llave);
        void setNumeroLlaves(int numeroLlaves);
        void setHoja(bool hoja);
};

class Llave{
    private:
        int data;
        Llave *prev;
        Llave *sig;
        Nodo *izq;
        Nodo *drcha;

    public:
        Llave(int data);
        ~Llave();

        bool tieneHijos();

        int getData();
        Llave* getPrev();
        Llave* getSig();
        Nodo* getIzq();
        Nodo* getDrcha();

        void setData(int);
        void setPrev(Llave*);
        void setSig(Llave*);
        void setIzq(Nodo*);
        void setDrcha(Nodo*);
};