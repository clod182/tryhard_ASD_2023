typedef struct Elem *PElem;

class Dizionario{
public:
    Dizionario();
    ~Dizionario();
    
    void inserisci(int k, int val);
    void cancella(PElem e);
    PElem cerca(int k);
    int numChiavi();
    int leggiChiave(PElem e);
    int leggiInfo(PElem e);
    void stampa();
private:
    struct Impl;
    Impl* pimpl;
};

