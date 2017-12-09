#include <iostream>
#include <fstream>
#include <string>

std::ofstream out;

int main()
{

	void Escribir5ActasDeMesa();
	Escribir5ActasDeMesa();


}

void PreguntarListaCandidatoYCantidadDeVotos();

std::string UnPartido, UnCandidato, UnCargo, UnaMesa, UnaLista, UnaCantidadDeVotos;

void PreguntarListaCandidatoYCantidadDeVotos()
{
	std::cout << "Ingrese la lista: \n";
	std::cin >> UnaLista;
	while (UnaLista.length() >= 9)
	{
		std::cout << "Ingrese una lista menor de 9 caracteres: \n";
		std::cin >> UnaLista;
	}

	std::cout << "Ingrese el candidato: \n";
	std::cin >> UnCandidato;
	while (UnCandidato.length() >= 9)
	{
		std::cout << "Ingrese un candidato menor de 9 caracteres: \n";
		std::cin >> UnCandidato;
	}

	std::cout << "Ingrese la cantidad de votos: \n";
	std::cin >> UnaCantidadDeVotos;
	while (UnaCantidadDeVotos.length() >= 9)
	{
		std::cout << "Ingrese una cantidad de votos menor de 9 caracteres: \n";
		std::cin >> UnaCantidadDeVotos;
	}
}

void EscribirPartidoListaCandidatoYCantidadDeVotos(std::string, std::string, std::string, std::string);
void EscribirPartidoListaCandidatoYCantidadDeVotos(std::string UnPartido, std::string UnaLista, std::string UnCandidato, std::string UnaCantidadDeVotos)
{
	out << UnPartido + " \t \t \t";
	out << UnaLista + " \t \t \t";
	out << UnCandidato + " \t \t \t";
	out << UnaCantidadDeVotos + " \n";
}
void EscribirCandidato(std::string);
void EscribirCandidato(std::string UnPartido)
{
	PreguntarListaCandidatoYCantidadDeVotos();
	EscribirPartidoListaCandidatoYCantidadDeVotos(UnPartido, UnaLista, UnCandidato, UnaCantidadDeVotos);
}

void Escribir3Candidatos(std::string);
void Escribir3Candidatos(std::string UnPartido)
{
	for (unsigned i = 0; i < 3; i++)
	{
		EscribirCandidato(UnPartido);
	}

}

void PreguntarPartido();
void PreguntarPartido()
{
	std::cout << "Ingrese el Partido: \n";
	std::cin >> UnPartido;

	while (UnPartido.length() >= 9)
	{
		std::cout << "Ingrese un partido menor de 9 caracteres: \n";
		std::cin >> UnPartido;
	}

}

void EscribirPartido();
void EscribirPartido()
{
	PreguntarPartido();
	Escribir3Candidatos(UnPartido);
}



void Escribir10Partidos();
void Escribir10Partidos()
{
	for (unsigned i = 0; i < 10; i++)
	{
		EscribirPartido();
	}
}

void EscribirVotosEnBlanco();
void EscribirVotosEnBlanco()
{
	std::string votosenblanco;
	std::cout << "Ingrese los Votos en blanco:";
	std::cin >> votosenblanco;
	out << "\n Votos en Blanco: " + votosenblanco << "\n";
}

void EscribirVotosImpugnados();
void EscribirVotosImpugnados()
{
	std::string votosimpugnados;
	std::cout << "Ingrese los Votos en impugnados:";
	std::cin >> votosimpugnados;
	out << "Votos en impugnados: " + votosimpugnados << "\n";
}

void EscribirCargo(std::string UnCargo)
{

	Escribir10Partidos();

	EscribirVotosEnBlanco();

	EscribirVotosImpugnados();


}

void EscribirTituloDeActa(std::string);
void EscribirTituloDeActa(std::string UnaMesa)
{
	out << "Acta de la Mesa " + UnaMesa + ".txt \n";
}

void EscribirSenadores();
void EscribirSenadores()
{
	out << "Senadores \n";
	out << "Agrupación politica             Número de lista         Nombre del candidato    Cantidad de votos \n";
	std::cout << "Senadores: \n";
	EscribirCargo(UnCargo);
}

void EscribirSeparador();
void EscribirSeparador()
{
	out << "******************************************************************************************\n";
}

void EscribirDiputados();
void EscribirDiputados()
{
	std::cout << "Diputados: \n";
	out << "Diputados \n";
	out << "Agrupación politica             Número de lista         Nombre del candidato    Cantidad de votos \n";
	EscribirCargo(UnCargo);
}

std::string GetNombreDeArchivoDeMesa(std::string);
std::string GetNombreDeArchivoDeMesa(std::string UnaMesa)
{
	return "Mesa" + UnaMesa + ".txt";
}

void EscribirActaDeMesa(std::string UnaMesa)
{
	out.open(GetNombreDeArchivoDeMesa(UnaMesa));
	EscribirTituloDeActa(UnaMesa);

	EscribirSenadores();

	EscribirSeparador();

	EscribirDiputados();
	out.close();


}

void Escribir5ActasDeMesa()
{
	void EscribirActaDeMesa(std::string);
	EscribirActaDeMesa("4568");
	EscribirActaDeMesa("4569");
	EscribirActaDeMesa("4579");
	EscribirActaDeMesa("4580");
	EscribirActaDeMesa("4581");


}
