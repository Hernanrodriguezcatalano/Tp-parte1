#include <iostream>
#include <fstream>
#include <string>
#include <array>


using namespace std;

ifstream in;

typedef struct {
	string agrupacion;
	string candidato;
	int lista;
	int votos;
}Listado;

const unsigned int MAX = 10 * 3;
array<Listado, MAX> senadores, diputados;
Listado r;
string GetNombreDeArchivoDeMesa(string UnaMesa)
{
	return "Mesa" + UnaMesa + ".txt";
}

string UnaMesa;

int main()
{
	void SumarLosVotos();
	void MostrarListados(array <Listado, MAX> &a, string unCargo);
	void CalcularEInformarLasEstadisticas();

	SumarLosVotos();
	MostrarListados(senadores, "senadores");
	MostrarListados(diputados, "diputados");
	CalcularEInformarLasEstadisticas();
	cin >> UnaMesa; //congelar la pantalla y evitar que termine
}
////////////////////////////////////////////////////////////////////////////////////////////////
/*
*/void PonerEnCeroLosVotos(array<Listado, MAX> &a)
{
	for (int i = 0; i<MAX; ++i)
		a.at(i).votos = 0;
}

void PonerEnCeroLosVotosDeSenadoresYDiputados()
{
	PonerEnCeroLosVotos(senadores);
	PonerEnCeroLosVotos(diputados);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void SaltearLineas(ifstream& in)
{
	string line;
	getline(in, line);
	cout << line << "\n" ;
}
void SaltearVotosEnBlancoEImpugnados(ifstream& in)
{
	SaltearLineas(in);
	SaltearLineas(in);
}

void SumarLosVotosDeUnArchivo(string nombreDeArchivo)
{
	in.open(GetNombreDeArchivoDeMesa(nombreDeArchivo));
	void AvanzarHastaSenadores();
	void SumarVotosDeSenadores();
	void AvanzarHastaDiputados();
	void SumarVotosDeDiputados();
	AvanzarHastaSenadores();
	SumarVotosDeSenadores();
	SaltearVotosEnBlancoEImpugnados(in);
	AvanzarHastaDiputados();
	SumarVotosDeDiputados();
	in.close();
}

Listado LeerRegistro(ifstream& in)
{
	in
		>> r.agrupacion
		>> r.lista
		>> r.candidato
		>> r.votos;
	return r;
}

void SumarVotosDeUnCargo(array <Listado, MAX>& a, ifstream& in);

void SumarVotosDeSenadores()
{
	SumarVotosDeUnCargo(senadores, in);

}

void SumarVotosDeDiputados()
{
	SumarVotosDeUnCargo(diputados, in);
}

void AvanzarHastaSenadores()
{
	SaltearLineas(in); //TODO: Qué se leyo?
	SaltearLineas(in);
	SaltearLineas(in);
}

void AvanzarHastaDiputados()
{
	SaltearLineas(in);
	SaltearLineas(in);
	SaltearLineas(in);
	SaltearLineas(in);
}

void SumarLosVotosDeLosArchivos()
{
	// TODO:cinco veces por cada archivo
	SumarLosVotosDeUnArchivo("4568");
	SumarLosVotosDeUnArchivo("4569");
	SumarLosVotosDeUnArchivo("4579");
	SumarLosVotosDeUnArchivo("4580");
	SumarLosVotosDeUnArchivo("4581");
}

void SumarLosVotos()
{
	PonerEnCeroLosVotosDeSenadoresYDiputados();//Linea 56
	SumarLosVotosDeLosArchivos();//Linea 127
}

void SumarVotosDeUnCargo(array <Listado, MAX> &a, ifstream& in)
{
	for (unsigned i = 0; i < MAX; ++i)
	{

		r = LeerRegistro(in);
		a.at(i).agrupacion = r.agrupacion;
		a.at(i).lista = r.lista;
		a.at(i).candidato = r.candidato;
		a.at(i).votos += r.votos;
		cout << r.agrupacion << "\t\t\t\t"          //esto habria q modularizarlo, imprime en pantalla lo q va leyendo
			<< r.lista << "\t\t\t"					//del archivo
			<< r.candidato << "\t\t\t\t"
			<< r.votos << "\t\t\t\n";
	}

}

void ImprimirArreglo(const array<Listado, MAX> &a)
{
	for (unsigned i = 0; i < MAX; ++i)
		cout << a[i].agrupacion << "\t\t\t\t"
		<< a[i].lista << "\t\t\t"
		<< a[i].candidato << "\t\t\t\t"
		<< a[i].votos << "\t\t\t\n";
}

int trade(array <Listado, MAX> &a, int start, int end) //funcion de quicksort
{
	int left, right;
	Listado pivot, temp;
	pivot = a[start];
	right = end;
	left = start;

	//mientras no se cruzen los indices, separamos mayores de menores respecto del pivot
	while (left < right)
	{
		while (a[right].votos>pivot.votos) //si los de la derecha son mayor que el pivot, decremento.
			right--;
		while ((left < right) && (a[left].votos <= pivot.votos)) //si los de la izquieda son menor que el pivot, aumento.
			left++;
		//una vez que encuentro un menor y un mayor que el pivot...
		if (left < right) //verifico que no se hayan cruzado los indices y hago el cambio.
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}
	//cuando se cruzan los indices intercambios el pivot con el slot de los indices cruzados.
	temp = a[right];
	a[right] = a[start];
	a[start] = temp;

	//retorno la posicion del pivot
	return right;

}

void quicksort(array <Listado, MAX> &a, int start, int end)		//funcion recursiva
{

	int pivot;
	int tope = 13;
	if (start < end)
	{
		pivot = trade(a, start, end);
		quicksort(a, start, pivot - 1); //sublista izquierda
		quicksort(a, pivot + 1, end); //sublista derecha
	}
}
void OrdenarPorVoto(array <Listado, MAX> &partidos) //Quicksort
{
	quicksort(partidos, 0, MAX - 1);
}

void OrdenarPorAgrupacion(array <Listado, MAX> &a) //burbuja
{
	for (int i = 0; i<MAX - 1; i++)
		for (int j = 0; j<MAX - 1; j++)
			if (a[j].agrupacion > a[j + 1].agrupacion)
			{
				Listado aux;
				aux = a[j];
				a[j] = a[j + 1];
				a[j + 1] = aux;
			}

}

void OrdenarPorCandidato(array <Listado, MAX> &a) //insercion
{
	int j;
	Listado temp;
	for (int i = 0; i<MAX; i++)
	{
		temp = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j].candidato> temp.candidato))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}

}

void OrdenarPorLista(array <Listado, MAX> &a) //shell
{
	for (int i = MAX / 2; i != 0; i /= 2)
		for (int j = 1; j != 0;)
		{
			j = 0;
			for (int k = i; k<MAX; k++)
				if (a[k - i].lista>a[k].lista)
				{
					Listado temp = a[k];
					a[k] = a[k - i];
					a[k - i] = temp;
					j++;
				}
		}
}

void OrdenarPorAgrupacionYVotos(array <Listado, MAX> &a) // burbuja
{
	for (int i = 0; i<MAX - 1; i++)
		for (int j = 0; j<MAX - 1; j++)
			if (a[j].agrupacion > a[j + 1].agrupacion && a[j].votos > a[j + 1].votos)
			{
				Listado aux;

				aux = a[j];
				a[j] = a[j + 1];
				a[j + 1] = aux;
			}
}


void OrdenarPorCandidatosYVotos(array <Listado, MAX> &a) //shell
{
	{
		for (int i = MAX / 2; i != 0; i /= 2)
			for (int j = 1; j != 0;)
			{
				j = 0;
				for (int k = i; k<MAX; k++)
					if (a[k - i].candidato>a[k].candidato && a[k - 1].candidato > a[k - 1].candidato)
					{
						Listado temp = a[k];
						a[k] = a[k - i];
						a[k - i] = temp;
						j++;
					}
			}
	}
}



void OrdenarPorAgrupacionYCandidatoYVotos(array <Listado, MAX> &a) // insercion
{
	int j;
	Listado temp;
	for (int i = 0; i<MAX; i++)
	{
		temp = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j].agrupacion> temp.agrupacion) && (a[j].candidato> temp.candidato) && (a[j].votos> temp.votos))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

void MostrarListado1(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << unCargo << " ordenados por votos: \n";
	OrdenarPorVoto(a);
	ImprimirArreglo(a);
}

void MostrarListado2(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << unCargo << " ordenados por agrupacion: \n";
	OrdenarPorAgrupacion(a);
	ImprimirArreglo(a);
}

void MostrarListado3(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << unCargo << " ordenados por lista : \n";
	OrdenarPorLista(a);
	ImprimirArreglo(a);
}

void MostrarListado4(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << unCargo << " ordenados por candidato : \n";
	OrdenarPorCandidato(a);
	ImprimirArreglo(a);
}
void MostrarListado5(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << unCargo << " ordenados por agrupacion y votos: \n";
	OrdenarPorAgrupacionYVotos(a);
	ImprimirArreglo(a);
}
void MostrarListado6(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << unCargo << " ordenados por candidatos y votos: \n";
	OrdenarPorCandidatosYVotos(a);
	ImprimirArreglo(a);
}
void MostrarListado7(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << unCargo << " ordenados por agrupacion y candidato y votos: \n";
	OrdenarPorAgrupacionYCandidatoYVotos(a);
	ImprimirArreglo(a);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MostrarCandidatosConBuenaEleccion(array <Listado, MAX> a)
{
	OrdenarPorVoto(a);
	cout << "\nCandidatos con buena eleccion: \n";
	for (size_t i = 0; i < MAX; i++)
	{
		if (a[i].votos >= (a[MAX - 1].votos * 17 / 100) && a[i].votos <= (a[MAX - 1].votos * 30 / 100))
		{
			cout << a[i].candidato <<"\n";
		}
	}
	
}

void MostrarGanadores3PrimerasAgrupaciones(array <Listado, MAX> a, string unCargo)
{
	unsigned B=0;
	OrdenarPorAgrupacionYVotos(a);
	cout << unCargo <<"\n";
	for (size_t i = 1; i <= 3; i++)
	{
		cout << a[MAX-i].candidato <<"\n";
	}
}

void MostrarGanadores3PrimerasAgrupaciones()
{
	MostrarGanadores3PrimerasAgrupaciones(senadores, "senadores:");
	MostrarGanadores3PrimerasAgrupaciones(diputados, "diputados:");
}

void MostrarGanadoresDeCadaAgrupacion(array <Listado, MAX> a, string unCargo)
{
	OrdenarPorAgrupacionYVotos(a);
	cout << unCargo;
	for (size_t i = 0; i < 10; i++)
	{
		cout <<"Agrupacion: " << a[i].agrupacion << "\n";
		for (size_t j = 0; j < 3; j++)
		{
			cout <<"Candidato: "<< a[j].candidato << "\n";
		}
	}
	
}

void MostrarGanadoresDeCadaAgrupacion()
{
	MostrarGanadoresDeCadaAgrupacion(senadores, "senadores: \n");
	MostrarGanadoresDeCadaAgrupacion(diputados, "diputados: \n");

}
void CalcularEInformarLasEstadisticas()
{
	void MostrarCandidatosConBuenaEleccion();
	void MostrarGanadores3PrimerasAgrupaciones();
	void MostrarGanadoresDeCadaAgrupacion();

}

void MostrarListado8(array <Listado, MAX> &a, string unCargo)
{
	MostrarCandidatosConBuenaEleccion(a);
}

void MostrarListado9(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" << "Mostrar Ganadores de cada agrupacion: \n";
	MostrarGanadores3PrimerasAgrupaciones();
}

void MostrarListado10(array <Listado, MAX> &a, string unCargo)
{
	cout << "\n" <<  "Mostrar 3 Ganadores de cada agrupacion: \n";
	MostrarGanadoresDeCadaAgrupacion();
}

void MostrarListados(array <Listado, MAX> &a, string unCargo)
{
	MostrarListado1(a, unCargo);
	MostrarListado2(a, unCargo);
	MostrarListado3(a, unCargo);
	MostrarListado4(a, unCargo);
	MostrarListado5(a, unCargo);
	MostrarListado6(a, unCargo);
	MostrarListado7(a, unCargo);
	MostrarListado8(a, unCargo);
	MostrarListado9(a, unCargo);
	MostrarListado10(a, unCargo);
}
