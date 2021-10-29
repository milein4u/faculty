 class Vocabular{
    public String[] cuvinte = new String[1000];
    public int contor = 0;
    public Vocabular(String cuv)
    {
        cuvinte[contor++]=cuv;
    }
    public void adaugaCuvinte(String[] tablou)
    {
        for(int i=0;i<tablou.length;i++)
        {
            cuvinte[contor++]=tablou[i]; //adauga pe rand cuvintele din tablou in vocabularul curent
        }
    } 
    public int determinaDiferente(Vocabular v)
    {
        int nr=0;
        for(int i=0;i<v.cuvinte.length;i++) //pe rand luam toate cuvintele din vocabularul v
        {
            if(v.cuvinte[i]!=null && this.cuvinte[i]!=null) //daca avem cuvinte in ambele vocabulare
            {
                if(v.cuvinte[i] != cuvinte[i]) //daca cuvantul cautat din v nu se gaseste in vocabularul curent
                {
                    nr++;
                }
            }
            
        }return nr;
    }

    public String toString()
    {
        String rez=""; //stringul rezultat
        for(int i=0;i<cuvinte.length;i++) //luam pe rand fiecare cuvant din vocabularul curent
        {
            if(cuvinte[i]!=null) //daca exista cuvinte
            {
                rez+=cuvinte[i]+"\n"; //adauga cuvinte concatenand la rezultat
            }
        }
        return rez;
    }
}

 class ClientVocabular{
    public static void main(String[] args)
    {
        Vocabular v1 = new Vocabular("Teo");
        String[] tablou1 = {"Alex","Ioana","Obi"};
        v1.adaugaCuvinte(tablou1);

        Vocabular v2 = new Vocabular("Andreea");
        String[] tablou2 = {"Teo","Meli","Bibi"};
        v2.adaugaCuvinte(tablou2);

        System.out.println(v1);
        System.out.println(v2);
        System.out.println(v1.determinaDiferente(v2));
    }
}