package pachet;

public class ClientFisier {
	public static void main (String args[]) {
		Fisier f1,f2;
		f1=new Fisier("fisier1","continut1");
		f2=new Fisier("fisier2","continut2");
		f1.concateneaza(f2);
		System.out.println(f1);
		System.out.println("Pe acest fisier s-au efectuat "+f1.numarConcatenari()+" concatenari");
	}
	
}
