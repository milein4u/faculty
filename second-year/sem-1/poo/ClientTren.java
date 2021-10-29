class Tren {
    private Vagon[] vagoane = new Vagon[15];
    private int count = 0;

    public Tren(Vagon[] v) {
        for (Vagon indexVagon : v) {
            if (count < 15) {
                vagoane[count] = indexVagon;
                count++;
            } else
                break;
        }
    }

    public int getTotalColete() {
        int s = 0;
        for (int i = 0; i < count; i++) {
            s += vagoane[i].getCapacitateColete();
        }
        return s;
    }

    public boolean equals(Object o) {
        if (o instanceof Tren) {
            Tren t = (Tren) o;
            return (this.getTotalColete() == t.getTotalColete());
        } else
            return false;
    }

    public String toString() {
        String aux =""  + vagoane[0];
        for (int i = 1; i < count; i++) {
            aux += " " + vagoane[i];
        }
        return aux;
    }

}

abstract class Vagon {
    abstract public int getCapacitateColete();
}

abstract class Calatori extends Vagon {
    abstract public int getCapacitatePasageri();

    public void deschideUsi() {
        System.out.println("Se deschid usile");
    }

    public void inchideUsi() {
        System.out.println("Se inchid usile");
    }

}

class CalatoriA extends Calatori {
    public int getCapacitateColete() {
        return 300;
    }

    public int getCapacitatePasageri() {
        return 40;
    }

    public String toString() {
        return "CalatoriA";
    }
}

class CalatoriB extends Calatori {
    public int getCapacitateColete() {
        return 400;
    }

    public int getCapacitatePasageri() {
        return 50;
    }

    public void blocheazaGeamuri() {
        System.out.println("Se blocheaza geamurile");
    }

    public String toString() {
        return "CalatoriB";
    }
}

class Marfa extends Vagon {
    public int getCapacitateColete() {
        return 400;
    }

    public String toString() {
        return "Marfa";
    }
}

public class ClientTren {
    public static void main(String[] args) {
        Vagon a1 = new CalatoriA();
        Vagon a2 = new CalatoriA();
        Vagon a3 = new CalatoriA();

        Vagon b1 = new CalatoriB();
        Vagon b2 = new CalatoriB();
        Vagon b3 = new CalatoriB();

        Vagon m1 = new Marfa();
        Vagon m2 = new Marfa();
        Vagon m3 = new Marfa();

        Vagon[] V1 = { a1, a2, b1, m1, b2 };
        Vagon[] V2 = { m2, m3, a3, b3 };

        Tren T1 = new Tren(V1);
        Tren T2 = new Tren(V2);

        System.out.println(a1 + " : " + a1.getCapacitateColete());
        System.out.println(b1 + " : " + b1.getCapacitateColete());
        System.out.println(m1 + " : " + m1.getCapacitateColete());

        ((Calatori) a1).deschideUsi();
        ((Calatori) a1).inchideUsi();
        ((CalatoriB) b1).blocheazaGeamuri();

        System.out.println(T1 + " : " + T1.getTotalColete() + "\n" + T2 +" : " + T2.getTotalColete() + "\n" + T1.equals(T2));
    }
}