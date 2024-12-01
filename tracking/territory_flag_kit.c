/*
  * This is an example on how to embed GameLabs entity ownership tracking and utilize persistent storage.
  * Storage is available for everything that inherits from `BaseBuildingBase`
*/

modded class TerritoryFlagKit extends KitBase {
    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" ) {
        super.OnPlacementComplete(player, position, orientation);

        if(GetGame().IsServer()) {
            PlayerBase playerBase = PlayerBase.Cast(player);
            PlayerIdentity identity = playerBase.GetIdentity();
            string steam64 = identity.GetPlainId();

            vector playerPos				= player.GetPosition();
            array<Object> nearestObjects	= new array<Object>();

            GetGame().GetObjectsAtPosition(playerPos, 15.0, nearestObjects, null);

            TerritoryFlag relatedObject, tmpObject;
            foreach (Object nearestObject : nearestObjects) {
                EntityAI ent = EntityAI.Cast(nearestObject);
                if(ent) {
                    if(ent.GetType() == "TerritoryFlag") {
                        tmpObject = TerritoryFlag.Cast(ent);
                        if(tmpObject.GL_GetStorage()) {
                            if(!tmpObject.GL_GetStorage().Available()) {
                                relatedObject = tmpObject;
                                break;
                            }
                        }
                    }
                }
            }

            if(relatedObject != NULL) {
                relatedObject.GL_SetSteam64(steam64);
                relatedObject.GL_GatherPersistentID();
                relatedObject.GL_Save(true);
            }
        }
    }
};
