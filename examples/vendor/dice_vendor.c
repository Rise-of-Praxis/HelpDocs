/* Equinox
 *
 * /realms/equinox/kobold/npc/weapon_vendor.c
 * Pitcairn weapon vendor - 
 *
 * created on: 03.22.04 by Equinox for NM.
 * updated on: 08.15.04 by Equinox for NM.
 *
 */


#include <lib.h>
#include <vendor_types.h>
#include <combat_group.h>
#include <damage_types.h>
#include <daemons.h>
#include "/realms/sorrow/Library/newbie2/newbie2def.h"

inherit LIB_VENDOR;

static void create() {
    vendor::create();
    SetKeyName("tombstone");
    SetId( ({ "tombstone", "vendor", "die seller" }) );
    SetShort("Tombstone, the dice vendor");
    SetLong("This grizzled dwarf wears an eye patch over its left eye and has so much tangled hair over its face, head "
	        "and hanging down over its body that it's quite impossible to tell whether it is male or female. Even the "
			"voice doesn't give a hint as to gender either. Tombstone is quite stout and it doesn't appear that any "
			"natural occurrence could knock Tombstone from its feet.\n"
			"%^GREEN%^%^BOLD%^<ask tombstone to browse>%^RESET%^ for a list of items they are selling.");
    SetClass("monk");
    SetLevel(4);
    SetRace("dwarf");
    SetGender("male"); 
    
	// Currencies that the vendor has on him.
    AddCurrency("gold", random(40)+5);
    AddCurrency("platinum", random(50)+2);
	AddCurrency("silver", random(50)+2);
    AddCurrency("electrum", random(50)+25);

    // To set the vendored items as not being able to be stolen.
    SetPreventSteal("All of the die are non-stealable.");

    SetMorality(0);
    
	// This is where you setup which room the inventory for his store will be.
    SetStorageRoom(NB2_ROOM+"dice_storage"); 
    
	SetSkill("bargaining", 50);
    SetSkill("blunt attack", 60);
    SetSkill("knife attack", 50);
    SetStat("strength", 75+random(25));
    SetMaxItems(90); // Max Items the vendor can have at any one time.
    SetProperty("no bump", 1); // Set the 'no bump' property to keep the vendor in his room
    SetLocalCurrency("silver"); // The currency that the vendor uses to trade/barter with
    SetVendorType(VT_WEAPON); // Set the Vendor Type and what kind of items the vendor will purchase
   
    SetResistance(BLUNT, "medium");
    SetResistance(BLADE, "extreme");
    SetResistance(COLD | HEAT, "high");

    // Actions that are one when the vendor is not in combat.
    SetAction(5, ({ "!emote scans the area silently.",
                    "!speak Another adventurer... how I miss those days.",
                    "!speak Would you like to view my wares?",
                    "!speak I have many different types of dice for sale. Please, take a look.",
                    "!speak You can ask me to browse, price, appraise, sell, show, or buy.",
                    }) );
    
    // This inventory is only for what the vendor has on him - NOT for sale!
    SetInventory( ([ 
                    NB2_ARMOUR+"nbrobe" : "wear robe",
                   ]) );

    SetDie("%^RED%^%^BOLD%^Tombstone dies with a defiant growl upon its lips.%^RESET%^");

    AddInformationResponse("default", "You are making no sense.");
}

// To prevent shoplifting from the vendor.
int eventShoplift(object who, string what) {
   who->eventPrint("None of the merchandise is within reach.");
   return 0;
}
/* Approved by venus on Thu Jul 15 14:58:13 2004. */
