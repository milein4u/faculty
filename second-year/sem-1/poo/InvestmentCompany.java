interface Risky {
    double getRisk();
}

abstract class Project implements Risky {
    private String titlu, obiectiv;
    private long fonduri;
    private Member manager;
    protected int k=0;
    protected Member[] membri;
    
    public Project(String titlu, String obiectiv, long fonduri, Member manager){
        this.titlu=titlu;
        this.obiectiv=obiectiv;
        this.fonduri=fonduri;
        this.manager=manager;
    }
    
    public String toString(){
        return this.titlu;
    }
    
    public abstract void addMember(Member m);
    
    public long getFonduri(){
        return this.fonduri;
    }
}

class Member {
    private int varsta;
    private String nume;
    
    public Member(int varsta, String nume){
        this.varsta=varsta;
        this.nume=nume;
    }
    
    public int getVarsta(){
        return this.varsta;
    }
    public String getNume(){
        return this.nume;
    }
}

abstract class Deadline extends Project {
    private String deadline;
    
    public Deadline(String titlu, String obiectiv, long fonduri, Member manager, String deadline){
        super(titlu, obiectiv, fonduri, manager);
        this.deadline=deadline;
        membri = new Member[15];
    }
    
    public void addMember(Member m){
        if(this.k<this.membri.length){
            this.membri[k]=m;
            k++;
        }
    }
}

class Comerciale extends Deadline {
    private long fonduri_mark;
    private int nr_echipe;
    
    public Comerciale(String titlu, String obiectiv, long fonduri, Member manager, String deadline, int nr_echipe){
        super(titlu, obiectiv, fonduri, manager, deadline);
        this.fonduri_mark=getFonduri()/2;
        this.nr_echipe=nr_echipe;
        if(this.nr_echipe>14){
            this.nr_echipe=14;
        }
    }
    
    public double getRisk(){
        return (double) (this.nr_echipe*3)/this.k/this.getFonduri()-this.fonduri_mark;
    }
}

class Militare extends Deadline {
    private String parola;
    
    public Militare(String titlu, String obiectiv, long fonduri, Member manager, String deadline, String parola){
        super(titlu, obiectiv, fonduri, manager, deadline);
        this.parola=parola;
    }
    
    public double getRisk(){
        return (double) (this.k)/this.parola.length()/this.getFonduri();
    }
}

class Open_source extends Project {
    private String mail_list;
    
    public Open_source(String titlu, String obiectiv, long fonduri, Member manager, String mail_list){
        super(titlu, obiectiv, fonduri, manager);
        this.mail_list=mail_list;
        membri=new Member[10];
        
    }
    
    public void addMember(Member m){
        if(this.k>=this.membri.length){
            Member[] aux = new Member[membri.length + 10];
            for(int i=0;i<membri.length;i++){
                aux[i]=membri[i];
            }
            membri=aux;
        }
        membri[k]=m;
        k++;
    }
    
    public double getRisk(){
        return (double) (this.k)/this.getFonduri();
    }
}

class InvestmentCompany {
    private Project[] proiecte = new Project[10];
    private int k=0;
    
    public void addProject(Project p){
        if(this.k>=this.proiecte.length){
            Project[] aux = new Project[proiecte.length + 10];
            for(int i=0;i<proiecte.length;i++){
                aux[i]=proiecte[i];
            }
            proiecte=aux;
        }
        proiecte[k]=p;
        k++;
    }
    
    public Project getBestInvestment(){
        Project curent_proj;
        double curent_risk;
        if(this.k==0){
            return null;
        }
        curent_proj=proiecte[0];
        curent_risk=curent_proj.getRisk();
        for(int i=1;i<this.k;i++){
            if(proiecte[i].getRisk()<curent_risk){
                curent_proj=proiecte[i];
                curent_risk=curent_proj.getRisk();
            }
        }
        return curent_proj;
    }
    
    public static void main(String[] arg){
        Member m1,m2,m3,m4,m5;
        m1 = new Member(20,"Casi");
        m2 = new Member(20,"Mihai");
        m3 = new Member(45,"Sorin");
        m4 = new Member(27,"Gigel");
        m5 = new Member(16,"Vasile");
        
        Project p1,p2,p3;
        p1 = new Comerciale("Proiect1","Obiectiv1",200,m1,"01/01/2020",5);
        p2 = new Militare("Proiect2","Obiectiv2",300,m2,"02/02/2020","dela1la8");
        p3 = new Open_source("Proiect3","Obiectiv3",100,m3,"mail1");
        
        p1.addMember(m4);
        p1.addMember(m5);
        
        p2.addMember(m3);
        p2.addMember(m1);
        p2.addMember(m5);
        
        p3.addMember(m4);
        
        InvestmentCompany ic = new InvestmentCompany();
        
        ic.addProject(p1);
        ic.addProject(p2);
        ic.addProject(p3);
        
        System.out.println(ic.getBestInvestment());
    }
}