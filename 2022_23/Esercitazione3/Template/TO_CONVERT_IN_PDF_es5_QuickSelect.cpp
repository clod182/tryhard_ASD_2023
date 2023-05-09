/*
1)ORDINARE ARRAY A TRAMITE FUNZIONE QuickSelect(A, p, q, r)
    int partition(array A, int p, int r){
        x=A[r]
        i=p-1
        for (j=p fino a r-1){
            if(A[j] <= x){
                i++
                scambia A[i] ed A[j]                
            }
        }
        scambia A[i+1], A[r]
        return i+1
    }

    void QuickSelect(array A, int p, int q, int r){
        if(p<r){
            int ele = partition(A,p,q)Q
            QuickSelect(A,p,ele-1,r)
            QuickSelect(A,ele+1,q,r)
        }
    }




2) Non può esistere un algoritmo di QuickSelect con complessità di O(log m) perchè la migliore 
complessità che è possibile ottere con tale algoritmo è O(m log m) che avviene quando il processo
di partizione divide l'input in 2 problemi di dimensione quasi uguale ad ogni passo della ricorsione.
*/