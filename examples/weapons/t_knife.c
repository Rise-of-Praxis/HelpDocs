
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;


static void create() {
    item::create();

    SetKeyName("knife");  		//the objects name
    SetId( ({ "knife"}));
    //SetAdjectives( ({ "simple"}));  	//A descriptor, this object can be referred to as 'knife', or 'simple knife'
    SetShort("a simple throwing knife");  	//the short description of the item when you see it in a room or on a player
    SetLong("A simple knife designed for throwing.");   	//the description of the item when you look at it.
    SetMass(40);  			//how much the item weighs
    SetVendorType(VT_WEAPON);    	//what type of vendor will buy this weapon.  (a weapons vendor in this case)
					//from /include/vendor_types.h
    SetBaseCost(4);  			//how much it's worth to a vendor when it's good as new
    SetClass(24);  			//how strong this weapon is.  30 being 'good'.
    SetDamagePoints(200);   //how long before the weapon gest damaged
    SetDamageType(KNIFE);  		//what type of damage from /include/damage_types.h this weapon
					//inflicts when it hits an enemy
    SetWeaponType("throwing");  	//the weapon type
}

