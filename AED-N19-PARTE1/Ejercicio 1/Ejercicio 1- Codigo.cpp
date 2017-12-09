

#include <iostream>
#include <string>

int main (){
    
    bool EvaluarPrecandidatura();
    bool EvaluarNulidadDeVoto();
    
    EvaluarPrecandidatura();
    EvaluarNulidadDeVoto();
}

bool Preguntar(std::string);

bool EsMiembroDelPartido(){
    return Preguntar("Pertenece al partido politico?");
}

bool TieneElAvalDel2(){
    return Preguntar("Tiene el Aval del 2%?");
}

bool NoEsOficial(){
    return Preguntar("El voto fue emitido mediante boleta no oficial?");
}

bool EsPapelMalo(){
    return Preguntar("El papel con el que fue emitido el voto es de cualquier color o cuenta con imagenes de cualquier naturaleza?");
}

bool Tiene2oMasboletas(){
    return Preguntar("El voto fue emitido mediante 2 o mas boletas de la misma categoria de candidatos y diferente agrupacion politica?");
}


bool Preguntar(std::string Frase){
    
    std::string Respuesta;
    std::cout << Frase <<"\n";
    std::cin >> Respuesta;
    
    if (Respuesta=="si" or Respuesta =="Si" or Respuesta=="sI" or Respuesta== "SI" or Respuesta == "S" or Respuesta == "s"){
        return true;
    }
    else{
        return false;
    }
}

bool EvaluarPrecandidatura(){
    if (EsMiembroDelPartido() and TieneElAvalDel2()){
        std::cout << "Precandidatura Aprobada" << "\n";
    }
    else {
        std::cout << "Precandidatura Desaprobada" << "\n";
    }
}

bool EvaluarNulidadDeVoto(){
    if (NoEsOficial() or EsPapelMalo() or Tiene2oMasboletas()){
        std::cout << "Voto Nulo" << "\n";
    }
    else {
        std::cout << "Voto Valido" << "\n";
    }
}




