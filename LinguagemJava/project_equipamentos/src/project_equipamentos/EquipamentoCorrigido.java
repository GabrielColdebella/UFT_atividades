package project_equipamentos;

public class EquipamentoCorrigido extends Equipamento{
	private Integer mesCorrente;
	private Integer mesCompra;
	
	// if(mesCompra==MesCorrente)
	
	public EquipamentoCorrigido(Integer numeroEquipamento, Integer mesCorrente) {
		super(numeroEquipamento);
		this.mesCorrente = mesCorrente;
	}

	public void corrige(Integer percentual) {
		
	}
	
	public void substitui(EquipamentoCorrigido equipCorrigido) {
		
	}

	
	
	public Integer getMesCompra(Integer numero) {
		
		return mesCompra;
	}
	
	public void setMesCompra(Integer mesCompra) {
		this.mesCompra = mesCompra;
	}
	
	public Integer getMesCorrente() {
		return mesCorrente;
	}

	public void setMesCorrente(Integer mesCorrente) {
		this.mesCorrente = mesCorrente;
	}
}
