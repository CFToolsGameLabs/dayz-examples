class GameLabsContextAction {
        string actionCode
        string actionName
        string actionIcon
        string actionColour = "default"
        string actionContext = "world"

        ref map<string, ref GameLabsActionParameter> parameters

        string referenceKey

        // Register the action with CFCloud
        void Register()

        // Execution environment
        bool Execute(GameLabsActionContext context)

        // Get and set for action parameters
        string GetActionCode()
        string GetActionName()
        string GetActionIcon()
        string GetActionColour()

        // Convert action to JSON for transmission
        string ToJson()

        // Used for storing responses for WebHooks, currently unused
        GameLabsActionResponse GetResponseSuccess()
        GameLabsActionResponse GetResponseFailed()
}