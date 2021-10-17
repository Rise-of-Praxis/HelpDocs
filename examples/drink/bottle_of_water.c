/*
 * /realms/equinox/kobold/food/water.c
 *
 *
 * created on: 03.15.04 by Equinox for NM.
 *
 */

#include <lib.h>

inherit LIB_BOTTLE;

// this object should only describe the container in the KeyName, Id,
// adjectives, short, and long
// the SetLiquidType() sets what liquid you are putting in
// but remember, this liquid type could change later
// once the initial liquid is emptied
// in other words, you don't want a short desc of 'a bottle of water'
// when someone could in fact empty out the water and put in some beer

protected void create() {
    bottle::create();
    SetKeyName("bottle");
    SetId("bottle");
    SetAdjectives("clear");
    SetShort("a clear bottle");
    SetLong("This bottle is fashioned from a clear glass.");
    // SetValue(50);
    SetMass(45);
    // remember, use '$target_name' and NOT 'a bottle of water'
    // if it became a bottle of beer, seeing the message
    // 'You chug a bottle of water.' might look weird!
    SetMessage(({ "chug", "$agent_name $agent_verb $target_name." }));
    SetVolume(49); // in centiliters
    SetMaxVolume(50);
    SetLiquidType("water");
    SetContainerName("bottle");
    SetValue(5);
    // SetStrength(10);
	
    SetSatiate(20); // like the old SetStrength()
    // SetAlcohol(2); if this were alcoholic
    // SetCaffeine(2); if this were caffinated
    // SetPoisonous(2); if this were poisonous
}
/* Approved by venus on Mon Jul 12 15:06:03 2004. */