# Custom map icons
CFTools Cloud offers a map with the ability to have custom icons displaying modded content.

This example shows you two pathways to implement such custom content based.

The basic function of how everything is displayed is based upon the `_Event` tracking class. See `event.c` for available parameters.

After registering an `_Event` for tracking, GameLabs handles everything automatically. The parameters that can be customized are only display related.

Special consideration must be taken when interacting with entities that are dynamic in nature. So that they either move, or have additional status modifiers. Additionally, when overriding tracking of a base-tracked object you must deferr loading 

For an example of how to handle this special case see `territory_flag.c`.

## Customization
### icon
The icon used for display on the map can be customized. We utilize FontAwesome icons for this instance.

Available icons: https://fontawesome.com/v5/search

Note: The icon type will *always* be `regular`; The colour is not customizable