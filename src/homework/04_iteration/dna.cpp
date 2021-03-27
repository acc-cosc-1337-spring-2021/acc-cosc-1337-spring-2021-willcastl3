#include "dna.h"

double get_gc_content(const std::string& dna)
{

    int count = 0;
    for (const char& i : dna )
    {
        if (i == 'C' || i == 'G')
        {
            count++;
        }
    }
    double size_of_string;
    size_of_string= dna.size();

    return count/size_of_string;
};


std::string get_dna_complement(std::string dna)
{
    std::string complement;

    for(auto letter: reverse_string(dna))
    {
        if(letter == 'T')
        {
            complement.append("A");
        }
        else if(letter == 'A')
        {
            complement.append("T");
        }
        else if(letter == 'C')
        {
            complement.append("G");
        }
        else if(letter == 'G')
        {
            complement.append("C");
        }
    }
    return complement;
};


std::string reverse_string(std::string dna)
{
    std::string reversed_dna;
    for (int i = dna.size() - 1; i >= 0; i--) {
        reversed_dna = reversed_dna.append(1, dna[i]);
    };

    return reversed_dna;
};




