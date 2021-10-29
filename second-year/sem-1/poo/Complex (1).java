class Complex{

    private double real = 0.0;
    private double imaginar = 0.0;

    private static int numarAfisareNumereComplexe = 0;

    public Complex(double re, double im){

        this.real = re;
        this.imaginar = im;
    }

    public void calculeazaModulComplex(){

        return Math.sqrt(this.real*this.real + this.imaginar*this.imaginar);

    }

    public void afisare(){

        System.out.println("Valoarea numarului complex: " + real +"+i*" +imaginar);

        numarAfisareNumereComplexe = numarAfisareNumereComplexe + 1;
    }

    public void calculeazaSumaComplex(Complex numar){
        
        double sumaReal;
        double sumaImaginar;
        sumaReal = real + numar.real;
        sumaImaginar = imaginar + numar.imaginar;
        return Complex(sumaReal,sumaImaginar);

    }

    public static int reurnareNumarAfisareNumereComplexe(){

        return numarAfisareNumereComplexe;

    }
}

class ClientComplex{

    public static void main(String[] args){

        Complex numarUnu = new Complex(2,2);
        Complex numarDoi = new Complex(3.5);

    }

}