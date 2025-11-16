#include <iostream>
#include <vector>
#include <sstream>
#include <map>

struct Atom
{
    int element; //!< Atomic Z-number
    double x;    //!< X-coordinate
    double y;    //!< Y-coordinate
    double z;    //!< Z-coordinate
};


class Molecule
{
    private:
        std::vector<Atom> atoms_; //vector of atoms

    public:
        Molecule(const std::vector<Atom> & atoms)
            : atoms_(atoms)
        { }


        std::string molecular_formula() const
        {
            /* Write code to find the molecular formula here */

            //lookup table; map atomic number to element symbol
            std::vector<std::string> elements = {
                "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"
            };

            //count number of each element in molecule
            //store counts in map
            std::map<std::string, int> counts;

            for (int i = 0; i < atoms_.size(); i++)
            {
                //convert atomic number index w/ map to actual symbol
                std::string symbol = elements[atoms_[i].element];
                //increase counts as more are recognized
                counts[symbol]++;
            }

            //build output stream
            std::ostringstream formula;

            //iterate through counts map in alphabetical order
            //pair key (symbol) to value (counts)
            for (const auto &key_value_pair : counts)
            {
                const std::string &element = key_value_pair.first;
                int printed_count = key_value_pair.second;

                //print element symbol
                formula << element;

                //only print count number if it's more than 1
                if (printed_count > 1)
                    formula << printed_count;
            }
            return formula.str();



        }
};


int main(void)
{
    /* Some testing code below */
    // Create atoms to add to a molecule
    std::vector<Atom> atoms;
    atoms.push_back(Atom{6, 0.0, 0.0, 0.0});
    atoms.push_back(Atom{1, 0.0, 0.0, 1.0});
    atoms.push_back(Atom{1, 0.0, 1.0, 0.0});
    atoms.push_back(Atom{9, 1.0, 0.0, 0.0});
    atoms.push_back(Atom{9, 1.0, 1.0, 0.0});

    Molecule m(atoms);
    std::cout << m.molecular_formula() << std::endl;

    atoms.clear();
    atoms.push_back(Atom{7, 0.0, 0.0, 0.0});
    atoms.push_back(Atom{8, 0.0, 0.0, 1.0});
    atoms.push_back(Atom{8, 0.0, 1.0, 0.0});

    Molecule m2(atoms);
    std::cout << m2.molecular_formula() << std::endl;

    return 0;
}

