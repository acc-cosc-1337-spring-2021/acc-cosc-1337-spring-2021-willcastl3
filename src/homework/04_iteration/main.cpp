#include <iostream>
#include "dna.h"

using std::cout; using std::cin; using std::string; using std::getline;

int main()
{
    string menu_selection;
    do {
        cout<<"******************\n"
            <<"Menu\n"
            <<"1 = GC Content\n"
            <<"2 = DNA Complement\n"
            <<"Y = Exit.\n"
            <<"******************"
            <<"\n"
            <<"\n"
            <<"Enter Option: ";

        getline(cin,menu_selection);
        cout <<"\n";

        if (menu_selection == "1")
        {
            string user_dna;
            cout << "Enter DNA: ";
            getline(cin,user_dna);

            double gc_content;
            gc_content = get_gc_content(user_dna);

            cout << "GC-content of a DNA: "<< gc_content;
            cout << "\n"
                 << "\n";
        }

        else if (menu_selection == "2")
        {
            string user_dna;
            cout << "Enter DNA: ";
            getline(cin,user_dna);

            string dna_complement;
            dna_complement = get_dna_complement(user_dna);

            cout << "DNA Complement: "<< dna_complement;
            cout << "\n"
                 << "\n";
        }

        else if(menu_selection != "y" || menu_selection != "1")
        {
            break;
        }

    }while(menu_selection == "1" || menu_selection == "2");

    cout<< "Program terminated by user...";

    return 0;
}

