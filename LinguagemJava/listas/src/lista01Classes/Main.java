package lista01Classes;
import java.time.LocalDate;

//17 06 2025
public class Main {
	public static void main(String[] args) {
		DataApp dat = new DataApp(19, 06, 2025);
		
//		LocalDate agora = LocalDate.of(2025, 6, 18);
//		LocalDate oDia = LocalDate.of(2025, 6, 20);
		
//		if(agora.isAfter(oDia)) System.out.println("Funcionou!");
		
		LocalDate.now().isLeapYear();
		System.out.println(dat.compara(dat));
	}
}
