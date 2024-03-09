/*
 * >>> THIS CODE WILL BE EXPOSED; ONLY USE ON SERVER SIDE <<<
 *
 * This will send a WebHook containing the entire execution parameters and action definition to a specified URL to a "success" or "failed" URL.
 * Your web server will then be able to process the success or failure of a specific execution and act out additional logic on your backend.
 *
 * >>> DO NOT USE THIS WITH DISCORD WEBHOOKS <<<
 */

class GameLabsTest_DummyActionWithWebHook extends GameLabsContextAction {
        void GameLabsInternal_DummyActionWithWebHook() {
            this.actionCode = "GameLabsInternal_DummyActionWithWebHook";
            this.actionName = "Dummy action (WebHook)";
            this.actionIcon = "accessible-icon";
            this.actionColour = "danger";
            this.actionContext = "world";

            string myWebHookURL = "https://example.com";

            // You are able to have unique URLs for success and error or only define one specific type
            this.responseSuccess = new GameLabsActionResponse("webhook", myWebHookURL);
            this.responseFailed = new GameLabsActionResponse("webhook", myWebHookURL);

            this.parameters.Insert("webhookUrl", GameLabsActionParameter("WebHook URL", "Any valid WebHook URL", "webhook_url"));
        }

        override bool Execute(GameLabsActionContext context) {
            GetGameLabs().GetLogger().Debug(string.Format("Dummy action called webhookUrl=%1", context.parameters.Get("webhookUrl").GetString()));
            return true;
        }
};