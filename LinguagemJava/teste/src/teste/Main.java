package teste;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		Video v[] = new Video[3];
		v[0] = new Video("Aula 1");
		
		Aluno al = new Aluno("jOrge", 22, "S");
		
		Visualizacao vis = new Visualizacao(al, v[0]);
		System.out.println(vis.toString());
		
		
		ArrayList<String> lista = new ArrayList<>(10);
		lista.add("Maçã");
		lista.add("Banana");
		System.out.println(lista.get(0)); // Retorna "Maçã"
		lista.set(1, "Laranja"); // Substitui "Banana" por "Laranja"
		lista.remove("Maçã");       // Remove pelo valor
		lista.remove(0);            // Remove pelo índice
		System.out.println(lista.size());
		System.out.println(lista.contains("Banana"));
		lista.clear(); //limpa tudo
		for (String fruta : lista) { //percorrendo
		    System.out.println(fruta);
		}
	}
}
