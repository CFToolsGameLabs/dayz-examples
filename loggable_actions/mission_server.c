/* Registering Loggable Actions
 * This example will show you how to register custom actions for logging using GameLabs
 *
 * The core functionality is realized using the "AddMonitoredAction" method, taking the class name of an action that
 * goes through the normal event pipeline and is loggable through the base game admin log plugin.
 *
 */


modded class MissionServer {
#ifdef GAMELABS
    override GLActionRegisterHook() {
        super.GLActionRegisterHook();

        GetGameLabs().AddMonitoredAction("HDSN_ActionDeployBreachingCharge");
        GetGameLabs().AddMonitoredAction("HDSN_ActionDefuseBreachingCharge");
    }
#endif
};
