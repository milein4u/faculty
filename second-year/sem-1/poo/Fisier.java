package pachet;

public class Fisier {
	private String nume, continut;
	private int id;
	private static int id_counter=1;
	private Fisier anterior=null;
	private static int concat=0;
	
	public Fisier (String name, String content) {
		this.nume=name;
		this.continut=content;
		id=id_counter++;
	}
	
	public void salveazaVersiune () {
		Fisier f;
		f=new Fisier(nume+"bak",continut);
		if(anterior==null)
			this.anterior=f;
		else {
			f.anterior=anterior;
			anterior=f;
		}
	}
	
	public void concateneaza (Fisier f) {
		salveazaVersiune();
		this.continut=this.continut + f.continut;
		concat++;
	}
	
	public String toString () {
		if(this.anterior==null)
			return this.id + this.nume + this.continut + "\n";
		else return this.id + this.nume + this.continut + "\n" + anterior.toString();
	}
	
	public int numarConcatenari () {
		return concat;
	}
	
}
