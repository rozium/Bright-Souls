//
//  mskill.c
//  
//
//  Created by Akmal Fadlurohman on 11/28/16.
//
//

#include <stdio.h>
#include "bintree.h"

int main()
{
    BinTree playerskill;
    
    InitializeSkill(&playerskill);
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill Flee\n");
    HasSkill(Akar(SearchTreeString (playerskill, "Flee"))) = true;
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill GiantArms\n");
    HasSkill(Akar(SearchTreeString (playerskill, "GiantArms"))) = true;
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill Iron Body\n");
    HasSkill(Akar(SearchTreeString (playerskill, "IronBody"))) = true;
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill FitBody\n");
    HasSkill(Akar(SearchTreeString (playerskill, "FitBody"))) = true;
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill Boxing Punch\n");
    HasSkill(Akar(SearchTreeString (playerskill, "BoxingPunch"))) = true;
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill Gatling Gun\n");
    HasSkill(Akar(SearchTreeString (playerskill, "GatlingGun"))) = true;
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill Exorcist\n");
    HasSkill(Akar(SearchTreeString (playerskill, "Exorcist"))) = true;
    SkillMenu(playerskill,2);
    printf("Anda mendapatkan skill Giant\n");
    HasSkill(Akar(SearchTreeString (playerskill, "Giant"))) = true;
    SkillMenu(playerskill,2);
    return 0;
}
