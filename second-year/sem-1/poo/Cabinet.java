 class Cabinet {
    private String nume_avocat; //numele avocatului
    private int nr_cazuri=0; //nr de cazuri
    String[] cazuri = new String[40]; //vector de cazuri
    public Cabinet(String nume_avocat)
    {
        this.nume_avocat=nume_avocat; 
    }

    public void adaugaCaz(String reclamant,String acuzat)
    {
        
        if(nr_cazuri<40)
        this.cazuri[nr_cazuri++]=reclamant + "vs" + acuzat;
    }

    public Cabinet formeazaAlianta(Cabinet cabinet)
    {
        
        if(cabinet.nr_cazuri + this.nr_cazuri < 40)
        {
            
            String s = cabinet.nume_avocat + this.nume_avocat;
            Cabinet nou = new Cabinet(s);
            for(int i=0;i<this.nr_cazuri;i++)
            {
                nou.cazuri[nou.nr_cazuri++]=this.cazuri[i];
            }
            for(int j=0;j<cabinet.nr_cazuri;j++)
            {
                nou.cazuri[nou.nr_cazuri++]=cabinet.cazuri[j];
            }
            return nou;
        }
        
        else return null;
    }
    public String toString()
    {
        String rez="";
        rez+=this.nume_avocat + "\n";
        for(int i=0;i<this.nr_cazuri;i++)
        {
            rez+=this.cazuri[i] + "\n";
        }
        return rez;
    }

}
class CabinetAvocatura{
    public static void main(String[] args){
    Cabinet C1 = new Cabinet("Avocat 1");
    Cabinet C2 = new Cabinet("Avocat 2");
    
    C1.adaugaCaz("Teo", "Milana");
    C1.adaugaCaz("Deian", "Milana");
    System.out.println(C1);
    
    C2.adaugaCaz("Alin", "Radu");
    C2.adaugaCaz("Ioana", "Milana");
    C2.adaugaCaz("Teo", "Ioana");
    System.out.println(C2);
    Cabinet C3= C1.formeazaAlianta(C2);
    System.out.println(C3);
    }
}