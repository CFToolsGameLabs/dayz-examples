/*
 * Contanimated areas are being tracked using a special "radius exclusive" mode.
 * Overlapping contaminated areas are not tracked with an exclusion radius of 100 units from its center
 */

modded class ContaminatedArea_Dynamic  {
    ref _Event _registeredInstance = new _Event("Contanimated Area", "biohazard", this);

    override void EEInit() {
        super.EEInit();
        if(!GetGame().IsServer()) return;
        vector position = GetPosition();
        if(position[0] <= 0 && position[1] <= 0 && position[2] <= 0) return;
        GetGameLabs().RegisterEventRadiusExclusive(this._registeredInstance, 100.0);
    }
    override void EEDelete(EntityAI parent) {
        super.EEDelete(parent);
        if(!GetGame().IsServer()) return;
        if(!GetGameLabs()) return;
        if(this._registeredInstance) GetGameLabs().RemoveEvent(this._registeredInstance);
    }
};
