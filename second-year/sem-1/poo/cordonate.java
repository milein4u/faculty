class Punct {
    private int x,y;
    public Punct(int x,int y){
        this.x=x;
        this.y=y;
    }
    public double distanta(Punct p){
        return Math.sqrt((p.x-this.x)*(p.x-this.x)-(p.y-this.y)*(p.y-this.y));
    }
    public int getx(){
        return this.x;
    }
    public int gety(){
        return  this.y;
    }
}

class CoordonateCarteziene{
    private Punct[] p=new Punct[128];
    int k=0;
    
    public void adaugaPunct(int x, int y){
        int i;
        if(k<128)
        {
            if(k!=0){
                for(i=0;i<k;i++){
                
                    if((p[i].getx()==x)&&(p[i].gety()==y)){
                    
                    System.out.println("Punctul deja exista");
                    return;

                    }
                }
            }
            p[k]=new Punct(x,y);
            k++;
        }
        else 
        System.out.println("Nu mai exista loc in tablou");     
    }
    public String toString(){
        String tmp;
        tmp="Coordonatele carteziene\n";
        for(int i=0;i<k;i++)
        {
            tmp+="Punct "+(i+1)+":("+p[i].getx()+","+p[i].gety()+")\n";
        }
        return tmp;
    }
}

 class Main{
    public static void  main(String[] args){
        CoordonateCarteziene c1;
        c1=new CoordonateCarteziene();
        c1.adaugaPunct(1,2);
        c1.adaugaPunct(3,4);
        c1.adaugaPunct(1,2);
        c1.adaugaPunct(1,2);
        c1.adaugaPunct(1,3);
        System.out.println(c1);


    }
}