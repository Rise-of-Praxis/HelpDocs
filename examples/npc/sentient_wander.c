/* Equinox
 * /realms/equinox/kobold/npc/kobold_wander.c
 * Kobold Wanderer for area "Kobold Caves" - Pitcairn
 *
 *
 * By Sorrow 12-19-98 (original)
 * By Despair 7.26.99 (updated) - 12.28.99 update
 * fixed for NM on 2.20.00
 * last update: 09.20.00
 * last update: 08.31.04 by Equinox for NM.
 *
 */

#include <lib.h>
#include "/realms/sorrow/kobold/kbdef.h"

inherit LIB_SENTIENT;

void DoHut();
void DoHut2();
void DoHut3();
void DoHut4();
void DoHut5();
void DoHut6();
void DoHut7();
int DoAction();

static void create()
{
    sentient::create();
    SetKeyName("kobold");
    SetId( ({"kobold" }));
    SetAdjectives(({ "wandering", "drunken" }));
    SetShort("a wandering drunken kobold");
    SetLong("This short green kobold drunkenly wanders the dark caves "
            "muttering to himself. He carries around a dirty loincloth "
            "and wears a blue bandana wrapped loosely on his right arm. "
            "He reeks of alcohol as well as bodily waste, not a pleasant "
            "creature to be around.");
    SetRace("kobold"); // Sets the race of the npc
    SetGender("male"); // Sets the sex of the npc
    SetClass("monk"); // Sets the class of the npc
    SetTown("Pitcairn");

    SetSmell("default", "He totally reeks of cheap alcohol and bodily "
             "waste. Very nasty.");  // 'smell kobold' 

    SetLevel(13+random(5)); // Sets the level at 13 + random of 5 (0-4)
    SetMorality(-35); // Morality can be positive (good), neutral, or negative (evil) 
    SetAction(30,  (:DoAction:));  // Actions that the npc does when NOT in combat.
    SetCombatAction(20, ({ "!mutter",
                           "!burp",
                           "!speak yer gawna get it...",
                           "!speak i wannnnna driink...",
                           "The drunken kobold pukes on the ground." }));
    SetDie("%^RED%^%^BOLD%^The drunken kobold falls to the ground with "
           "spittle flying from its mouth.%^RESET%^");
    SetEncounter(10);
    SetInventory( ([
                    KB_ARMOUR+"loin2.c" : "wear loincloth",
                    KB_ARMOUR+"bandblue.c" : "wear bandana on left arm",
                   ]) );
    // SetWander(75); // Sets the npc up to randomly wander through open exits
    // SetArea("Kobold Caves"); // Should stay within this specified area when wandering.
    // SetWanderSpeed(1); // Sets the speed that they move to a new room

    // SetWander() -- Below is a specific path setup for the npc to wander and it will
    //                not deviate from it. You can also just have the npc set to SetWander(#)
    //                and the npc will randomly move about through open exits. The # in the
    //                SetWander(#) is how fast they will wander/move about.
    SetWander(1,
             ({ "go south", "go east", "go south", "go south", "go south",
                "go out", "go west", "go north", "go north", "go east", "go east", 
                "go south", "go south", "go west", "enter cave", "go north",
                "go north", "go north", "go north", "go west", "go north", "go north",
                "search vines", "enter opening", "go down", "go down", "go down", "go down",
                "get all", "enter hole", "go up", "go up", "go up", "enter opening", 
                "go south" }) );
    SetWanderRecurse(0);  // 1: will go in reverse of SetWander() when finished or 0: will not
    AddInformationResponse("hut", (:DoHut:));
}

int DoAction() {
        object ob;
        switch(random(6)) {
            case 0:
                   eventForce("!emote slips and almost falls.");
                   break;
            case 1:
                   eventForce("!emote stumbles, muttering curses to himself.");
                   break;
            case 2:
                   eventForce("!burp");
                   break;
            case 3:
                   eventForce("!emote mutters incoherently as a stream of urine "
                          "runs down his leg to the ground.");
                   if(!present("puddle")) {
                        ob = new(KB_ITEM+"urinepuddle");
                        ob->eventMove(environment());       
                   }
                   break;
            case 4:
                   eventForce("!mutter");
                   break;
            case 5:
                   eventForce("!emote drunkenly scratches his buttocks.");
                   break;
        }
        return 1;
}


void DoHut() {
        eventForce("!speak Uht? Me noo 'bout uht! uhhh.. ");
        eventForce(LIB_UTIL->random_element(({ "!emote wipes the spittle from his chin with"
                                     " his arm.",
                                     "!emote coughs up some phlegm.",
                                     "!emote hacks and coughs loudly."})));
        call_out( (:DoHut2:), 5);
}

void DoHut2() {
        eventForce(LIB_UTIL->random_element(({ "!speak Yessss.. ifff youu ..",
                                     "!speak Umm, i.. mean.. no!",
                                     "!speak Nooo! Iss ter.. terrible!"})));
        eventForce(LIB_UTIL->random_element(({ "!emote hiccups.",
                                     "!emote farts loudly.",
                                     "!emote belches.",
                                     "!emote picks his nose."})));
        call_out( (:DoHut3:), 5);
}

void DoHut3() {
        eventForce(LIB_UTIL->random_element(({"!yell Whattt!!!??",
                                    "!yell A rat! A rat!",
                                    "!yell dogbutt!",
                                    "!yell Beaner!"})));
        call_out( (:DoHut4:), 5);
}

void DoHut4() {
        eventForce("!speak Ohh, tha' uht!");
        eventForce("!speak loook 'nda' vinies.");
        call_out( (:DoHut5:), 5);
}

void DoHut5() {
        eventForce(LIB_UTIL->random_element(({ "!emote wobbles and almost falls over.",
                                     "!emote lurches forward, almost falling on"
                                     " his face.",
                                     "!emote stumbles sideways, almost losing his"
                                     " balance.",
                                     "!emote falls to the floor and quickly stands"
                                     " again."})));
        eventForce("!speak itt dohwn neer 'da big froggy!");
        call_out( (:DoHut6:), 5);
}

void DoHut6() {
        eventForce(LIB_UTIL->random_element(({ "!emote wets himself.",
                                     "!emote doesn't notice a trickle of urine running"
                                     " down "
                                     "his own leg.",
                                     "!emote unceremoniously releases his bladder."})));
        eventForce(LIB_UTIL->random_element(({ "!emote rubs his legs with his hands.",
                                     "!emote runs his hands up and down his legs.",
                                     "!emote cleans off his legs with his hands."})));
        call_out( (:DoHut7:), 5);
}

void DoHut7() {
        eventForce("!speak uhhh, i' h'den 'doh!  h'den!");
        eventForce(LIB_UTIL->random_element(({ "!emote babbles on to himself eyes totally"
                                     " glazed over.",
                                     "!emote pays no more attention to you.",
                                     "!emote drools on his chest and stumbles away."})));
}
           

/* Approved by venus on Mon Aug  2 17:13:55 2004. */
