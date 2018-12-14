//funciones clase agenda
#include "agenda.hpp"

void Agenda::cargarDatosFichero(std::string nombre) //carga los datos de los alumnos al sistema desde un fichero binario
{
  std::ifstream in;
  Alumno al;
  in.open(nombre, std::ios::binary);
  if(!in.is_open())
  {
    std::cout<<"Error al abrir el fichero: "<<nombre<<"\n";
  }
  else
  {
    while(in>>al) {
      vAlumnos.push_back(al);
    }
  }
  in.close();
}


void Agenda::guardarDatosFichero(std::string nombre) //carga los datos de los alumnos al sistema desde un fichero binario
{
  std::ofstream out;
  out.open(nombre, std::ios::binary);

  for(int i=0; i<vAlumnos.size(); i++)
  {
    out<<vAlumnos[i];
  }

  out.close();
}

bool Agenda::isLider(std::string dni)//comprueba si un alumno indicado por su dni es lider o no
{
  for(int i=0; i<vAlumnos.size(); i++)
  {
    if(vAlumnos[i].getDni() == dni)
    {
      if(vAlumnos[i].getLider() == 1)
      {
        return true;
      }
    }
  }
  return false;
}

void Agenda::mostrarAlumnosHTML() //genera un fichero HTML "alumnos.html" con los datos de todos los alumnos.
{
  if(vAlumnos.empty())
  {
    std::cout<<"La agenda de alumnos está vacía\n";
  } else{
    std::ofstream myfile;
    std::string es_lider;
    myfile.open("alumno.html");
    myfile << "<html> <body> <h2>Lista de Alumnos:</h2> <table border=3> <head> <td><b>Alumno</b></td> <td><b>DNI</b></td> <td><b>Nombre</b></td> <td><b>Apellidos</b></td> <td><b>Telefono</b></td> <td><b>Fecha de Nacimiento</b></td> <td><b>Email</b></td> <td><b>Curso</b></td> <td><b>Grupo</b></td> <td><b>Lider</b></td> </head>";
    for (int i = 0; i<vAlumnos.size(); i++)
    {
      myfile << "<tr>";
      if( isLider(vAlumnos[i].getDni()) == true )
      {
        es_lider = "Sí";
      } else{
        es_lider = "No";
      }
      myfile << "<td> "<< i+1 << "</td><td>" << vAlumnos[i].getDni()  << "</td><td>" << vAlumnos[i].getNombre() << "</td><td>" << vAlumnos[i].getApellidos() << "</td><td>" << vAlumnos[i].getTelefono()
      << "</td><td>" << vAlumnos[i].getFechaNacimiento() << "</td><td>" << vAlumnos[i].getEmail() << "</td><td>" << vAlumnos[i].getCurso() << "</td><td>" << vAlumnos[i].getGrupo()
      << "</td><td>" << es_lider << "</td>";
      myfile << "</tr>";
    }

    myfile << "</table></body></html>";
    myfile.close();
  }
}

void Agenda::mostrarAlumnosTerminal() //muestra la lista de alumnos con todos sus datos por la terminal
{
  if(vAlumnos.empty())
  {
    std::cout<<"La agenda de alumnos está vacía\n";
  } else{
    for(int i=0; i<vAlumnos.size(); i++)
    {
      std::cout<< "Alumno "<<i+1<<": \n";
      std::cout<<"DNI: " << vAlumnos[i].getDni() << "\n";
      std::cout<<"Nombre: " << vAlumnos[i].getNombre() << "\n";
      std::cout<<"Apellidos: " << vAlumnos[i].getApellidos() << "\n";
      std::cout<<"Telefono: " << vAlumnos[i].getTelefono() << "\n";
      std::cout<<"Fecha de Nacimiento: " << vAlumnos[i].getFechaNacimiento() << "\n";
      std::cout<<"Email: " << vAlumnos[i].getEmail() << "\n";
      std::cout<<"Curso: " << vAlumnos[i].getCurso() << "\n";
      std::cout<<"Grupo: " << vAlumnos[i].getGrupo() << "\n";

      if( isLider(vAlumnos[i].getDni()) == true )
      {
        std::cout<<"El alumno es lider\n";
      } else{
        std::cout<<"El alumno no es lider\n";
      }
      std::cout<<"\n";
    }
  }
}

int Agenda::searchAlumnoDNI(std::string dni) //devuelve la posicion del alumno que se está buscando
{


  for(int i=0 ; i<vAlumnos.size() ; i++)
  {
    if(vAlumnos[i].getDni() == dni)
    {
      return i;
    }
  }
  return -1;
}


bool Agenda::addAlumno(Alumno alumno)
{
  if(vAlumnos.size() < 150){ //SI en la clase hay menos de 150 alumnos, se puede añadir un alumno
      vAlumnos.push_back(alumno);
      return true;
  }
  return false;
}

bool Agenda::deleteAlumno(std::string dni)//EL metodo debe borrar por dni
{
  if(!vAlumnos.empty())
  {
    int numPosicion = searchAlumnoDNI(dni);
    vAlumnos.erase(vAlumnos.begin()+numPosicion);
    return true;
  }
  return false;
}

void Agenda::mostrarAlumnosMismoGrupo(int grupo){
  for ( int i = 0; i < vAlumnos.size() ; i++){
    if(vAlumnos[i].getGrupo() == grupo){

      std::cout<< "Alumno "<<i+1<<": \n";
      std::cout<<"DNI: " << vAlumnos[i].getDni() << "\n";
      std::cout<<"Nombre: " << vAlumnos[i].getNombre() << "\n";
      std::cout<<"Apellidos: " << vAlumnos[i].getApellidos() << "\n";
      std::cout<<"Telefono: " << vAlumnos[i].getTelefono() << "\n";
      std::cout<<"Fecha de Nacimiento: " << vAlumnos[i].getFechaNacimiento() << "\n";
      std::cout<<"Email: " << vAlumnos[i].getEmail() << "\n";
      std::cout<<"Curso: " << vAlumnos[i].getCurso() << "\n";
      std::cout<<"Grupo: " << vAlumnos[i].getGrupo() << "\n";

      if( isLider(vAlumnos[i].getDni()) == true )
      {
        std::cout<<"El alumno es lider\n";
      } else{
        std::cout<<"El alumno no es lider\n";
      }
      std::cout<<"\n";
  }
}
}

void Agenda::mostrarUnAlumno(std::string dni){

  int posicion = searchAlumnoDNI(dni);
  if(posicion != -1){
    std::cout<< "Alumno "<<posicion+1<<": \n";
      std::cout<<"DNI: " << vAlumnos[posicion].getDni() << "\n";
      std::cout<<"Nombre: " << vAlumnos[posicion].getNombre() << "\n";
      std::cout<<"Apellidos: " << vAlumnos[posicion].getApellidos() << "\n";
      std::cout<<"Telefono: " << vAlumnos[posicion].getTelefono() << "\n";
      std::cout<<"Fecha de Nacimiento: " << vAlumnos[posicion].getFechaNacimiento() << "\n";
      std::cout<<"Email: " << vAlumnos[posicion].getEmail() << "\n";
      std::cout<<"Curso: " << vAlumnos[posicion].getCurso() << "\n";
      std::cout<<"Grupo: " << vAlumnos[posicion].getGrupo() << "\n";

      if( isLider(vAlumnos[posicion].getDni()) == true )
      {
        std::cout<<"El alumno es lider\n";
      } else{
        std::cout<<"El alumno no es lider\n";
      }
  }else std::cout<<"No existe un alumno con el DNI indicado\n";
}

void Agenda::modificarAlumno(std::string dni, int pos)
{
  //FUNCION EN DESARROLLO
  std::string updni,upname,upsurname,update,upemail;
  int uptlf,upcurso,upgrupo,uplider;

  std::cout<<"1.DNI: ";
  std::cin>>updni;
  vAlumnos[pos].setDni(updni);
  std::cout<<"2.Nombre: ";
  std::cin>>upname;
  vAlumnos[pos].setNombre(upname);
  std::cout<<"3.Apellidos: ";
  std::getline(std::cin,upsurname);
  std::getline(std::cin,upsurname);
  vAlumnos[pos].setApellidos(upsurname);
  std::cout<<"4.Telefono: ";
  std::cin>>uptlf;
  vAlumnos[pos].setTelefono(uptlf);
  std::cout<<"5.Fecha de Nacimiento: ";
  std::cin>>update;
  vAlumnos[pos].setFechaNacimiento(update);
  std::cout<<"6.Email: ";
  std::cin>>upemail;
  vAlumnos[pos].setEmail(upemail);
  std::cout<<"7.Curso: ";
  std::cin>>upcurso;
  vAlumnos[pos].setCurso(upcurso);
  std::cout<<"8.Grupo: ";
  std::cin>>upgrupo;
  vAlumnos[pos].setGrupo(upgrupo);
  std::cout<<"9.Lider (0=NO, 1=SI): ";
  std::cin>>uplider;
  vAlumnos[pos].setLider(uplider);
}
