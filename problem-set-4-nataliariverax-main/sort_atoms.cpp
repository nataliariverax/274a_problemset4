#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//list of correct order
std::vector<std::string> correct_order = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "Ne"
};

//match atom to an atom index based on correct order
int atom_index(std::string atom_number)
{
    for (int i = 0; i < correct_order.size(); i++)
        if (correct_order[i] == atom_number)
        return i;
    return -1;
}

//helper function to compare atoms based on index
bool compare_atom_index(std::string a, std::string b)
{
    return atom_index(a) < atom_index(b);
}

int main(void)
{
    /* Here is a vector of atomic symbols */
    std::vector<std::string> atoms = {"N",  "Be", "B",  "C",  "B", 
                                      "H",  "H",  "Li", "O",  "Ne",
                                      "Be", "H",  "C",  "N",  "N",
                                      "C",  "B",  "C",  "He", "B"};

/* ------------------------------------------------------------------------- */

    /* Sort this vector so that it is in order by element number,
     * and print it out */

     //sort using the index
    std::sort(atoms.begin(), atoms.end(), compare_atom_index);

    //print
    std::cout << "Vector sorted by element number:" << std::endl;
    for (int i = 0; i < atoms.size(); i++)
    {
        std::cout << atoms[i] << " ";
    }
    std::cout << std::endl;

/* ------------------------------------------------------------------------- */

    /* Find the unique elements, and print those out */
    std::vector<std::string> unique_elements = {};

    //add first element
    unique_elements.push_back(atoms[0]);

    //compare each new element to the one before before adding to unique_elements
    //iterate through list
    for (int i = 1; i < atoms.size(); i++)
    {
        if (atoms[i] != unique_elements.back())
        {
            unique_elements.push_back(atoms[i]);
        }
    }

    //print
    std::cout << "Unique elements of the vector:" << std::endl;
    for (int i = 0; i < unique_elements.size(); i++)
    {
        std::cout << unique_elements[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}

