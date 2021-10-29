class Multime{
    private String[] s=new String[100];
    private int k=0;

    public boolean adauga(String m){
        if(k<100){
            if(k!=0)
            {
                for(int i=0;i<k;i++){
                    if(m.equals(this.s[i])){
                        return false; 
                    }

                }
            }
            
                s[k]=new String(m);
                this.k++;
                return true;
        }
        return false ;
    }
    public String toString(){
        String tmp;
        tmp="Elementele multimii sunt:\n";
        for(int i=0;i<k;i++){
            tmp+=(i+1)+"."+s[i]+"\n";
        }
        return tmp;
    }
    public Multime intersectie(Multime m){
        Multime nm;
        int i,j;
        nm=new Multime();
        for(i=0;i<this.k;i++){
            for(j=0;j<m.k;j++)
            {
                if(this.s[i].equals(m.s[j])){
                    nm.adauga(this.s[i]);

                }
            }
        }
        return nm;
    }
}
class main{
    
    
    public static void main(String[] args){
        Multime m1,m2 ;
        m1=new Multime();
        m2=new Multime();
        System.out.println(m1.adauga("Teo"));
        System.out.println(m1.adauga("Alin"));
        System.out.println(m1.adauga("Alin"));
        m2.adauga("Radu");
        m2.adauga("Teo");
        System.out.println(m1);
        System.out.println(m2);
        System.out.println(m1.intersectie(m2));
    }
}