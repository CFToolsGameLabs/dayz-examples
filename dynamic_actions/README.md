# Dynamic Actions
This example will show you how to create a custom action and register it for use with CFTools Cloud.

You can use various contexts (vehicle, player, world) to facilitate actions, depending on their scope.

For an implementation reference, please check `action.c`. Any action must be registered using the `Register()` method as described in `mission_server.c`.

In general dynamic actions will be executed based on a specific context. The `Execute(GameLabsActionContext context)` method will be invoked, when requested remotely through the Data API or CFTools Cloud.
Your action must implement the logic within this function and perform error handling itself. The `context` argument contains information based on the specified context. For `player`, `vehicle` and `object` this will contain the actual reference to a specific entity.

In `example_actions` you can find an assortment of actions as implemented natively in GameLabs for each `contextType` to guide you on how to use specific context types.

## Parameters
### actionCode
Action code is a short code that must be registered and unique. It is being used to call your action and must match the
actual class name. This will also be the primary identifier for any Data API calls to trigger the action.

Format: `{YourModPrefix}_{Action}`

Example: `TestMod_SomeAction`

### actionName
Name of your action in a human readable format. You should only use ASCII characters to ensure DayZ can properly handle and transmit it.

### actionIcon
The icon used for representing your action in the CFTools Cloud interface. We utilize FontAwesome icons for this instance.

Available icons: https://fontawesome.com/v5/search

Note: The icon type will *always* be `dualtone`

### actionColour
A color to tag your action within the CFTools Cloud interface and make certain actions more noticeable than others.

Available colour tags:
- `success` Green; No specific usage recommendation
- `danger` Red; Use for destructive actions
- `warning` Orange; No specific usage recommendation
- `default` White; No specific usage recommendation

### actionContext
Dynamic actions can be executed in different contexts, for example a player context action can only be executed with a specific player reference, while world can be executed everywhere and without a specific reference.

The action context dictates the existence of a `referenceKey`.

Available contexts:
- `world` Can be used without `referenceKey` and does not have a specific reference.
- `player` Requires `referenceKey` to be the `steam64` of a player. Will be executed with player entity as reference.
- `vehicle` Requires `referenceKey` to be a GameLabs internal vehicle reference. Will be executed with the vehicle entity as reference.
- `object` Requires `referenceKey` to be a GameLabs internal object reference. Will be executed with an `EntityAI` object referenced.

### parameters
A list of optional parameters of different datatypes. For an example check `action.c`.

Available parameter types:
- `int`
- `float`
- `string`
- `boolean`
- `vector`
- `cf_itemlist`Special parameter that returns a `string` class name of an entity. Using this parameter will render a item list selection within CFTools Cloud.
- `webhook_url` Special parameter that returns a `string` containing an HTTP url that GameLabs uses from your game server to send a completion WebHook.
