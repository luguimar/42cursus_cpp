#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    {
        ClapTrap ct("CL4P-TP");

        ct.attack("Enemy");
        ct.takeDamage(3);
        ct.beRepaired(5);
        ct.takeDamage(12);
        ct.attack("Enemy");
    }
    {
        ScavTrap st("Serena");
        st.attack("an enemy");
        st.guardGate();
    }
    {
        FragTrap ft("FragTrap");
        ft.attack("an enemy");
        ft.highFivesGuys();
    }
    {
        DiamondTrap dt("DiamondTrap");
        dt.attack("an enemy");
        dt.whoAmI();
    }
    return 0;
}
