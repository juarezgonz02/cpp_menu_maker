#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

void escribirSwitch(int, ofstream*);
int main(){

    string name, footer, file_name;
    cout << "Creador de menu"<<endl;
    cout << "Nombre del archivo: ";
        cin >> name;
        cin.ignore();


    file_name = name+".cpp";

    ofstream cpp_file(file_name);

    cpp_file << "#include <iostream>\n#include <string>\nusing namespace std;\nint main(){\n\tbool salir = false;\n\tdo{\n\t\t int option;\n\t\t cout <<";
    cpp_file << '"';
    cpp_file << "(Escribe el titulo del menu)"; 
    cpp_file << '"';
    cpp_file << "<<endl;";
    int n_opciones = 1;
    bool salir = false;
    do{
        int option;
        string description, num;
        cout << "1) Agregar opcion al menu "<<endl;
        cout << "2) Salir: "<<endl;
        
        cout<< " Opcion: "; cin >> option;
        cin.ignore();

        switch (option){
            case 1:
                cout << "Ingresa el label de la opcion: ";
                getline(cin, description);
                num =  to_string(n_opciones) +")";
                cpp_file << " \n\t\t cout <<  ";
                cpp_file << '"';
                cpp_file << num;
                cpp_file << " ";
                cpp_file << description;
                cpp_file << '"';
                cpp_file << "<< endl;";
                n_opciones+=1;
                cout << endl;
                break;

            case 2:
                salir = true;
                num =  to_string(n_opciones) +")";
                cpp_file << " \n\t\t cout <<  ";
                cpp_file << '"';
                cpp_file << num;
                cpp_file << " ";
                cpp_file << "Salir";
                cpp_file << '"';
                cpp_file << " << endl;";
                escribirSwitch(n_opciones, &cpp_file);
                break;

            default:
                break;
        }

    }while(!salir);

    footer = "\n\t }while(!salir);\n\n\t return 0;\n}";

    cpp_file << footer;
    cpp_file.close();

    return 0;

}

void  escribirSwitch( int n, ofstream *cpp_file){
    
    *cpp_file << "\n\t\t cout <<  ";
    *cpp_file << '"';
    *cpp_file << " Escoge una opcion: ";
    *cpp_file << '"';
    *cpp_file << ';';

    *cpp_file << "cin >> option;";
    *cpp_file << "\n\t\t cin.ignore();";
    *cpp_file << "\n";
    *cpp_file << "\n\t\t switch(option){";

    for(int i = 1; i<n; i++) {
    *cpp_file << "\n\t\t\t case ";
    *cpp_file << to_string(i);
    *cpp_file << ":";
    *cpp_file << "\n\t\t\t\t break;";

    }

    *cpp_file << "\n\t\t\t case ";
    *cpp_file << to_string(n);
    *cpp_file << ":";
    *cpp_file << "\n\t\t\t\t salir = true;";
    *cpp_file << "\n\t\t\t\t break;";

       *cpp_file << "\n\t\t\t default";
    *cpp_file << ":";
    *cpp_file << "\n\t\t\t\t break;";



    *cpp_file << "\n";
      *cpp_file << "\n\t\t  }";
}

