#include <iostream>
#include <locale>
#include <String>
#include <windows.h>
#include <vector>
using namespace std;

int main(){
	setlocale(LC_ALL,"spanish"); 
	string ProductName[4]={"Coca-Cola","Papas Fritas","Galletas","Gomitas"};
	int Price[4]={2500,2200,1500,2000};
	int creditos,opcion,miniopcion,vlagregado,ccompra,cproducto,cuenta1,cuenta2,cuenta3,cuenta4,cuentaF;
	vector<int> compras;
	creditos =0;
	do{
		system("cls");
		cout << "Bienvenido a la maquina Dispensadora"<<endl<<"1. Visualizar la información de los productos."<<endl<<"2. Agregar Monedas a la máquina."<<endl<<"3. Comprar un producto."<<endl<<"4. Calcular la cantidad total de unidades compradas."<<endl<<"5. Calcular el valor total por las compras realizadas."<<endl<<"6. Calcular el porcentaje de disponibilidad de la máquina."<<endl<<"7. Consultar el producto más comprado"<<endl<<"8. Terminar la compra"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				system("cls");
				cout << "Tu Saldo es de : "<<creditos<<endl;
				cout << "Los productos de la maquina dispensadora son: "<<endl;
				for(int i = 0 ; i < 4 ; i++){
					cout << i+1<<") "<<ProductName[i]<<": $"<<Price[i]<<endl;
				}
				cout <<endl<<"Volver al menu principal"<<endl<<"1) Si "<<endl;
				cin>>miniopcion;
				if(miniopcion == 1){
					break;
				}
			
			case 2:
				system("cls");
				cout<<"Ingrese que valor desea cargar como saldo: "<<endl;
				cin>>vlagregado;
				creditos+=vlagregado;
				cout <<endl<<"Volver al menu principal"<<endl<<"1) Si 2) cargar otro saldo"<<endl;
				cin>>miniopcion;
				if(miniopcion == 1){
					break;
				}else{
					if(miniopcion == 2){
						opcion = 2;
						break;
					}
				}
				
			case 3:
				system("cls");
				miniopcion=2;
				cout << "Los productos de la maquina dispensadora son: "<<endl;
				for(int i = 0 ; i < 4 ; i++){
					cout << i+1<<") "<<ProductName[i]<<": $"<<Price[i]<<endl;
				}
				do{
					cout << "Ingrese el numero de el producto que desea comprar" <<endl;
					cin >> cproducto;
					cproducto=cproducto-1;
					if(creditos-Price[cproducto] > 0){
						compras.push_back(cproducto);
						creditos=creditos-Price[cproducto];
						cout << "Su saldo actual es: "<< creditos<<endl;
					}else{
						if(creditos-Price[cproducto] < 0){
							cout<<"No puede comprar este producto ya que no tiene saldo"<<endl;
						}
					}
				cout <<endl<<"Volver al menu principal"<<endl<<"1) Si"<<endl<<"2) Seguir Comprando"<<endl;
				cin>>miniopcion;
				}while(miniopcion == 2);
				break;
			
			case 4:
				system("cls");
				cout << "La cantidad de unidades comprada a la maquina es igual a: $"<<endl;
				cuenta1=0;
				cuenta2=0;
				cuenta3=0;
				cuenta4=0;
				for(int i = 0 ; i<compras.size() ; i++){
					if(ProductName[0]==ProductName[compras[i]]){
						cuenta1++;
					}else{
						if(ProductName[1]==ProductName[compras[i]]){
							cuenta2++;
						}else{
							if(ProductName[2]==ProductName[compras[i]]){
								cuenta3++;
							}else{
								if(ProductName[3]==ProductName[compras[i]]){
									cuenta4++;
								}
							}
						}
					}
				}
				if(cuenta1 >= 1){
					cout<<"Se compraron "<<cuenta1<<" unidades de "<< ProductName[0]<<endl;
				}
				if(cuenta2 >= 1){
					cout<<"Se compraron "<<cuenta2<<" unidades de "<< ProductName[1]<<endl;
				}
				if(cuenta3 >= 1){
					cout<<"Se compraron "<<cuenta3<<" unidades de "<< ProductName[2]<<endl;
				}
				if(cuenta4 >= 1){
					cout<<"Se compraron "<<cuenta4<<" unidades de "<< ProductName[3]<<endl;
				}
				cout <<endl<<"Volver al menu principal"<<endl<<"1) Si "<<endl;
				cin>>miniopcion;
				if(miniopcion == 1){
					break;
				}
			
			case 5:
				system("cls");
				cuentaF=0;
				for(int i = 0 ; i<compras.size() ; i++){
					cuentaF=cuentaF+Price[compras[i]];
				}
				cout<<"El valor total de las compras realizadas en esta maquina son por: "<<cuentaF<<endl;
				
				cout <<endl<<"Volver al menu principal"<<endl<<"1) Si "<<endl;
				cin>>miniopcion;
				if(miniopcion == 1){
					break;
				}
		}
	}while(opcion!=8);
}
