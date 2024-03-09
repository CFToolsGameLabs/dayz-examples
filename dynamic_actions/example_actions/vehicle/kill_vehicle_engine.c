class CFCloud_KillVehicleEngine extends GameLabsContextAction {
        void CFCloud_KillVehicleEngine() {
            this.actionCode = "CFCloud_KillVehicleEngine";
            this.actionName = "Stop engine";
            this.actionIcon = "engine-warning";
            this.actionColour = "default";
            this.actionContext = "vehicle";
        }

        override bool Execute(GameLabsActionContext context) {
            _Vehicle vehicle;
            _Vehicle.CastTo(vehicle, context.GetReferencedObject());

            Car vehicleEntity;
            Car.CastTo(vehicleEntity, vehicle.Ref());

            GetGameLabs().GetLogger().Warn(string.Format("[Vehicle-EngineStop] %1", vehicleEntity));

            CarScript.Cast(vehicleEntity).EngineStop();
            return true;
        }
};