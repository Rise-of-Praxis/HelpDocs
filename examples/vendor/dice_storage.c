/* Equinox
 * Sorrow's area "Kobold Caves" - Town of Pitcairn
 *
 * /realms/Equinox/kobold/room/weapon_storage.c
 * weapon vendors room of Pitcairn
 * 
 * created on: 03.22.04 by Equinox for NM.
 * updated on: 04.08.04 by Equinox for NM.
 *
 */
 
#include <lib.h>
#include "/realms/sorrow/Library/newbie2/newbie2def.h"

inherit LIB_STORAGEROOM;

static void create()
{
    storageroom::create();
    SetNoClean(1);
    SetMinInventory(40);
    SetResetRate(4);

    SetProperty("no teleport", 1);
    SetProperty("no bump", 1);
    SetAmbientLight(12);
    SetClimate("indoors");
    SetTown("Nuberia");
    SetObviousExits("%^CYAN%^n%^RESET%^");
    SetShort("%^CYAN%^Nuberia Dice Storage Room%^RESET%^");
    SetLong("Dice Storage Room");
 
    AddExit("north", NB2_ROOM+"start");

	// This is the specific inventory that the vendor will have for sale. This stuff 
	// just lies in the room and when you ask the vendor to browse, the vendor will read
	// from the things lying in the room.
    SetInventory( ([  
                           
            NB2_ITEM+"d4" : 5,
            NB2_ITEM+"d6" : 5,       
            NB2_ITEM+"d8" : 5,      
            NB2_ITEM+"d10" : 5,   
            NB2_ITEM+"d12" : 5,  
            NB2_ITEM+"d20.c" : 5,
            NB2_ITEM+"d100.c" : 5,
                    ]) );
 
 
}       



int CanReceive(object ob) {
    if( !living(ob) || creatorp(ob) ) return storageroom::CanReceive(ob);
    else return 0;
}
/* Approved by venus on Sun Jul 25 13:59:47 2004. */