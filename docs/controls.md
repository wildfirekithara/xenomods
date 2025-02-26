## Controls

Xenomods mostly utilizes a menu to interact with the game, as most buttons are already taken up on the controller. A few specific things like moonjump and event debugging are notable exceptions to this.

---

#### P1 controls:
| Action                | Control      | Description                                                                                                  |
|-----------------------|--------------|--------------------------------------------------------------------------------------------------------------|
| Moonjump              | R+B          | Hold to make the player infinitely fly in the air.                                                           |
| Events - Toggle Debug | R+Dpad Up    | Toggles debug rendering from the currently selected event manager.<br>**Only applicable in 2/Torna events.** |
| Events - Prev Debug   | R+Dpad Left  | Selects the previous event manager.<br>**Only applicable in 2/Torna events.**                                |
| Events - Next Debug   | R+Dpad Right | Selects the next event manager.<br>**Only applicable in 2/Torna events.**                                    |

#### Camera controls:

The camera can be controlled by P1 while the Menu is open, but ideally should be used by P2 so both analog sticks are always free.

| Action                    | Control               | Description                                                                                                                                    |
|---------------------------|-----------------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| Freecam Toggle            | LStick+RStick, **P2** | Enables the free camera. Left stick controls movement, right stick controls the view.                                                          |
| -                         | -                     | **!! ALL BELOW ONLY FUNCTION WHILE THE FREECAM IS ACTIVE !!**                                                                                  |
| Freecam - Speed Up        | L+R+Plus, **P2**      | Increases the speed of the freecam.                                                                                                            |
| Freecam - Speed Down      | L+R+Minus, **P2**     | Decreases the speed of the freecam.                                                                                                            |
| Freecam - Change FOV      | L+R+LStick, **P2**    | Changes the field of view of the freecam. Up on the stick to tighten in, down to loosen up.<br/>Click to reset to 80.                          |
| Freecam - Change Roll     | L+R+RStick, **P2**    | Changes the roll (tilt) of the freecam. The stick controls the amount of added tilt in each direction.<br/>Click to completely reset rotation. |
| Freecam - Teleport Player | L+R+B, **P2**         | Teleports the player to the freecam's position.                                                                                                |

#### Menu controls:
| Action      | Control    | Description                                                              |
|-------------|------------|--------------------------------------------------------------------------|
| Toggle Menu | L+R+ZL+ZR  | Opens the Menu. Will take the place of logger messages.                  |
| Up          | Dpad Up    | Navigates to the previous choice.                                        |
| Down        | Dpad Down  | Navigates to the next choice.                                            |
| Select      | Dpad Right | Selects the currently hovered choice. Will automatically call functions. |
| Back        | Dpad Left  | Returns to the parent section/deselects the current option.              |

###### Option controls:

These are the controls for Options (numbers, booleans, enums).

| Action        | Control   | Description                                                                 |
|---------------|-----------|-----------------------------------------------------------------------------|
| Increment     | Dpad Up   | Increments the number by the tens multiplier, or toggles the boolean.       |
| Decrement     | Dpad Down | Decrements the number by the tens multiplier, or toggles the boolean.       |
| Multiply by 2 | B         | Hold while changing a number to instead multiply or divide the number by 2. |
| Next Tens     | A         | Cycles through the powers of ten that the number can hold.                  |
| Negate        | Y         | Press to negate the current number, or toggle the boolean.                  |
| Set to 0      | X         | Sets the current number to 0.                                               |