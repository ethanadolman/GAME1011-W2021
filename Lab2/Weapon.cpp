#include "Weapon.h"

ostream& operator<<(ostream& out, Weapon w)
{
	out << "\n-----Weapon----- " << "\nName: " << w.GetName() << "\nDescription: " << w.GetDescription() << "\nDamage: " << w.GetDamage() << "\nSpecial Abilities: " << w.GetSpecialAbility(0) << ", " << w.GetSpecialAbility(1);
	return out;
}
