 class Nota {
    private float val_nota;
    private String nume_materie;
    public Nota(float nota, String materie)
    {
        this.val_nota=nota;
        this.nume_materie=materie;
    }

    public float getNota()
    {
        return this.val_nota;
    }
    public String getMaterie()
    {
        
        return this.nume_materie;
    }
}
class Carnet{
    public String nume_elev;
    Nota[] note = new Nota[256];
    public int contor = 0; //numar de note adaugate
    public float suma_note=0; //suma tututor notelor
    public int x=0;//numara cate materiia avem
    public Carnet(String nume_elev)
    {
        this.nume_elev=nume_elev;
    }
    public void adaugaNota(float nt,String m)
    {
        if(contor<256)
        {
            note[contor]=new Nota(nt,m);
            suma_note=suma_note+nt;
            contor++;
        }
    }
    public float medieMaterie(String nume_materie)
    {
        float s=0; //suma notelor de la materia asta
        int nr=0; //cate note avem la materia asta
        
        for(int i=0;i<contor;i++){
            if(note[i].getMaterie().equals(nume_materie)) //daca gasim materia respectiva in carnet    
            {
                s=s+note[i].getNota();
                nr++;
            }
        }
        return s/nr;
    }
    public String toString()
    {
        String rez=this.nume_elev;
        for(int i=0;i<contor;i++)
        {
            rez+= "\n" + note[i].getNota() + " " + note[i].getMaterie() + " ";
        }
        rez+="\n Media tuturor notelor: " + suma_note/contor;
        return rez;
    }

}
class Source{
    public static void main(String[] args){
        Carnet C1 = new Carnet("Teo");
        C1.adaugaNota(8,"Mate");
        C1.adaugaNota(10,"Mate");
        C1.adaugaNota(9,"Bio");
        C1.adaugaNota(10,"Bio");
        
        System.out.println(C1);

    }
}
