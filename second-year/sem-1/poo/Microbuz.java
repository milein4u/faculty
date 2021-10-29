package pack;

public class Microbuz {
	private String marca, nume_proprietar;
	private String[] pasageri=new String[14]; 
	private int contor=0;
	
	public Microbuz (String marca, String nume_proprietar) {
		this.marca=marca;
		this.nume_proprietar=nume_proprietar;
	}
	
	public boolean urca (String nume_pasager) {
		if(this.contor>=14)
			return false;
		else {
			this.pasageri[this.contor]=nume_pasager;
			this.contor++;
			return true;
		}
	}
	
	public int getNrPasageri () {
		return this.contor;
	}
	
	public boolean transferaPasageri (Microbuz m) {
		if(this.contor + m.getNrPasageri()<=14) {
			for(int i=0;i<this.contor;i++) {
				m.urca(this.pasageri[i]);
			}
			return true;
		}
		else return false;
	}
	
	public String toString() {
		String s = this.marca + " " + this.nume_proprietar + ": ";
		for(int i=0;i<contor;i++)
		{
			s= s+ this.pasageri[i]+" ";
		}
		return s;
	}
}
