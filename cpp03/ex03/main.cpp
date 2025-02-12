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
        // Create a DiamondTrap
        DiamondTrap dt("Shiny");

        // Check basic stats
        dt.whoAmI();  // Should print DiamondTrap name + ClapTrap name

        // Try the attack() method (should come from ScavTrap)
        dt.attack("Some target");

        // Try something from the FragTrap side (e.g. highFivesGuys() if present)
        dt.highFivesGuys();

        // Show that HP and stats are from FragTrap for HP/AD, ScavTrap for EP
        // dt._hitPoints   => 100 (FragTrap)
        // dt._energyPoints=> 50  (ScavTrap)
        // dt._attackDamage=> 30  (FragTrap) 
    }
    return 0;
}
