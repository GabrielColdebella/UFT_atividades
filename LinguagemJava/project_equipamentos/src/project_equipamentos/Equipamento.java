package project_equipamentos;

public class Equipamento {
	private Integer[] valor;
	private Integer numeroEquipamentos;

	public Equipamento(Integer numeroEquipamento) {
		this.numeroEquipamentos = numeroEquipamento;
		
		for (int i = 0; i < numeroEquipamento; i++) {
			this.valor[i] = 1;
		}
	}

	public Integer getNumeroEquipamentos() {
		return numeroEquipamentos;
	}
	
	public Integer getValor(Integer numero) {
		return this.valor.length;
	}

	public void setValor(Integer valor, Integer numero) {
		
		for (int i = 0; i < numero; i++) {
			this.valor[i] = 1;
		}
	}

	
}